#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;  
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class DoubleLinkedList{
    public:
    // int size=0; when you define here you're compiler will give you error in order to deal this you can define it in your constructor
    int size;
    Node*head;
    Node*tail;
    DoubleLinkedList():size(0){
        head=NULL;tail=NULL;
    }
    void Linkedlistsize(){
        size=0;
        Node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        cout<<"Size of the Linked List is : "<<size<<endl;
    }
    void print(){
        if(head==NULL){
            cout<<"Your Linked List is empty"<<endl;
        }
        else{
            Node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<"\nHead: "<<head->data<<"\tTail : "<<tail->data<<endl;
            cout<<endl;
        }
    }
    void insertAtHead(int data){
        Node*newNode=new Node(data);
        newNode->next=head;
        if(head!=NULL){
            head->prev=newNode;
        }
        head=newNode;
        if(tail==NULL){
            tail=newNode;
        }
    }
    void insertAttail(int data){
        Node* NewNode=new Node(data);
        tail->next=NewNode;
        NewNode->prev=tail;
        tail=NewNode;
        if(tail==NULL){
            head=NewNode;
            tail=NewNode;
        }
    }
};

int main()
{
    DoubleLinkedList lst;
    lst.insertAtHead(45);
    lst.insertAtHead(35);
    lst.insertAtHead(21);
    lst.insertAtHead(42);
    
    lst.Linkedlistsize();
    lst.print();

    cout<<"Inserting at end "<<endl;
    lst.insertAttail(101);
    lst.Linkedlistsize();
    lst.print();

    return 0;
}
