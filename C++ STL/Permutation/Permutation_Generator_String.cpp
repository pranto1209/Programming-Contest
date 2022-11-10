#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	sort(str.begin(), str.end());
	//auto ip=unique(str.begin(), str.end());
	//str=string(str.begin(), ip);

    cout<<endl<<str<<endl;
	while(next_permutation(str.begin(), str.end())){
        cout<<str<<endl;
	}
}
