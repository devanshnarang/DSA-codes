/*Data structures are of 2 types -linear and non-linearLinear(sequential manner data storage)-array,linked list,stacks,queues
Non-linear(hierarchical storage)-Trees,Graphs
Tree is a non-linear data structure which stores hierarchical data,elements are stored at different levels,elements are called nodes(which are linked together to represent hierarchy)
Topmost node from where tree starts expanding is called root node
Every node will have some data,links to the successor node(descendent nodes)
A tree is represented by its root node.
Root-Topmost Node-Not a child node,has no parent node
Child Node-successor or descendent of any node
Parent node-predecessor of any node is called parent node
Sibiling node-nodes with common parent node
Leaf node-which hve no child nodes
Number of edges(edge is link between 2 nodes)-if we have to travel from A to E then we require 2 edges A to B and B to E
Level-no of edges from root node
Height-maximum number of edges between leaf node and root node
Size-number of nodes in a tree,for n nodes we have n-1 edges
subtree-a tree which is a child of a node */
/*Generic Tree-A node can have any number of child nodes
Binary Tree-in which a node can have maximum 2 nodes
Binary search tree-binary tree in which all nodes in left subtree have value less than root node value && all nodes in right subtree will have value more than root node value
AVL trees-known as self balancing trees,difference between heights of left subtree and right subtree can be 1,0,-1*/
//BINARY TREE
/*every node can have maximum 2 child nodes,every node will contain data ,link to left child,link to right child
Implementation of node class ;
Node-  left,Data,Rightif any child doesn't exist ,pointer will point to null*/
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<stack>
using namespace std;
class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value=v;
        left=right=NULL;}
};
//PREORDER TRAVERSAL
void preorderTraversal(Node* rootNode){
    //base case    
    if (rootNode==NULL) {
        /* code */
        return;}
        cout<<rootNode->value<<" ";
        preorderTraversal(rootNode->left);
        preorderTraversal(rootNode->right);
        }
//INORDER TRAVERSAL
void inorderTraversal(Node* rootNode){
    //base case    
    if (rootNode==NULL){
        /* code */
        return;}
        //recursive case    
        inorderTraversal(rootNode->left); 
        cout<<rootNode<<" ";;
        inorderTraversal(rootNode->right);}
//POSTORDER TRAVERSAL
void inorderTraversal(Node* rootNode){
    //base case    
    if (rootNode==NULL){
        /* code */
        return;}
        //recursive case    
        inorderTraversal(rootNode->left);
        inorderTraversal(rootNode->right);
        cout<<rootNode<<" ";;}
//LEVEL ORDER TRAVERSAL
void levelOrderTraversal(Node* rootNode){
    if (rootNode==NULL){
        /* code */
        return ;}
        queue<Node*> q;
        q.push(rootNode);
        while (!q.empty())
        {
            int nodesAtCurrentLevel=q.size();
            while (nodesAtCurrentLevel--)
            {
                Node* currNode=q.front();
                q.pop();
                if (currNode->left){
                    /* code */
                    q.push(currNode->left);}
                    if (currNode->right)
                    {
                        /* code */
                        q.push(currNode->right);
                        }
                        cout<<currNode->value<<" ";
                        }
                        cout<<endl; }
                    }
