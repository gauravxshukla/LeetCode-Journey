#include<bits/stdc++.h>
using namespace std;

    int sumofsquare(int n){
        
        //Base condition
        if(n==1){
            return 1;
        }

        //Hypothesis - Exact function but for one input lower
        int sum=sumofsquare(n-1);

        //Induction -  Where actual calculation happens
        return sum+n*n;
    }


    int main(){
        cout<<sumofsquare(3);
        return 0;
    }