#include <bits/stdc++.h>
using namespace std;

int binarysearch(int *a, int n, int x)
{
    int l = 0, r = n-1, index = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(x == a[mid]) {
            index = mid;
            break;
        }
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return index;
}

int main()
{
    int n, x;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\n";
    cout<<"Enter a number for search: ";
    cin>>x;
    if(binarysearch(a, n, x)!=-1) cout<<"Found at position: "<<binarysearch(a, n, x);
    else cout<<"Not found\n";
}
//O(log2^n)
//O(1)
