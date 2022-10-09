// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int value){
        data=value;
        next=NULL;
    }
};





void insertathead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}





void insertafter(node* head, int key, int val){
    node* n=new node(val);
    if(key==head->data){
        n->next=head->next;
        head->next=n;
        return;
    }
    
    node* temp=head;
    while(temp->data!=key){
        temp=temp->next;
        if(temp==NULL){
            return;
        }
    }
    n->next=temp->next;
    temp->next=n;
}





void insertattail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}





void print(node* &head){
    node* temp=head;
    
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}





void deletion(node* &head, int key){
    if(head==NULL){
        return;
    }
    
    if(key==head->data){
        node* todelete=head;
        head=head->next;
        delete todelete;
        return;
    }
    
    node* temp=head;
    
    while(temp->next->data!=key){
        temp=temp->next;
        if(temp->next==NULL){
            return;
        }
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}





bool search(node* head, int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}





 void printmiddle(node* &head){
     node* temp=head;
     node* temp2=head->next;
     
     while(temp2!=NULL  && temp2->next!=NULL){
         temp=temp->next;
         temp2=temp2->next->next;
     }
     cout<<temp->data<<endl;
 }





void deletemiddle(node* &head){
    node* temp=head;
    node* temp2=head->next;
    
    while(temp2->next->next!=NULL  &&  temp2->next->next->next!=NULL){
        temp= temp->next;
        temp2=temp2->next->next;
    }
    
    temp->next=temp->next->next;
}





int main() {
    node* head=NULL;
    
    insertattail(head, 3);
    insertathead(head, 1);
    insertattail(head, 4);
    insertafter(head, 1, 2);
    insertattail(head, 5);
    insertafter(head, 5, 6);
    
    print(head);
    
    printmiddle(head);
    deletemiddle(head);
    print(head);
    // cout<<search(head, 6)<<endl;
    // cout<<search(head, 8)<<endl;
    // deletion(head, 55);
    // print(head);

    return 0;
}