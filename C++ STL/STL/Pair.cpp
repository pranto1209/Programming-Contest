#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
    int n, i, x;
    string s;
    cin>>n;
    pair<string, int>p[n];
    for(i=0; i<n; i++){
        cin>>s;
        cin>>x;
        p[i]=make_pair(s, x);
    }

    for(i=0; i<n; i++){
        cout<<p[i].first<<"\t"<<p[i].second<<endl;
    }
    cout<<endl;

    sort(p, p+n);

    for(i=0; i<n; i++){
        cout<<p[i].first<<"\t"<<p[i].second<<endl;
    }
    cout<<endl;

    return 0;
}
