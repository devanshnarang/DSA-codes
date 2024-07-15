#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};
    void insertAtStart(Node* &head,int x){
        Node* ne=new Node(x);
        if(head==NULL){
            head=ne;
            return ;
        }
        ne->next=head;
        head=ne;
    }
    void insertAtEnd(Node* &head,int x){
        Node* ne=new Node(x);
        if(head==NULL){
            head=ne;
            return ;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ne;
        return;
    }
    void insertAtK(Node* &head,int x,int k){
        if(k==0){
            insertAtStart(head,x);
            return;
        }
        Node* ne=new Node(x);
        k-=1;
        Node* temp=head;
        while(k--){
            temp=temp->next;
        }
        ne->next=temp->next;
        temp->next=ne;
        return;
    }
    void deleteAtStart(Node* &head){
        head=head->next;
        return;
    }
    void deleteAtEnd(Node* head){
        if(head==NULL || head->next==NULL){
            head=NULL;
            return;
        }
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        return;
    }
    void deleteAtK(Node* &head,int k){
        if(k==0){
            head=head->next;
            return;
        }
        k-=1;
        Node* temp=head;
        while(k--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return;
    }
    void deleteAlternate(Node* head){
        if(head==NULL || head->next==NULL){
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return;
    }
    void deleteDuplicates(Node* head){
        if(head==NULL || head->next==NULL){
            return;
        }
        Node* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->val==temp->next->val){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return;
    }
    void reversePrint(Node* head){
        if(head==NULL)return;
        reversePrint(head->next);
        cout<<head->val<<"->";
    }
    void Reverse(Node* &head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    Node* ReverseKNodes(Node* head,int k){
        if(head==NULL || head->next==NULL){
            return head;
        }
        //recursive case
        Node* prev=NULL;
        Node* curr=head;
        //k-=1;
        int count=k;
        while(curr!=NULL && k--){
            Node* temp=curr->next;
            curr->next=prev; 
            prev=curr;
            curr=temp;
        }
        head->next=ReverseKNodes(curr,count);
        return prev;
    }
    void print(Node* &head){
        Node* temp=head;
        if(head==NULL){
            cout<<"NULL"<<endl;
        }
        while(temp!=NULL){
            cout<<temp->val<<"->"<<"";
            temp=temp->next;
        }
        cout<<"NULL";
        return;
    }

int main()
{
    Node* head=NULL;
    insertAtStart(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    // print(head);
    // cout<<endl;
    insertAtK(head,4,3);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    print(head);
    cout<<endl;
    // deleteAtStart(head);
    // print(head);
    // cout<<endl;
    // deleteAtEnd(head);
    // deleteDuplicates(head);
    // print(head);
    //reversePrint(head);
    // Reverse(head);
    // print(head);
    Node* new_header=ReverseKNodes(head,4);
    print(new_header);
    return 0;
}
