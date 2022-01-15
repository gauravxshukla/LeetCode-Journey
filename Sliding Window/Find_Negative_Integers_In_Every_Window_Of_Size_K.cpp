#include<bits/stdc++.h>
using namespace std;

int main(){
    int size,k;
    cin>>size>>k;
    vector<int> arr(size),ans;
    // arr is the array which contains input elements.
    //ans is the array which contains the ans of the window.
    list<int> l;
    //l is a queue(FIFO) which contains all the negative values present in the input array.
    for(int i=0;i<size;i++)     cin>>arr[i]; //Taking Inputs


    for(int i=0,j=0;j<size;j++){

        if(arr[j]<0)    l.push_back(arr[j]);
        //If we spot out a negative number, we add it to our queue(FIFO).    
        
        if(j-i+1==k){
        //Checks if the window size is met or not.
        
            if(l.size()==0)     ans.push_back(0);
            //Checks if there is any value left in the queue, if not, it adds zero to the ans array.
        
            else{
                ans.push_back(l.front());
                //If there is a value, it will be in the front, so we append it to the ans array.
                if(arr[i]==l.front()){
                    l.pop_front();
                }
                //To remove the value from the queue, since i is going to increment and it won't add up.

            }
            i++;
        }
    }
    for(int i=0;i<ans.size();i++)     cout<<ans[i]<<" ";
    return 0;
}