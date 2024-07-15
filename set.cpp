/*Set is used to store unique valuesSet is a STL container used to store unique values,it stores values in order state(increasing order or decreasing order)In set there is no indexing,elements are identified by their own valuesOnce value is inserted in a set it cannot be modified(can be first remove and then insert a new value)Advantages of a set-unique values,ordered,dynamic size,no overflowing errors in a set,faster(O(logN) fro insertion deletion search(binary search)Disadvantages-elements can't be accessed using indexing,uses more memory than array,not suitable for large data setsDeclaration- set<data_type> set_nameBy default values are stored in increasing order;for decreasing orderset<datatype,greater<datatype>> set_name*/
/*Inserting elements into a setset1.insert(4)-returns an iterator to the inserted valueTraversal-set_name.begin()-retunr iterator to first element of the setset_name.end()-iterator pointing to position after last element of the set*/
#include<iostream>
#include<set>
using namespace std;
int main(){    
    set<int,greater<int>> set1;    
//insertion in a set    set1.insert(2);    set1.insert(3);    set1.insert(4);    set1.insert(5);    
//cout<<set1.size()<<endl;    set1.insert(3);
//size remains same as it stores only unique values    
//deleting elements     auto itr=set1.begin();    auto start=set1.begin();    advance(start,1);    auto end=set1.begin();    advance(itr,3);    advance(itr,3);    set1.erase(4);    set1.erase(itr);    set1.erase(start,end);    
//traversing a set    set<int>::iterator itr;    for(itr=set1.begin();itr!=set1.end();itr++){        cout<<*itr<<endl;    }    
// for(auto value:set1){    
//     cout<<value<<endl;    
// }    
/*set_name.erase(value),set_name.erase(position), time complexity-O(logN)    set_name.erase(start pos,end pos)(including start,excluding end pos) time complexity -O(N)*/     
    return 0;
}
/*Member functions-size(),max_size()-max no. of elements set can holdempty()-checks if set is empty or not,clear()-removes all elements from the set,find(value)-returns position of element if present,else return end iterator,count-retunr no. of occurences of an element,lower_bound()-returns element if present ,else returns just greater valueupper_bound-returns next greater value,rbegin(),rend()*/
//UNORDERED SETS
/*unordered_set-values are stored in unordered fashion,unique values,values willbe identified by itself,values cannot be modified inside setInsertion,Deletion,Search operations average time complexity-O(1) using hashing*//*Member functions of unordered_set-insert(element) time complexity avg-O(1),worst-O(N) for single elementfor multiple elements O(n) best case where n is number of elementsfor worst case O(n*(N+1)) N-size of unordered setDeletion-erase(value),,erase(iterator),erase(start_itr,end_itr)single element -O(1)-avgO(N)-worstFind-find(v) -O(1)-avg,O(N)-worstcount(v)-O(1) avg ,O(N)- worst case*//*Functions related to hashing-load factor-load_factor() gives size of unordered set/bucket_countrehash(x)-sets the number of bucket to x or more ;O(N)-avg,O(N^2)-worst case*/
//MULTISET
/*multiset-it can store duplicate values,ordered,values will be identified by itself,value cannot be modified in multiset*/
#include<iostream>
#include<set>
using namespace std;int main(){ 
    multiset<int> ms; 
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(2);
    for(auto ele:ms){
        cout<<ele<<endl;
        }
        return 0;
}
//member functions of multiset
/*Insert insert()-O(logN)erase(value)-will erase all instances of the valueerase(iterator)-to delete at particular indexerase(start_itr,end_itr)find()-return lower_bound of element searched if found else end iterator time ocmplexity O(logN)count() time complexity O(k+logN) where k is the number fo occurenceslower_bound-itr pointing to first occurence of value if present,else position of will return next greter value  O(logN)upper_bound-postion of next greater value*/
//UNORDERED MULTISET
/*allows duplicate values,values are not ordered,value will be identified by itself,values cannot be modified*/
/*Member functions-insert() for single element O(1) avg,O(N) worstmultiple elements-O(n) avg O(n*(N+1)) where ever hashing happens due to size becoming more than capacity Deletion- erase()  O(1) avg,O(N) worstFind- find()  -O(1) avg O(N) worst casecount()  O(n) avg n-number of occurencesO(N)- worst N-size*/