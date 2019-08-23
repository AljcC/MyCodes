#include<iostream>
#include<map>
using namespace std;
map<string,string> f;
string find(string a)
{
    return a==f[a]?a:find(f[a]);
}
int main()
{
    string a,b,c;
    while(cin>>a)
    {
        f.clear();
        while(a!="$")
        {
            if(a[0]=='#')
            {
                b=a.substr(1,a.size()-1);
                if(f[b]=="")
                f[b]=b;
            }
            else if(a[0]=='+')
            {
                c=a.substr(1,a.size()-1);
                b=find(b);
                f[c]=b;
            }
            else if(a[0]=='?')
            {
                c=a.substr(1,a.size()-1);
                cout<<c<<" "<<find(c)<<endl;
            }
            cin>>a;
        }
    }
    return 0;
}
