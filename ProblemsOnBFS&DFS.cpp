//CONNECTED COMPONENT-it is a subset of the given graph that has vertices
//between which there is always a path.

//vertices present in 2 different connected component do not
//have a path

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
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
void dfs(int node,unordered_set<int> &visited){
    visited.insert(node){
        for(auto neighbour: graph[node]){
            if (! visited.count(neighbour))
            {
                dfs(neighbour,visited);
            }
            
        }
    }
}
int connected_component(){
    int result=0;
    unordered_set<int> visited;
    for (int i = 0; i < v; i++)
    {
        //go to every vertex
        //if from a vertex we can initialise a dfs,we got one more connected component
        if (visited.count(i)==0)
        {
            /* code */
            result++;
            dfs(i,visited);
        }
    }
    return result; 
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

//Ques 1 - Number of Islands
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    public:
    int numIslands(vector<vector<char>>  &grid){
        int m=grid.size();
        int n=grid[0].size();
        int cc=0;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c]=='0')
                {
                    //it is a water body
                    continue;
                }
                //new unvisited land piece found, i.e. new connected component
                cc++;
                grid[r][c]='0';//mark it visited
                queue<pair<int,int>> qu;
                qu.push({r,c}); //store the src node
                while (!qu.empty()){
                    auto curr=qu.front();//get one node from queue
                    qu.pop();
                    //go to all univisited neighbours
                    int currRow=curr.first;
                    int currCol=curr.second;
                    if (currRow-1>=0 && grid[currRow-1][currCol]=='1')
                    {
                        qu.push({currRow-1,currCol});
                        grid[currRow-1][currCol]='0';
                    }
                    if (currRow+1<m && grid[currRow+1][currCol]=='1')
                    {
                        qu.push({currRow+1,currCol});
                        grid[currRow+1][currCol]='0';
                    }
                    if (currCol-1>=0 && grid[currRow][currCol-1]=='1')
                    {
                        qu.push({currRow,currCol-1});
                        grid[currRow][currCol-1]='0';
                    }
                    if (currCol+1<n && grid[currRow][currCol+1]=='1')
                    {
                        qu.push({currRow,currCol+1});
                        grid[currRow][currCol+1]='0';
                    }
                }
    
            }   
        }
        return cc;
    }
};

//Ques 2-Atlantic Pacific Ocean
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    vector<vector<int> > dir ={{1,0},{-1,0},{0,1},{0,-1}};
    int rows;
    int cols;
    vector<vector<int> > h;
    vector<vector<int> > pacificAtlantic(vector<vector<int> > &heights){
        rows=heights.size();
        cols=heights[0].size();
        h=heights;
        queue<pair<int,int> > pacificbfs;
        queue<pair<int,int> > atlanticbfs;
        //step of multisource bfs
        for (int i = 0; i < rows; i++)
        {
            /* code */
            pacificbfs.push({i,0});
            atlanticbfs.push({i,cols-1});
        }
        for (int j = 1; j < cols; i++)
        {
            /* code */
            pacificbfs.push({0,j});
        }
        for (int j = 0; j < cols-1; j++)
        {
            /* code */
            atlanticbfs.push({rows-1,j});
        }
        vector<vector<bool> > pacific=bfs(pacificbfs);
        vector<vector<bool> > atlantic=bfs(atlanticbfs);
        vector<vector<int> > result;
        for (int i = 0; i < rows; i++)
        {
            /* code */
            for (int j = 0; j < cols; j++)
            {
                /* code */
                if (pacific[i][j] and atlantic[i][j])
                {
                    /* code */
                    result.push_back({i,j});
                }
                
            }
            
        }
        
    }
    vector<vector<bool> > bfs(queue<pair<int,int> > &qu){
        vector<vector<bool> > visited(rows,vector<bool> (cols,false));
        while (!qu.empty())
        {
            auto cell=qu.front();
            qu.pop();
            int i=cell.first;
            int j=cell.second;
            visited[i][j]=true;
            for (int d = 0; d < 4; d++)
            {
                int newRow=i+dir[d][0];
                int newCol=j+dir[d][1] ;
                if (newRow<0 or newCol<0 or newRow>=rows or newCol>=cols)
                {
                    continue;
                }
                if (visited[newRow][newCol])
                {
                    continue;
                }
                if (h[newRow][newCol]<h[i][j])
                {
                    continue;
                }
                qu.push({newRow,newCol});
            }
            
        }
        return visited;
    }
};

//Rotten Oranges
class Solution{
    public:
    int orangesRotting(vector<vector<int>> &grid){
        queue<pair<int,int> > qu;
        int fo=0;
        int n=grid.size();
        int m=grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]==1)fo++;
                else if(grid[i][j]==2)qu.push(i,j);//multisource bfs step                
            }
        }
        //we have added all the src
        qu.push({-1,-1});
        int mins=0;
        vector<vector<int> > dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!qu.empty()){
            auto cell=qu.front();
            qu.pop();
            if(cell.first==-1 and cell.second==-1){
                mins++;
                if(not qu.empty()){
                    qu.push({-1,-1});
                }else{
                    break;
                }
            }else{
                int i=cell.first;
                int j=cell.second;
                for (int d = 0; d < 4; d++)
                {
                    int nr=i+dir[d][0];
                    int nc=j+dir[d][1];
                }
                if (nr<0 or nc<0 or nr>=n or nc>=m)continue;
                if (grid[r][c]==2 || grid[nr][nc]==0)continue;
                fo--;
                grid[nr][nc]=2;
                qu.push({nr,nc});
            }
        }
        return (fo==0)?mins-1 : -1;
    }
};
