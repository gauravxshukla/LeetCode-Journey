#include<bits/stdc++.h>
using namespace std;

    int bruteforce(vector<int>& arr){
        //The approach is simple, we will sort the array first.
        //We will then find the longest band if the next element is greater than the previous element.
        //And, check the longest band using the max function.
        int size=arr.size();
        int longest_band=0,count=1;
        //Sorting the array.
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<size;i++){
            if(arr[i+1]-arr[i]==1){
                count+=1;
            }
            else{
                longest_band=max(longest_band,count);
                count=1;
            }
        }
        return longest_band;
    }
    
    int optimal(vector<int>& arr){
        int longest_band=0;
        unordered_set<int> Hashtable;

        for(auto element:arr){
            Hashtable.insert(element);
        }

        for(auto element:arr){
            int parent=element-1;
            
            //Check for a number one less than the value, if it does not exists, it is the head.
            //If it exist, skip the number since it is not the head.
            if(Hashtable.find(parent)==Hashtable.end()){
                int count=1;
                int next_element=element+1;
                while(Hashtable.find(next_element)!=Hashtable.end()){
                    count++;
                    next_element++;
                }
                longest_band=max(longest_band,count);
            }
        }
        return longest_band;
    }


int main(){
    vector<int> arr={1,9,3,0,18,5,2,4,10,7,12,6};
    //cout<<bruteforce(arr);
    cout<<optimal(arr);
    return 0;
}