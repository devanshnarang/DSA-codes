#include<iostream>#include<vector>#include<string>using namespace std;void insertionsort(vector<string> &v){    int n=v.size();    for (int i = 0; i <n-1; i++)    {        for (int j = 0; j < n-1-i; j++)        {            if(v[j][0]>v[j+1][0]){                string temp=v[j];                v[j]=v[j+1];                v[j+1]=temp;            }        }                    }    }int main(){    int n;    cin>>n;    vector<string> v(n);    for (int i = 0; i < n; i++)    {        cin>>v[i];    }    insertionsort(v);    cout<<"ans"<<endl;    for (int i = 0; i < n; i++)    {        cout<<v[i]<<endl;    }            return 0;}