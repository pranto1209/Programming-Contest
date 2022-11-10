#include <bits/stdc++.h>
using namespace std;

int lowerbound(int *a, int n, int x)
{
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(x == a[mid]) {
            r = mid - 1;
        }
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int upperbound(int *a, int n, int x)
{
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(x == a[mid]) {
            l = mid + 1;
        }
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    int n, x;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Enter a number for search: ";
    cin>>x;
    cout<<"The lower bound is at position: "<<lowerbound(a, n, x)<<endl;
    cout<<"The upper bound is at position: "<<upperbound(a, n, x)<<endl;
}

//O(log2^n)
//O(1)
