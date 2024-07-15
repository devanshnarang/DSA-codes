// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int x){
//         data=x;
//         next=NULL;
//     }
// };
// class Queue{
//     int *arr;
//     int fr,re;
//     public:
//     Queue(){
//         arr=new int[20];
//         fr=0;
//         re=0;
//     }
//     void push(int x){
//         arr[re++]=x;
//     }
//     void pop(){
//         fr++;
//     }
//     int front(){
//         return arr[fr];
//     }
//     bool isEmpty(){
//         if (fr>re)
//         {
//             /* code */
//             return true;
//         }
//         return false;
//     }
// };
// class Stack{ 
//     int *arr;
//     int fr,re;
//     public:
//     Stack(){
//         arr=new int[10];
//         fr=0;
//         re=0;
//     }
//     void push(int x){
//         if(re==0){
//             arr[re]=x;
//             re++;
//         }
//         else{
//             re++;
//             arr[re]=x;
//         }
//     }
//     void pop(){
//         re--;
//     }
//     int top(){
//         return arr[re];
//     }
//     bool empty(){
//         if (re<0)
//         {
//             /* code */
//             return 1;
//         }
//         return 0;
//     }
//     int size(){
//         //cout<<this->fr<<endl;
//         return (this->re-this->fr+1);
//     }
// };
// void add_edge(int src,int dest,Node* graph[]){
//     Node* temp=graph[src];
//     while (temp!=NULL && temp->next!=NULL)
//     {
//         /* code */
//         temp=temp->next;
//     }
//     if (temp==NULL)
//     {
//         /* code */
//         graph[src]=new Node(dest);
//     }
//     else{
//         temp->next=new Node(dest);
//     } 
// }
// void DFS(int curr,int end,Node* graph[],int visited[],int path[],int &i){
//     if (curr==end)
//     {
//         /* code */
//         path[i]=end;
//         return;
//     }
//     Node* temp=graph[curr];
//     path[i]=curr;
//     while(temp!=NULL){
//         if (visited[temp->data]!=1)
//         {
//             /* code */
//             DFS(temp->data,end,graph,visited,path,++i);
//         }
        
//         temp=temp->next;
//     }
//     visited[curr]=0;
//     i--;    
// }
// int main()
// {
//     int v;
//     cin>>v;
//     Node* graph[v];
//     for(int i=0;i<v;i++){
//         graph[i]=NULL;
//     }
//     int itr=v;
//     while (itr--)
//     {
//         /* code */
//         int s,d;
//         cin>>s>>d;
//         add_edge(s,d,graph);
//     }
//     int visited[v];
//     for (int i = 0; i < v; i++)
//     {
//         /* code */
//         visited[i]=0;
//     }
//     int path[4];
//     int y=0;
//     for (int i = 0; i < 4; i++)
//     {
//         /* code */
//         path[i]=0;
//     }
    
//     DFS(0,1,graph,visited,path,y);
//     for (int i = 0; i < 4; i++)
//     {
//         /* code */
//         cout<<path[i]<<"   ";
//     }
//     cout<<endl;
//     for (int i = 0; i < v; i++)
//     {
//         /* code */
//         cout<<i<<" :  ";
//         Node* temp=graph[i];
//         if(temp==NULL){
//             cout<<endl;
//             continue;
//         }
//         while (temp!=NULL)
//         {
//             /* code */
//             cout<<temp->data<<"   ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
    
//    return 0;
// }

// #include<iostream>
// #include<queue>
// using namespace std;
// //Trees
// class Node{
//     public:
//     Node* left;
//     Node* right;
//     int val;
//     Node(int x){
//         this->val=x;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };
// void insert(Node* &root,int y){
//     if (root==NULL){
//         cout<<"JI"<<endl;
//         root=new Node(y);
//         return;
//     }
//     else{
//         Node* temp=root;
//         while(temp!=NULL){
//             if (y<temp->val)
//             {
//                 /* code */
//                 if (temp->left==NULL)
//                 {
//                     /* code */
//                     temp->left=new Node(y);
//                     return;
//                 }
                    
