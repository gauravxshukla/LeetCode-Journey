/*

Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

*/

#include<bits/stdc++.h>
using namespace std;

    bool isPowerofTwo(int n){
        if(n==0 || n%2!=0)    return false;
        //Base Condition - Condition valid for smallest input.
        if(n<=2)    return true;

        return isPowerofTwo(n/2);
    }


    int main(){

        cout<<isPowerofTwo(3)<<endl;
        cout<<isPowerofTwo(4)<<endl;
        cout<<isPowerofTwo(1)<<endl;
        cout<<isPowerofTwo(6)<<endl;
        
        return 0;
    }