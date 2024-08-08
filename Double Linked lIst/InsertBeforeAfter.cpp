#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->next=NULL;
        this->prev=NULL;
        this->data=data;
    }
};
class doubleLL{
    public:
    Node* head;
    Node* tail;
    doubleLL(){
        this->head=NULL;
        this->tail=NULL;
    }
    void print(){
        if(head==NULL){
            cout<<"Your LL is empty "<<endl;
            return;
        }
        Node* curr=head;
        while (curr!=NULL){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl<<"\n\nhead.data: " <<head->data<<"\ttail.data: "<<tail->data<<endl;
        cout<<"head.next"<<head->next->data<<"\ttail.prev"<<tail->prev->data<<endl;
    }
    void insertAthead(int data){
        Node* nodeToinsert=new Node(data);
        if(head==NULL){
            head=nodeToinsert;
            tail=nodeToinsert;
            return;
        }
        nodeToinsert->next=head;
        head->prev=nodeToinsert;
        head=nodeToinsert;
        if(tail==NULL){
            tail=nodeToinsert;
            return;
        }
    }
    void insertAttail(int data){
        if(head==NULL){
            cout<<"your linked list is empty"<<endl;
            return;
        }
        Node* nodetoinsert=new Node(data);
        tail->next=nodetoinsert;
        nodetoinsert->prev=tail;
        tail=nodetoinsert;
        
    }
    void insertAfter(int data, int key){
        if(head==NULL){
            cout<<"Your linked list is empty"<<endl;
            return;
        }

        if(tail->data==key){
            insertAttail(data);
            return;
        }

        Node* curr=head;
        while (curr->next!=NULL){
            if(curr->data==key){
                Node* newNode=new Node(data);
                newNode->next=curr->next;
                curr->next->prev=newNode;
                newNode->prev=curr;
                curr->next=newNode;
                return;
                break;
            }
            curr=curr->next;
        }

        if(curr==NULL){
            cout<<"key Not found"<<endl;
            return;
        }

    }
    
    void insertBefore(int data,int key){
        Node* newnode=new Node(data);
        if(head->data==key){
            insertAthead(64);
            return;
        }
        Node* curr=head;
        while(curr!=NULL){
            if(curr->data==key){
                curr->prev->next=newnode;
                newnode->prev=curr->prev;
                newnode->next=curr;
                curr->prev=newnode;
                return;
            }
            curr=curr->next;
        }
        if(curr==NULL){
            cout<<"key Not found"<<endl;
        }
    }

};

int main()
{
    doubleLL mylst;
    mylst.print();
    
    mylst.insertAthead(74);
    mylst.insertAthead(64);
    
    mylst.insertAttail(67);
    mylst.insertAttail(42);
    
    mylst.print();
    cout<<"\n\nUsing insertAfter function: mylst.insertAfter(2,42)"<<endl;
    mylst.insertAfter(2,42);
    cout<<"\ninsertbefore(31,167)"<<endl;
    mylst.insertBefore(31,167);

    cout<<"\ninsertafter(211,3)"<<endl;
    mylst.insertAfter(211,3); // User must be informed key(3) isn't present in the double LL.
    mylst.print();

    return 0;
}
