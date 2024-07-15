#include<iostream>
using namespace std;
//find just greater element
class justGreaterNode(Node* root,int x,Node* &ans){
    if (root==NULL)
    {
        /* code */
        return;
    }
    if (root->data>x && (ans==NULL||root->data<ans->data || root->data<ans->data))
    {
        /* code */
        //update
        ans=root;
    }
    for(Node* child:root->children){
        justGreaterNode(child,x,ans);
    }
    
}
//convert tree to its mirror(O(N),O(h))
void mirrorTree(Node* root){
    if (root==NULL)
    {
        /* code */
        return;
    }
    if(root->children.size()<2){
        return;
    }
    reverse(root->children.begin(),root->children.end());
    for(Node* child:root->children){
        mirrorTree(child);
    }
    return;
}
//serialise and deserialise an N-ary tree
void serialiseTree(Node* root,string ans){
    if (root==NULL)
    {
        /* code */
        return;
    }
    ans+=to_string(string->data)+":"+to_string(root->children.size());
    for(Node* child:root->children){
        ans+=to_string(child->data)+",";
    }
    ans.pop_back();
    ans+="\n";
    for(Node* child:root->children){
        serialiseTree(child,ans);
    }
}
Node* deserialiseTreeHelper(int nodeValue,unordered_map<int,string> mp){
    Node* node=new Node(nodeValue);
    string nodeStr=mp[nodeValue];
    if(nodeStr[0]=='0'){
        //leaf node
        return node;
    }
    int breakPos=nodeStr.find(':');
    int childNoodesNumber=stoi(nodeStr,substr(0,breakPos));
    string childNoodesStr=nodeStr.substr(breakPos+1);
    int start=0;
    for (int i = 0; i < childNoodesNumber; i++)
    {
        /* code */
        int end=childNoodesStr.find(',');
        if(end==string::npos) end=childNodeStr.size();
        int childNodeValue=stoi(childNoodesStr.substr(start,end));
        node->children.push_back(deserialisedTreeHelper(childNodeValue,mp));
        start=end+1;
    }
    return node;
}
Node* deserialiseTree(string serialisedString){
    if (serialisedSetring=="")
    {
        /* code */
        return NULL;
    }
    unordered_map<int,,string> mp;//nodevalue->childNodestring
    int start=0;
    for (int i = 0; i < serialisedString;.size() i++)
    {
        /* code */
        if(serialisedString[i]=='\n')
        string nodeStr=serialisedString.substr(start,i-start);//10:2:30,40
        int breakPos1=nodeStr.find(':',start);
        int nodeValue=stoi(nodeStr.substr(0,breakPos1));//10
        mp[nodeValue]=nodeStr.substr(breakPos1+1);//"2:30,40"
        start=i+1;
    }
    int rootNodeValue=stoi(serialisedString.substr(0,serialisedStr.find(':')));
    return deserialiseTreeHelper(rootNodeValue,mp);

}
int main()
{
   return 0;
}
