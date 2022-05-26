#include<bits/stdc++.h>
using namespace std;

    void solve(int open,int close,string op,vector<string>& result){
        if(open==0 && close==0){
            result.push_back(op);
            return;
        }

        if(open!=0){
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1,result);
        }

        if(close>open){
            string op2=op;
            op2.push_back(')');
            solve(open,close-1,op2,result);
        }
        return;
    }


int main(){
    int n;
    cin>>n;
    vector<string> result;
    string op="";
    solve(n,n,op,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}