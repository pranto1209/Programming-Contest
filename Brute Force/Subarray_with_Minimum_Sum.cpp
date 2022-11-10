#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int minsum=a[1], l=1, r=1, sum=0, pos=0;
    for(int i=1; i<=n; i++){
        sum += a[i];
        if(sum < minsum){
            minsum = sum;
            l = pos+1, r = i;
        }
        if(sum > 0) sum=0, pos=i;
    }

    cout<<minsum<<endl;
    cout<<l<<" "<<r<<endl;
}

/*

8
10 10 -10 -100 -10 10 10 10

4
6 2 1 5

*/
