//DSU(Disjoint Set Union)
//The problem of clustering or grouping -You will have some elements
//and you need to add them/segregate them in different groups/clusters
//and sometimes we might need to identify the group any element belongs to

//TERMINOLOGIES
/*
1. leader /parent of the group - to uniquely identify a group we will pick any element from the group & make it the representative 
or leader or parent of the group
*/
// Q. What function does need to support?
/*
1.Union(a,b)-adds the group where element b belongs to the group where element
A belongs or vice-versa.
2. find(x)/get(x)- this will be used to find which group x belongs to.we will return the parent of
the group x belongs to
*/