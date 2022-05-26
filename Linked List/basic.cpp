#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class Solution{
    public:

    struct Node* create(int val){
        struct Node *head=new Node;
        head->data=val;
        head->next=NULL;
        return head;
    }

    void recursive_insert(Node *head,int val){
        if(head->next==NULL){
            //Creating a new node and inserting value into it.
            struct Node *temp=new Node;
            temp->data=val;
            temp->next=NULL;

            //Connecting it at the end of the LinkedList.
            head->next=temp;
            return;
        }

        recursive_insert(head->next,val);
    }

    void insert(Node *head,int val){
        struct Node *new_node;
        new_node= new Node;
        new_node->data=val;
        new_node->next=NULL;
        while(head->next!=NULL){
            head=head->next;
        }
        head->next=new_node;
        return;
    }

    void recursive_display(Node *head){
        if(head==NULL){
            cout<<endl;
            return;
        }

        cout<<head->data<<"-> ";
        recursive_display(head->next);
        return;
    }

    void display(Node *head){
        while(head!=NULL){
            cout<<head->data<<"-> ";
            head=head->next;
        }
        cout<<endl;
        return;
    }
};

int main(){
    int size,val;
    struct Node *head;
    Solution sol;

    cout<<"Enter size of LinkedList?"<<endl;
    cin>>size;
    cout<<"Enter value of Element?\n";
    
    //For inserting 1st value of element.
    cin>>val;
    head=sol.create(val);
    sol.display(head);
    
    //For subsequent insertions.
    for(int i=1;i<size;i++){
        cin>>val;
        sol.recursive_insert(head,val);
        sol.recursive_display(head);
    }

    return 0;
}