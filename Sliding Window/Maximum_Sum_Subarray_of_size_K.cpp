/* Approach - This is a classic problem of Fixed Size Sliding Window.
Since, we have to find the maximum sum of a subarray of size k,
it is obvious we need to maintain a window of size k which needs to move forward to make sure we check out all the values of K.
To implement this,
we have used two variable which are the end points of a window(left end = i, right end = j).
Now, we need to calulate the sum of all elements between these two ends while also ensuring that right and left end is moving forward too.
To achieve this, we are constantly adding values to a variable sum(sum+=arr[j]),
the if loop comes into picture when difference between the right end(j) and the left end(i)
is equal to the sub array size of k.
When this happens, we have a variable mx which keeps of the maximum value of a window encountered in the past,
it compares all the previous value with the present to provide us with the maximum as per the question's requirement,
Also, we need to make sure the left end is also moving since the size of window should be k and it would exceed the size if 
don't do the needful.
Hence, we achieve it in O(n) time.


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
        
        //Make sure the right end is moving and the value is being added.
        sum+=arr[j];
        if(j-i+1==k){

            //Compares with the previous max and the present value
            mx=max(mx,sum);

            //Removing the left end's value(sum-arr[i]) and also moving the left end(i++)
            //to make sure we don't exceed the subarray size of K.
            sum=sum-arr[i];
            i++;
        }
    }
    cout<<mx;
    return 0;
}