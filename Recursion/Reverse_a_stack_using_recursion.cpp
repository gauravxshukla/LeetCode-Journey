/*
Stack Prerequisites

    Declaring a Stack = stack<int> stk;
    Push a value - stk.push(value);
    Pop a value - stk.pop();
    Find the top element - stk.top();
    Check if Stack is empty - stk.empty();
    Size of Stack - stk.size();

*/


#include<bits/stdc++.h>
using namespace std;

    void insert(stack<int>& stk,int value){
        //Base Condition - Since, we have to put our value at the bottom,
        //We will make sure we are putting it when the stack is Empty.
        if(stk.empty()){
            stk.push(value);
            return;
        }

        // Hypothesis - We have to define and refine our function
        //The main purpose of this function is to remove element and then insert our value
        // at the bottom.
        int temp=stk.top();
        stk.pop();
        insert(stk,value);
        
        // Induction - This is where the calculation takes place.
        // Since, we removed an element before, we have to insert it again as part of our calculation.
        stk.push(temp);
        return;
    }

    void reversestack(stack<int>& stk){
        //Base Condition
        if(stk.size()<=1){
            return;
        }

        //Hypothesis
        int value=stk.top();
        stk.pop();
        reversestack(stk);

        //Induction
        insert(stk,value);
        return;
    }



    int main(){
        stack<int> stk;
        for(int i=1;i<=5;i++){
            stk.push(i);
        }
        cout<<stk.top()<<endl;
        reversestack(stk);
        for(int i=1;i<=5;i++){
            cout<<stk.top()<<" ";
            stk.pop();
        }

        return 0;
    }