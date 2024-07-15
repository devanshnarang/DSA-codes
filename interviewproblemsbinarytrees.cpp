//return number of paths where sum of elements is equal to target sum
class Solution{
    public:
    int pathSumHelper(TreeNode* root,int targetSum,int currSum,unordered_map<lomg int,int> pathCount){
        if(root==NULL){
            return 0;
        }
        currSum+=root->val;
        int ansCount=pathCount[currSum-targetSum];
        pathCount[currSum]++;
        ansCount+=pathSumHelper(root->left,targetSum,currSum,pathCount)+pathSumHelper(root->right,targetSum,currSum,pathCount);
        pathCount[currSum]--;//while backtracking
        return anscount;
    }
    int pathSum(TreeNode* root,int targetSum){
        unordered<long int,int> pathCount;
        pathCount[0]=1;
        return pathSumHelper(root,targetSum,0,pathCount);
    }
}
//return maximum sum path
class Solution{
    int maxPathSumHelper(TreeNode* root,int &maxSum){
        if(root==NULL){
            return 0;
        }
        int leftMaxSum=max(0,maxPathSumHelper(root->left,maxSum));
        int rightMaxSum=max(0,maxPathSumHelper(root->right,maxSum));
        maxSum=max(maxSum,root->val+leftMaxSum+rightMaxSum);
        return root->val+max(leftMaxSum,rightMaxSum);
    }
    int maxPathSum(TreeNode* root){
        int maxsum=INT_MIN;
        maxPathSumHelper(root,maxSum);
        return maxSum;
    }
}
//construct binary tree from preorder and inorder traversal
class Solution{
    TreeNode* buildTreeNodeHelper(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart,int inend,unordered_map<int,int> &imap){
        if(prestart>preend || instart>inend){
            return NULL;//handling the leaf nodes
        }
        TreeNode* rootNode=new TreeNode(preorder[prestart]);
        int rootInorderIndex=imap[rootNode->val];
        int leftSubtreeSize=rootInorderIndex-instart;
        rootNode->left=buildTreeNodeHelper(preorder,prestart+1,prestart+leftSubtreeSize,inorder,instart,rootInorderIndex-1,imap);
        rootNode->right=buildTreeNodeHelper(preorder,prestart+leftSubtreeSize+1,preend,inorder,rootInorderIndex+1,inend,imap);
        return rootNode;
    }

    TreeNode* buildTree(vector<int>&preorder,vector<int>& inorder){
        unordered_map<int,int> imap;
        for(int i=0;i<inorder.size();i++){
            imap[inorder[i]]=i;
        }
        return buildTreeNodeHelper(preorder,0,preorder.size()-1,inorder,inorder.size()-1,imap);
    }

}
//construct binary tree from preorder and postorder binary trees
class Solution{
    TreeNode* constructFromPrePost(vector<int>& preorder,int prestart,int prened,vector<int>&postorder,int poststart,int postend,unordered_map<int,int> &postmap){
        if(prestart>preend||poststart>postend){
            return NULL;
        }
        TreeNode* rootNode=new TreeNode(preorder[prestart]);
        if(prestart==preend){
            return rootNode;
        }
        int leftChildval=preorder[prestart+1];
        int leftChildIndex=postmap[leftChildval];
        int leftSubtreeSize=leftChildIndex-poststart+1;
        rootNode->left=constructFromPrePostHelper(preorder,prestart+1,prestart+leftSubtreeSize,postorder,poststart,leftChildIndex,postmap);
        rootNode->right=constructFromPrePostHelper(preorder,prestart+leftSubtreeSize+1,preend,postorder,leftChildIndex+1,postend-1,postmap);
        return rootNode;
    }
    TreeNode* constructFromPrePost(vector<int>&preorder,vector<int>&){
        unordered_map<int,int> postmap;
        for(int i=0;i<postorder.index();i++){
            postmap[postorder[i]]=i;
            return constructFromPrePostHelper(preorder,0,preorder.size()-1,postorder,0,postorder.index()-1,postmap);
        }
    }
}
//CREATE LINKED LIST FROM EXISTING BINARY TREE
class Solution{
    public:
    TreeNode* lastNode=NULL;
    void flatten(TreeNode* root){
        if(root==NULL){
            flatten(root->right);
            flatten(root->left);
            root->right=lastNode;
            root->left=NULL;
            lastNode=root;
        }
    }
}
//TIME TAEKN TO INFECT ENTIRE TREE
class Solution{
    public:
    int calculateTime(TreeNode* startNode,unordered_map<TreeNode*,TreeNode*>&parent){
        unordered_set<TreeNode> infected;
        queue<TreeNode*> q;
        q.push(startNode);
        infected.insert(startNode);
        int time=0;
        while(!q.empty()){
            int currLevelNodes=q.size();
            bool infectFLag=false;
            while(currLevelNodes--){
                TreeNode* currNode=q.front();
                q.pop();
                if(currNode->left && !infected.count(currNode->left)){
                    infectFLag=true;
                    infected.insert(currNode->left);
                    q.push(currNode->left);
                }
                if(currNode->right && !infected.count(currNode->right)){
                    infectFLag=true;
                    infected.insert(currNode->right);
                    q.push(currNode->right);
                }
                if(parent[currNode] && !infected.count(parent[currNode])){
                    infectFLag=true;
                    infected.insert(parent[currNode]);
                    q.push(parent[currNode]);
                }
            }
            if(infectFLag)time++;
        }
        return time;
    }
    TreeNode* makeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*,TreeNode* &parent,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode;
        while(!q.empty()){
            TreeNode* currNode=q.front();
            q.pop();
            if(currNode->val==start){
                startNode=currNode
            }
            if(currNode->left){
                parent[currNode->left]=currNode;
                q.push(currNode->left);
            }
            if(currNode->right){
                parent[currNode->right]=currNode;
                q.push(currNode->right);
            }
        }
        return startNode;
    }
    int amountOfTime(TreeNode* root,int start){
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* startNode=makeParent(root,parent,start);
        return calculateTime(start,parent);
    }
}