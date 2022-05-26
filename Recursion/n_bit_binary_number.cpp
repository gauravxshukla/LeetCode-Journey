#include<bits/stdc++.h>
using namespace std;

    void solve(int n,int one_count,int zero_count,string op){
        if(n==0){
            cout<<op<<endl;
            return;
        }

        string op1=op;
        op1.push_back('1');
        solve(n-1,one_count+1,zero_count,op1);

        if(one_count>zero_count){
            string op2=op;
            op2.push_back('0');
            solve(n-1,one_count,zero_count+1,op2);
        }
        return;
    }


int main(){
    int n;
    cin>>n;
    string op="";
    solve(n,0,0,op);

    return 0;
}