// #include<iostream>// #include<stack>// using namespace std;// int main(){//     stack<int> st;//     st.push(1);//     st.push(2);//     st.push(3);//     cout<<st.top()<<endl;//     st.push(4);//     st.push(5);//     cout<<st.top()<<endl;//     st.pop();//     st.pop();//     cout<<st.top()<<endl;//     cout<<st.empty()<<endl;//     return 0;// }//whenever we transfer data from 1 stack to other it gets reversed//copy one stack to another// #include<iostream>// #include<stack>// using namespace std;// stack<int> copyStack(stack<int> &input){//     stack<int> temp;//     while(not input.empty()){//         //do the process till the time imput stack doesn't become empty//         int curr=input.top();//         input.pop();//         temp.push(curr);//     }//     stack<int> result;//     while(not temp.empty()){//         int curr=temp.top();//         temp.pop();//         result.push(curr);//     }//     return result;// }// void f(stack<int> &st,stack<int> &result){//     if(st.empty()){//         return;//     }//     int curr=st.top;//     st.pop();//     f(st.result);//     result.push(curr);// }// int main(){//     stack<int> st;//     st.push(1);//     st.push(2);//     st.push(3);//     st.push(4);//     //stack<int> res=copyStack(st);//     stack<int> res;//     f(st,res);//     while(not res.empty()){//         int curr=res.top();//         res.pop();//         cout<<curr<<" ";//     }//     return 0;// }//insert element at bottom// #include<iostream>// #include<stack>// using namespace std;// void insertAtBottom(stack<int> &st,int x){//     stack<int> temp;//     while(not st.empty()){//         int curr=st.top();//         st.pop();//         temp.push(curr);//     }//     st.push(x);//     while(not temp.empty()){//         int curr=temp.top();//         temp.pop();//         st.push(curr);//     }// }// void f(stack<int> &st,int x){//     if (st.empty())//     {//         st.push(x);//         return;//     }//     int curr=st.top();//     st.pop();//     f(st,x);//     st.push(curr);    // }// int main(){//     stack<int> st;//     st.push(1);//     st.push(2);//     st.push(3);//     st.push(4);//     return 0;// }// #include<iostream>// #include<stack>// using namespace std;// void insertAt(stack<int> &st,int x,int idx){//     stack<int> temp;//     int n=st.size();//     int count=0;//     while (count<n-idx)//     {//         count++;//         int curr=st.top();//         st.pop();//         temp.push(curr);//     }//     st.push(x);//     while(not temp.empty()){//         int curr=temp.top();//         temp.pop();//         st.push(curr);//     }    // }// int main(){
//     return 0;// }//reverse stack in the same stack-iterative case has time//complexity-O(N) and recursive case has time complexity O(N^2)#include<iostream>#include<stack>void insertAtBottom(stack<int> &st,int x){    stack<int> temp;    while(not st.empty()){        int curr=st.top();        st.pop();        temp.push(curr);    }    st.push(x);    while(not temp.empty()){        int curr=temp.top();        temp.pop();        st.push(curr);    }}void reverse(stack<int> &st){    stack<int> t1,t2;    while(not st.empty()){        int curr=st.top();        st.pop();        t1.push(curr);    }    while(not t1.empty()){        int curr=t1.top();        t1.pop();        t2.push(curr);    }    while(not t2.empty()){        int curr=t2.top();        t2.pop();        st.push(curr);    }}void f(stack<int> &st){    if (st.empty())    {        return;    }    int curr=st.top();    st.pop();    f(st);    insertAtBottom(st,curr);    }using namespace std;int main(){    return 0;}