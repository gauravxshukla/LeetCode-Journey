#include<bits/stdc++.h>
using namespace std;

    int trappedwater(vector<int>& heights){
        int size=heights.size();

        if(size<=2){
            return 0;
        }
        vector<int> left(size,0), right(size,0);
        left[0]=heights[0];
        right[size-1]=heights[size-1];

        for(int i=1;i<size;i++){
            left[i]=max(left[i-1],heights[i]);
            right[size-i-1]=max(right[size-i],heights[size-i-1]);
        }

        int water=0;
        for(int i=0;i<size;i++){
            water+=min(left[i],right[i])-heights[i];
        }

        return water;
    }



int main(){
    vector<int> water={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedwater(water);
    return 0;
}