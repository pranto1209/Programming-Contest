#include<bits/stdc++.h>
using namespace std;
int ax, ay, bx, by, cx, cy, dx, dy;
double dis(double m)
{
    double px=ax+(bx-ax)*m;
    double py=ay+(by-ay)*m;
    double qx=cx+(dx-cx)*m;
    double qy=cy+(dy-cy)*m;
    double ret=sqrt((px-qx)*(px-qx)+(py-qy)*(py-qy));
    return ret;
}
double ternary_search()
{
    double l=0, r=1, m1, m2, f1, f2;
    for(int cnt=0; cnt<100; cnt++){
        m1=l+(r-l)/3;
        m2=r-(r-l)/3;
        f1=dis(m1);
        f2=dis(m2);
        if(f1>f2) l=m1;
        else r=m2;
    }
    return dis(l);
}
int main()
{
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    double ans = ternary_search();
    cout<<ans<<endl;
}

/*

0 0 5 0 5 5 5 0

0 0 5 5 10 10 6 6

0 0 5 0 10 1 1 1

*/
