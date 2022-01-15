/*
    Problem Link - https://leetcode.com/problems/two-sum/
    In this problem,
    we are given with an array and a target and 
    we need to find two numbers which can sum upto the target.
    There only exists a unique solution.

    Approach -

    1) Bruteforce - In this you just select an element(a) and search the whole array for (target-a).
    This way you iterate element(a) to the end and implement it using bruteforce approach.

    2) Hashmap - You create a map(Unordered_map because O(1) time) and iterate the whole array only once with an element(x).
    While iterating the whole array you check for the (target-x) in your map while making sure
    you insert the key(value of element x) and value(index of element x) while traversing the array
    so that you are able to find the target-x since you were already inserting index and value from the start. 

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> bruteforce(vector<int>& nums,int target){
    vector<int> ans;
    int size=nums.size();
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> hashsol(vector<int>& nums,int target){
    int size=nums.size();
    vector<int> ans;
    unordered_map<int,int> umap;
    for(int i=0;i<size;i++){
        if(umap.count(target-nums[i])){ //To check if target-nums exist in the map or not.
            ans.push_back(i);
            ans.push_back(umap[target-nums[i]]);
            return ans;
        }
        umap[nums[i]]=i;    //Inserting the value in map since we didn't found a pair.
    }
    return ans;
}

int main(){
    int size,target;
    cin>>size>>target;
    vector<int> nums(size),ans;
    for(int i=0;i<size;i++) cin>>nums[i];
    //ans=bruteforce(nums,target);
    ans=hashsol(nums,target);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}

