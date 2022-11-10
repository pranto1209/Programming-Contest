#include<iostream>
#include<set>
using namespace std;

void show(set<int>st)
{
    set<int>::iterator p;
    for(p=st.begin(); p!=st.end(); p++){
        cout<<*p<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, x;
    set<int>s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        s.insert(x);//sort
    }

    for(auto i: s) cout<<i<<" ";
    cout<<endl;

    int a=*s.begin();
    cout<<"First element: "<<a<<endl;

    cin>>x;
    auto p=s.find(x);
    if(p!=s.end()) cout<<"Found: "<<x<<endl;
    else cout<<"Not Found: "<<x<<endl;

    s.erase(s.begin(), p);
    show(s);

    cin>>x;
    s.erase(x);
    show(s);

    s.erase(s.begin());
    show(s);

    cout<<"Size: "<<s.size()<<endl;

    return 0;
}

/*

6
2 4 6 8 10 12
6
10

*/
