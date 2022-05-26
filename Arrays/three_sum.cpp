#include<bits/stdc++.h>
using namespace std;

    //Time Complexity - O(N^3)
    vector<vector<int>> brute(vector<int>& arr, int sum){
        int size=arr.size();
        vector<vector<int>> result;

        sort(arr.begin(),arr.end());
        if(size<3){
            return {};
        }

        //Pick every 1st element till last third element.
        for(int i=0;i<size-2;i++){
            //Pick every 2nd element till last second element.
            for(int j=i+1;j<size-1;j++){
                //Pick every 3rd element till last element.
                for(int k=j+1;k<size;k++){

                    //If the sum of all three element is sum, insert it in the array.
                    if(arr[i]+arr[j]+arr[k]==sum){
                        result.push_back({arr[i],arr[j],arr[k]});
                    }
                }
            }
        }
        return result;
    }


    //Time Complexity - O(NLogN).
    // O(NLogN) for sorting, O(N)(For traversing) * O(N)(For two pointers).
    vector<vector<int>> optimal(vector<int>& arr,int sum){
        int size=arr.size();
        vector<vector<int>> result;
        //Cannot create a triplet.
        if(size<3){
            return {};
        }
        sort(arr.begin(),arr.end());

        //Pick every element(arr[i]) till last 3rd element
        for(int i=0;i<size-2;i++){
            //Two pointers approach
            
            //Initializing variables for two pointers(left and right pointers).
            int j=i+1;
            int k=size-1;
            
            //We don't want the pointer to collide.
            while(j<k){
                int current_sum=arr[i]+arr[j]+arr[k];
                
                //If Current sum is equal, push it to the result array.
                if(current_sum==sum){
                    result.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    k--;
                }

                //If it is more, decrease k to make so that we get a lesser value to match sum.
                else if(current_sum>sum){
                    k--;
                }

                //If it is less, increase j to make it bigger to match the sum.
                else{
                    j++;
                }
            }
        }
        return result;
    }

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,15};
    int sum=18;
    
    //auto result=brute(arr,sum);
    auto result=optimal(arr,sum);
    for(auto i:result){
        for(auto num:i){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}