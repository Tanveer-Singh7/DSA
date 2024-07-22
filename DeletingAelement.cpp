#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class LinkedList{
    public:
    Node* head;
    Node* tail;
    int size=0;
    LinkedList(){
        head=NULL;tail=NULL;
    }
    void  print(){
        if(head==NULL){
            cout<<"Your linked list is empty "<<endl;
        }
        else{
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
            cout<<"head: "<<head->data<<"\ttail: "<<tail->data<<endl;
        }
    }
    void insertAthead(int data){
        Node* NewNode=new Node(data);
        NewNode->next=head;
        head=NewNode;
        if(tail==NULL){
            tail=NewNode;
        }
        size++;
    }
    void insertAtend(int data){
        Node*newnode=new Node(data);
        if(head==NULL){
            cout<<"Your Linklist is empty "<<endl;
            head=newnode;tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        size++;
    }
    void insertatposition(int data, int position){
        if(position<=0){
            cout<<"Invalid Input "<<endl;
        }
        if(position==1){
            insertAthead(data);
            size++;
            return;
        }
        Node * nodetoinsert=new Node(data);
        Node*temp=head;
        int count=1;
        while(count<position-1){
            temp=temp->next;
            count++;
            if(temp==NULL){
                cout<<"Position out of bounds\n Size of the Linked List is: "<<size<<endl;
                return;
            }
        }
        if(temp->next==NULL){
            insertAtend(data);
            size++;
            return;
        }
        nodetoinsert->next=temp->next;
        temp->next=nodetoinsert;
        size++;
    }
    void Deletion_Node(int position){
        if(position==1){
            if(head==NULL){
                cout<<"The linkedList is already empty "<<endl;
            }
            Node*temp=head;
            head=temp->next;
            delete temp;
            size--;
            if(head==NULL){
                tail==NULL;
            }
        }
        else{
            int count=1;
            Node* prev=NULL;
            Node*temp=head;
            while(count<position){
                prev=temp;
                temp=temp->next;
                if(temp==NULL){
                    cout<<"Position out of bounds \n Size of the Linked List is: "<<size<<endl;
                    return;
                }
                count++;
            }
            // if(temp->next==NULL){
            //     tail=prev;
            //     delete temp;
            //     return;
            // }
            prev->next=temp->next;
            size--;
            if(temp->next==NULL){
                tail=prev;
            }
            delete temp;
        }
    }
    
};

int main()
{
    LinkedList list;
    while(true){
        cout<<"________________\t\tMenu"<<endl;
        cout<<" 0. Exit "<<endl;
        cout<<" 1. Print linked List "<<endl;
        cout<<" 2. Insert At Beign "<<endl;
        cout<<" 3. Insert At End "<<endl;
        cout<<" 4. Insert At Position "<<endl;
        cout<<" 5. Delete A Position "<<endl;
        cout<<" 6. Size of the Linked List "<<endl;
        cout<<"Enter your choice: \t";
        int choice;cin>>choice;
        cout<<"______________________\n"<<endl;
        if(choice==0){break;}
        else if(choice==1){
            list.print();
        }
        else if(choice==2){
            cout<<"Enter an element to insert at beginning of the list:\t";
            int element;cin>>element;
            list.insertAthead(element);
        }
        else if(choice==3){
            cout<<"Enter an element to insert at End of the list:\t";
            int element;cin>>element;
            list.insertAtend(element);
        }
        else if(choice==4){
            cout<<"enter the position to insert your element :\t";int position;cin>>position;
            cout<<"Enter an element to insert at "<< position<<" position of the list:\t";
            int element;cin>>element;
            list.insertatposition(element,position);
        }
        else if(choice==5){
            cout<<"enter the position to delete the node :\t";int position;cin>>position;
            list.Deletion_Node(position);
        }
        else if(choice==6){
            cout<<"Size of the Linked list: "<<list.size<<endl;
        }
        else{
            cout<<"Invalid Input"<<endl;
        }
    }
    return 0;    
}
