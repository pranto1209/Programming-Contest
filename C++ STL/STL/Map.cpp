#include<iostream>
#include<map>
using namespace std;

void show(map<int, int>mp)
{
    map<int, int>::iterator p;
    for(p=mp.begin(); p!=mp.end(); p++){
        cout<<p->first<<"\t"<<p->second<<endl;
    }
    cout<<endl;
}

int main()
{
    int n, i, x, y;
    map<int, int>m;
    map<int, int>::iterator p;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        cin>>y;
        m.insert(make_pair(x, y));//sort
    }
    show(m);

    cin>>x;
    p=m.find(x);
    if(p!=m.end()) cout<<"Found\n";
    else cout<<"Not found\n";

    m.erase(m.begin(), p);
    show(m);

    cin>>x;
    m.erase(x);
    show(m);

    cout<<"Size: "<<m.size()<<endl;

    return 0;
}

/*

5
1 6
2 7
3 8
4 9
5 10

*/
