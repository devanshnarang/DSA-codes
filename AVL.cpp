#include<iostream>
using namespace std;
class Node{
    int val;
    Node* left;
    Node* right;
    public:
    int height;
    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
        height=0;
    }
};
int height(Node* x){
    if (x==NULL)
    {
        /* code */
        return 0;
    }
    return x->height;
}
int getBalance(Node* x){
    if (x==NULL)
    {
        /* code */
        return 0;
    }
    return height(x->left)-height(x->right);
    
}
Node* rightRotate(Node* x){
    Node* temp=x->left;
    Node* temp2=temp->right;
    temp->right=x;
    x->left=temp2;
    temp->height=1+max(height(temp->left),temp->right);
    x->height=1+max(height(x->left),height(x->right));
    return temp;
}
Node* leftRotate(Node* x){
    Node* temp=x->right;
    Node* temp2=temp->left;
    temp->left=x;
    x->right=temp2;
    temp->height=1+max(height(temp->left),temp->right);
    x->height=1+max(height(x->left),height(x->right));
    return temp;
}
void insert(Node* &root,int x){
    if(root==NULL){
        return new Node(x);
    }
    if (x<root->val)
    {
        /* code */
        root->left=insert(root->left,x);
    }
    else if(x>root->val){
        root->right=insert(root->right,x);
    }
    root->height=1+max(height(root->left),height(root->right));
    int getDiff=getBalance(root);
    //left left case
    if(getDiff>1 && x<root->left->val){
        return rightRotate(root);
    }
    if(getDiff>1 && x>root->left->val){
        root->left=leftRotate(root->left)
        return rightRotate(root);
    }
    if(getDiff<1 && x<root->right->val){
        root->right=rightRotate(root->right)
        return leftRotate(root);
    }
    if(getDiff<1 && x>root->right->val){
        return leftRotate(root);
    }
    return root;
}
Node* tobeDeleted(Node* x){
    x=x->right;
    while(x && x->left){
        x=x->left;
    }
    return x;
}
Node* Delete(Node* &root,int x){
    if (root==NULL)
    {
        /* code */
        return NULL;
    }
    if (root->val==x)
    {
        /* code */
        if (root->left==NULL && root->right==NULL)
        {
            /* code */
            delete root;
            return NULL;
        }
        else if (root->left==NULL)
        {
            /* code */
            Node* temp=root->right;
            delete root;
            return root->right;
        }
        else if (root->right==NULL)
        {
            /* code */
            Node* temp=root->left;
            delete root;
            return root->left;
        }
        else{
            Node* tobeDeleted=nextGreater(root->right);
            swap(tobeDeleted->val,root->val);
            Delete(root->right,x);
        }
    }
    else if(root->val<x){
        root->left=Delete(root->left,x);
    }
    else{
        root->right=Delete(root->right,x);
    }  
}
int main()
{
    Node root(8);
    Node* tree=&root;

   return 0;
}