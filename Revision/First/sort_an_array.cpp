#include<bits/stdc++.h>
using namespace std;

    void sortarr(vector<int>& arr, int n){
        //If array has only one element, it is already sorted.
        if(n==0){
            return;
        }

        //For traversing the whole array.
        sortarr(arr,n-1);

        // --------------------------------------------------
        //For inserting the element at the right place in the array.
        for(int i=0;i<n;i++){
            if(arr[i]>arr[n]){
                swap(arr[i],arr[n]);
            }
        }
        // ------------------------------------------------
        return;
    }


int main(){
    vector<int> arr={5,4,3,2,1};
    sortarr(arr,arr.size()-1);

    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}