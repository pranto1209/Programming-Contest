#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    ordered_set s;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.insert(x);
    }

    for(auto i: s) cout<<i<<" ";
    cout<<endl;

    for(int i=0; i<n; i++) cout<<*s.find_by_order(i)<<" ";
    cout<<endl;

    // Finding the number of elements strictly less than x
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    cout<<s.order_of_key(x)<<endl;

    s.erase(3);
    s.erase(s.find(5));

    for(int i=0; i<n; i++) cout<<*s.find_by_order(i)<<" ";
    cout<<endl;

    cout<<"Size: "<<s.size()<<endl;
}

/*

5
9 7 1 3 5

*/