//FIND MAX DEPTH QUESTION
int maxDepth(Node* root){
    //base case    
    if (root==NULL){
        /* code */
        return 0;}
        //recursive case    
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        return (max(leftDepth,rightDepth)+1);}
//LEAF NODES
int leafNodes(Node* root){    
    //base case    
    if (root==NULL){
        /* code */
        return 0;}
        if (root->left==NULL && root->right==NULL){
            /* code */
            return 1;}
        //recursive case    
        int leftSubtreeLeafNodes=leafNodes(root->left);
        int rightSubtreeLeafNodes=leafNodes(root->right);
        return leftSubtreeLeafNodes+rightSubtreeLeafNodes;
}
//return the nodes which you can see from the right hand side
//USE LEVEL ORDER TRAVERSAL
vector<int> rightViewBinaryTree(Node* root){
    vector<int> ans; 
    if(root==NULL){
        return ans;}
        queue<Node*> q;
        while(!q.empty()){ 
            int nodesAtCurrentLevel=q.size();
            while(nodesAtCurrentLevel){
                Node* currNode=q.front();
                q.pop();
                if (nodesAtCurrentLevel==1)
                {
                    ans.push_back(currNode->value);
                }
                if (currNode->left)
                {
                    q.push(currNode->left);
                }
                if (currNode->right)
                {
                    /* code */
                    q.push(currNode->right); 
                }
                nodesAtCurrentLevel--; 
            }
        }
}
                            
//Print the TOP VIEW OF A BINARY TREE/
/LEVEL ORDER TRAVERSAL
vector<int> topViewBinaryTree(Node* root){
    vector<int> ans; 
    if (root==NULL) { 
        return ans;
        }
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        map<int,int> m;
        while(!q.empty()){
            int nodesAtCurrentLevel=q.size(); 
            while (nodesAtCurrentLevel--)
            {
                pair<Node*,int> p=q.front();
                Node* currNode=p.first;
                int currColumn=p.second;
                q.pop();
                if (m.find(currColumn)==m.end())
                {
                    /* code */
                    m[currColumn]=currNode->value; 
                }
                if (currNode->left)
                {
                    /* code */ 
                    q.push(make_pair(currNode->left,currColumn-1)); 
                    } 
                    if (currNode->right)
                    {
                        /* code */
                        q.push(make_pair(currNode->right,currColumn+1)); 
                    } 
                } 
                }
                for (auto it:m){
                    /* code */
                    ans.push_back(it.second); 
                    } 
                }
//PRINTING IN REVERSE ORDER
vector<int> reverseLevelOrder(Node* root){
    vector<int> ans;
    if (root==NULL){
        /* code */ 
        return ans;
        }
        queue<Node> q; 
        stack<int> s;
        while (!q.empty()){ 
            /* code */
            int nodesAtCurrentLevel=q.size(); 
            while (nodesAtCurrentLevel--)
            { 
                /* code */
                Node* currNode=q.front(); 
                q.pop(); 
                s.push(currNode);
                if (currNode->right) 
                { 
                    /* code */
                    q.push(currNode->right);
                }
                if (currNode->left)
                {
                    /* code */
                    q.push(currNode->left); 
                } 
            }
        }
        while(!s.empty()){ 
            ans.push_back(s.top()->value);
            s.pop();
        } 
    }
        int main(){
            Node* root=new Node(3); 
            root->left=new Node(4); 
            root->right=new Node(5); cout<<root->value<<root->left->value<<root->right->value<<endl;
            return 0;}
//TRAVERSAL
//DFS(DEPTH_FIRST SEARCH)
/*travel along the height,DFS-3 types of traversal (preorder,inorder,post order)
Preorder-visit the root node,visit the left subtree,visit the right subtree (all 3 recursively)
Inorder-visit the left subtree,visit the root node,visit the right subtree
Postorder-visit left subtree,right subtree,root node(recursively)*/
//BFS(Breadth First Traversal)
/*travel along breadth
Levelorder-we will use queue to store elements at same level as it uses FIFO (the left will be stored then right ;then left will be popped first to accesss its child and then right)*/


struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* CreateNode(char data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* InsertNode(Node* root, char data)
{
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}
ll bfs(Node* root)
{
    if (root == NULL)
        return 0;
    queue<Node*> q;
    q.push(root);
    ll cnt=0;
    while (q.empty() == false) {
        Node* node = q.front();
        q.pop();
        if (node->left != NULL){
            if(node->data=='P' && node->left->data=='S')cnt++;
            q.push(node->left);
        }
        if (node->right != NULL){
            if(node->data=='P' && node->right->data=='S')cnt++;
            q.push(node->right);
        }
    }
}