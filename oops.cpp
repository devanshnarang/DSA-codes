#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};
int search(int inorder[],int st,int en,int key){
    for (int i = st; i <= en; i++)
    {
        /* code */
        if (inorder[i]==key)
        {
            /* code */
            return i;
        } 
    }
    return -1;
}
int l=5;
Node* buildTREE(int inorder[],int postorder[],int start,int end){
    if(start>end)return NULL;
    int curr=postorder[l--];
    Node* root=new Node(curr);
    cout<<root->val<<"    ";
    int pos=search(inorder,start,end,curr);
    if (start==end)
    {
        return root;
    }
    root->right=buildTREE(inorder,postorder,pos+1,end);
    root->left=buildTREE(inorder,postorder,start,pos-1);
    return root;
}
void display(Node* root){
    if (root==NULL)
    {
        return;
    }
    display(root->left);
    display(root->right);
    if(root)cout<<root->val<<"   ";
    return;
}
void reversed(int postorder[]){
    for (int i = 0; i < 3; i++)
    {
        /* code */
        swap(postorder[i],postorder[5-i]);
    }
    return;
}
int main()
{
    int inorder[6]={40,20,50,10,60,30};
    int postorder[6]={40,50,20,60,30,10};
    //int postorder[6]={10,20,40,50,30,60};
                     //10,30,60,20,50,40
    //reversed(postorder);
    Node* ans=buildTREE(inorder,postorder,0,5);
    //cout<<endl;
    //cout<<ans->val<<" "<<endl;
    cout<<endl;
    display(ans);
    return 0;
}
