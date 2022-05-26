#include<bits/stdc++.h>
using namespace std;

    void insert_element(stack<int>& stk,int temp){
        if(stk.empty()==1){
            stk.push(temp);
            return;
        }
        
        int val=stk.top();
        stk.pop();
        
        insert_element(stk,temp);
        stk.push(val);
    }


    void reverse_stack(stack<int>& stk){
        if(stk.size()==1){
            return;
        }

        int val=stk.top();
        stk.pop();
        reverse_stack(stk);

        insert_element(stk,val);

    }



int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    reverse_stack(stk);

    while (!stk.empty()) {
        cout << ' ' << stk.top();
        stk.pop();
    }


    return 0;
}