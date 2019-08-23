#include<iostream>
#include<cstring>  
#include<stack>
using namespace std;  
string s;
int l; 
stack<char> a;
stack<char> b;
bool judge(string s) {  
    int i=0;  
    while(i<l) {  
        if(s[i]=='(')
            if(s[i+1]==']')
                return false;
            else a.push(s[i]);  
        if(s[i]==')')  
        {  
            if(a.empty())
                return false;  
            a.pop();  
        }
        if(s[i]=='[')
            if(s[i+1]==')')
                return false;
            else b.push(s[i]);  
        if(s[i]==']')  
        {  
            if(b.empty())
                return false;  
            b.pop();  
        }
        i++;  
    }  
    if(a.empty()&&b.empty())
        return true;
    else return false;
}
int main()  
{     
    cin>>s; 
    l=s.size();
    if(judge(s))
        cout<<"OK";  
    else cout<<"Wrong";  
    return 0;  
}  
