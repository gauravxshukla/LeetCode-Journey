#include<bits/stdc++.h>
using namespace std;

//Code successfully submitted on LeetCode.


class Solution{
    public:

    string customSortString(string order, string s) {

        //Step - 1 Create an ans string.
        string ans="";
        unordered_map<char,int> charcnt;
        int osize=order.size(),ssize=s.size();
        
        //Step - 2 Run unordered_map on s string and store the sum of all characters.
        for(int i=0;i<ssize;i++){
            charcnt[s[i]]++;
        }

        //Step - 3 (Traverse through the order string and simultaneously push back
        //the characters with their frequency in the ans string.)
        for(int i=0;i<osize;i++){

            //Check if the order character exists in the s string or not.
            if(charcnt.find(order[i])!=charcnt.end()){
                
                //Store the frequency of the charcter you need to push in the string.
                int frequency=charcnt[order[i]];            
                while(frequency>0){
                    ans.push_back(order[i]);
                    frequency--;
                }
                charcnt.erase(order[i]);
            }
        }

        //Step - 4 (Add the remaining characters from the map.)
        if(charcnt.size()>0){
            for(auto it:charcnt){
                    int frequency=it.second;
                    while(frequency>0){
                        ans.push_back(it.first);
                        frequency--;
                    }
            }
        }
        return ans;
    }

    int main(){
        string order="cba";
        string s="abcd";

        auto ans=customSortString(order,s);
        cout<<ans;
        return 0;
    }
};