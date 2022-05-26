#include<bits/stdc++.h>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // initialize max product,min product and answer
        int ans = INT_MIN,max_prod = 1,min_prod =1; 
        
        
        for(int i=0;i<nums.size();i++){

            // if number is negative, we will swap max prod and min prod
            if(nums[i]<0){   
                swap(max_prod,min_prod);
            }

            max_prod = max(nums[i],max_prod*nums[i]); // find current max prod each time
            min_prod = min(nums[i],min_prod*nums[i]); // find current min prod each time
            
            ans = max(ans,max_prod); // store the maximum product each time
        }
        return ans;
    }
};