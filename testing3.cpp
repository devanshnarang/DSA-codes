#include<iostream>
using namespace std;
int main()
{
    int bags;
    cin>>bags;
    int n;
    cin>>n;
    int weights[n];
    for (int i = 0; i < n; i++)
    {
        cin>>weights[i];
    }
    int used=1;
    int capacity=0;
    for (int i = 0; i < n; i++)
    {
        if(capacity+weights[i]>n){
            used++;
            capacity=weights[i];
        }
        else{
            capacity+=weights[i];
        }
    }
    cout<<(used<=bags);
   return 0;
}