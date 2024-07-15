/*
2 main elemental parts of graph are vertices,edges
*/
//Adjacency List-In this approach we represent graphs as an array of linked list
/*It has 2 parts-
->array-represents vertices
->linked listindex represents neighbour of ith vertex.
This neighbour info is stored in a Linked list
Neighbour-any node having direct edge from a vertex.    
*/
//What about directed weighted and undirected weighted graph
/*
Answer- Instead of storing an integer in the linked list,we can store
a pair of <neighbour_vertex,weight>
*/
//Adjacency Map-Here we represent graphs in the form of array of hasmap/
//unordered map,every ith vertex represent data of ith vertex


//Adjacency Matrix- In this approach we represent the graph in a 2D array
// or matrix of V*V dimensions where V is the number of vertices.
//where adj[i][j]=1 represents there is an edge from i to j vertex
//while adj[i][j]=0 represents no edge from i to j vertex

//Incident Matrix
/*Here we don't make a v*v matrix instead we prepare v*e
matrix where v is no. of vertices and e is no. of edges
m[i][j]=1 if ith vertex belongs to jth cell
m[i][j]=0 else
*/

//adjacency list
#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int> > graph;
void add_edge(int src,int dest,vector<list<int> > graph,bool bi_dir=true,){
    graph[src].push_back(dest);
    if (bi_dir)
    {
        graph[dest].push_back(src);
    } 
}

void display(){
    for (int i = 0; i < graph.size(); i++)
    {
        cout<<i<<"-> ";
        for(auto el:graph[i]){
            cout<<el<<" , ";
        }
        cout<<"\n";
    }  
}
int main()
{
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while (e--)
    {
        /* code */
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
    return 0;
}

//weighted adjacency list
// #include<iostream>
// #include<vector>
// #include<list>
// using namespace std;
// vector<list<pair<int,int>> > graph;
// void add_edge(int src,int dest,int wt,bool bi_dir=true,){
//     graph[src].push_back({dest,wt});
//     if (bi_dir)
//     {
//         graph[dest].push_back({src,wt});
//     } 
// }

// void display(){
//     for (int i = 0; i < graph.size(); i++)
//     {
//         cout<<i<<"-> ";
//         for(auto el:graph[i]){
//             cout<<el.first<<"   "<<ele.second<<" , ";
//         }
//         cout<<"\n";
//     }  
// }
// int main()
// {
//     cin>>v;
//     graph.resize(v,list<pair<int,int>> ());
//     int e;
//     cin>>e;
//     while (e--)
//     {
//         /* code */
//         int s,d,wt;
//         cin>>s>>d>>wt;
//         add_edge(s,d);
//     }
//     display();
//     return 0;
// }

//Adjacency map
// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;
// vector<unordered_map<int,int> > graph;
// void add_edge(int src,int dest,int wt,bool bi_dir=true,){
//     graph[src][dest]=wt;
//     if (bi_dir)
//     {
//         graph[src][dest]=wt;
//     } 
// }

// void display(){
//     for (int i = 0; i < graph.size(); i++)
//     {
//         cout<<i<<"-> ";
//         for(auto el:graph[i]){
//             cout<<el.first<<"   "<<ele.second<<" , ";
//         }
//         cout<<"\n";
//     }  
// }
// int main()
// {
//     cin>>v;
//     graph.resize(v,unordered_map<int,int> ());
//     int e;
//     cin>>e;
//     while (e--)
//     {
//         /* code */
//         int s,d,wt;
//         cin>>s>>d>>wt;
//         add_edge(s,d);
//     }
//     display();
//     return 0;
// }