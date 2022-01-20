#include<bits/stdc++.h>
using namespace std;

    void deletemid(vector<int>& stack,int top,int mid){
        //Base Condition - We have to traverse till Middle Element only.
        //And, we have to remove that element, right?
        //So, we did remove the mid element.
        if(top==mid){
            stack.pop_back();
            return;
        }

        // Hypothesis - Defining the value of our function.
        //Popping values from the top to make input small.
        int val=stack[top];
        stack.pop_back();
        top--;
        deletemid(stack,top,mid);

        //Induction - Where the calculation takes place,
        // Pushing back value again which we removed above.
        stack.push_back(val);
        top++;
        return;
    }



    int main(){
        vector<int> stack = {5,4,3,2,1};

        deletemid(stack,stack.size()-1,stack.size()/2);
        for(int i=0;i<stack.size();i++) cout<<stack[i]<<" ";
        return 0;
    }