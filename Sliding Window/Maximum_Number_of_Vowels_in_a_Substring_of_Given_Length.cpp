#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,sum=0,mx=INT_MIN;
    string s;
    cin>>s>>k;
    for(int i=0,j=0;j<s.size();j++){
        if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
            sum++;
        }
        if(j-i+1==k){
            mx=max(mx,sum);
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                sum--;
            }
            i++;
        }
    }
    cout<<mx;
    return 0;
}