#include<bits/stdc++.h>
using namespace std;
void show(stack<pair<int, int>>stk)
{
    while(!stk.empty())
    {
        cout<<stk.top().first<<" "<<stk.top().second<<endl;
        stk.pop();
    }
    cout<<endl;
}
int main()
{
    stack<pair<int, int>>s1, s2;
    int n, min_elmnt, front_elmnt;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        int mn=s1.empty() ? x : min(x, s1.top().second);
        s1.emplace(x, mn);
    }

    while(!s1.empty()){
        int x=s1.top().first;
        s1.pop();
        int mn=s2.empty()? x : min(x, s2.top().second);
        s2.emplace(x, mn);
    }
    show(s2);

    front_elmnt=s2.top().first;
    min_elmnt=s2.top().second;

    cout<<"Front Element: "<<front_elmnt<<endl;
    cout<<"Min Element: "<<min_elmnt<<endl;
    cout<<endl;

    s2.pop();

    show(s2);
}

/*

5
9 3 1 5 7

*/
