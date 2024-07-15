// //balanced breacket sequence-   ((()))-balanced  (()-not balanced  )(-not balanced// //   ()-paranthesis  {}-curly braces   []-square brackets// //if we concatenate 2 balanced strings then overall string will also be balanced// //if wrap a balanced string with a pair of brackets then result is also balanced // #include<iostream>// #include<stack>// using namespace std;// bool isValid(string str){//     stack<char> st;//     for (int i = 0; i < str.size(); i++)//     {//         char ch=str[i];//current char//         if (ch=='[' or ch=='{' or ch=='(')//         {//             st.push(ch);//         }else{//             //closing bracket//             if (ch==')' and !st.empty() and st.top()=='('){//                 st.pop();//             } //             else if (ch==']' and !st.empty() and st.top()=='['){//                 st.pop();//             } //             else if (ch=='}' and !st.empty() and st.top()=='{'){//                 st.pop();//             } //             else{//                 return false;//             }//         }//     }//     return st.empty();// }// int main(){ //     string str="((((([{{}}])))))";//     cout<<isValid(str);//     return 0;// }
//Next Greater Element(N<10^5)//Eg [4,3,9,1,6,8,2]  output array- [9,9,-1,6,8,-1,-1]//whenever we require waiting strategy ,we use stacks as a data structures// #include<iostream>// #include<stack>// #include<vector>
// vector<int> nge(vector<int> &arr){
//     int n=arr.size();
//     vector<int> output(n,-1);
//     stack<int> st;
//indexes
//     st.push(0);
//     for (int i = 0; i < n; i++)
//     {
//         while(!st.empty()&& arr[i]>arr[st.top()])
//         {
//             output[st.top()]=arr[i];
//             st.pop();
//         }
//         st.push(); 
//     }
//     //for safety check
//     while(not st.top()){
//         output[st.top()]=-1;
//         st.pop();
//     }
//     return output;  
// }
// //next smaller element
// vector<int> nse(vector<int> &arr){
//     int n=arr.size();
//     vector<int> output(n,-1);
//     stack<int> st;
//indexes
//     st.push(0);
//     for (int i = 0; i < n; i++)
//     {
//         while(!st.empty()&& arr[i]<arr[st.top()])
//         {
//             output[st.top()]=arr[i];
//             st.pop();
//         }
//         st.push(); 
//     }
//     //for safety check
//     while(not st.top()){
//         output[st.top()]=-1;
//         st.pop();
//     }
//     return output;  
// }
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v;
//     while(n--){
//         int x;
//         cin>>x;
//         v.push_back(x);
//     }
//     vector<int> result=nge(v);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout<<result[i]<<" ";
//     }
//     return 0;
// }
//to find previous greater element-reverse input array;
//find next greater for reversed array,and finally reverse the output array
//and vice versa for previous smaller element

//stock span problem//eg-[100,80,60,70,60,75,85]//output array-[1,1,1,2,1,4,6]
// #include<iostream>
// #include<stack>
// vector<int> pge(vector<int> &arr){
    //     int n=arr.size();
    //    
    //to just reverse the array not sort in reverse order
    //     reverse(arr.begin(),arr.end());
    //     vector<int> output(n,-1);
    //     stack<int> st;
    //indexes
    //     st.push(0);
    //     for (int i = 0; i < n; i++)
    //     {
    //         while(!st.empty()&& arr[i]>arr[st.top()])
    //         {
    //             output[st.top()]=i;
    //             st.pop();
    //         }
    //         st.push(); 
    //     }
    //     
    //for safety check
    //     while(not st.top()){
    //         output[st.top()]=n-i-1;
    //         st.pop();
    //     }
    //     reverse(output.begin(),output.end());
    //     reverse(arr.begin(),arr.end());
    //     return output;  // }
    // using namespace std;
    // int main(){
    //     int n;
    //     cin>>n;
    //     vector<int> v;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int x;
    //         cin>>x;
    //         v.push_back(x);
    //     }
    //     vector<int> res=pge(v);
    //     for (int i = 0; i < res.size(); i++)
    //     {
    //         cout<<(i-res[i])<<"  ";
    //     }    
    //     return 0;
    // }
    //Histogram Problem
    #include<iostream>
    #include<stack>
    int histogram(vector<int> &arr){    
        int n=arr.size();    
        //vector<int> output(n,-1);    
        stack<int> st;
        //indexes    
        int ans=INT_MIN;    
        st.push(0);    
        for (int i = 0; i < n; i++)    
        {        
            while(!st.empty()&& arr[i]<arr[st.top()])        
            {            
                //output[st.top()]=arr[i];            
                int el=arr[st.top()]
                //curretn bar to be removed and whose ans will be calc            
                st.pop();            
                int nsi=i;            
                int psi=(st.empty())?-1:st.top();            
                ans=max(ans,el*(nsi-psi-1));        
                }        
                st.push();     
                }    
                //for safety check    
                while(not st.top()){        
                    int el=arr[st.top()];        
                    int nsi=n;        
                    int psi=(st.empty())?-1:st.top();        
                    ans=max(ans,el*(nsi-psi-1));        
                    st.pop();    
                    }    
                    return ans;  }
using namespace std;int main(){    
    int n;    
    cin>>n;    
    vector<int> v;   
    while(n--){        
        int x;        
        cin>>x;        
        v.push_back(x);    
        }    
        int ans=histogram(arr);    
        cout<<ans<<endl;    
        return 0;
    }


