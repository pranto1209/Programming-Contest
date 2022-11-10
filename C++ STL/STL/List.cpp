#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void show(list<int>lst)
{
    list<int>::iterator p;
    for(p=lst.begin(); p!=lst.end(); p++){
        cout<<*p<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, i, x;
	list<int>l, l2;
	list<int>::iterator p;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        l.push_back(x);
    }
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        l2.push_front(x);
    }
    cout<<"Size: "<<l.size()<<endl;
    cout<<"l: ";
    show(l);
    cout<<"l2: ";
    show(l2);

    l.sort();
    show(l);

    l.reverse();
    show(l);
    l.reverse();
    for(auto i: l) cout<<i<<" ";
    cout<<endl;

	l.pop_back();
	l.pop_front();
	show(l);

	cout<<"Enter a number for position: ";
    cin>>x;
    p=find(l.begin(), l.end(), x);
    int y;
    cout<<"Enter a number for insert: ";
    cin>>y;
    l.insert(p, y);
    show(l);

    cout<<"Enter a number for remove: ";
	cin>>x;
	l.remove(x);
	show(l);

	l.swap(l2);
	cout<<"l: ";
	show(l);
	cout<<"l2: ";
	show(l2);

    l.merge(l2);
	show(l);

	return 0;
}

/*

5
1 2 3 4 5
5
10 9 8 7 6

*/

