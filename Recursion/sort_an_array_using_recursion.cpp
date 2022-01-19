#include<bits/stdc++.h>
using namespace std;

    void insert(vector<int>& arr, int temp){
        //Base Condition
        if(arr.size()==0 || arr[arr.size()-1]<=temp){
            arr.push_back(temp);
            return;
        }

        //Hypothesis-Design
        int val=arr[arr.size()-1];
        arr.pop_back();
        insert(arr,temp);

        //Induction
        arr.push_back(val);
        return;
    }

    void sort(vector<int>& arr){
        
        //Base Condition
        if(arr.size()==1){
            return;
        }

        //Hypothesis - Design
        int temp=arr[arr.size()-1];
        arr.pop_back();
        sort(arr);
        
        //Induction
        insert(arr,temp);
    }




    int main(){
        vector<int> arr={5,4,3,2,1};
        sort(arr);
        for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
        return 0;
    }