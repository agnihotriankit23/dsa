#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head , int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtEnd(Node* head,int d){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode= new Node(d);
    temp->next=newNode;
}

void insertAtPos(Node* &head,int pos,int d){
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    Node* newNode=new Node(d);
    newNode->next=temp->next;
    temp->next=newNode;
}

bool isListCircular(Node* &tail){
    if(tail==NULL){
        return true;
    }
    else{
        Node* temp=tail;
        do{
            temp=temp->next;
            if(temp==NULL){
                return false;
            }
        }while(tail!=temp);
        return true;



    }
}

bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node*,bool> visited;
    Node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
void deleteNodeAtPos(Node* &head, int pos){
    Node* temp=head;
    Node* prev;
    if(pos==1){
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;     
    }
    for(int i=1;i<pos;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;

    
}
void display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
Node* node1=new Node(10);
//cout<<node1->data<<" "<<node1->next;
Node* Head=node1;

insertAtHead(Head,20);
insertAtHead(Head,30);
insertAtHead(Head,40);
insertAtHead(Head,50);
insertAtEnd(Head, 60);
insertAtPos(Head,3,70);
insertAtPos(Head,1,90);
insertAtPos(Head,9,80);
display(Head);

// deleteNodeAtPos(Head,9);
// display(Head);

//Head->next=Head;

cout<<isListCircular(Head)<<endl;
cout<<detectLoop(Head);
    return 0;
}