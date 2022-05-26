#include<bits/stdc++.h>
using namespace std;

    void solve(string ip,string op){
        if(ip.length()==0){
            cout<<op<<endl;
            return;
        }

        //Space nahi lagana hai.
        string op1=op;

        //Space lagana hai.
        string op2=op;

        op1.push_back(ip[0]);
        op2.push_back(' ');
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);

        solve(ip,op1);
        solve(ip,op2);

    }


int main(){
    string ip,op;
    cin>>ip;
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op);
}