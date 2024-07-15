#include<iostream>
using namespace std;class Node{    
    public:    
    int val;    
    Node* next;    
    Node(int data){        
        this->val=data;        
        this->next=NULL;    
        }};
    class Stack{    
        Node* head;    
        int capacity;    
        int currSize;    
        Stack(int c){        
            this->capacity=c;        
            this->currSize=0;        
            head=NULL;    
        }    
        bool isEmpty(){        
            return this->head==NULL;    
        }    
        bool isFull(){        
            return this->currSize==this->capacity;    
        }    
        void push(int data){        
            if (this->capacity==this->currSize)        
            {            
                cout<<"Overflow";            
                return;        
            }        
            Node* new_node=new Node(data);        
            new_node->next=this->head;        
            this->head=new_node;        
            this->currSize++;    
        }    
        int pop(){        
            if (this->currSize==NULL)        
            {            
                cout<<"Underflow";            
                return;        
            }        
            Node* new_head=this->head->next;        
            this->head->next=NULL;        
            Node* tobeRemoved=this->head;        
            int result=tobeRemoved->val;        
            delete tobeRemoved;        
            this->head=new_head;        
            return result;    
        }     
        int getTop(){        
            if (this->head==NULL)        
            {            
                cout<<"Underflow";            
                return;        
            }        
            return this->head->val;            
        }     
        int size(){        
            return this->currSize;    
            } 
};