#include<bits/stdc++.h>
using namespace std;

    int peak(vector<int>& arr){
        int size=arr.size();
        int height=0;

        if(size<3){
            return 0;
        }

        for(int i=1;i<size-1;i++){

            // To find a peak, if the front and back are less than the middle element.
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int front=i-1;
                int back=i+1;

                // To increase the height of peak backwards.
                while(back<size-1 && arr[back]>arr[back+1])   back++;

                //To increase the height of peak forward.
                while(front>0 && arr[front]>arr[front-1])   front--;

                int current_height=(arr[i]-arr[front]) + (arr[i]-arr[back]);
                height=max(current_height,height);
            }
        }
        return height;
    }



int main(){
    vector<int> arr={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<peak(arr);

    return 0;
}