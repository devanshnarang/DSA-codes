/*strings-objects of a class std:string in cppwhich are used to represent sequence of characters.declaration string string_name="sequence of characters"string string_name("sequence of characteers")taking string input-string str;cin>>str;(for single word)(or untill it encounters space,tab or a new line2nd method-getline(cin,str)in strings at 'n' index is an empty space for a null character which tells that the string has ended there.string vs character array-string is a class,string variables are objects of this classcharacter array is an array of character data type.in character array we need to specify its size at time of declaration(static memory allocation,unused allocated memory is wasted) while in strings we need not do so as in strings there is dynamic memory allocation(no pre allocated memory)strings have inbuilt functions,while character arrays are faster than strings.inbuilt functions of string:reverse()-eg-string str="abcd";reverse(str.begin(),str.end());time complexity of this function is O(length oof string)substr()-to find substring of a given string-eg-string_name.substr(position,length)'+'operator-used to concatenate stringstrcat()-used to concatenate character arrays.eg-strcat(s1,s2)push_back()-eg-string_name.push_back(ch)size()-str.size(),str.length()[for string][time complexity-O(1)];for character array-eg-strlen(character_array_name)[time complexity-O(n)]to_string-used to convert numeric(integer) value to string.*///Given a string str,sort the given string?///in a lexocographical order/*#include<iostream>#include<string>#include<vector>using namespace std;string countSort(string str){    vector<int> freq(26,0);    //create frequency array    for (int i = 0; i < str.size(); i++)    {        int index=str[i]-'a';        freq[index]++;    }    //create our sorted string    int j=0    for (int i = 0; i < 26; i++)    {        while (freq[i]--)        {            str[j++]=i+'a';        }            }    return str;}int main(){    string str;    cin>>str;    cout<<countSort(str)<<endl;    return 0;}*///given 2 string and check for anagram/*#include<iostream>#include<string>#include<vector>using namespace std;string countsort(string s){    vector<int> freq(26);    for (int i = 0; i < s.size(); i++)    {        int index=s[i]-'a';        freq[index]++;    }    int j=0;    for (int i = 0; i < 26; i++)    {        while (freq[i]--)        {           s[j++]=i+'a';         }            }    return s;        }int main(){    string s;    string t;    cin>>s;    cin>>t;    string str1=countsort(s);    string str2=countsort(t);    if (str1==str2)    {        cout<<"true"<<endl;    }    else{        cout<<"false"<<endl;    }    return 0;}*///check if 2 strings are isomorphic/*#include<iostream>#include<string>#include<vector>using namespace std;bool isIsomorphic(string s1,string s2){    if (s1.length()!=s2.length())    {        return false;    }    int i=0;    vector<int> v1(128,-1);    vector<int> v2(128,-1);    for (int i = 0; i < s1.size(); i++)    {        if (v1[s1[i]]!=v2[s2[i]])        {            return false;        }        v1[s1[i]]=v2[s2[i]]=i;    }    return true;}int main(){    string s,t;    cin>>s>>t;    if (isIsomorphic(s,t))    {        cout<<"they are isomorphic"<<endl;    }    else{        cout<<"not"<<endl;    }    return 0;}*///find longest common prefix in a given string/*#include<iostream>#include<vector>#include<string>#include<algorithm>using namespace std;string longestcommonprefix(vector<string> &str){    sort(str.begin(),str.end());    string s1=str[0];    string i=0;    string s2=str[str.size()-1];    string j=0;    string ans="";    while(i<s1.size() && j<s2.size()){        if (s1[i]==s2[j])        {            ans+=s1[i];            i++;            j++;        }            }    return ans;}int main(){    int n;    cin>>n;    vector<string> str(n);    for (int i = 0; i < n; i++)    {        cin>>str[i];    }    cout<<longestcommonprefix(str)<<endl;    return 0;}*///timecomplexity-O(nlogn*m)+O(min(s[0].size(),s[n-1].size()));where m is general length of string//or/*string longestcommonprefix(vector<string> &str){    string s1=0;    int ans_length=s1.size();    for (int i = 1; i < str.size(); i++)    {        int j=0;        while(j<s1.size()&&j<str[i].size() && s1[j]=str[i][j]){            j++;        }        ans_length=min(ans_length,j);    }    string ans=s1.substr(0,ans_length);    return ans;    }*///decoding encoded string/*#include<iostream>//#include<cstring>using namespace std;string decodedString(string s){    string result;    for (int i = 0; i < s.length(); i++)    {        if (s[i]!=']')        {            result.push_back(s[i]);        }        else{            //extract str from result            string str="";            while (!result.empty() && result.back()!='[')            {                str.push_back(result.back());                result.pop_back(result.back());            }            //reversing the str            reverse(str.begin(),str.end());            //remove last char from result which is '['            result.pop_back();            //extract num from result            string num="";            while (!result.empty() && result.back()>='0' && result.back()<='9')            {                num.push_back(result.back());                result.pop_back();            }            //reversing the num string            reverse(num.begin(),num.end());            //convert num string to integer            int int_num=stoi(num);            //inserting str in result int_num times            while (int_num)            {                result+=str;                int_num--;            }          }            }    return result;}int main(){    string str;    cin>>str;    cout<<decodedString(str);    return 0;}*///sliding window technique-used to find longest/shortest sequence with given condition#include<iostream>#include<string>using namespace std;int longestOnes(string str,int k){    int start=0;    int end=0;    int zero_count=0;    int max_length=0;    for (; end < str.length(); end++)    {        if (str[end]=='0')        {            zero_count++;        }        while (zero_count>k)        {            if(str[start]=='0') zero_count--;            start++;        }        max_length=max(max_length,end-start+1);            }    //timecomlexity-O(N)    //space complexity-O(1)    }int main(){    string str;    cin>>str;    int k;    cin>>k;    cout<<longestOnes(str,k)<<endl;    return 0;}