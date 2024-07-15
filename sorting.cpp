/*bubble sort-repeatedly(until an array is sorted) sort 2 adjacent elements if in wrong order.*/
/*#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int> &v){
    int n=v.size();    
    for (int i = 0; i < n-1; i++)    
    {        
        bool flag=false;        f
        for (int j = 0; j < n-1-i; j++)        
        {            
            if (v[j]>v[j+1])            
            {                
                flag=true;                
                int temp=v[j+1];                
                v[j+1]=v[j];                
                v[j]=temp;            
                }                    
        }        
        if(!flag) break;            
    }    
    return;    
}
// 5 4 3 2 1
int main(){    
    int n;    
    cin>>n;    
    vector<int> v(n);    
    for (int i = 0; i < n; i++)    
    {        
        cin>>v[i];     
    }    
    bubblesort(v);    
    for (int i = 0; i < n; i++)    
    {        
        cout<<v[i]<<endl;    
    }            
    return 0;
}*/
/*stable sort=does not disturb the order of elements with same valueunstable sort-order may or may not change.bubble sort is stable sort*/
/*selection sort-repeatedly(until array is sorted) find minimum element in unsorted array and place it at beginning.*/
/*
#include<iostream>
#include<vector>
using namespace std;
void selectionsort(vector<int> &v){    
    int n=v.size();    
    for (int i = 0; i < n-1; i++)    
    {        int minidx=i;        
    for (int j = i+1; j < n; j++)        
    {            
        if (v[j]<v[minidx])            
        {                
            minidx=j;            
        }                    
    }        
    if (minidx!=i)        
    {            
        int temp=v[minidx];            
        v[minidx]=v[i];            
        v[i]=temp;        
    }                    
}    
}
int main(){    
    int n;    
    cin>>n;    
    vector<int> v(n);    
    for (int i = 0; i < n; i++)    
    {        
        cin>>v[i];    
    }    
    selectionsort(v);    
    for (int i = 0; i < n; i++)    
    {        
        cout<<v[i]<<endl;    
    }            
    return 0;}
*/
/*selection better than bubble as with each swap element is reaching its correct position.It is an unstable sort.*/
/*insertion sort-repeatedly(until array is sorted) take elements from unsorted subarray and insert(at its correct position) in sorted array.*/
/*#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int> &v){    
    int size=v.size();    
    for (int i = 1; i < size; i++)    
    {        
        int j=i-1;        
        int curr=v[i];        
        while(j>=0 && v[j]>curr){            
            v[j+1]=v[j];            
            j--;        
        }        
        v[j+1]=curr;    
    }    
}
int main(){    
    int n;    
    cin>>n;    
    vector<int> v(n);    
    for (int i = 0; i < n; i++)    
    {        
        cin>>v[i];    
    }    
    insertionsort(v);    
    for (int i = 0; i < n; i++)    
    {        
        cout<<v[i]<<endl;    
    
    }            
    return 0;
}*/ 
/*insertion sort is stable array*/
/*merge sort-first divide the problem into subproblems,conquer(solve) the subproblems and finally combine solutions to get final output*/
/*#include<iostream>
using namespace std;
void merge(int arr[],int l,int r,int mid){    
    //create two temporary arrays    
    int an=mid-l+1;    
    int bn=r-mid;    
    int a[an];    
    int b[bn];    
    for (int i = 0; i < an; i++)    
    {        
        a[i]=arr[l+i];    
    }    
    for (int i = 0; i < bn; i++)    
    {        
        b[i]=arr[mid+1+i];    
    }    
    int i=0;    
    int j=0;    
    int k=l;
    //cout<<an<<"   "<<bn<<"  ";     
    while(i<an && j<bn){        
        //cout<<a[i]<<"  "<<b[j]<<"  ";        
        if (a[i]<b[j])        
        {            
            arr[k++]=a[i++];            
            cout<<"exe"<<"  ";        
        }        
        else{            
            arr[k++]=b[j++];        
        }        
        //cout<<arr[(k-1)]<<"  ";    
    }    
    while(i<an){        
        arr[k++]=a[i++];        
        //cout<<"exe2"<<"  ";    
    }    
    while(j<bn){        
        arr[k++]=b[j++];        
        //cout<<"exe3"<<"  ";    
        }    cout<<endl;    
    return;    
}
void mergesort(int arr[],int l,int r){    
    if(l>=r){        
        return;    
    }    
    int mid=(l+r)/2;    
    //cout<<"exe"<<endl;    
    mergesort(arr,l,mid);    
    mergesort(arr,mid+1,r);    
    merge(arr,l,r,mid);    
    return;    
}
int main(){    
    int n;    
    cin>>n;    
    int arr[n];    
    for (int i = 0; i < n; i++)    
    {        
        cin>>arr[i];    
    }    
    int l=0;    
    int r=n-1;    
    mergesort(arr,l,r);    
    for (int i = 0; i < n; i++)    
    {        
        cout<<arr[i]<<"  ";    
    }            
    return 0;
}*/
//time complexity=nlogn(base2)
/*master's theorem-It is a method to find time complexity of divide and conquer algorithmsT(n)=aT(n/b)+theta(n^k(logn)^p)a>=1,b>1,k>=0,p=real numberif (loga(base b)>k) then T(n)=theta(nloga(base b))if(loga(base(b))=k and if p>-1 theta(n^klogn^P+1))if p=-1 theta(n^k loglogn)if p<-1 theta(n^k)if loga(base b) and ifp>=0 theta(n^klogn^p)p<0 theta(n^k)*/
/*slower for smaller tasks,takes O(n) extra spacegoes thorugh even if array is sorted*/
//quick sort algorithm-divide and conquer approach
/*#include<iostream>
using namespace std;
int partition(int arr[],int first,int last){    
    int pivot=arr[last];    
    int i=first-1;    
    int j=first;    
    for (; j < last; j++)    
    {        
        if (arr[j]<pivot)        
        {            
            i++;            
            swap(arr[i],arr[j]);        
        }            
    }    
    //now i is pointing to last element less than pivot    
    swap(arr[i+1],arr[last]);    
    return i+1;    
}
void quicksort(int arr[],int first,int last){    
    //base case    
    if (first>=last)    
    {        
        return;    
    }    
    //recursive case    
    int pi=partition(arr,first,last);    
    quicksort(arr,first,pi-1);    
    quicksort(arr,pi+1,last);    
}
int main(){    
    int arr[]={20,12,35,16,18,30};    
    int n=sizeof(arr)/sizeof(arr[0]);    
    quicksort(arr,0,n-1);    
    for (int i = 0; i < n; i++)    
    {       
        cout<<arr[i]<<"  ";    
    }        
    return 0;
}
*/
/*best case-when pivot element is medianeg 5,3,4,1,2 T(n)=2T(n/2)+n=theta(nlogn)#when last element is pivot element then it is worst case and time complexity is O(n^2),Eg=(1,2,3,4,5)*/
//space complexity is O(n);/*for random element-random pivot index=first+rand()/%(last-first+1)quick sort is not a stable sortit is used where memory is a concern*/
/*merge sort used where large datasets,stable,linked listquick sort-smaller datasets,unstable,new memory is costly*/
//count sort
/*
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void countsort(vector<int> &v){    
    int n=v.size();    
    int max_ele=INT_MIN;    
    //find max element    
    for (int i = 0; i < n; i++)    
    {        
        if (v[i]>max_ele)        
        {            
            max_ele=v[i];        
        }            
    }    
    //create the frequency array    
    vector<int> frequency(max_ele+1,0);    
    for (int i = 0; i < n; i++)    
    {        
        freq[v[i]]++    
    }    
    //calculate cumulative frequency    
    for (int i = 0; i < max_ele; i++)    
    {        
        freq[i]+=freq[i-1];    
    }    
    vector<int> ans(n);    
    //calculate the sorted array    
    for (int i = n-1; i>0; i--)    
    {        
        ans[--freq[v[i]]]=v[i];    
    }    
    //copyback the ans arr to original array    
    for (int i = 0; i < n; i++)    
    {        
        v[i]=ans[i];    
    }                
}
int main(){    
    int n;    
    cin>>n;    
    vector<int> v(n);    
    for (int i = 0; i < n; i++)    
    {       
        cin>>v[i];    
    }    
    countsort(v);    
    for (int i = 0; i <n; i++)    
    {        
        cout<<v[i];    
    }            
    return 0;
}*/
/*time complexity - O(n+max)space complexity-O(n+k) where k is max_elementto use count sort on negative numbers subtract minimum element from all elements of array and then apply countsort algorithmif difference in numbers(elements of array is large there we can;t use count sort)*/
