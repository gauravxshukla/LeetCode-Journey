#include<bits/stdc++.h>
using namespace std;

    void reverse(vector<int>& arr,int size){
        if(arr.size()/2==size){
            return;
        }
        
        swap(arr[size-1],arr[arr.size()-size]);
        
        reverse(arr,size-1);

    }


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}