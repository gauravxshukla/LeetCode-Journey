#include<bits/stdc++.h>
using namespace std;
/*
1) Print 1 to n.
2) Go through an array and print out all of the elements.
3) Determine whether or not a string is a palindrome.
4) Calculate a raised to the power of b.
5) Print Fibonacci Number from 1 to n.
*/

    void print(int n){
        //Base Condition/Terminating Condition
        //Smallest Valid Input/ Largest Invalid Input
        if(n==0){
            return;
        }

        //Calculation
        cout<<n<<" ";
        
        //Iterator aka Function call Decrement
        print(n-1);

        return;
    }



int main(){
    print(5);    
    return 0;
}