#include<bits/stdc++.h>
using namespace std;
vector<int>occurences;
int main()
{
	string t, p;
	cin>>t>>p;
	int ts=t.size(), ps=p.size();
	for(int i=0; i<=ts-ps; i++){
        int j;
		for(j=0; j<ps; j++) if(t[i+j] != p[j]) break;
		if(j==ps) occurences.push_back(i);
	}

	if(occurences.size()){
        cout<<"Pattern Found at Index: ";
        for(auto i: occurences) cout<<i<<" ";
        cout<<endl;
    }
    else cout<<"Pattern Not Found!\n";
}

/*

hellolllolloolo
ello

*/
