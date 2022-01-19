#include<bits/stdc++.h>
using namespace std;

    void push(vector<int>& arr,int val,int top){
        if(top==-1 || arr[top]<=val){
            top++;
            arr[top]=val;
            return;
        }

        int temp=arr[top];
        arr.pop_back();
        top--;
        push(arr,val,top);

        arr.push_back(temp);
        top++;
        return;

    }

    void sortstack(vector<int>& arr, int top){
        if(top==0){
            return;
        }

        int val=arr[top];
        arr.pop_back();
        top--;
        sortstack(arr,top);

        push(arr,val,top);
        top++;
    }



int main(){
    vector<int> arr={5,4,3,2,1};
        sortstack(arr,arr.size()-1);
        for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";

    return 0;
}