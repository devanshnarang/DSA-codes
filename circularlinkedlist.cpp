/*advantages-we can start traversing from any node,when we have to traverse thr ll in circular fashion multiple times*/
// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* next;
//     Node(int data){
//         val=data;
//         next=NULL;
//     }
// };
// class circularLinkedList{
//     public:
//     Node* head;
//     circularLinkedList(){
//         head=NULL;
//     }
//     void display(){
//         Node* temp=head;
//         do
//         {
//             cout<<temp->val;
//             temp=temp->next;
//         } while (temp!=head);        
//     }
//     void insertAtStart(int val){
//         Node* new_node=new Node(val);
//         if (head==NULL)
//         {
//             head=new_node;
//             new_node->next=head;
//circular ll
//             return;
//         }
//         Node* tail=head;
//         while (tail->next!=head)
//         {
//             tail=tail->next;
//         }
//         
//tail is pointing to last node
//         tail->next=new_node;
//         new_node->next=head;
//         head=new_node;        
//     }
//     void insertAtEnd(int val){
//         Node* new_node;
//         if (head==NULL)
//         {
//             head=new_node;
//             new_node->next=head;
//         }
//         Node* temp=head;
//         while (temp->next!=head)
//         {
//             temp=temp->next;
//         }
//         temp->next=new_node;
//         new_node->next=head;                
//     }
//     void printCircular(){
//         Node* temp=head;
//         for (int i = 0; i < 15; i++)
//         {
//             cout<<temp->val<<"->";
//             temp=temp->next;
//         }        
//     }
//     void deleteAtStart(){
//         if (head==NULL)//         {
//             return;
//         }
//         Node* temp=head;
//         Node* tail=head;
//         while (tail->next!=head)
//         {
//             tail=tail->next;
//         }
//         head=head->next;
//         tail->next=head;
//         free(temp);   
//     }
//     void deleteAtEnd(){
//         if (head==NULL)
//         {
//             return;
//         }
//         Node* tail=head;
//         while (tail->next->next!head)//         {
//             tail=tail->next;
//         }
//         Node* temp=tail->next;
//         tail->next=head;
//         free(temp);                
//     }    
// }
// int main(){
//     circularLinkedList cll;
//     cll.insertAtStart(3);
//     cll.insertAtStart(2);
//     cll.insertAtStart(1);
//     cll.insertAtEnd(4);
//     cll.deleteAtStart();
//     cll.deleteAtEnd();
//     cll.display();
//     cll.printCircular();
//     return 0;
// }
//template classes-they allow us to pass data type as parameter// #include<iostream>// using namespace std;// template<typename T>// class Node{//template class//     public://     T val;//     Node* next;//     Node(int data){//         val=data;//         next=NULL;//     }// };// int main(){//     Node<int>* node1=new Node<int>(3);//     cout<<node1->val<<endl;//     Node<char>* node2=new Node<char>('c');//     cout<<node2->val<<endl;//     return 0;// }//STL-standard template library/*set of template classes for implementing commonly used data structures & functions3 major components-container,iterators,algorithmsContainer-used to hold data of same typeegvector-class that defines a dynamic array,list-class for dll,map-used to store unique key value pairs,set-used to store unique valuesIterators-used to traverse the containers,pointer like entitiesAlgorithms-functions that are used to manipulate data in the containersEg-sort(),min(),max()*//*List- template class in STL for implementing doubly linked listAdvantages of a list in cpp STL-implementation becomes easyIterator functions-begin()-iterator for the first element,end()-iterator for the position after the last element,.rbegin()-iterator for the first element in reverse iteration,.rend()-iterator for the postion after last element in reverse iteration,advance(itr,n)-advances the iterator by n places*//*list.insert(itr,value)-insert value before the position of the itr,list.insert(itr,count,value)-insert value count number of time before itr,list.insert(itr,start_itr,end_itr)-insert values from start_itr to end_itrbefore given itr,end_itr not included*//*deleting elements from a list-list.erase(itr)-delete the element pointed to by the itr,list.erase(start_itr,end_itr)//end itr not included*//*Other member functions of a list container-push_front(val)-insert val in the front of listpop_front()-removes value from front of listpush_back(val)-insert val in the back of the listpop_back()-removes val from the back of the list*/#include<iostream>#include<list>using namespace std;int main(){    list<int> l1={1,2,3,4};    auto itr=l1.begin();    //l1.end()-iterator pointing to the memory location after 4    // advance(itr,2);    // cout<<*itr<<endl;    // using range based loop    // for (auto num:l1)    // {    //     cout<<num<<endl;    // }    //using iterators    for(auto itr=l1.begin();itr!=l.end();itr++){        cout<<*itr<<endl;    }    //reverse traversal    for(auto itr=l1.rbegin();itr!=l1.rend(),itr++){        cout<<*itr<<" ";    }cout<<endl;    //inserting elements    auto itr=l1.begin();    advance(itr,2);    l1.insert(itr,5);    l1.insert(itr,3,5);    auto l=l1.begin();    auto r=l1.begin();    advance(r,2);    l1.insert(itr,l,r);    //deletion    auto s_itr=l1.begin();    advance(s_itr,2);    auto e_itr=l1.begin();    advance(e_itr,4);    l1.erase(s_itr,e_itr);
        return 0;}