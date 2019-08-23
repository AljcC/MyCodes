#include<iostream>
#include<stack>
using namespace std;
string s;
stack<char> a;
bool judge(string s)
{
    int i=0;
    while(s[i]!='@')
    {
        if(s[i]=='(')
            a.push(s[i]);
        if(s[i]==')')
        {
            if(a.empty())
                return false;  
            a.pop();  
        }  
        i++;  
    }
    if(a.empty())
        return true;
    else return false;
}
int main()
{
    cin>>s;
    if(judge(s))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
