#include<bits/stdc++.h>
using namespace std;

    vector<vector<string>> optimal(vector<string>& str){
        if(str.size()==0){
            return {};
        }
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> result;

        for(auto i:str){
            string b=i;
            sort(b.begin(),b.end());
            mp[b].push_back(i);
        }

        for(auto i:mp){
            result.push_back(i.second);
        }
        return result;
    }


int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    
    auto result=optimal(strs);

    for(auto it:result){
        for(auto str:it){
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}