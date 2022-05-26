#include<iostream>
#include<string>

using namespace std;


int main(){
    string str,word;

    //Taking a line of input before delimiter(.).
    getline(cin,str,'.');
    
    //Taking a word to search for occurence.
    cin>>word;
    
    int index=str.find(word);
    cout<<"1st Occurence :"<<index<<endl;
    return 0;
}