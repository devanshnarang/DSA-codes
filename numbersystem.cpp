//number system is used to represent a number using different forms using different base value/*decimal number system-base value 10In this a number can be represented in 0-9 digits and also in powers of 10binary number system-number can be represented in 0,1 and in powers of 2hexadecimal-number can be represented in 0-15,powers of 1610-A,...,15-F*/#include<iostream>using namespace std;int main(){    //conversion of binary to decimal    /*int n;    cin>>n;    int a;    int decimal=0;    int b=1;    while (n>0)    {        a=n%10;        decimal=decimal+a*b;        n/=10;        b*=2;
    }    cout<<decimal<<endl;*/    //parity digit-remainder on dividing n by 2    //1-parity odd of n    0-parity even of n    //decimal to binary    int n;    cin>>n;    int ans=0;    int power=1;    while (n>0)    {        int paritydigit=n%2;        ans+=paritydigit*power;        power*=10;        n/=2;    }    cout<<ans<<endl;    
            return 0;}