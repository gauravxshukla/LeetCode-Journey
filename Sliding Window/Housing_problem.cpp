#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    void bruteforce(vector<int>& arr,int sum){
        int size=arr.size();
        vector<pair<int,int> > result;
        for(int i=0;i<size-1;i++){
            int current_sum=arr[i];
            for(int j=i+1;j<size;j++){
                current_sum+=arr[j];
                if(current_sum==sum){
                    result.push_back({i,j});
                }
            }
        }

        for(auto it:result){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }

    void slidingwindow(vector<int>& arr,int sum){
        int i=0;
        int j=0;
        int current_sum=0;

        while()
    }

};

int main(){
    vector<int> arr={1,3,2,1,4,1,3,2,1,1,2};
    int k=8;
    Solution sol;
    sol.bruteforce(arr,k);

    return 0;
}