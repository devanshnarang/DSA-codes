#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<"HI";
    map<int,int> mp;
    for(auto it:arr)mp[it]++;
    int st=1;
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(mp[arr[i]]==1)continue;
        while(st<n && mp.find(st)!=mp.end())st++;
        mp[arr[i]]--;
        arr[i]=st;
        mp[st]++;
        cnt++;
    }
    for(auto it:arr)cout<<it<<endl;
    
   return 0;
}