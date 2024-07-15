//Binary search Tree
/*It is a binary tree where all values in left subtree of node is less than
value of node and all values in right subtree of node is greater than value
of node,this value of true for root node of all subtrees*/
/*Advantages-Insertion,deletion ,searching all will be of time complexity O(LogN base 2) in average case;easier to find minimum and maximum elements as all are in sorted order
Disadvantages-Worst case time complexity will be O(N) when we have unbalanced tree(tree skewed in one direction)*/
//Sets,Priority Queues and   Maps are implmented using binary search trees that's why their insertion ,searching operations are of complexity O(logN)
/*Traversal-Preorder,Inorder,Postorder
Insertion-value can only be inserted only at particular positions*/
#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value=v;
        left=right=NULL;
    }
};
class BST{
    public:
    Node* root;
    BST(){
        root=NULL;
    }
};
void insertBST(Node* root,int val){
    Node* newNode=new Node(val);
    if (root==NULL)
    {
        /* code */
        root=newNode;
        return;
    }
    Node* current=root;
    while(true){
        if(current->value>val){
            if (current->left==NULL)
            {
                /* code */
                current->left=newNode;
                return;
            }
            current=current->left;
        }else{
            if(current->right==NULL){
                current->right=newNode;
                return;
            }
            current=current->right;
        }
    }  
}
Node* insertBSTRecursive(Node* root,int val){
    //base case;
    if(root==NULL){
        Node* newNode=new Node(val);
        return newNode;
    }
    //recursive case
    if (root->value>val)
    {
        /* code */
        root->left=insertBSTRecursive(root->left,val);
    }else if(root->value<val){
        root->right=insertBSTRecursive(root->right,val);
    }
    return root;
}
bool searchBST(Node* root,int key){
    //base case
    if (root==NULL)
    {
        /* code */
        return false;
    }
    if(root->value==key){
        return true;
    }
    
    //recursive case
    if (root->value<key)
    {
        /* code */
        return searchBST(root->right);
    }else if(root->value>key){
        return searchBST(root->right);
    }
    
}
void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->value<<" ";
    inorderTraversal(root->right);
}
Node* largestNodeBST(Node* root){
    Node*curr=root;
    while(curr && curr->right!=NULL){
        curr->right;
    }
    return curr;
}
//DELETION:The node has 0 child
Node* deleteBST(Node* root,int key){
    if (root==NULL)
    {
        /* code */
        return ;
    }
    if (root->value<key)
    {
        /* code */
        root->right=deleteBST(root->right,key);
    }
    else if (root->value>key)
    {
        /* code */
        root->left=deleteBST(root->left,key);
    }
    else{
        //root is the key to be deleted
        if (root->left==NULL && root->right==NULL)//node has 0 child nodes
        {
            /* code */
            free(root);
            return NULL;
        }
        //node has 1 child node
        else if (root->left==NULL)
        {
            /* code */
            Node* temp=root->right;
            free(root);
            return temp;
        }else if (root->right==NULL)
        {
            /* code */
            Node* temp=root->left;
            free(root);
            return temp;
        }
        //node has 2 child nodes
        else{
            Node* justSmallerNode=largestNodeBST(root->left);
            root->value=justSmallerNode->value;
            root->left=deleteBST(root->left,justSmallerNode->val);
        }
        
        
    }
    return root;    
}
//sorted array to Balanced BST
Node* sortedArrayToBST(vector<int> v,int start,int end){
    if (start>end)
    {
        /* code */
        return NULL;
    }
    
    int mid=(start+end)/2;
    Node* root=new Node(v[mid]);
    //recursive case;
    root->left=sortedArrayToBST(v,start,mid-1);//recursively creating left subtree from the array
    root->right=sortedArrayToBST(v,mid+1,end);//recursively creating right subtree from the array
    return root;

}
//lowest common ancestor of BST(shared ancestor farthest from root node)
Node* lowestCommonAncestor(Node* root,Node* node1,Node* node2){
    //base case
    if (root==NULL)
    {
        /* code */
        return NULL;

    }
    
    if (root->value>node1->value && root->value>node2->value)
    {
        /* code */
        return lowestCommonAncestor(root->left,node1,node2);
    }
    if (root->value<node1->value && root->value<node2->value)
    {
        /* code */
        return lowestCommonAncestor(root->right,node1,node2);
    }
    //if root value lies between node1 and node2 value
    //if root value is equal to any of root values
    return root; 
}
//Remove leaf nodes from binary search tree
Node* removeLeafNodes(Node* root){
    //base case
    if (root==NULL)
    {
        /* code */
        return NULL;
    }
    if (root->left==NULL && root->right==NULL)
    {
        /* code */
        return NULL;
    }
    
    
    //recursive case
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;
}
//inorder predecessor and successor for a given key in BST
//Inorder predecessor and sucessor are just smaller and just greater values in a given binary tree for the given key
void inorderPreSuccBST(Node* root,Node* pre,Node* succ,int key){
    if (root==NULL)
    {
        /* code */
        return;
    }
    if (root->value==key)
    {
        /* code */
        //predecessor->rightmost node in left subtree
        if (root->left!=NULL)
        {
            /* code */
            Node* temp=root->left;
            while (temp->right!=NULL)
            {
                /* code */
                temp=temp->right;
            }
            pre=temp; 
        }
    
        //succesor-leftmost value in right subtree
        if (root->right!=NULL)
        {
            /* code */
            Node* temp=root->right;
            while (temp->left!=NULL)
            {
                /* code */
                temp=temp->left;
            }
            succ=temp;
        }
        return;
    }
    if (root->value>key)
    {
        /* code */
        succ=root;
        inorderPreSuccBST(root->left,pre,succ,key);
    }
    if (root->value<key)
    {
        /* code */
        pre=root;
        inorderPreSuccBST(root->right,pre,succ,key);
    }
}
int main()
{
   return 0;
} 
//for a balanced binary search tree max no. of comparisons to search for a value will be O(logN)

