//implement hash table with closed addressing
#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Hashing{
    vector<list<int>> hashtable;
    int buckets;
    public:
    Hashing(int size){
        buckets=size;
        hashtable.resize(size);
        }
        int hashvalue(int key){
            return key%buckets;
            //division method    
        } 
        void add(int key){
            int idx=hashvalue(key);
            hashtable[idx].push_back(key);
            }
            list<int>::iterator searchKey(int key){
                int idx=hashvalue(key);
                return find(hashtable[idx].begin().hashtable[idx].end());
            }
        void deleteKey(int key){
                int idx=hashvalue(key);
                if (searchKey(key)!=hashtable[idx].end())
                {
                    hashtable[idx].erase(searchKey(key));
                    //key is present            
                    cout<<key<<" is deleted"<<endl;
                    }    
                }
};
int main(){
    Hashing h=new Hashing(10);
    h.addkey(10);
    return 0;
}