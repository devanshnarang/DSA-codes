//Queues-FIFO(First in first out) or FCFS(First come first serve)
/*Queue is a data structure that supports FIFO or FCFSQueue is a linear data structure*/
/*Types of Operations on Queues-Enque-this operation will help us to add a new element in the queueDeque-this operation will help us to remove a new element in the queueisFull,isEmptyfront-gives us the element which came first*/
/*Types of queuesSimple-one end is back(rear),one end is frontthe element which came first will be accessed firstPriority queue it is not the case the element which came first will be processed first  it is processed on the basis of priorityCircular queue-front and rear eist adjacent after rear comes the firstDouble ended queue -additioon is possible even from the front and removal is possible even from the back*/
//Linked list implementation of Queues
// #include<iostream>// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* next;
//     Node(int data){
//         this->val=data;
//         this->next=NULL;
//     }  
// };
// class Queue{
//     Node* head;
//     Node* tail;
//     int size=0;
//     public:
//     Queue(){
//         this->head=NULL;
//         this->tail=NULL;
//     }
//     void enqueue(int data){
//         Node* newNode=new Node(data);
//         if (this->head==NULL)
//         {
//         this->head=newNode;
//         this->tail=newNode;
//         }else{
//             this->tail->next=newNode;
//             this->tail=newNode;
//         }   
//         this->size++;
//     }
//     void dequeue(){
//         if (this->head==NULL)
//         {
//             return;
//         }else{
//             Node* oldHead=this->head;
//             Node* newHead=this->head->next;
//             this->head=newHead;
//             if (this->head==NULL)
//             {
//                 this->tail=NULL;
//             }
//             oldHead->next=NULL;
//             delete oldHead;
//             this->size--;
//         }  
//     }
//     int getSize(){
//         return this->size;
//     }
//     bool isEmpty(){
//         return this->head==NULL;
//     }
//     int front(){
//         if (this->head==NULL)
//         {
//             return -1;
//         }return this->head->data;        

//     }
// };
// int main(){
//     Queue qu;
//     qu.enqueue(10);
//     qu.enqueue(20);
//     qu.enqueue(30);
//     qu.enqueue(40);
//     while (not qu.isEmpty())
//     {
//         cout<<qu.front()<<" ";
//         qu.dequeue();
//     }    
//     return 0;
// }
//Implementation using arrays
// using namespace std;
// class Queue{    
//     int front;    
//     int back;    
//     vector<int> v;
//     public:    
//     Queue(){        
//         this->front=-1;        
//         this->back=-1;    
//     }    
//         void enqueue(int data){        
//             v.push_back(data);        
//             this->back++;        
//             if (this->back==0)        
//             {            
//                 this->front++;        
//             }            
//         }    
//         void dequeue(){        
//             if (this->front==this->back)        
//             {            
//                 this->front=-1;            
//                 this->back=-1;            
//                 this->v.clear();        
//             }else{            
//                 this->front++;        
//             }     
//         }    
//         int front(){        
//             if (this->front==-1)        
//             {            
//                 return -1;        
//             }        
//             return v[this->front];    
//         }    
//         bool isEmpty(){        
//             return this->front==-1;    
//         }
// };
int main(){    
    return 0;}
/*linked list based implementation is space efficient,pointer,deletion is to be managedwhile array manages the same itself*/
//reverse elements of a queue
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){    
    queue<int> input;    
    input.push(10);    
    input.push(20);    
    input.push(30);    
    input.push(40);    
    stack<int> st;    
    while (not input.empty())    
    {        
        st.push(input.front());        
        input.pop();    
    }    
    while (not st.empty())    
    {        
        input.push(st.top());        
        st.pop();    
    }        
    return 0;
}
