/*
    Problem Link - https://leetcode.com/problems/rotate-image/
    Problem Statement - In this problem, we are being given an input matrix(n*n),
                        we have to rotate the matrix by 90 Degree.
    
    Approach - 

    1) Brute- Force - Create another 2-D matrix and simple copy the rows into column and vice versa.

    2) Optimal - Since, in the last approach, we were creating a secondar matrix, we can improve on that.
                 We can transpose the matrix and then 
*/


#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> brute(vector<vector<int>>& nums){
        int n=nums.size(),m=nums[0].size();
        vector<vector<int>> result(n,vector<int> (m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                result[j][n-i-1]=nums[i][j];
        return result;
    }

    void optimal(vector<vector<int>>& nums){
        int n=nums.size();

        //Transpose of a matrix
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                    swap(nums[i][j],nums[j][i]);


        //Swapping only columns
        //Rewrite this loop on your own everytime you visit.
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(nums[i][j],nums[i][n-j-1]);
            }
        }

    }
    int main(){

        vector<vector<int>> nums = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
        };
        optimal(nums);
        //nums=brute(nums);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[0].size();j++){
                cout<<nums[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }