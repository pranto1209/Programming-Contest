#include<iostream>
#include<map>
using namespace std;

void show(multimap<int, int>mp)
{
    multimap<int, int>::iterator p;
    for(p=mp.begin(); p!=mp.end(); p++){
        cout<<p->first<<"\t"<<p->second<<endl;
    }
    cout<<endl;
}

int main()
{
    int n, i, x, y;
    multimap<int, int>m;
    multimap<int, int>::iterator p;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        cin>>y;
        m.insert(make_pair(x, y));//sort
    }
    show(m);

    cin>>x;
    p=m.find(x);
    m.erase(p);
    show(m);

    cin>>x;
    m.erase(x);
    show(m);

    cout<<"Size: "<<m.size()<<endl;

    return 0;
}

