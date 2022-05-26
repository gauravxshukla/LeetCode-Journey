#include<bits/stdc++.h>
using namespace std;

    void reverse_arr(vector<int>& arr,int i){
        if(i>(arr.size()-1)/2){
            return;
        }
        swap(arr[i],arr[arr.size()-i-1]);
        reverse_arr(arr,i+1);
        return;
    }

int main(){
    vector<int> arr={1,2,3,4,5};
    reverse_arr(arr,0);
    for(auto i:arr){
        cout<<i<<" ";
    }


    return 0;
}