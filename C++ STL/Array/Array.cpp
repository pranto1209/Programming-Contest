#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, x;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<"Max element: "<<*max_element(a, a+n);
    cout<<" at postion: "<<max_element(a, a+n)-a<<endl;
    cout<<"Min element: "<<*min_element(a, a+n);
    cout<<" at postion: "<<min_element(a, a+n)-a<<endl;

    sort(a, a+n);
    //sort(a+2, a+5);
    for(i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"Enter a number for search: ";
    cin>>x;
    int *p=find(a, a+n, x);
    printf("%d\n", *p);
    if(binary_search(a, a+n, x)) cout<<"Found at position: "<<distance(a, p);
    else cout<<"Not found";
    cout<<endl;
    cout<<"The lower bound is at position: "<<lower_bound(a, a+n, x)-a<<endl;
    cout<<"The upper bound is at position: "<<upper_bound(a, a+n, x)-a<<endl;
}

/*

10
2 4 6 8 10 12 14 16 18 20

*/
