/*vectors are dynamic arrays(i.e. arrays can be resized when we want to insert or delete elements)contiguous meemory allocation*///declaration of vectors#include<iostream>#include<vector>/*vector<datatype> vector-name;vector<datatype> vector-name(size);vector<int> v;*//*to check size- v.size()to resize-v.resize(new size)to check capacity(space occupied){capacity>=size}-v.capacityif we add elements one by one only then capacity increase in powers of 2*//*add elements-v.pushback(element)v.insert(position,element){position relative to position of first element}v.begin(),v.end()-to find position of first and last elementsdelete elements-v.popback()v.erase(position of element)*/using namespace std;int main(){    vector<int> v;    //for loop    for (int i = 0; i < 5; i++)    {        int element;        cin>>element;        v.push_back(element);        //to add element in the form of v[i]-we have to specify size of vector initially    }    for (int i = 0; i < v.size(); i++)    {        cout<<v[i]<<"  ";    }    cout<<endl;
    //for each loop    for(int ele:v){        cout<<ele<<"  ";    }    cout<<endl;        }/*to sort vector in descending order-sort(v.begin(), v.end(), greater<int>()); */#include<iostream>#include<vector>using namespace std;int main(){    vector<int> v;    for (int i = 0; i < 5; i++)    {        int element;        cin>>element;        v.push_back(element);    }    // cout<<"enter the character:  "<<"";    // int e;    // cin>>e;    // int index=-1;    // for (int i = 0; i < v.size(); i++)    // {    //     if(v[i]==e){    //         index=i;    //     }    // }    // cout<<index;    //to check if array is sorted or not     for (int i = 1; i < v.size(); i++)    {        if(v[i]<v[i-1]){            cout<<"not sorted";            break;        }    }                return 0;}