//                 temp=temp->left;
//             }
//             else if(y>temp->val){
//                 if (temp->right==NULL)
//                 {
//                     /* code */
//                     temp->right=new Node(y);
//                     return;
//                 }
//                 temp=temp->right;
//             }
//             else{
//                 Node* temp2=root->right;
//                 temp->right=new Node(y);
//                 temp->right->right=temp2;
//                 return;
//             }
//         }
//     }
// }
// Node* nextGreaterNode(Node* ptr){
//     ptr=ptr->right;
//     while(ptr && ptr->left){
//         ptr=ptr->left;
//     }
//     return ptr;
// }
// Node* Delete(Node* &root,int v){
//     if (root==NULL)
//     {
//         /* code */
//         return NULL;
//     }
//     else if(root->val==v){
//         if (root->left==NULL && root->right==NULL)
//         {
//             /* code */
//             delete root;
//             return NULL;
//         }
//         else if(root->left==NULL){
//             Node* tempo=root->right;
//             delete root;
//             return tempo;
//         }
//         else if (root->right==NULL)
//         {
//             /* code */
//             Node* tempo=root->left;
//             delete root;
//             return tempo;
//         }
//         else{
//             Node* tobeDeleted=nextGreaterNode(root);
//             swap(tobeDeleted->val,root->val);
//             Delete(root->right,v);
//             return root;
//         }
        
        
//     }
//     else if (root->val<v)
//     {
//         /* code */
//         root->right=Delete(root->right,v);
//         return root;
//     }
//     else{
//         root->left=Delete(root->left,v);
//         return root;
//     }
    
//     return NULL;
// }
// int getHeight(Node* root){
//     if (root==NULL)
//     {
//         /* code */
//         return 0;
//     }
//     if(root->left==NULL && root->right==NULL){
//         return 1;
//     }
//     return 1+max(getHeight(root->left),getHeight(root->right));
// }
// int getDiameter(Node* root,int &ans){
//     if (root==NULL)
//     {
//         /* code */
//         return 0;
//     }
//     int lh=getDiameter(root->left,ans);
//     int rh=getDiameter(root->right,ans);
//     ans=max(ans,1+lh+rh);
//     cout<<ans<<endl;
//     return 1+max(lh,rh);
// }
// void bfs(Node* root){
//     cout<<"HI"<<endl;
//     queue<Node*> qu;
//     if(root==NULL)return;
//     qu.push(root);
//     while (!qu.empty())
//     {
//         /* code */
//         int nodesAtCurrentLevel=qu.size();
//         while(nodesAtCurrentLevel--){
//             //cout<<qu.front()->val;
//             Node* fre=qu.front();
//             if (fre->left!=NULL)
//             {
//                 /* code */
//                 qu.push(fre->left);
//                 //cout<<fre->left->val<<"  ";
//             }
//             if (fre->right!=NULL)
//             {
//                 /* code */
//                 qu.push(fre->right);
//                 //cout<<fre->right->val<<"  ";
//             }
//             qu.pop();
//             //cout<<fre->left->val<<"   "<<fre->right->val<<endl;
//             //cout<<qu.front()->val<<"&"<<nodesAtCurrentLevel<<endl;
//             cout<<fre->val<<" ";
//         }
//         cout<<"  %  ";
//     } 
// }
// //Inorder
// void Preorder(Node* root){
//     if (root==NULL)
//     {
//         /* code */
//         return;
//     }
//     cout<<root->val<<"  ";
//     Preorder(root->left);
//     Preorder(root->right);
//     return;
// }
// //Inorder
// void Inorder(Node* root){
//     if (root==NULL)
//     {
//         /* code */
//         return;
//     }
//     Inorder(root->left);
//     cout<<root->val<<"  ";
//     Inorder(root->right);
//     return;
// }
// //Postorder
// void Postorder(Node* root){
//     if (root==NULL)
//     {
//         /* code */
//         return;
//     }
//     Postorder(root->left);
//     Postorder(root->right);
//     cout<<root->val<<"  ";
//     return;
// }
// int main(){
//     Node root(8);
//     Node* tree1=&root;
//     insert(tree1,3);
//     insert(tree1,10);
//     insert(tree1,14);
//     insert(tree1,13);
//     insert(tree1,1);
//     insert(tree1,6);
//     insert(tree1,4);
//     insert(tree1,7);
//     cout<<"INORDER is:   ";
//     Inorder(tree1);
//     cout<<endl;
//     cout<<"PREORDER is:   ";
//     Preorder(tree1);
//     cout<<endl;
//     cout<<"POSTORDER is:   ";
//     Postorder(tree1);
//     cout<<endl;
//     cout<<"Height is: "<<getHeight(tree1)<<endl;
//     // int ans=0;
//     // getDiameter(tree1,ans);
//     //cout<<"Diameter is : "<<ans-1<<endl;
//     bfs(tree1);
//     return 0;
// }




// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int x){
//         data=x;
//         next=NULL;
//     }
// };
// class Queue{
//     int *arr;
//     int fr,re;
//     public:
//     Queue(){
//         arr=new int[20];
//         fr=0;
//         re=0;
//     }
//     void push(int x){
//         arr[re++]=x;
//     }
//     void pop(){
//         fr++;
//     }
//     int front(){
//         return arr[fr];
//     }
//     bool isEmpty(){
//         if (fr>re)
//         {
//             /* code */
//             return true;
//         }
//         return false;
//     }
// };
// class Stack{
//     int *arr;
//     int fr,re;
//     public:
//     Stack(){
//         arr=new int[10];
//         fr=0;
//         re=0;
//     }
//     void push(int x){
//         if(re==0){
//             arr[re]=x;
//             re++;
//         }
//         else{
//             re++;
//             arr[re]=x;
//         }
//     }
//     void pop(){
//         re--;
//     }
//     int top(){
//         return arr[re];
//     }
//     bool empty(){
//         if (re<0)
//         {
//             /* code */
//             return 1;
//         }
//         return 0;
//     }
// //     int size(){
// //         //cout<<this->fr<<endl;
// //         return (this->re-this->fr+1);
// //     }
// };
// Node* arr[50];
// bool visited[6];
// int path[10];
// int color[10];
// bool reached=false;
// Stack st;
// void add_edge(int src,int dest){
//     if (arr[src]==NULL)
//     {
//         /* code */
//         arr[src]=new Node(dest);
//         return;
//     }
//     Node* temp=arr[src];
//     while (temp->next!=NULL)
//     {
//         /* code */
//         temp=temp->next;
//     }
//     temp->next=new Node(dest);
// }
// // void dfsPath(int curr,int end,int pos){
// //     if(curr==end){
// //         path[pos]=end;
// //         reached=true;
// //         return;
// //     }
// //     Node* temp=arr[curr];
// //     visited[curr]=true;
// //     //cout<<pos<<"   ";
// //     path[pos]=curr;
// //     //cout<<curr<<"   ";
// //     while(temp!=NULL){
// //         dfs(temp->data,end,pos+1);
// //         if (reached)
// //         {
// //             /* code */
// //             return;
// //         }       
// //         temp=temp->next;
// //     }
// //     visited[curr]=false;
// //     pos--;
// //     return;
// // }
// void topologicalSort(int curr){
//     visited[curr]=true;
//     Node* temp=arr[curr];
//     while(temp!=NULL){
//         if(visited[temp->data]==0)topologicalSort(temp->data);
//         temp=temp->next;
//     }
//     cout<<curr<<"   ";
//     st.push(curr);
//     return;
// }
// bool bipartite(int src,int end){
//     Queue qu;
//     qu.push(src);
//     color[src]=0;
//     while(!qu.isEmpty()){
//         int st=qu.front();
//         Node* temp=arr[st];
//         while(temp!=NULL){
//             if(color[temp->data]==-1){
//                 color[temp->data]=!color[st];
//                 qu.push(temp->data);
//             }
//             else{
//                 if(color[st]==color[temp->data])return false;
//             }
//             temp=temp->next;
//         }
//         qu.pop();
//     }  
//     return true;   
// }
// void display(){
//     for (int i = 0; i < 6; i++)
//     {
//         /* code */
//         Node* temp=arr[i];
//         cout<<i<<": ";
//         while (temp!=NULL)
//         {
//             /* code */
//             cout<<temp->data<<"  ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
//     int v;
//     cin>>v;
//     int e;
//     cin>>e;
//     while(e--){
//         int s,d;
//         cin>>s>>d;
//         add_edge(s,d);
//     }
//     for (int i = 0; i < 6; i++)
//     {
//         /* code */
//         visited[i]=false;
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         /* code */
//         path[i]=INT_MAX;
//     }
//     //dfs(5,2,0);
//     //cout<<endl;
//     // for (int i = 0; i < 10; i++)
//     // {
//     //     /* code */
//     //     if(path[i]==INT_MAX){
//     //         break;
//     //     }
//     //     cout<<path[i]<<"   ";
//     // }
//     // for (int i = 0; i < 6; i++)
//     // {
//     //     /* code */
//     //     if(!visited[i])topologicalSort(i);
//     //     cout<<endl;
//     // }
//     // while(!st.empty()){
//     //     cout<<st.top()<<"   ";
//     //     st.pop();
//     // }
//     cout<<endl;
//     for (int i = 0; i < v; i++)
//     {
//         /* code */
//         color[i]=-1;
//     }
//     cout<<bipartite(0,6)<<endl;
//     for (int i = 0; i < 6; i++)
//     {
//         /* code */
//         cout<<color[i]<<"   ";
//     }
//     cout<<endl;
//     display();
    
