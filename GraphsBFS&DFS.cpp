//Graph Traversals
//To read any graph we have 2 major techniiques BFS & DFS
//DFS(recursion)

//Let's take a motivation problem->
// 1) Given a graph calculate all paths between 2 vertices
// 2) Given a graph check whether there is a path b/w any 2 vertices or not ?

//ANSWERS
//2) simplest soln for any path problem would be if src & dest are neighbours
//if there is a path from neighbours(of src) to dest then there will be a path
//from src to dest via the neighbours

#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<unordered_map>
using namespace std;
vector<list<int> > graph;
unordered_set<int> visited;
int v; //no. of edges
void add_edge(int src,int dest,vector<list<int> > graph,bool bi_dir=true,){
    graph[src].push_back(dest);
    if (bi_dir)
    {
        graph[dest].push_back(src);
    } 
}
bool dfs(int curr,int end){
    if(curr == end) return true;
    visited.insert(curr); // mark visited
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            bool result=dfs(neighbour,end);
            if (result) return true;    
        }
    }
    return false;
}
bool anyPath(int src,int dest){
    return dfs(src,dest);
}
int main()
{
    cin>>v;
    graph.resize(v,list<int> ());
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
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<"\n";
   return 0;
}

//1)
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<unordered_map>
using namespace std;
vector<list<int> > graph;
unordered_map<int,int> visited;
vector<vector<int>> result;
int v; //no. of edges
void add_edge(int src,int dest,vector<list<int> > graph,bool bi_dir=true,){
    graph[src].push_back(dest);
    if (bi_dir)
    {
        graph[dest].push_back(src);
    } 
}
void dfs(int curr,int end,vector<int> &path){
    if(curr == end){
        path.push_back(curr);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr); // mark visited
    path.push_back(curr);
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour,end,path);   
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
void allPath(int src,int dest){
    vector<int> v;
    return dfs(src,dest,v);
}
int main()
{
    cin>>v;
    graph.resize(v,list<int> ());
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
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<"\n";
   return 0;
}

//BFS-In BFS we travel immediate neighbours first together
//Applicatin to find shortest path in an unweighted graph
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<unordered_map>
using namespace std;
vector<list<int> > graph;
unordered_map<int,int> visited;
int v; //no. of edges
void add_edge(int src,int dest,vector<list<int> > graph,bool bi_dir=true,){
    graph[src].push_back(dest);
    if (bi_dir)
    {
        graph[dest].push_back(src);
    } 
}
void bfs(int src,int dest,vector<int> &distance){
    queue<int> qu;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src]=0;
    visited.insert(src);
    qu.push(src);
    while (!qu.empty())
    {
        int curr=qu.front();
        qu.pop();
        for(auto neighbour: graph[curr]){
            if(!visited.count[neighbour]){
                qu.push(neighbour);
                visited.insert(neighbour);
                distance[neighbour]=distance[curr]+1;
            }
        }
    }
    
}
int main()
{
    cin>>v;
    graph.resize(v,list<int> ());
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
    int x,y;
    cin>>x>>y;
    vector<int> dist;
    bfs(x,y,dist);
    for (int i = 0; i < dist.size(); i++)
    {
        /* code */
        cout<<dist[i]<<"    ";
    }
    
   return 0;
}
