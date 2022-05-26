#include<bits/stdc++.h>
using namespace std;

    void delete_mid(stack<int>& stk,int size){
        if(stk.size()==size/2+1){
            stk.pop();
            return;
        }

        int val=stk.top();
        stk.pop();
        delete_mid(stk,size);
        stk.push(val);
        return;
    }



int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    // while (!stk.empty()) {
    //     cout << ' ' << stk.top();
    //     stk.pop();
    // }
    cout<<endl;

    delete_mid(stk,stk.size());

    while (!stk.empty()) {
        cout << ' ' << stk.top();
        stk.pop();
    }

    return 0;
}