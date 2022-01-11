/* Approach - This is a classic problem of Fixed Size Sliding Window.
We run a loop from 0 to n. We add up to the variable sum everytime we iterate.
The If loop comes into picture after a desired size of values are added to the variable sum.
To make sure we don't exceed the size, we remove an element too(Since, we are adding one element on every iteration).
This is how we iterate throughout the array.

We have kept a special variable mx which keeps track of all the values of sum of sub-array and makes sure we get the maximum value.

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n,sum=0,mx=INT_MIN;
    //Taking size of array(n) and size of subarray(k).
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i]; //Taking inputs
    for(int i=0,j=0;j<n;j++){
        sum+=arr[j];
        if(j-i+1==k){
            mx=max(mx,sum);
            sum=sum-arr[i];
            i++;
        }
    }
    cout<<mx;
    return 0;
}