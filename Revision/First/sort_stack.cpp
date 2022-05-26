#include<bits/stdc++.h>
using namespace std;

    void insert_val(stack<int>& stk,int val){
        if(stk.empty() || stk.top()<val){
            stk.push(val);
            return;
        }

        int temp=stk.top();
        stk.pop();
        insert_val(stk,val);
        
        stk.push(temp);
        return;
    }

    void sort_stack(stack<int>& stk){
        if(stk.size()==1){
            return;
        }
        
        int val=stk.top();
        stk.pop();
        sort_stack(stk);
        
        insert_val(stk,val);
        
        return;
    }


int main(){
    stack<int> stk;
    stk.push(5);
    stk.push(3);
    stk.push(4);
    stk.push(2);
    stk.push(1);

    sort_stack(stk);
    while (!stk.empty()) {
        cout << ' ' << stk.top();
        stk.pop();
    }
    return 0;
}