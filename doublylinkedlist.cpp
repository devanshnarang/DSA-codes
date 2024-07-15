

/*advantages of a doubly linked list over a singly linked list-
traversal can be done both ways,insertion and deletion becomes more efficient
disadvantage-extra space for previous ptr*/
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};
class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertAtStart(int val){
        Node* new_node=new Node(val);
        if (head==NULL)
        {
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        
    }
    void display(){
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
    void inserAtTail(int val){
        Node* new_node=new Node(val);
        if (head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }


    void insertAtPosition(int val,int k){
        //assuming k is less than or equal to length of dll
        Node* temp=head;
        int count=1;
        while (count<(k-1))
        {
            temp=temp->next;
            count++;
        }
        //temp will be pointing to the node at (k-1)th position
        Node* new_node=new Node(val);
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next->prev=new_node;
        return;

    }
    void deleteAtStart(){
        if (head==NULL)
        {
            return;
        }
        Node* temp=head;
        head=head->next;
        if (head==NULL)//if dll has only one node
        {
            tail=NULL;
        }
        else{
            head->prev=NULL;
        }
        free(temp);
        return;
        
    }
    void deleteAtEnd(){
        if (head==NULL)
        {
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        if (tail==NULL)
        {
            head=NULL;
        }
        else{
            tail->next=NULL;
        }
        free(temp);
        return;   
    }
    void deleteAtPosition(int k){
        //assuming k is less than or equal to length of dll
        Node* temp=head;
        int counter=1;
        while (counter<k)
        {
            temp=temp->next;
            counter++;
        }
        //mow temp is pointing to node at kth position
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return;
        
    }
};
void reverseDll(Node* &head,Node* &tail){
    Node* currPtr=head;
    while (currPtr)
    {
        Node* nextPtr=currPtr->next;
        currPtr->next=currPtr->prev;
        currPtr->prev=nextPtr;
        currPtr=nextPtr;
    }
    //swapping head and tail pointer
    Node* newHead=tail;
    tail=head;
    head=newHead;
    
}
bool ispalindrom(Node* head,Node* tail){    
    while (head!=tail && tail!=head->prev)    
    {        
        if (head->val!=tail->val)        
        {            
            return false;        
        }        
        head=head->next;        
        tail=tail->prev;            
        }    
}
void deleteSameNeighbourNode(Node* &head,Node* tail){    
    Node* currNode=tail->prev;
    //second last node    
    while (currPtr!=head)    
    {        
        Node* prevNode=currNode->prev;        
        Node* nextNode=currNode->next;        
        if (prevNode->val==nextNode->val)        
        {            
            //need to delete currNode            
            prevNode->next=nextNode;            
            nextNode->prev=prevNode;            
            free(currNode);        }        
            currNode=prevNode;            
            }
}
bool isCriticalPoint(Node* &currNode){    
    if (currNode->prev->val<currNode-val && currNode->next->val<currNode->val)
    //local maxima    
    {        return true;    
    }    
    if (currNode->prev->val>currNode-val && currNode->next->val>currNode->val)
    //local maxima    
    {        return true;    
    }    
    return false;
}
vector<int> distanceBetweenCriticalPoints(Node* head,Node* tail){    
    vector<int> ans(2,INT_MAX);    
    int firstCP=-1;    
    int lastCP=-1;    
    Node* currNode=tail->prev;    
    if (currNode==NULL)    
    {        
        ans[0]=ans[1]=-1;    
    }    
    int currPos=0;    
    while (currNode->prev!=NULL)    
    {        
        if (isCriticalPoint(currNode))        
        {            
            if (first==-1)            
            {                
                firstCP=lastCP=currPos;            
                }            
            else{                
                ans[0]=min(ans[0],currPos-lastCP);
                //finding min distance                
                ans[1]=currPos-firstCP;                
                lastCP=currPos;            
            }            
            currPos++;            
            currNode=currNode->prev;
                    
        }        
        if (ans[0]==INT_MAX)        
        {            
            ans[0]=ans[1]=-1;            
            return ans;        
            }                    
        }        
}
vector<int> pairSumDLL(Node* head,Node* tail,int x){    
    vector<int> ans(2,-1);    
    while (head!=tail)    
    {        
        int sum=head->val+tail->val;        
        if (sum==x)        
        {            
            ans[0]=head->val;            
            ans[1]=tail->val;        
            }        
            if (sum>x)
            //need smaller values i will move my tail back        
            {            
                tail=tail->prev;        
            }        
            else
            //i need bigger values i  will move my head forward        
            {            
                head=head->next;        
            }            
        }    
        return ans;    
}
int main(){    
    Node* new_node=new Node(3);    
    DoublyLinkedList dll;    
    // dll.head=new_node;    
    // dll.tail=new_node;    
    // cout<<dll.head->val;    
    dll.insertAtStart(1);    
    dll.insertAtStart(2);    
    dll.insertAtStart(3);
    dll.inserAtTail(4);    
dll.inserAtTail(5);    
dll.insertAtPosition(10,2);    
dll.deleteAtStart();    
dll.deleteAtEnd();    
dll.deleteAtPosition(2);    
reverseDll(dll.head,dll.tail);    
dll.display();    
return 0;
}
