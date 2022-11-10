#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int maxsum=a[1], l=1, r=1, sum=0, pos=0;
    for(int i=1; i<=n; i++){
        sum += a[i];
        if(sum > maxsum){
            maxsum = sum;
            l = pos+1, r = i;
        }
        if(sum < 0) sum=0, pos=i;
    }

    cout<<maxsum<<endl;
    cout<<l<<" "<<r<<endl;
}

/*

8
10 10 10 -100 10 10 10 10

3
-5 -10 -1

*/
