/*greedy algorithm-they build soln piece by piece
greedy choice-focus on local optimum*/
/*Dijkstra's algorithm- used for finding the shorteest paths betwen nodes in a weighted graph(road network)
Optimal substructure- it says if we divide a problem into subproblems and if we have answer of subproblems then we can find answer of bigger problem.eg-fibanocci series
Advantages-easy to implement ,better time complexity
disadvantages-don't work always*/
//questions
//1-fractional knapsack
//how to choose? v/w is max
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item{
    int value;
    int weight;
};
bool cmp(Item i1,Item i2){
    //custom comparator for sorting
    double v_w_i1= static_cast<double>(i1.value)/(i1.weight);
    double v_w_i2= static_cast<double>(i2.value)/(i2.weight);
    return v_w_i1>v_w_i2;
}
double  fractional(int W,vector<Item> &items){
    sort(items.begin(),items.end(),cmp);
    for(const auto& item:items){
        if(item.weight <=W){
            ans+=item.value;
            W-=item.weight;
        }
        else{
            //we can't pick the whole item as space in knapsack is less
            double fraction=static_cast<double>(W)/item.weight;
            ans+=fraction*item.value;
            W=0;
        }
    }
}
int main()
{
   return 0;
}
//maximum meetings in 1 meeting room
struct meeting{
    int start;
    int end;
    int idx;
}
bool cmp(meeting m1,meeting m2){
    return m1.end<m2.end;
}
void print_max_meeting(vector<meeting> &arr){
    sort(arr.begin(),arr.end(),cmp);
    cout<<arr[0].idx<<"  ";
    meeting last=arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        /* code */
        if (arr[i].start>last.end)
        {
            /* code */
            cout<<arr[i].idx<<" ";
            last=arr[i];
        }
        
    }
    
}
//3-Activity Selection Problem
//4-check if it is possible to survive on island
if((S-S/7)*N<=S*M){
    return false;
}
else {
    return ceil((S*M)/N);
}
//print biggest palindromic number made from given digits
bool isPossible(unordered_map<int,int> &mp){
    int count=0;
    for(int i=0;i<=9;i++){
        if(mp.count(i)){
            if(mp[i]%2!=0)count++;
            if(count>1)return false;
        }
    }
    return true;
}
string max_palindrome(string num){
    int l=num.size();
    unordered_map<int,int> mp;
    for (int i = 0; i < l; i++)
    {
        /* code */
        mp[num[i]-'0']++;
    }
    if (isPossible(mp))
    {
        /* code */
        return "NP";
    }
    vector<char> v(l);
    int front=0;
    for(int i=9,i>=0;i--){
        if(mp[i]%2!=0){
            v[l/2]=char(i+48);
            mp[i--];
        }
        while(mp[i]>0){
            v[front]=char(i+48);
            v[l-front-1]=char(i+48);
            mp[i]-=2;
            front++;
        }
    }
    string res="";
    for (int i = 0; i < v.size(); i++)
    {
        /* code */
        res+=v[i];
    }
    return res;
    
    
}
