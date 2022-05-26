#include<bits/stdc++.h>
using namespace std;

    int coinchange(int m,vector<int> denoms){
        if(m==0){
            return 0;
        }
        
        int ans=INT_MAX;
        for(auto c:denoms){
            if(m-c>=0){
                ans=min(ans,coinchange(m-c,denoms)+1);
            }
        }
        return ans;
    }

int main(){
    vector<int> denoms={1,5,7,10};
    int m=8;
    cout<<coinchange(m,denoms);
    return 0;
}