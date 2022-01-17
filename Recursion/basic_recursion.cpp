#include<bits/stdc++.h>
using namespace std;

/*

1) Print 1 to n.
2) Go through an array and print out all of the elements.
3) Determine whether or not a string is a palindrome.
4) Calculate a raised to the power of b.
5) Print Fibonacci Number from 1 to n.

*/
    int fibonacci(int n){
        if(n<1) return 0;
        if(n==1) return 1;

        return fibonacci(n-1) + fibonacci(n-2);
    }


    bool palindromecheck(string str,int start, int end){
        
        //Base Condition
        if(end-start <2 && str[start]==str[end]){
            return true;
        }

        //For looping recursively
        if(str[start]==str[end]){
            return palindromecheck(str,start+1,end-1);
        }

        //For calculation
        return false;
    }


    void printarr(vector<int>& arr,int n){
        //Base condition - Where the function should stop and not further it.
        if(n<0){
            return;
        }

        // This is the most important step, can be considered as the iterating step just like in for loop.
        //Remember, it's job is to lower the input.
        printarr(arr,n-1);

        //Content of the loop, can be considered as the calculations part.
        cout<<arr[n]<<" ";
        return;
    }

    void oneton(int n){
        if(n==0)    return;

        cout<<n<<" ";
        oneton(n-1);
    
        return;
    }

    int main(){
        //oneton(50);
        // int n;
        // cin>>n;
        // vector<int> arr(n);
        // for(int i=0;i<n;i++)    cin>>arr[i];
        // printarr(arr,n-1);
        // string str;
        // cin>>str;
        // cout<<palindromecheck(str,0,str.size()-1);
        cout<<fibonacci(5);
        return 0;
    }