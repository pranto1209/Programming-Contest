#include <bits/stdc++.h>
using namespace std;
string add(string a, string b)
{
    string c;
    int n = max(a.size(), b.size()), t=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i=0; i<n; i++) {
        if(i>=a.size()) t += (b[i]-'0');
        else if(i>=b.size()) t += (a[i]-'0');
        else t += (a[i]-'0') + (b[i]-'0');
        c+=(t%10+'0');
        t/=10;
    }
    if(t) c+=(t+'0');
    reverse(c.begin(), c.end());
    return c;
}
int main()
{
    string a, b, sum;
    cin>>a>>b;
    sum = add(a, b);
    cout<<sum<<"\n";
}
