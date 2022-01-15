/*
Problem Link - https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/



*/

#include<bits/stdc++.h>
using namespace std;

int countKDifference(vector<int>& nums, int k) {
    int size=nums.size(),count=0;
    unordered_map<int,int> umap;
    for(int i=0;i<size;i++){
        if(umap[nums[i]+k]) count+=umap[nums[i]+k]; 
        if(umap[nums[i]-k]) count+=umap[nums[i]-k]; 
        umap[nums[i]]++;
    }
    return count;
}



int main(){
    int size,k;
    cin>>size>>k;
    vector<int> nums;
    for(int i=0;i<size;i++) cin>>nums[i];
    cout<<countKDifference(nums,k);
    return 0;
}