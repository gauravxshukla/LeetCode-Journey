#include<bits/stdc++.h>
#include<iostream>
using namespace std;

    //Globally declared LinkedList structure for easy accessibility
    struct Node{
        int data;
        //Self referential structure
        struct Node *next;
    };

class LinkedList{

    public:

    Node* create(int val){
        Node* head=new Node;
        head->data=val;
        head->next=NULL;
        return head;
    }

    void recursive_insert(Node* head,int val){
        if(head->next==NULL){
            Node* new_node=new Node;
            new_node->data=val;
            new_node->next=NULL;
            head->next=new_node;
            return;
        }

        recursive_insert(head->next,val);
        return;
    }                          

    void recursive_display(Node* head){
        if(head==NULL){
            cout<<endl;
            return;
        }

        cout<<head->data<<"-> ";
        recursive_display(head->next);
    }

    int recursive_countNodes(Node *head){
        if(head==NULL){
            return 0;
        }

        return 1+recursive_countNodes(head->next);
    }

    int recursive_SumOfElements(Node *head){
        if(head==NULL){
            return 0;
        }

        return head->data + recursive_SumOfElements(head->next);
    }

    int recursive_MaxOfAll(Node *head){
        if(head==NULL){
            return INT32_MIN;
        }

        return max(head->data,recursive_MaxOfAll(head->next));
    }

};


int main(){
    Node* head;
    LinkedList List;
    head=List.create(10);
    for(int i=2;i<=5;i++){
        List.recursive_insert(head,i);
    }
    cout<<"Elements present in the LinkedList:\n";
    List.recursive_display(head);

    cout<<"Count Of Nodes: "<<List.recursive_countNodes(head)<<endl;
    cout<<"Sum of Elements :"<<List.recursive_SumOfElements(head)<<endl;
    cout<<"Maximum Of All Elements:"<<List.recursive_MaxOfAll(head)<<endl;
    return 0;
}