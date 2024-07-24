#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data):data(data),next(NULL),prev(NULL){}
};

class doubleLinkedList{
    public:
    int size;
    Node* head;Node * tail;
    doubleLinkedList(){
        head=NULL;tail=NULL;
    }
    void LLsize(){
        Node*temp=head;
        size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        cout<<"Size of linked list:\t"<<size<<endl;
        if(size==0){
            cout<<"Your LL is empty"<<endl;
        }
    }
    void insertatBegin(int data){
        Node *newnode=new Node(data);
        newnode->next=head;
        if(head!=NULL){
            head->prev=newnode;            
        }
        head=newnode;
        if(tail==NULL){
            tail=newnode;
        }
    }
    void insertAtend(int data){
        Node*newnode=new Node(data);
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        if(tail==NULL){
            head=newnode;
            tail=newnode;
        }
    }
    void print(){
        if(head==NULL){
            cout<<"Your LinkedList is empty"<<endl;
            return;
        }
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        cout<<"head: "<<head->data<<"\ttail: "<<tail->data<<endl;
    }
    void insertatPosition(int data, int position){
        if(position<=0){
            cout<<"Invalid Position "<<endl;
            return;
        }
        Node *newNode=new Node(data);
        Node* temp=head;
        if(position==1){
            insertatBegin(data);
            return;
        }
        int count=1;
        while(count<position-1){
            temp=temp->next;
            count++;
            if(temp==NULL){cout<<"position out of bounds"<<endl;return;}
        }
        if(temp->next==NULL){
            insertAtend(data);
            return;
        }

        newNode->next=temp->next;
        newNode->prev=temp;        
        temp->next=newNode;
        temp->next->prev=newNode;
    }
};

int main()
{
    doubleLinkedList myll;
    while(true){
        int ch;cout<<"Enter your choice:\t ";cin>>ch;
        if(ch==1){myll.print();}
        else if(ch==2){
            int data;cout<<"Enter your data to insert at head :\t";cin>>data;
            myll.insertatBegin(data);
        }
        else if(ch==3){
            int data;cout<<"Enter your data to insert at tail:\t";cin>>data;
            myll.insertAtend(data);
        }
        else if (ch==4){myll.LLsize();}
        else if(ch==5){
            int data;int position;cout<<"Enter the value of element to insert: ";cin>>data;cout<<"Enter the position: ";cin>>position;
            myll.insertatPosition(data,position);
        }
        else{
            break;
        }
    }
    return 0;
}
