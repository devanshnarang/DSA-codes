#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int arr2[n];
    int k;
    cin>>k;
    int j=0;
    for (int i = n-k; i < n; i++)
    {
        arr2[j]=arr[i];
        j++;
    }
    int l=k;
    for (int i = 0; i < n-k; i++)
    {
        arr2[l]=arr[i];
        l++;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr2[i]<<"  ";
    }


//return sum of rectangle from (l1,r1)to (l2,r2)
#include<iostream>
#include<vector>
using namespace std;
void spiralsum(vector<vector<int>>& matrix){
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    int left=l1;
    int right=l2;
    int top=r1;
    int bottom=r2;
    int direction=0;
    int sum=0;
    while (left<=right && top<=bottom)
    {
        if (direction==0)
        {
            for (int col = left; col <=right ; col++)
            {
                sum+=matrix[top][col];
            }
            top++;
            direction++;
            cout<<sum;
            
        }
        else if (direction==1)
        {
            for (int row = top; row <=bottom ; row++)
            {
                sum+=matrix[row][right];
            }
            right--;
            direction++;
            cout<<sum;
        }
        else if(direction==2){
            for (int col = right; col >= left; col--)
            {
                sum+=matrix[bottom][col];
            }
            bottom--;
            direction++;
            cout<<sum;
        }
        else if(direction==3){
            for (int row = bottom; row >= top; row--)
            {
                sum+=matrix[row][left];
            }
            left++;
            direction++;
            cout<<sum;
        }
        if (direction>=4)
        {
            direction=direction%4;
        }
        
    }
    cout<<sum;
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int> (m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>matrix[i][j];
        }
        
    }
    spiralsum(matrix);
    
    return 0;
}



    
    
    

    
    
    
    return 0;
}

