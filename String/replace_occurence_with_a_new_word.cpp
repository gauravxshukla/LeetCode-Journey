#include<iostream>
#include<string>
using namespace std;
    
    //Sent the string using call by reference just to reduce the copying time and the edits will be directly applied to the string.
    void replacealloccurences(string& str,string& word,string& new_word,int index){
        if(index==-1){
            return;
        }
        str.erase(index,word.size());
        str.insert(index,new_word);
        replacealloccurences(str,word,new_word,str.find(word,index+1)); 
    } 


int main(){
    string str,word,new_word;

    //Taking a line of input ending with a delimiter('.').
    getline(cin,str,'.');

    //Taking the word which is to be replaced..
    cin>>word;
    
    //New replacement for the old word.
    cin>>new_word;
    int index=str.find(word);

    replacealloccurences(str,word,new_word,index);
    cout<<str;
    return 0;
}