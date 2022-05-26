#include<iostream>
#include<string>
using namespace std;

    void getalloccurences(string str,string word,int index,int count){
        if(index==-1){
            return;
        }

        cout<<"Occurence "<<count<<": "<<index<<endl;
        getalloccurences(str,word,str.find(word,index+1),count+1); 
    } 


int main(){
    string str,word;

    //Taking a line of input ending with a delimiter('.').
    getline(cin,str,'.');

    //Taking the word to search for all occurence in the string.
    cin>>word;

    int index=str.find(word);
    int count=1;

    getalloccurences(str,word,index,count);

    //str.find() returns a -1 if there are no occurence in a string.
    // while(index!=-1){
    //     cout<<"Occurence "<<count<<": "<<index<<endl;
    //     index=str.find(word,index+1);
    //     count++;
    // }

    return 0;
}