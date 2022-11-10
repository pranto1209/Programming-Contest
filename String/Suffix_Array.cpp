#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector<int>sort_cyclic_shifts(string s)
{
    int n=s.size(), alpha=256;
    vector<int> p(n), c(n), cnt(max(alpha, n));
    for(int i=0; i<n; i++) cnt[s[i]]++;
    for(int i=1; i<alpha; i++) cnt[i] += cnt[i-1];
    for(int i=0; i<n; i++) p[--cnt[s[i]]]=i;
    c[p[0]]=0;
    int classes=1;
    for(int i=1; i<n; i++){
        if(s[p[i]] != s[p[i-1]]) classes++;
        c[p[i]]=classes-1;
    }
    vector<int> pn(n), cn(n);
    for(int h=0; (1<<h)<n; h++){
        for(int i=0; i<n; i++){
            pn[i]=p[i]-(1<<h);
            if(pn[i]<0) pn[i]+=n;
        }
        fill(cnt.begin(), cnt.begin()+classes, 0);
        for(int i=0; i<n; i++) cnt[c[pn[i]]]++;
        for(int i=1; i<classes; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]]=0;
        classes=1;
        for(int i=1; i<n; i++){
            pii cur = {c[p[i]], c[(p[i]+(1<<h))%n]};
            pii prev = {c[p[i-1]], c[(p[i-1]+(1<<h))%n]};
            if(cur!=prev) classes++;
            cn[p[i]]=classes-1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s)
{
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int main()
{
    string s;
    cin>>s;
    vector<int> suffix_array = suffix_array_construction(s);
    for(auto i: suffix_array) cout<<i<<" ";
    cout<<endl;
}

/*

abaab

*/