//    return 0;
// }


//heap sort
// #include<iostream>
// using namespace std;
// void heapify(int arr[],int curr,int n){
//     while((2*curr+1)<n){
//         int left=2*curr+1;
//         int right=2*curr+2;
//         int minChild=left;
//         if(right<n && arr[minChild]>arr[right]){
//             minChild=right;
//         }
//         if (arr[minChild]<arr[curr])
//         {
//             /* code */
//             swap(arr[curr],arr[minChild]);
//         }
//         curr=minChild;
//     }
// }
// void heapify(int s,int n,int arr[]){
//     swap(arr[0],arr[n-1]);
//     heapify(0,n,arr);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         cin>>arr[i];
//     }
//     for (int i = (n/2)-1; i >= 0 ; i--)
//     {
//         /* code */
//         heapify(arr,i,n);
//     }
//     int x=n;
//     while(n){
//         //heapify(0,n,arr);
//         n--;
//     }
//     for (int i = 0; i < x; i++)
//     {
//         /* code */
//         cout<<arr[i]<<"    ";
//     }
//     cout<<endl;
//    return 0;
// }

// bool isBST(Node* root,int mini,int maxi){
//     if(root==NULL)return true;
//     if(root->val>mini && root->val<maxi){
//         bool leftsub=isBST(root->left,mini,root->val);
//         bool rightsub=isBST(root->right,root->val,maxi);
//         return leftsub && rightsub;
//     }  
//     else{
//         return false;
//     }  
// }
// int maximini(Node* root){
//     if(root==NULL)return -1;
//     Node* temp=root;
//     while(temp && temp->right){
//         temp=temp->right;
//     }
//     Node* temp2=root;
//     while(temp2 && temp2->left){
//         temp2=temp2->left;
//     }
//     int ma=temp->val;
//     int mi=temp2->val;
// }

// #include<iostream>
// #include<queue>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int x){
//         data=x;
//         left=NULL;
//         right=NULL;
//     }
// };
// bool isComplete(Node* root){
//     if(root==NULL)return true;
//     queue<Node*> qu;
//     qu.push(root);
//     bool flag=true;
//     while(!qu.empty()){
//         Node* fr=qu.front();
//         qu.pop();
//         if (fr->left)
//         {
//             /* code */
//             if(!flag)return false;
//             qu.push(fr->left);
//         }
//         else{
//             flag=false;
//         }
//         if(fr->right){
//             if(!flag)return false;
//             qu.push(fr->right);
//         }
//         else{
//             flag=false;
//         }
//     }
//     return true;
// }
// bool isHeap(Node* root){
//     if (root==NULL)
//     {
//         /* code */
//         return true;
//     }
//     if(!root->left && !root->right)return true;
//     else if(root->right==NULL){
//         return root->data>=root->left->data;
//     }
//     else{
//         if(root->data>=root->left->data && root->data>=root->right->data){
//             return isHeap(root->left)&& isHeap(root->right);
//         }
//     }
// }
// int main()
// {
//     Node root(10);
//     Node* temp=&root;
//     temp->left = new Node(9);
//     temp->right = new Node(8);
//     temp->left->left = new Node(7);
//     temp->left->right = new Node(6);
//     temp->right->left = new Node(5);
//     temp->right->right = new Node(4);
//     temp->left->left->left = new Node(3);
//     temp->left->left->right = new Node(2);
//     temp->left->right->right = new Node(1);
//     if(isComplete(temp))cout<<isHeap(temp);
//     else{
//         cout<<false;
//     }
//    return 0;
// }

