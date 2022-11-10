#include<bits/stdc++.h>
using namespace std;

int linearsearch(int *a, int n, int x)
{
    int i, index=-1;
    for(i=0; i<n; i++){
        if(x==a[i]){
            index=i;
            break;
        }
    }
    return index;
}

int main()
{
    int n, x;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Enter a number for search: ";
    cin>>x;
    if(linearsearch(a, n, x)!=-1) cout<<"Found at position: "<<linearsearch(a, n, x);
    else cout<<"Not found";
}
