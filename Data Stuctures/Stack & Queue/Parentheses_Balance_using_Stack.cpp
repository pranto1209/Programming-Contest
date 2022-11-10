#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char>stk;
    string s;
    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        if(!stk.empty() && s[i]==')' && stk.top()=='(') stk.pop();
        else if(!stk.empty() && s[i]=='}' && stk.top()=='{') stk.pop();
        else if(!stk.empty() && s[i]==']' && stk.top()=='[') stk.pop();
        else stk.push(s[i]);
    }
    if(stk.empty()) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