// #include<iostream>
// using namespace std;
// int postindex=0;
// int search(int in[],int x){
//     for (int i = 0; i < 6; i++)
//     {
//         /* code */
//         if (in[i]==x)
//         {
//             /* code */
//             return i;
//         }  
//     }
//     return -1;
// }
// void postorder(int pre[],int in[],int post[],int instart,int inend,int prestart){
//     if (instart>inend)
//     {
//         return;
//     }
//     if(instart==inend){
//         post[postindex++]=in[instart];
//         return;
//     }
//     int pos=search(in,pre[prestart]);
//     postorder(pre,in,post,instart,pos-1,prestart+1);
//     postorder(pre,in,post,pos+1,inend,prestart+pos+1);
//     post[postindex++]=pre[prestart];
//     return;
// }
// int main(){
//     int pre[]={1,2,4,5,3,6};
//     int in[]={4,2,5,1,3,6};
//     int post[6];
//     int idx=0;
//     postorder(pre,in,post,0,5,0);
//     for (int i = 0; i < 6; i++)
//     {
//         /* code */
//         cout<<post[i]<<"   ";
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int x){
//         data=x;
//         next=NULL;
//     }
// };
// class Queue{
//     int *arr;
//     int fr,re;
//     public:
//     Queue(){
//         arr=new int[20];
//         fr=0;
//         re=0;
//     }
//     void push(int x){
//         arr[re++]=x;
//     }
//     void pop(){
//         fr++;
//     }
//     int front(){
//         return arr[fr];
//     }
//     bool isEmpty(){
//         if (fr>re)
//         {
//             /* code */
//             return true;
//         }
//         return false;
//     }
// };
// class Stack{
//     int *arr;
//     int fr,re;
//     public:
//     Stack(){
//         arr=new int[10];
//         fr=0;
//         re=0;
//     }
//     void push(int x){
//         if(re==0){
//             arr[re]=x;
//             re++;
//         }
//         else{
//             re++;
//             arr[re]=x;
//         }
//     }
//     void pop(){
//         re--;
//     }
//     int top(){
//         return arr[re];
//     }
//     bool empty(){
//         if (re<0)
//         {
//             /* code */
//             return 1;
//         }
//         return 0;
//     }
//     int size(){
//         //cout<<this->fr<<endl;
//         return (this->re-this->fr+1);
//     }
// };
// void add_edge(int src,int dest,Node* graph[]){
//     Node* temp=graph[src];
//     while (temp!=NULL && temp->next!=NULL)
//     {
//         /* code */
//         temp=temp->next;
//     }
//     if (temp==NULL)
//     {
//         /* code */
//         graph[src]=new Node(dest);
//     }
//     else{
//         temp->next=new Node(dest);
//     } 
//     temp=graph[dest];
//     while (temp!=NULL && temp->next!=NULL)
//     {
//         /* code */
//         temp=temp->next;
//     }
//     if (temp==NULL)
//     {
//         /* code */
//         graph[dest]=new Node(src);
//     }
//     else{
//         temp->next=new Node(src);
//     } 
//     return;
// }
// void DFS(int curr,int end,Node* graph[],int visited[],int path[],int &i){
//     if (curr==end)
//     {
//         /* code */
//         path[i]=end;
//         return;
//     }
//     Node* temp=graph[curr];
//     path[i]=curr;
//     while(temp!=NULL){
//         if (visited[temp->data]!=1)
//         {
//             /* code */
//             DFS(temp->data,end,graph,visited,path,++i);
//         }
        
//         temp=temp->next;
//     }
//     visited[curr]=0;
//     i--;    
// }
// void BFS(int src,int end,int dist[],Node* graph[],int visited[]){
//     Queue qu;
//     qu.push(src);
//     dist[src]=0;
//     visited[src]=1;
//     while(!qu.isEmpty()){
//         int fr=qu.front();
//         qu.pop();
//         Node* temp=graph[fr];
//         //cout<<fr<<" - ";
//         while(temp!=NULL){
//             //cout<<temp->data<<"  ";
//             if(!visited[temp->data]){
//                 visited[temp->data]=1;
//                 qu.push(temp->data);
//                 dist[temp->data]=dist[fr]+1;
//                 cout<<fr<<"-"<<temp->data<<"    "<<dist[temp->data]<<"  &  ";
//             }
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
//     return;
// }
// int main()
// {
//     int v;
//     cin>>v;
//     Node* graph[v];
//     for(int i=0;i<v;i++){
//         graph[i]=NULL;
//     }
//     int itr=v;
//     int e;
//     cin>>e;
//     while (e--)
//     {
//         /* code */
//         int s,d;
//         cin>>s>>d;
//         add_edge(s,d,graph);
//     }
//     int visited[v];
//     for (int i = 0; i < v; i++)
//     {
//         /* code */
//         visited[i]=0;
//     }
//     // int path[4];
//     // int y=0;
//     // for (int i = 0; i < 4; i++)
//     // {
//     //     /* code */
//     //     path[i]=0;
//     // }
    
//     // DFS(0,1,graph,visited,path,y);
//     // for (int i = 0; i < 4; i++)
//     // {
//     //     /* code */
//     //     cout<<path[i]<<"   ";
//     // }
//     // cout<<endl;
//     int dist[20];
//     BFS(0,6,dist,graph,visited);
//     cout<<endl;
//     for (int i = 0; i <= 6; i++)
//     {
//         /* code */
//         cout<<dist[i]<<"  ";
//     }
//     cout<<endl;
//     for (int i = 0; i < v; i++)
//     {
//         /* code */
//         cout<<i<<" :  ";
//         Node* temp=graph[i];
//         if(temp==NULL){
//             cout<<endl;
//             continue;
//         }
//         while (temp!=NULL)
//         {
//             /* code */
//             cout<<temp->data<<"   ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
    
//    return 0;
// }
// #include<iostream>
// #include<stack>
// using namespace std;
// int precedence(char oper){
//     if (oper=='+' || oper=='-')
//     {
//         return 1;
//     }
//     else if(oper=='*' || oper=='/'){
//         return 2;
//     }
//     else{
//         return 3;
//     }
// }
// string infixtopostfix(string s){
//     string ans;
//     stack<char> st;
//     for (int i = 0; i < s.size(); i++)
//     {
//         cout<<i<<"    "<<ans<<endl;
//         if(s[i]>='a' && s[i]<='z')ans+=s[i];
//         else{
//             if (st.empty() || precedence(s[i])>precedence(st.top()))
//             {
//                 st.push(s[i]);
//             }
//             else{
//                 while(!st.empty()  && precedence(s[i])<=precedence(st.top())){
//                     ans+=st.top();
//                     st.pop();
//                 }
//                 st.push(s[i]);
//             }
//         }
//     }
//     while(!st.empty()){
//         ans+=st.top();
//         st.pop();
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }
// string infixtoprefix(string ques){
//     reverse(ques.begin(),ques.end());
//     return infixtopostfix(ques);
// }
// // int main()
// {
//     cout<<infixtoprefix("a*b+c/d");
//    return 0;
// }


// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* left;
//     Node* right;
//     Node(int data){
//         val=data;
//         left=NULL;
//         right=NULL;
//     }
// };
// int search(int inorder[],int st,int en,int key){
//     for (int i = st; i <= en; i++)
//     {
//         /* code */
//         if (inorder[i]==key)
//         {
//             /* code */
//             return i;
//         } 
//     }
//     return -1;
// }
// int l=0;
// Node* buildTREE(int inorder[],int preorder[],int start,int end){
//     if(start>end)return NULL;
//     int curr=preorder[l++];
//     cout<<curr<<"     "<<l<<"     "<<preorder[l]<<endl;
//     Node* root=new Node(curr);
//     //l++;
//     if(start==end)return root;
//     int pos=search(inorder,start,end,curr);
//     root->left=buildTREE(inorder,preorder,start,pos-1);
//     root->right=buildTREE(inorder,preorder,pos+1,end);
//     return root;
// }
// void display(Node* root){
//     if (root==NULL)
//     {
//         /* code */
//         return;
//     }
//     cout<<root->val<<"   ";
//     display(root->left);
//     display(root->right);
//     return;
// }
// int main()
// {
//     int inorder[6]={40,20,50,10,60,30};
//     int preorder[6]={10,20,40,50,30,60};
//     Node* ans=buildTREE(inorder,preorder,0,5);
//     cout<<endl;
//     cout<<ans->val<<" "<<endl;
//     display(ans);
//    return 0;
// }
#include<iostream>
#include<algorithm>
using namespace std;
void selectionSort(int arr[]){
    for (int i = 0; i < 5; i++)
    {
        int mini=arr[i];
        for (int j = i+1; j < 6; j++)
        {
            mini=min(arr[j],mini);
        }
        swap(arr[i],mini);
    }
    return;
}
int main()
{
    int arr[6]={4,3,2,6,1,9};
    selectionSort(arr);
    cout<<endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<"     ";
    }
   return 0;
}
