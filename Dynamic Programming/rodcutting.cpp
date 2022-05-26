#include<bits/stdc++.h>
using namespace std;

    int rodcutting(int n,vector<int> prices){
        if(n==0){
            return 0;
        }
        int ans=INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(n-(i+1)>=0){
                ans=max(ans,rodcutting(n-i-1,prices)+prices[i]);
            }
        }
        return ans;
    }

int main(){
    vector<int> prices={3,5,8,9,10,17,17,20};
    int n=8;
    cout<<rodcutting(n,prices);
    return 0;
}