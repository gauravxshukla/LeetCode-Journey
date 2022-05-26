#include<bits/stdc++.h>
using namespace std;

    void print_name(int i,int n){
        if(i==0)    return;
        cout<<"Gaurav Shukla\n";
        print_name(i-1,n);
    }

    void print_n_to_1_backtrack(int i,int n){
        if(i>n) return;

        print_n_to_1_backtrack(i+1,n);
        cout<<i<<endl;
    }

int main(){
    int n;
    cin>>n;
    //print_name(n,n);
    print_n_to_1_backtrack(1,n);
    return 0;
}