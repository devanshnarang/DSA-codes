//setprecision is fn in header file iomanip.it is used to specify precision digits.//for decimal division-//cout<<fixed<<setprecision(6)<<avg/double(N-2*K)<<endl/*climits header file is used to use INT_MAX and INT_MINalgorithm header file used for sort function*/#include <iostream>using namespace std;
int main() {    int T;    cin>>T;    for(int i=0;i<T;i++){        int N,S;        cin>>N>>S;        int max=0;        for(int j=0;j<N-1;j++){            for(int k=N;k>j;k--){                if(i+j==S){                   if(j-i>max){                       max=j-i;                       cout<<max<<endl;                   }                 }            }        }        cout<<max<<endl;    }    return 0;}


