#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>v;
	int n, x;
	cin>>n;
	for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
	}
	//sort(v.begin(), v.end());

    for(auto i: v) cout<<i<<" ";
    cout<<endl;
	while(next_permutation(v.begin(), v.end())){
        for(auto i: v) cout<<i<<" ";
        cout<<endl;
	}
}

/*

5
9 3 1 5 7

*/
