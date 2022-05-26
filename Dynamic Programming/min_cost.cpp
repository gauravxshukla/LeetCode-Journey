#include<bits/stdc++.h>
using namespace std;

    int getmincost(vector<int> stones,int i){
        int n=stones.size();
        if(i==n-1){
            return 0;
        }

        int min_cost=INT_MAX;
        for(int j=i+1;j<=i+2;j++){
            if(j<n){
                min_cost=min(min_cost,getmincost(stones,j)+abs(stones[j]-stones[i]));
            }
        }
        return min_cost;
    }

int main(){
    vector<int> stones={30,10,60,10,60,50};
    cout<<getmincost(stones,0);
    return 0;
}