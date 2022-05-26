#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<vector<int>> ans;
    int solve(vector<int>& input,vector<int>& output){
        if(input.size()==0){
            for(auto i:output){
                cout<<i;
            }
            cout<<endl;
            return 0;
        }
        //For selecting an input
        //vector<int> output1=output;
        int x=input[0];
        output.push_back(input[0]);
        input.erase(input.begin()+0);
        solve(input,output);
        input.insert(input.begin(),x);
        //Remove the first element
        output.pop_back();
        solve(input,output);
        return 0;
    }
    
    int main() {
        ans.clear();
        vector<int> nums={1,2,3};
        vector<int> output;
        solve(nums,output);
        return 0;
    }

};