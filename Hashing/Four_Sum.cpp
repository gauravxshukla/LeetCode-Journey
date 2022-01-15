/*
    Problem Link - https://leetcode.com/problems/4sum/

    Brute - In this approach, we run 4 nested loops with 4 variables and if the sum of those variables comes out to be the target.
    We store all the 4 index in a hashset(because we want the unique ones only.)
    When we are done, we return our 2D vector by copying our hashset contents into it.

    Example - 
    Input - 4 3 3 4 4 3 1 2 1 1
    Sorted - 1 1 1 2 2 3 3 4 4 4
    Output - []

*/



#include<bits/stdc++.h>
using namespace std;

class FourSum{
    public:
    vector<vector<int>> brute(vector<int>& nums,int target){
        set<vector<int>> unique;
        vector<int> temp;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-3;i++){
            for(int j=i+1;j<size-2;j++){
                for(int k=j+1;k<size-1;k++){
                    for(int l=k+1;l<size;l++){
                        temp.clear();
                        if((nums[i]+nums[j]+nums[k]+nums[l])==target){
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            temp.push_back(nums[l]);
                        }
                        if(temp.size()!=0)  unique.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(unique.begin(),unique.end());
        return ans;
    }

    vector<vector<int>> better(vector<int>& nums, int target) {
        int n=nums.size();
            sort(nums.begin(),nums.end());
            set<vector<int>>sv;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                    
                    int chk=(long long)target-((long long)nums[i]+(long long)nums[j]+(long long)nums[k]);
                        if(binary_search(nums.begin()+k+1,nums.end(),chk)){
                        
                            vector<int>v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(chk);
                        
                        
                            sort(v.begin(),v.end());
                            sv.insert(v);
                        }
                    }
                }
            }
        vector<vector<int>>ans(sv.begin(),sv.end());
        return ans;
    }

/*
    Example - 
    Input - 4 3 3 4 4 3 1 2 1 1
    Sorted - 1 1 1 2 2 3 3 4 4 4
    Output - [1,1,3,4], [1,2,3,3]
*/

    vector<vector<int>> optimal(vector<int>& num, int target) {
         vector<vector<int> > res;
        
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }

};