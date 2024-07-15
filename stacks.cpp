/*stacks-LIFO data structure,insert at top,remove from topfunctions -isempty,isFull,size,top(to find topmost element in a stack)*/
/*implementations-stack using arrays,stacks using linked lists*/
/*overflow-if we exceed the capacity of stackunderflow-if we try to remove an element from an empty stack*/
//implementation of stacks using arrays
/*if top_idx=-1 then we are either in underflow condition or the stack is empty*/
#include<iostream>
using namespace std;
class Stack{    
    int capacity;   
    int* arr;    
    int top;    
    public:
    Stack(int c){        
        this->capacity=c;        
        arr=new int[c];        
        this->top=-1;    }    
        void push(int data){        
            if(this->top==this->capacity-1){            
                cout<<"Overflow"<<endl;            
                return         }        
                this->top++;        
                this->arr[this->top]=data;    
                }    
                int pop(){        
                if(this->top==-1){            
                    cout<<"underflow";            
                    return INT_MIN;        
                }        
                this->top--;    
                }    
                int gettop(){        
                if (this->top==-1)        
                {            
                    cout<<"Underflow";            
                    return INT_MIN;        
                }        
                return this->arr[this->top];    
            }    
            bool isEmpty(){        
                return this->top==-1;    
            }    
            int size(){        
                return this->top + 1;    
            }    
            bool isFull(){        
                return this->top==this->capacity-1;    
            }};
            int main(){    
                Stack st(5);    
                st.push(1);    
                st.push(2);    
                st.push(3);    
                cout<<st.top()<<endl;    
                st.push(4);    
                st.push(5);    
                cout<<st.top()<<endl;    
                st.push(6);
    return 0;
}
//implementation using Linked Lists