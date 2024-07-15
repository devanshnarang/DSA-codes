//Maps in c++
/*Maps is an STL container which stores key value pairs The elements are stored in ascending or descending orderMaps cannot have duplicate keys.Maps are implemented through binary search treesHeader file 
#include<map>
declaration-  map<key_data_type,value_data_type>By default order is ascendingfor descending order-  map<datatype1,datatype2,greater<datatype1>> map_nameInitialisation- map<datatype1,datatype2> map_name={{key1,val1},{key2,val2}}Insertion- directory.insert({key,value}) time complexity -O(logN)pair1=make_pair(key,value)directory[key]=valuePrinting the elementsfor(auto ele:map1){    
    //where ele is of datatype key value pair    key=ele.first;    value=elle.second}*/
// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     map<string,int> directory;
//     directory["naman"]=234;
//     directory["manas"]=1234;
//     directory["jai"]=125;
//     for(auto ele:directory){
//         cout<<"Name: "<<ele.first<<"  ";
//         cout<<"Contact: "<<ele.second<<endl;
//     }
//     return 0;
// }
//maps are dynamic sized//iterators are used to traverse our STL containers
//erase-m.erase(itr),m.erase(itr),m.erase(key),m.erase(start_itr,end_itr)
//end_itr won't be deleted-  O(logN) except whe ndeleting a range/*swap()-used to swap 2 maps of same data typem1.swap(m2) or swap(m1,m2)clear()- for eg-m.clear()empty-checks if my map is emptysize()-  for eg-m.size()max_size()find()-returns iterator to element
//m.end()-returns iterator pointing to position after last elementm.begin()count()-returns number of occurences of the keyupper_bound()-returns itr to next greater elementlower_bound()-returns itr element if present else itr to next greater element*/
// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> input(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>input[i];
//     }
//     map<int,int> m;
//     for (int i = 0; i < n; i++)
//     {
//         //storing frequency of every element in input array
//         m[input[i]]++;
//     }
//     int sum=0;
//     for(auto ele:m){
//         if (ele.second>1)
//element is repetitive
//         {
//             sum+=ele.first;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }
//UNORDERED MAP
/*STL container stores key-value pairs,elements are not oordered,keys will be uniqueInsertion Deletion Retrieval all time complexity O(1)implemented using hashing*/
// #include<iostream>
// #include<unordered_map>
// using namespace std;
// int main(){
//     unordered_map<int,string> record;
//     //roll no.,name;
//     record.insert(make_pair(1,"ria"));
//     record[2]="bali";
//     record[3]="animesh";
//     for(auto pair:record){
//         cout<<pair.first<<"   "<<pair.second<<endl;
//     }
//     return 0;
// }
//Member functions
/*insert erase find time complexity - O(1) avg case O(N)-worst case*/
//MULTIMAP
/*Stl container stores key-value pairs ,elements are stored in an order ascending or descending,duplicate keys are allowed,implemented using binary search trees o(logN) for insert delete search*/
// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     multimap<string,int> directory;
//     directory.insert(make_pair("nrvi",9899));
//     directory.insert(make_pair("saghvi",456));
//     directory.insert(make_pair("saghvi",9044));
//     //directory["urvi"]=4567 not allowed for multimaps
//     for(auto ele:directory){
//         cout<<ele.first<<"  "<<ele.second<<endl;
//     }
//     return 0;
// }
/*Member functions -insert,erase,find,count()-number of occurences,m.begin(),m.end()*/
//UNORDERED MULTIMAP
/*STL container store key value pairs,elements are not ordered,duplicate keys are allowed,implemented using hashing*/
#include<iostream>
#include<unordered_map>
using namespace std;int main(){
    unordered_multimap<string,int> fruitcount;
    fruitcount.insert(make_pair("mango",4));
    fruitcount.insert(make_pair("apple",5));
    fruitcount.insert(make_pair("mango",6));
    fruitcount.insert(make_pair("melon",4)); 
    for(auto ele:fruitcount){
        cout<<ele.first<<" "<<ele.second<<endl;
        } 
        return 0;}
    /*Member functions-insert,erase,find,counnt(can be more than 1),begin,end */
    //equal_range(key)-returns bounds of range of elements with key passed
    //it return 2 iterators pointing to start and end iterators to those elementswhere key is same as key passed