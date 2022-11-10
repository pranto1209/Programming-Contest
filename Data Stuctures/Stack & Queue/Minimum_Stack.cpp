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
    stack<pair<int, int>>s;
    int n, min_elmnt, top_elmnt;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        int mn=s.empty() ? x:min(x, s.top().second);
        s.emplace(x, mn);
    }
    show(s);

    top_elmnt=s.top().first;
    min_elmnt=s.top().second;

    cout<<"Top Element: "<<top_elmnt<<endl;
    cout<<"Min Element: "<<min_elmnt<<endl;
    cout<<endl;

    s.pop();

    show(s);
}

/*

5
9 3 1 5 7

*/
