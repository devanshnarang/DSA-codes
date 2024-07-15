//ques1 check if 2 ll are equal or not 
#include<iostream>
#include<vector>
using namespace std;cla
//ques1 check if 2 ll are equal or not
#include<iostream>
#include<vector>
using namespace std;
class Node{public:    
int val;    Node* next;    
Node(int data){        
    val=data;        
    next=NULL;    
    }
};
class linkedlist{
    public:    
    Node* head;    
    linkedlist(){        
        head=NULL;    }    
        void insertAtTail(int val){        
            Node* new_node=new Node(val);        
            if (head==NULL)        
            {            
                head=new_node;        
            }        
            Node* temp=head;        
            while (temp->next!=NULL)        
            {            
                temp=temp->next;        
            }        
            temp->next=new_node;         
            cout<<"HI!"      
            }    
            void display(){        Node* temp=head;        while(temp!=NULL){            cout<<temp->val<<" ";            temp=temp->next;        }    }   };bool checkEqualLinkedList(Node* head1,Node* head2){    Node* ptr1=head1;    Node* ptr2=head2;    while (ptr1!=NULL && ptr2!=NULL)    {        if (ptr1->val!=ptr2->val)        {            return false;        }        ptr1=ptr1->next;        ptr2=ptr2->next;    }    return(ptr1==NULL && ptr2==NULL);    }int getLength(Node* head){    Node* temp=head;    int length=0;    while (temp!=NULL)    {        length++;        temp=temp->next;    }    return length;    }Node* moveHeadByK(Node* head,int k){    Node* ptr=head;    while (k--)    {        ptr=ptr->next;    }    return ptr;}Node* getIntersection(Node* head1,Node*head2){    Node* ptr1=head1;    Node* ptr2=head2;    //calculate length of both linked lists    int l1=getLength(head1);    int l2=getLength(head2);    //find difference and move longer linkedlist ptr by k steps    if (l1>l2)    {        int k=l1-l2;        ptr1 = moveHeadByK(head1,k);        ptr2 = head2;    }    else{        int k=l2-l1;        ptr1=head1;        ptr2 = moveHeadByK(head2,k);    }    //compare ptr1 and ptr2 nodes    while (ptr1!=NULL)    {        if (ptr1==ptr2)        {            return ptr;        }        ptr1=ptr1->next;        ptr2=ptr2->next;    }    return NULL;    }//assuming k is always less than/equal length of linked listvoid removeKthNodeFromEnd(Node* &head,int k){    Node* ptr1=head;    Node* ptr2=head;    //move ptr2 by k steps    int count=k;    while (k--)    {        ptr2=ptr2->next;    }    if (ptr2==NULL)//k is equal to length of linked list    {        Node* temp=head;        head=head->next;        free(temp);        return;
    }        
//now ptr2 is k steps ahead of ptr1    
//when ptr2 is at null(end of list),ptr1 will be at node to be deleted    
while (ptr2->next!=NULL)    
{        
    ptr1=ptr1->next;        
    ptr2=ptr2->next;    
    }    
//now ptr1 is pointing to the node before kth node from end    
//node to be deleted is ptr1->next    
Node* temp=ptr1->next;    
ptr1->next=ptr1->next->next;    
free(temp);    
}
Node* mergeLinkedLists(Node* &head1,Node* &head2){    
    Node* dummyHeadNode=new Node(-1);    
    Node* ptr1=head1;    
    Node* ptr2=head2;    
    Node* ptr3=dummyHeadNode;    
    while (ptr1 && ptr2)    
    {        
        if (ptr1->val<ptr2->val)        
        {            
            ptr3->next=ptr1;            
            ptr1=ptr1->next;        
        }        
        else{            
            ptr3->next=ptr2;            
            ptr2=ptr2->next;        
        }        
        ptr3=ptr3->next;    
        }    
        while (ptr1)    
        {        
            ptr3->next=ptr1;        
            ptr1=ptr1->next;        
            ptr3=ptr3->next;    
        }    
        while (ptr2)    
        {        
            ptr3->next=ptr2;        
            ptr2=ptr2->next;        
            ptr3=ptr3->next;    
        }    
        return dummyHeadNode->next;}
        void removeCycle(Node* &head){
            //assuming the list has a cycle    
            Node* slow=head;    
            Node* fast=head;    
            do    
            {       
                slow=slow->next;       
                fast=fast->next->next;     
            } 
            while (slow!=fast);    
            fast=head;    
            while (slow->next!=fast->next)    
            {        
                slow=slow->next;        
                fast=fast->next;    
            }    
            slow->next=NULL;    
        }
Node* mergeKLinkedList(vector<Node*> &lists){    
    while (lists.size()>1)    
    {        
        Node* mergedHead=mergeKLinkedList(lists[0],lists[1]);        
        lists.push_back(mergedHead);        
        lists.erase(lists.begin());        
        lists.erase(lists.begin());    
    }    
    return lists[0];}
// vector-> head1 head2 head3 head4
//1. head1 and head2 ll will be merged
// vector-> head3 head4 mergedhead1_2
//2. head3 and head4 will be merged
// vector-> mergedhead1_2 mergedhead3_4
//3. mergedhead1_2 and mergedhead3_4 will be merged
//vector-> mergedhead1_2_3_4



