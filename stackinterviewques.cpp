// #include<iostream>
// #include<stack>
// #define ll long long int
// using namespace std;
// class MinStack{
//     public:
//     stack<int> st;
//     ll mn;
//     MinStack(){
//         this->mn=INT_MAX;
//     }
//     void push(int val){
//         if (this->st.empty())
//         {
//             this->mn=val;
//             this->st.push(val);
//         }else{
//             this->st.push(val-this->mn);
//             if (this->mn > val)
//             {
//                 this->mn=val;
//             }            
//         }  
//     }
//     void pop(){
//         if (not this->st.empty())
//         {
//             if (this->st.top()>=0)
//             {
//                 this->st.pop();
//             }else{
//                 this->mn=this->mn-this->st.top();
//             }       
//         } 
//     }
//     int top(){
//         if (this->st.size()==1)
//         {
//             return this->st.top();
//         }else if(this->st.top()<0){
//             return this->mn-this->st.top();
//         }        
//     }
//     int getMin(){
//         return this->mn;        
//     }
// };
//number of paranthesis to make balanced paranthesis
#include<iostream>
#include<stack>
// #include<string>
// using namespace std;
// int numberrequired(string st){
//     cout<<"HI";
//     stack<char> temp;
//     int count=0;
//     int n=st.size();
//     for (int i = 0; i < n; i++)
//     {
//         char now=st[i];
//         if (now=='(' or now=='{' or now=='[')
//         {
//             temp.push(now);
//         }else{
//             if (now==')' and !st.empty() and temp.top()=='(')
//             {
//                 temp.pop();
//             }
//             else if (now==')' and !st.empty() and temp.top()=='(')
//             {
//                 temp.pop();
//             }
//             else if (now==')' and !st.empty() and temp.top()=='(')
//             {
//                 temp.pop();
//             }
//             else{
//                 count++;
//             }            
//         }        
//     }
//     return count;    
// }
// int main(){
//     cout<<"HI";
//     string sti=")({[[]]})";
//     cout<<numberrequired(sti)<<endl;
//     return 0;
// }
//Infix expressions- Eg- a+b*(c-d+e)*r
//Postfix expression-reverse Polish notation
//Eg- ABCD+-+//Prefix Expression- Eg- +-ABC
//Evalueation of Postfix Expression
// #include<iostream>
// #include<stack>
// #include<math.h>
// #include<string>
// using namespace std;
int calc(int v1,int v2,char op){
    if (op=='^')
    {
        return pow(v1,v2);
    }else if (op=='+')
    {
        return v1+v2;
    }else if (op=='-')
    {
        return v1-v2;
    }else if (op=='*')
    {
        return v1*v2;
    }else if (op=='/')
    {
        return v1/v2;
    } 
}
int evaluate(string str){
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch=str[i];
        if (isdigit(ch))
        {
            st.push(ch-'0');
subtracting '0' to get original value of the number
        }else{
            int v2=st.top();
            st.pop();
            int v1=st.top();
            st.pop();
            st.push(calc(v1,v2,ch));
        }
    }
    return st.top();
}
int main(){
    string str="231*+9-";
    cout<<evaluate(str);
    return 0;
}
//Evaluation of Prefix Expression
// #include<iostream>
// #include<stack>
// #include<math.h>
// #include<string>
// using namespace std;
// int calc(int v1,int v2,char op){
//     if (op=='^')
//     {
//         return pow(v1,v2);
//     }else if (op=='+')
//     {
//         return v1+v2;
//     }else if (op=='-')
//     {
//         return v1-v2;
//     }else if (op=='*')
//     {
//         return v1*v2;
//     }else if (op=='/')
//     {
//         return v1/v2;
//     } 
// }
// int evaluate(string str){
//     stack<int> st;
//     for (int i = str.size()-1; i >= 0; i--)
//     {
//         char ch=str[i];
//         if (isdigit(ch))
//         {
//             st.push(ch-'0');
//subtracting '0' to get original value of the number
//         }else{
//             int v2=st.top();
//             st.pop();
//             int v1=st.top();
//             st.pop();
//             st.push(calc(v1,v2,ch));
//         }
//     }
//     return st.top();// }
// int main(){
//     string str="-9+*132";
//     cout<<evaluate(str);
//     return 0;
// }
//Infix Evaluation
// #include<iostream>
// #include<stack>
// #include<math.h>
// #include<string>
// using namespace std;
// int calc(int v1,int v2,char op){
//     if (op=='^')
//     {
//         return pow(v1,v2);
//     }else if (op=='+')
//     {
//         return v1+v2;
//     }else if (op=='-')
//     {
//         return v1-v2;
//     }else if (op=='*')
//     {
//         return v1*v2;
//     }else if (op=='/')
//     
//         return v1/v2;
//     } 
// }
// int precedence(char ch){
//     if (ch=='^')
//     {
//         return 3;
//     }
//     else if (ch=='*' or ch=='/'){
//         return 2;
//     }
//     else if (ch=='+' or '-')
//     {
//         return 1;
//     }else{
//         return -1;
//     }
// }
// int eval(string str){
//     stack<int> nums;
//     stack<char> ops;
//     for (int i = 0; i < str.size(); i++)
//     {
//         if (isdigit(str[i]))
//         {
//             nums.push(str[i]-'0');
//         }
//         else if (str[i]=='(')
//         {
//             ops.push(str[i])
//         }else if (str[i]==')')
//         {
//             while(not ops.empty() and ops.top()!='('){
//                 char op=ops.top();
//                 ops.pop();
//                 int v2=nums.top();
//                 nums.pop();
//                 int v1=nums.top();
//                 nums.pop();
//                 nums.push(calc(v1,v2,op));
//             }
//         }else{
//             while (not ops.empty() and precedence(ops.top())>=precedence(str[i]))
//             {
//                 char op=ops.top();
//                 ops.pop();
//                 int v2=nums.top();
//                 nums.pop();
//                 int v1=nums.top();
//                 nums.pop();
//                 nums.push(calc(v1,v2,op));   
//             }
//             ops.push(str[i]);
//             while(not ops.empty()){
//                 char op=ops.top();
//                 ops.pop();
//                 int v2=nums.top();
//                 nums.pop();
//                 int v1=nums.top();
//                 nums.pop();
//                 nums.push(calc(v1,v2,op));
//             }            
//         }
//         return nums.top();      
//     }  
// }
// int main(){
//     string str="-9+*132";
//     cout<<evaluate(str);
//     return 0;
// }
//Prefix To Postfix
#include<iostream>
#include<stack>
using namespace std;
string eval(string &pre){    
    stack<string> st;    
    reverse(pre.begin(),pre.end());    
    for (int i = 0; i < pre.size(); i++)    
    {        
        if (isDigit(pre[i]))        
        {            
            st.push(to_string(pre[i]-'0'));        
        }else{            
            string v1=st.top();            
            st.pop();            
            string v2=st.top();            
            st.pop();            
            string newexp=v1+v2+pre[i];            
            st.push(newexp);
        }        
        return st.top();     
    }    
}
int main(){    
    return 0;
}

