//check if given tree is BST or not
class Solution{
    public:
    bool isValidBSTHelper(TreeNode* root,long minValue,long maxValue){
        //base case
        if (root==NULL)
        {
            /* code */
            return true;
        }
        
        //1. root node value should lie within its range
        if (root->value<=maxValue ||root->value>=minValue)
        {
            /* code */
            return false;
        }
        //2. & 3. left and right subtrees should be BST
        return isValidBSTHelper(root->left,minValue,root->value);
        return isValidBSTHelper(root->right,root->val,maxValue);
        
        
    }
    bool isValidBST(TreeNode* root){
        return isValidBSTHelper(root,LONG_MIN,LONG_MAX);
    }
}
class Solution{
    public:
    bool isValidBSTHelper(TreeNode* root,TreeNode* prevNode){
        if (root==NULL)
        {
            /* code */
            return true;
        }
        
        if (!isValidBST(root->left,prev))
        {
            /* code */
            return false;
        }
        if (prev!=NULL && root->val<=prev->val)
        {
            /* code */
            return false;
        }
        if (!isValidBSTHelper(root->right,prev));
        {
            /* code */
            return false;
        }
        
        
        
    }
    bool isValidBST(TreeNode* root){
        TreeNode* prev=NULL;
        return isValidBSTHelper(root,prev);
    }
}
    //Given 2 vectors ;tell if 2 BST's will be identical or not without actually constructing the tree
    //find the first element within range in both arrays
    //if both elements are leaf nodes->return true
    //if one elements is leaf nodes-return false
    //if elements not same-return false
    //recursively check for left and right subtree
    bool checkIdenticalBSTHelper(vector<int> &v1,vector<int> &v2,int a1,int a2,int minValue,int maxValue){
        //find the first element in v1 within range
        itn i;
        for (i = a1; i < v1.size(); i++)
        {
            /* code */
            if (v1[i]>minValue && v[i]<maxValue)
            {
                /* code */
                break;
            }  
        }
        //find the first element in v2 within range
        int j;
        for (j = a2; j < v2.size(); j++)
        {
            /* code */
            if (v2[j]>minValue && v2[j]<maxValue)
            {
                /* code */
                break;
            }
        }
        //if no element is found within range (leaf nodes)
        if (i==v1.size() && j==v2.size())
        {
            /* code */
            return true; 
        }
        //if only one vector does not have element within range
        if ((i==v1.size() && j!=v2.size())||(i!=v1.size() && j==v2.size())){
            return false;
        }
        if (v[1]!=v2[j])
        {
            /* code */
            return false;
        }
        //recursively check for left and right subtree
        return checkIdenticalBSTHelper(v1,v2,a1+1,a2+1,minValue,v1[i]) && 
        checkIdenticalBSTHelper(v1,v2,a1+1,a2+1,v1[i],maxValue);
        
        
        
        
    }
    bool checkIdenticalBSTs(vector<int> &v1,vector<int> &v2){
        return checkIdenticalBSTHelper(v1,v2,0,0,INT_MIN,INT_MAX);
    }

