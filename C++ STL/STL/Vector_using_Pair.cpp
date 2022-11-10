#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, i, x;
    string s;
    vector< pair<string, int> >v;
    vector< pair<string, int> >::iterator p;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>s;
        cin>>x;
        v.push_back(make_pair(s, x));
        //v.push_back({s, x});
        //v.push_back(pair<string, int>(s, x));
    }

    for(i=0; i<v.size(); i++){
        cout<<v[i].first<<"\t"<<v[i].second<<endl;
    }
    cout<<endl;

    sort(v.begin(), v.end());

    for(p=v.begin(); p!=v.end(); p++){
        cout<<p->first<<"\t"<<p->second<<endl;
    }
    cout<<endl;

    return 0;
}

