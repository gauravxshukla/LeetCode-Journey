#include<bits/stdc++.h>
using namespace std;

    void delete_mid(vector<int>& arr,int i,int n){
        if(i==n){
            arr.pop_back();
            return;
        }
        int val=arr[n];
        arr.pop_back();
        delete_mid(arr,i,n-1);
        arr.push_back(val);
        return;
    }


int main(){
    vector<int> arr={1,2,3,4,5};
    delete_mid(arr,2,arr.size()-1);

    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}