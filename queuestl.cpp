#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.pop();
    cout<<qu.empty()<<"   "<<qu.front()<<endl;
    return 0;
}


