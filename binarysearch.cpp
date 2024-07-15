/*search space reduces by 1 after each iteration.in worst case it would be that element is not present so time complexity would be order of N.the brute force solution(approach) is called linear search.Binary search algorithm-it is valid for those problems where we can divide the search pace into 2 parts such that 1 and 2 parts are different from each other due to some reason.eg -given a sorted array find a given element in it*/
/*
#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> &input,int target){    
//define search space    
int lo=0;    
int hi=input.size()-1;    
while (lo<=hi)    
{        
//calculate midpoint for the search space        
int mid=(hi+lo)/2;        
if (input[mid]==target)        
{            
    return mid;        
    }        
else if (input[mid]<target)        
{            
    //discard the left of mid            
    lo=mid+1;        
}        
else{            
    //discard the right of mid;            
    hi=mid-1;        
    }    
}    
return -1;    
}
int binarysearchrecursive(vector<int> &input,int target,int lo,int hi){    
//time-logN    
//space-//logN    
if (lo>hi)    
{        
    return -1;    
}        
int mid=(lo+hi)/2;    
if (input[mid]==target)    
{        
    return mid;    
}    
if (input[mid]<target)    
{        
    binarysearchrecursive(input,target,mid+1,hi);    
}    
else    
{        
    binarysearchrecursive(input,target,lo,mid-1);    
}        
}
int main(){    
    vector<int> input {2,4,5,7,15,24,45,50};    
    int target =15;    
    cout<<binarysearchrecursive(input,target,0,7);    
    return 0;}*/
//time complexity is of order of logN of binary search in worst case.
//space complexity is constant. 
/*suppose lo and high are very big values so while calculating mid when lo and hi are added it will give very large value so modified formula ofmid is lo+(hi-lo)/2*/
#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> &input,int target){    
    int lo=0;    
    int hi=input.size()-1;    
    int mid=lo+(hi-lo)/2;    
    if (input[mid]==target)    
    {        
    if (input[mid-1]==target)        
    {            
        hi=mi            
        binarysearch(input,target)        }            }    }int main(){    return 0;}