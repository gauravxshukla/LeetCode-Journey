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

    void recursion_sort(vector<int>& arr,int size){
        //Base Condition
        if(size==1){
            return;
        }

        //Hypothesis/Iteration
        recursion_sort(arr,size-1);

        //Calculation
        for(int i=0;i<=size-2;i++){
            if(arr[size-1]<arr[i]){
                swap(arr[i],arr[size-1]);
            }
        }
    }


    int main(){
        vector<int> arr={5,4,3,2,1};
        recursion_sort(arr,5);
        for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
        return 0;
    }