/*A graph is a collection of nodes where each node might or might not point 
to other nodes.The nodes represent real life entities and are connected by edges representing
relationships b/w nodes/entities.
Nodes are called vertices.
Applications-Google maps,dependency resolution,shortest path algorithms,spannin trees,
algorithms,protein-protein interaction*/
/*Mathematical definition of graphs-It is defined as G=(V,E),it is an ordered
pair of set V and set E representing vertices and edges respectively*/
//Types Of Graphs
/*

->On the basis of direction - undirected graph,directed graph
-undirected graph-direction does not exist b/w edges,
-directed graph-direction exist b/w edges

->On the basis of edge weights - weighted graphs,unweighted graphs
-weighted graphs-a measurable quantity exists with edges
-unweighted graphs-no measurable quantity exists on edges

Multigraph- an undirected graph in which multiple edges are allowed b/w 2 nodes

Simple Graph-an undirected graph in which both multiple edges and loops are not allowed

Complete Graph- a complete graph is the one in which every node is DIRECTLY connected to the every other node,
a direct edge exists for every possible node pair

Connected Graph-In this graph we have a DIRECT/INDIRECT path for every possible pair of vertex

Path-It is a graph whose vertices can be arranged in a sequence

Cycle -It is also a graph whose vertices can be arranged in cycle sequence

DAG(Directly Acyclic Graph)-no cycle exists 

Degree- Degree of a vertex in a graph is the total number of edges incident to
it or away from it.
For Directed graph- 2 tpyes of degree are defined -indegree and outdegree
-Outdegree-total number of edges goin in outward direction
-Indegree-total number of incoming edges

Trees-It is a connected graph with no cycles.If we rremove all cycles
from a graph we get  tree.If we remove an edge from a tree ,it no more 
remains connected and should be called FOREST.

If there is a disconnected graph then the set of vertices whoch are connected forms a 
connected component.

FACTS-
in a tree |E|=|V|-1
in a forest |E|=|V|-1(max)
in a connected graph |E|=|V|-1(min)
in a undirected complete graph |E|=|V|C2
in a directed complete graph |E|=|V|*(|V|-1)
*/