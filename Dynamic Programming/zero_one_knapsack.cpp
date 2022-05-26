#include<bits/stdc++.h>
using namespace std;

static int dp[102][1002];

    int knapsack(int wt[],int val[],int W,int n){
        if(n==0 || W==0){
            return 0;
        }

        if(dp[n][W]!=-1){
            return dp[n][W];
        }

        if(wt[n-1]<=W){
            return dp[n][W]=max((val[n-1]+knapsack(wt,val,W-wt[n-1],n-1)),knapsack(wt,val,W,n-1));
        }

        else if(wt[n-1]>W){
            return dp[n][W]=knapsack(wt,val,W,n-1);
        }

    }




int main(){
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W=7;
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(wt,val,W,4);
    return 0;
}