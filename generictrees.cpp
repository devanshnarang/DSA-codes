/*Generic trees-every node has data and list of references to its children nodes
It is also caled N-ary tree*/
//Implementation
#include<iostream>
#include<queue>
using namespace std;
class Node{
    char data;
    vector<Node*> children;
    Node(char data){
        this->data=data;
    }
};
void preorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(Node* child:root->children){
        preorderTraversal(child);
    }
    return;
}
void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    int childNodes=root->children.size();
    for (int i = 0; i < childNodes-1; i++)
    {
        /* code */
        inorderTraversal(root->children[i]);
    }
    cout<<root->data<<"  ";
    if(childNodes>0){
        inorderTraversal(root->children[childNodes-1]);
    }
}
void postorderTraversal(Node* root){
    if (root==NULL)
    {
        /* code */
        return;
    }
    for(Node* child:root->children){
        postorderTraversal(child);
    }
    cout<<root->data<<"  ";
    
}
void levelorderTraversal(Node){
    if (root==NULL)
    {
        /* code */
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int currentElementNodes=q.size();
        while(currentElementNodes--){
            //deque
            Node* curr=q.front();
            q.pop();
            cout<<curr->data<<"  ";
            //enque all child nodes
            for(Node* child:curr->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
    
}
int main()
{
    Node* root=new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
   return 0;
}
//Traversals
//DFS(O(N)-time complexity)
//Preorder-print root,recursively call for child nodes(from left to right)
//Inorder-recursively visit all child nodes except last,print root node,recursively visit last chil node
//Postorder-recursively visit all child nodess,print root
//BFS