/*

Problem Link - https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] 
have averages 4, 5 and 6 respectively.
All other sub-arrays of size 3 have averages less than 4 (the threshold).
*/



#include<bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int size=arr.size(),count=0,sum=0;
    for(int i=0,j=0;j<size;j++){
        sum+=arr[j];
        if(j-i+1==k){
            if(sum/k>=threshold){
                count++;
            }
            sum-=arr[i];
            i++;
        }
    }
    return count;
}

int main(){
    vector<int> arr={2,2,2,2,5,5,5,8};
    cout<<numOfSubarrays(arr,3,4);
    return 0;
}