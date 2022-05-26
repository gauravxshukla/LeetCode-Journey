#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution{
    public:
    vector<string> getalltokens(string& input_str){
        string token;
        vector<string> result;
        stringstream ss(input_str);

        while(getline(ss,token,' ')){
            result.push_back(token);
        }

        return result;
    }
};

int main(){
        string input_str,token,delimiter;

        getline(cin,input_str);

        Solution sol;
        auto result=sol.getalltokens(input_str);

        for(auto i:result){
            cout<<i<<endl;
        }
        return 0;
    }