/*Heap-binary tree which is a complete binary tree(means all
levels will be filled completely except maybe last level & last level has keys as left as possible)
Can be of 2 types-
Min heap-parent node has smaller value than child nodes
Max heap-parent node has larger values than child node*/
//Representation of a heap using an array
/*root index will be at index1,for node at index i,left child at 2*i,right child at 2*i+1
for node at index i-parent node at i/2 */
//Insertion in a min heap
//best case-O(1) worst case-O(h) height of binary tree is logm where m is number of elements
#include<iostream>
using namespace std;
// int const N=1e3;
// void insertMinHeap(int minHeap[],int &size,int value){
//     size++;
//     minHeap[size]=value;
//     int curr=size;
//     while (curr/2>0 && minHeap[curr/2]>minHeap[curr])
//     {
//         /* code */
//         swap(minHeap[curr/2],minHeap[curr]);
//         curr/=2;
//     }
    
// }
// void insertMaxHeap(int maxHeap[],int &size.int value){
//     size++;
//     minHeap[size]=value;
//     int curr=size;
//     while(curr/2>0 && maxHeap[curr/2]<maxHeap[curr]){
//         swap(maxHeap[curr/2],maxHeap[curr]);
//         curr/=2;
//     }
// }
//deletion in a min heap worst case(O(logN)) 
// void removeMinHeap(int minHeap[],int &size){
//     minHeap[1]=minHeap[size];
//     size--;
//     int curr=1;
//     while(2*curr<=size){
//         //looping till curr node has child nodes
//         int leftchild=2*curr;
//         int rightchild=2*curr+1;
//         int minchild=leftchild;
//         if (rightchild<=size && arr[rightchild]<arr[leftchild])
//         {
//             minchild=rightchild;
//         }
//         if (arr[minchild]>=arr[curr])
//         {
//             return;
//         }
//         swap(arr[minchild],arr[curr]);
//         curr=minchild;
//     }
// }
// void removeMaxHeap(int maxHeap[],int &size){
//     maxHeap[1]=maxHeap[size];
//     int curr=1;
//     while(2*curr<=size){
//         int leftchild=2*curr;
//         int rightchild=2*i+1;
//         int maxchild=leftchild;
//         if(rightchild<=size && arr[rightchild]>arr[leftchild]){
//             maxchild=rightchild;
//         }
//         if(arr[curr]>=arr[maxchild]){
//             return;
//         }
//         swap(arr[curr],arr[maxchild]);
//         curr=maxchild
//     }
// }
// void heapify(int arr[],int size,int curr){
//     while(2*curr<=size){
//         int leftchild=2*curr;
//         int rightchild=2*curr+1;
//         int minchild=leftchild;
//         if(rightchild<=minchild &&arr[rightchild]<arr[minchild]){
//             minchild=rightchild
//         }
//         if (arr[curr]<=arr[minchild])
//         {
//             /* code */
//             return;
//         }
//         swap(arr[minchild],arr[curr]);
//         curr=minchild;
//     }
// }
void heapify(int arr[],int n,int curr){
    while ((2*curr+1)<=n)
    {
        /* code */
        int leftchild=2*curr+1;
        int rightchild=2*curr+2;
        int maxchild=leftchild;
        if (rightchild<=n && arr[rightchild]>arr[maxchild])
        {
            /* code */
            maxchild=rightchild;
        }
        if (arr[maxchild]<=arr[curr])
        {
            /* code */
            return;
        }
        swap(arr[maxchild],arr[curr]);
        curr=maxchild;
    } 
}
void remove(int arr[],int &size){
    size--;
    heapify(arr,size,0);
}
void heapSort(int arr[],int n){
    //1.heapify
    for (int i = n/2-1; i >=0; i--)
    {
        /* code */
        heapify(arr,n,i);
    }
    swap(arr[0],arr[n]);
    heapify(arr,n-1,0);
}
int main()
{
    int arr[7]={3,-1,0,2,-4,8,-7};
    heapSort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
   return 0;
}
//Heapify-arranging nodes in correct order so that they follow properties of a minHeap/maxHeap
//in binary heap leaf nodes start from n/2+1
//last non-leaf nodes will be at position n/2
//TC-O(logN)
//Heapsort
/*1)convert array into heap data structure using heapify
2)one by one delete root node of heap and replace it with the last node in the
heap and then heapify the root of the heap.repeat this process till the size of the heap is greater than 1
TC-O(NlogN)
*/
// void heapify(vector<int> &v,int size,int i){
//     //loop till curr has child node
//     while((2*curr+1)<size){
//         int leftchild=2*curr+1;
//         int rightchild=2*curr+2;
//         int maxchild=leftchild;
//         if (rightchild<size &&v[rightchild]>v[leftchild])
//         {
//             /* code */
//             maxchild=rightchild;
//         }
//         if (v[maxchild]<=v[curr])
//         {
//             /* code */
//             return;
//         }
//         swap(v[maxchild],v[curr]);
//         curr=maxchild;
        
        
//     }
// }
// vector<int> mergeHeaps(vector<int> &a,vector<int> &b,int n,int m){
//     vector<int> mergedHeap;
//     for(auto ele:a){
//         mergedHeap.push_back(ele);
//     }
//     for(auto ele:b){
//         mergedHeap.push_back(ele);
//     }
//     int lastParentNode=(n+m)/2-1;
//     for(int i=lastParentNode;i>=0;i--){
//         heapify(mergedHeap,n+m,i);
//     }
// }
// //kth smallest element
// void remove(int arr[],int size){
//     arr[0]=arr[size];
//     size--;
//     heapify(arr,size,0);
// }
// int kthsmallestelement(int arr[],int size,int k){
//     //create minheap
//     for(int i=size/2-1,i>=0;i--){
//         heapify(arr,size,i);
//     }
//     k-=1;
//     while(k--){
//         remove(arr,size);
//     }
//     return arr[0];
// }
