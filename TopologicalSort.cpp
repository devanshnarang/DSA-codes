//It applies only on DAG(Directed Acyclic Graph)
//It is a linear ordering of vertices u->v ;u always appear before v in that ordering
//make an adjacency list to verify the same

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
unordered_set<int> visited;
vector<list<int> > graph;
stack<int> st;
void add_edge(int src,int dest){
    graph[src].push_back(dest);
    return;
}
void dfs(int curr,int end){
    if(visited.count(curr))return;
    visited.insert(curr);
    for(auto neighbour:graph[curr]){
        if (visited.count(neighbour)==0)
        {
            dfs(neighbour,end);
        } 
    }
    st.push(curr);
    return;
}
void display(int v){
    for (int i = 0; i < v; i++)
    {
        cout<<i<<" - ";
        for(auto ele : graph[i]){
            cout<<ele<<"   ";
        }
        cout<<endl;
    }
    
}
int main()
{
    int v;
    cin>>v;
    graph.resize(v+1,list<int> ());
    int e;
    cin>>e;
    visited.clear();
    while (e--)
    {
        /* code */
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display(v);
    cout<<endl;
    cout<<"HI"<<endl;
    for (int i = 0; i < v; i++)
    {
        dfs(i,v);
    }
    while(!st.empty()){
        cout<<st.top()<<"  ";
        st.pop();
    }
    return 0;
}