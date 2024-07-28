#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    
};
class DoubleLinkedList{
    public:
    Node* head;
    Node* tail;
    DoubleLinkedList(){
        this->head=NULL;
        this->tail=NULL;
    }
    void print(){
        if(head==NULL){
            cout<<"Your Linked list is empty"<<endl;
            return;
        }
        
        Node *curr=head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl<<"head : "<<head->data<<"\ttail : "<<tail->data<<endl;
        cout<<"head.next : "<<head->next->data<<"\ttail.prev : "<<tail->prev->data<<endl;
    
    }
    void insertAthead(int data){
        if(head==NULL){
            Node* curr=new Node(data);
            head=curr;
            tail=curr;
        }
        else{
            Node* curr=new Node(data);
            curr->next=head;
            head->prev=curr;
            head=curr;
        }
    }
    void insertAttail(int data){
        Node*curr=new Node(data);
        if(head==NULL){
            head=curr;tail=curr;
            return;
        }
        tail->next=curr;
        curr->prev=tail;
        tail=curr;
    }
    void insertAtposition(int data,int position){
        if(position<=0){
            cout<<"Invalid Position"<<endl;
        }
        if(position==1){
            insertAthead(data);
            return;
        }
        int count=1;
        Node*nodetoInsert=new Node(data);
        Node*curr=head;
        while(count<position-1){
            curr=curr->next;
            count++;
        }
        if(curr->next==NULL){
            insertAttail(data);
        }
        nodetoInsert->next=curr->next;
        curr->next->prev=nodetoInsert;
        curr->next=nodetoInsert;
        nodetoInsert->prev=curr;
    }
    void DeleteHead(){
        Node*curr=head;
        head=curr->next;
        delete curr;
    }
    void DeleteNode(int position){
        if(position<=0){
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(position==1){
            DeleteHead();
            return;
        }
        Node*curr=head;
        int count=1;
        while(count<position){
            curr=curr->next;
            if(curr->next==NULL&& count<position){cout<<"position out of bounds"<<endl;}
            count++;
        }
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
};

int main()
{
    DoubleLinkedList mylst;
    mylst.insertAttail(82);
    mylst.insertAthead(94);
    mylst.print();
    mylst.insertAtposition(13,2);
    mylst.print();
    mylst.insertAthead(32);
    mylst.print();

    mylst.DeleteNode(6);
    mylst.print();
    return 0;
}
