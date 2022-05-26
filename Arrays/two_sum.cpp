// Other names - Pair Sum, Two Sum, Doublets.

#include<bits/stdc++.h>
using namespace std;

    //Time Complexity - O(N.N)
    void bruteforce(vector<int>& arr,int sum){
        int size=arr.size();

        //Iterating this loop from 1 to size-1.
        for(int i=0;i<size-1;i++){
            //Iterating this from j to size.
            for(int j=i+1;j<size;j++){
                //If the sum of both iterators is sum, print it and return.
                if(arr[i]+arr[j]==sum){
                    cout<<arr[i]<<" "<<arr[j];
                    return;
                }
            }
        }
        return;
    }

    // Time Complexity - O(NLogN)
    // [O(NLogN)(For sorting)] + [O(N)(For traversing the array) * O(LogN)(Binary Search)]
    void better(vector<int>& arr,int sum){
        //In this approach, we will sort the array(Time Complexity - O(NLogN)).
        //Then, one iterator will traverse the array, and another will perform 
        //binary search to search for the remaining part in the array.
        int size=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(binary_search(arr.begin()+i,arr.end(),sum-arr[i])==true){
                cout<<arr[i]<<" "<<sum-arr[i];
                return;
            }
        }
        return;
    }

    //Time Complexity - O(N)
    //Note - Inserting and searching a Hashtable(Unordered_set) takes O(1).
    //O(N) for traversing the array.
    void optimal(vector<int>& arr,int sum){
        //In this approach, we will use hashing to store elements because searching in hashing takes O(1) time
        // and we will just run a simple traversal on array.
        int size=arr.size();
        unordered_set<int> hashtable;

        for(int i=0;i<arr.size();i++){
            
            //Checking if the Hashtable already contains the other pair of arr[i].
            if(hashtable.find(sum-arr[i])!=hashtable.end()){
                cout<<arr[i]<<" "<<sum-arr[i];
            }

            //Inserting an element in the hashtable after a successful traversal.
            hashtable.insert(arr[i]);
        }
    }


int main(){
    vector<int> arr={10,5,2,3,-6,9,11};
    int sum=4;
    //bruteforce(arr,sum);
    //better(arr,sum);
    optimal(arr,sum);
    return 0;
}