#include<bits/stdc++.h>
using namespace std;

    void insert_ele(vector<int>& arr, int val){
        if(arr.size()==0 || arr[arr.size()-1]<val){
            arr.push_back(val);
            return;
        }

        int temp=arr[arr.size()-1];
        arr.pop_back();
        insert_ele(arr,val);

        arr.push_back(temp);
    }

    void sort(vector<int>& arr){
        if(arr.size()==1){
            return;
        }

        int val=arr[arr.size()-1];
        arr.pop_back();
        sort(arr);

        insert_ele(arr,val);
    }

int main(){
    vector<int> arr={5,4,3,2,1};
    sort(arr);

    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}