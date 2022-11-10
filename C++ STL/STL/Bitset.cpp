#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    bitset<8>b(x);
    cout<<b<<endl;
    b.flip();
    cout<<b<<endl;
    cout<<b.count()<<endl;

    b.set();
    cout<<b<<endl;
    b.reset();
    cout<<b<<endl;

    bitset<8>b2("1111");
    cout<<b2<<endl;

    bitset<8>c;
    c=b|b2;
    cout<<c<<endl;

    for(int i=0; i<c.size(); i++) cout<<c.test(i)<<" ";
    cout<<endl;
}
