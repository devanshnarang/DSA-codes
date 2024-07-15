struct Node{
    Node* links[26];
    bool flag=false;
    int idx=-1;
    int len=1e9;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node,int i,int l){
        links[ch-'a']=node;
        if(l<len){
            len=l;
            idx=i;
        }
    }
    Node *get(char ch) {
		return links[ch - 'a'];
	}
    int getIdx(){
        return idx;
    }
    int getLen(){
        return len;
    }
    void changeIdx(int i){
        idx=i;
    }
    void changeLen(int l){
        len=l;
    }
    bool setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(string word,int idx){
        Node* node=root;
        for (int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node(),idx,word.size());
            }
            //moves to the reference trie
            else{
                int le=node->getLen;
                if(word.size()<le){
                    node->changeIdx(idx);
                    node->changeLen(word.size());
                }
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    // bool search(string word){
    //     Node* node=root;
    //     for(i = word.size(); i>=0; i--)
    //     {
    //         if(!node->containsKey(word[i])){
    //             return node->getIdx();
    //         }
    //         node=node->get(word[i]);
    //     }
    //     return node->getIdx();
    // }
}