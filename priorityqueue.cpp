/*Priority queues-
STL container-implement heap data structure
every element will have some priority
queue where front element will have the highest priority
Syntax-
#include<queue>
priority-queue<data_type> pq;
it will be max heap by default
for min heap
priority-queue<int,vector<int>,greater<int>> pq2;*/
//Insertion
/*pq.push(element)*/
//Deletion
/*pq.pop()-removes the front element*/
//member function
/*pq.top()-returns the front element
pq.size()-returns the size of priority queue
pq.empty()-returns boolean value
1-if empty
0-if not*/
// #include<iostream>
// #include<queue>
// using namespace std;
// int main()
// {
//     priority_queue<int,vector<int>,greater<int> > pq1;
//     pq1.push(3);
//     pq1.push(1);
//     pq1.push(4);
//     cout<<pq1.top();
//    return 0;
// }
//questions
//1
// int KthLargestElement(vector<int> a,int n,int k){
//     priority_queue<int,vector<int>,greater<int>> pq;
//     for(int i=0;i<n;i++){
//         pq.push(a[i]);
//         if(pq.size()>k){
//             pq.pop();//remove smallest element out of k+1 elements
//         }
//     }
//     return pq.top();
// }
//2
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int,int> > kClosestPoints(vector<pair<int,int> > pts,int n,int k){
    priority_queue<pair<int,pair<int,int> > > pq;//max heap
    for(auto &pt:pts){
        int distance=pt.first + pt.second;
        pq.push(make_pair(distance,pt));
        if(pq.size()>k){
            pq.pop();//remove largest distance pt in k+1 pts
        }
    }
    vector<pair<int,int> > ans(k);
    while(!pq.empty()){
        ans[pq.size()-1]=pq.top().second;
        pq.pop();
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > pts(n);
    for(auto &pt:pts){
        cin>>pt.first>>pt.second;
    }
    vector<pair<int,int> > anspts=kClosestPoints(pts,n,k);
    for(auto &pt:anspts){
        cout<<pt.first<<"  "<<pt.second<<endl;
    }
   return 0;
}
//3
int largestPoint(vector<int>,int n,int k){
    priority_queue<int,vector<int>,greater<int> > pq;
    for(auto i:a){
        pq.push(i);
    }
    while(k--){
        int firstElement=pq.top();
        pq.pop();
        int secondElement=pq.top();
        pq.pop();
        int product=firstElement*secondElement;
        pq.push(product);
        while(pq.size()>1){
            pq.pop();
        }
        return pq.top();
    }
}
//3
int leastInterval(vector<char> tasks,int n){
    //1.count frequence of tasks
    unordered_map<char,int> taskFreq;
    for(auto t:tasks){
        taskFreq[t]++;
    }
    //2. insert freq into max heap
    priority_queue<int> pq;
    for(auto e:taskFreq){
        pq.push(e.second);
    }
    //3. finding time until pq is empty
    int totalTime=0;
    while(!pq.empty()){
        vector<int> temp;
        //looping one time frame=n+1 units of time
        for (int i = 0; i <= n; i++)
        {
            /* code */
            if (!pq.empty())
            {
                /* code */
                int freq=pq.top();
                pq.pop();
                if (freq>1)
                {
                    /* code */
                    temp.push_back(freq-1);//adding remaining tasks in temporary vector
                }          
            }
            totalTime++;  
            if (pq.empty() && temp.empty())
            {
                /* code */
                return totalTime;
            }
            
        }
        for(auto t:temp){
            pq.push(t); //adding back remaining tasks from temp vector to priority queue
        }    
    }
    return totalTime;
}
//4
class MedianFinder{
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int> > minpq;
    public:
    MedianFinder(){

    }
    void addNum(int num){
        if(maxpq.empty() || num<=maxpq.top()){
            maxpq.push(num);
        }
        else{
            minpq.push(num);
        }
        //rebalancing the pq
        if(maxpq.size()>minpq.size()+1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(
            maxpq.push(minpq.top());
            minpq.pop();
        )
    }
    double findMedian(){
        if(maxpq.size()==minpq.size()){
            return (minpq.top()+maxpq.top())/2;
        }
        else{
            return maxpq.top();
        }
    }
};
