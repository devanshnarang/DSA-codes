//lec 32 best problem recursion/*#include<iostream>using namespace std;int f(int *h,int n,int i){    if(i==n-1){        return 0;    }    if(i==n-2){        return f(h,n,i+1)+abs(h[i]-h[i+1]);    }    return min(f(h,n,i+1)+abs(h[i]-h[i+1]),f(h,n,i+2)+abs(h[i]-h[i+2]));}int main(){    int arr[]={10,10,10,10};    int n=4;    cout<<f(arr,n,0);    return 0;}*//*#include<iostream>using namespace std;bool f(int *arr,int n,int i,int x){    int sum=0;    if (i==n){        return false;    }    return(arr[i]==x)||(f(arr,n,i+1,x));    }int main(){    int arr[]={5,4,1,8,6};    int n=5;    int x=8;    bool result=f(arr,n,0,x);    cout<<result;    return 0;}*//*#include<iostream>#include<vector>
using namespace std;void f(int n,int m,int i,int j,vector <int> &result){    if(i==n-1&&j==m-1){        result.push_back(0);        return ;    }    if (i<n-1&&j<m-1)    {        f(n,m,i+1,j,result);        f(n,m,i,j+1,result);    }    else if (i==n-1&j<m-1)    {        f(n,m,i,j+1,result);    }    else if (i<n-1&&j==m-1)    {        f(n,m,i+1,j,result);    }}int main(){    int arr[2][3]={{1,2,3},{4,5,6}};    int n=2,m=3;    vector<int> result;    f(n,m,0,0,result);    cout<<result.size();    
    return 0;}*//*#include<iostream>#include<vector>#include<string>using namespace std;void f(string &str,int l,int i,string result,vector<string> &str1){    if (i==l)    {        str1.push_back(result);        return;    }    f(str,l,i+1,result+str[i],str1);    f(str,l,i+1,result,str1);    }int main(){    string str="abc";    int m=3;    int n=0;    vector<string> str1;    f(str,m,n,"",str1);    for (int i = 0; i < str1.size(); i++)    {        cout<<str1[i]<<endl;    }    return 0;    
}*//*#include<iostream>#include<vector>#include<string>using namespace std;void f(string ini,int i,string result,vector<string> &fin,vector<string> &v){    if(i==ini.size()){        fin.push_back(result);        return;    }    int digit=ini[i]-'0';    if(digit<=1){        f(ini,i+1,result,fin,v);        return;    }    for (int j = 0; j < v[digit].size(); j++)    {        f(ini,i+1,result+v[digit][j],fin,v);    }    return;    }int main(){    vector<string> v(10);    v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};    string str="23";    vector<string> fin;    string result="";    f(str,0,result,fin,v);     for (int i = 0; i < fin.size(); i++)    {        cout<<fin[i]<<endl;    }        return 0;
}*/#include<iostream>using namespace std;void merge(int arr[],int l,int mid,int r){    int an=mid-l+1;    int bn=r-mid;    int a[an];        while (i<an && j<bn)    {        if (a[i]<b[j])        {            arr[k++]=a[i++];        }        else{            arr[k++]=b[j++];        }    }    while (i<an)    {        arr[k++]=a[i++];             }    while (j<bn)    {        arr[k++]=b[j+ +];             }int b[bn];    for (int i = 0; i < an; i++)    {        a[i]=arr[l+i];    }    for (int j = 0; j < bn; j++)    {        b[j]=arr[mid+1+j];    }    int i=0;    int j=0;    int k=l;
                }void mergesort(int arr[],int l,int r){    if(l>=r){        return;    }    int mid=(l+r)/2;    mergesort(arr,l,mid);    mergesort(arr,mid+1,r);    merge(arr,l,mid,r);
}int main(){    int arr[]={10,28,24,6,34,18,38,44};    int n=sizeof(arr)/sizeof(arr[0]);    mergesort(arr,0,n-1);    for (int i = 0; i < n; i++)    {        cout<<arr[i]<<" ";    }    cout<<endl;        return 0;}