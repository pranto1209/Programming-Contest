#include<iostream>
#include<set>
using namespace std;

void show(multiset<int>st)
{
    multiset<int>::iterator p;
    for(p=st.begin(); p!=st.end(); p++){
        cout<<*p<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, i, x;
    multiset<int>s;
    multiset<int>::iterator p;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        s.insert(x);//sort
    }
    show(s);

    cin>>x;
    p=s.find(x);
    s.erase(p);
    show(s);

    cin>>x;
    s.erase(x);
    show(s);

    cout<<"Size: "<<s.size()<<endl;

    return 0;
}