//review again above question
//given the preorder traversal of a binary search tree construct the BST
class Solution{
    public:
    TreeNode* bstFromPreorderHelper(vector<int> &preorder,int prestart,int preend,vector<int>&inorder,
    int instart,int inend,unorder<int,int> imap){
        if (prestart>preend||instart>inend)
        {
            /* code */
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot_idx=imap[preorder[prestart]];
        int leftsubtree_elements=inroot_idx-instart;
        root->left=bstFromPreorderHelper(preorder,prestart+1,prestart+leftsubtree_elements,inorder,instart,inroot_idx-1,imap);
        root->right=bstFromPreorderHelper(preorder,prestart+leftsubtree_elements+1,preend,,inorder,inroot_idx+1,inend,imap);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int> &preorder){
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> imap;
        for (int i = 0; i < inorder.size(); i++)
        {
            /* code */
            imap[inorder[i]]=i;//storing value-index pairs
        }
        bstFromPreorderHelper(preorder,prestart,preend,inorder,instart,inend,imap);    
    }
}
//optimised solution
class Solution{
    TreeNode* bstFromPreorderHelper(vector<int> &preorder,int index,int upper_bound){
        if (index>= preorder.size())
        {
            return NULL;
        }
        if (preorder[index]>=upper_bound)
        {
            /* code */
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index]);
        index++;
        root->left=bstFromPreorderHelper(preorder,index,root->value);
        root->right=bstFromPreorderHelper(preorder,index,upper_bound);
        return root;
        
        
    }
    TreeNode* bstFromPreorder(vector<int> &preorder){
        return bstFromPreorderHelper(preorder,index,INT_MAX);
    }
}
//Maximum Sum BST in BINARY TREE
class NodeInfo{
    public:
    int minValue;
    int maxValue;
    int maxCurrentSize;
    NodeInfo(int min,int max,int sum){
        minValue=min;
        maxValue=max;
        maxCurrentSizeSum=sum;
    }
}
class Solution{
    public:
    int ans=0;
    NodeInfo maxSumBSTHelper(TreeNode* root){
        if (!root)
        {
            /* code */
            return NodeInfo(INT_MAX,INT_MiN,0);
        }
        NodeInfo leftSubtree=maxSumBSTHelper(root->left);
        NodeInfo rightSubtree=maxSumBSTHelper(root->right);
        if (root->val>leftSubtree.maxValue && root->val<rightSubtree.minValue)
        {
            //root node forms a BST
            ans=ma(ans,leftsubtree.maxCurrentSum+rightsubtree.maxCurrentSum+root->val);
            return NodeInfo(min(leftsubtree.minvalue,root->val),max(rightsubtree.maxvalue,root->val),leftsubtree.maxCurrentSum+rightsubtree.maxCurrentSum+root->val);
        }
        //root node does not form a binary search tree
        return Nodeinfo(INT_MIN,INT_MAX,max(leftsubtree.maxCurrentSum,rightsubtree.maxCurrentSum));

        
        
    }
    int maxSumBST(TreeNode* root){

    }
}
//for given N find all possible BSTs
class Solution{
    public:
    vector<TreeNode*> generateTreesHelper(int start,int end){
        vector<TreeNode*> treesList;
        //base case
        if (start>end)
        {
            /* code */
            treesList.push_back(NULL);
            return treesList;
        }
        for (int i = start; i <end ; i++)
        {
            /* code */
            vector<TreeNode*> leftsubtrees=generateTreesHelper(start,i-1);
            vector<TreeNode*> rightsubtrees=generateTreesHelper(i+1,end);
            for (TreeNode* leftsubtree:leftsubtrees)
            {
                for(TreeNode* rightsubtree:rightsubtrees){
                    TreeNode* rootNode=new TreeNode(i);
                    rootNode->left=leftsubtree;
                    rootNode->right=rightsubtree;
                    treesList.push_back(rootNode);
                }
            }
            
        }
        
    }
    vector<TreeNode*> generateTrees(int n){
        return generateTreesHelper(start,end);
    }
}
//given array of integers replace every element with least greater element on the right side of it
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val=v;
        left=right=NULL;
    }
}
TreeNode* insertNode(TreeNode* root,int element,int successor){
    if (root==NULL)
    {
        /* code */
        return new TreeNode(element);
    }
    
    if (element<root->val)
    {
        /* code */
        successor=root->val;
        root->left=insertNode(root->left,element,successor)
    }else if (element>root->val)
    {
        /* code */
        root->right=insertNode(root->right,element,successor);
    }
    return root;
    
}
void replaceWithLeastGreaterElement(vector<int> &v){
    TreeNode* root=NULL;
    for (int i = v.size()-1; i >== 0; i--)
    {
        /* code */
        int successor=-1;
        root=insertNode(root,v[i],successor);
        v[i]=successor;
    }
    
}

