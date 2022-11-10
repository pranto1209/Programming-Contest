#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int x;
    string str="Enter a sentence: ";
    cout<<str<<endl;

    getline(cin, str);
    cout<<str<<endl;

    str.push_back('s');
    cout<<str<<endl;

    str.pop_back();
    cout<<str<<endl;

    str.insert(0, "hello"); //(pos, str)
    cout<<str<<endl;

    str.erase(str.begin());
    cout<<str<<endl;

    str.erase(str.end()-1);
    cout<<str<<endl;

    cout<<"Enter position for erase: ";
    cin>>x;
    str.erase(x, 1); //(pos, len)
    cout<<str<<endl;

    cout<<"Enter lenght for replace: ";
    cin>>x;
    str.replace(0, x, "masumpranto"); //(pos, len, str)
    cout<<str<<endl;

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str<<endl;

    cout<<"Size: "<<str.size()<<endl;
    cout<<"Lenght: "<<str.length()<<endl;

    sort(str.begin(), str.end());
    cout<<str<<endl;

    reverse(str.begin(), str.end());
    cout<<str<<endl;

    int s=str.find("AA");
    if(s>=0) cout<<"Found \"AA\" at: "<<s;
    else cout<<"Not found";
    cout<<endl;

    cout<<"Enter lenght for copy: ";
    cin>>x;
    char ch[x];
    str.copy(ch, x, 0); //(ch, len, pos)
    cout<<ch<<endl;

    cin>>x;
    str.resize(x);
    cout<<str<<endl;

    /*str.erase(str.begin(), str.end());
    cout<<str<<endl;*/

    str.clear();
    cout<<str<<endl;

    if(str.empty()) cout<<"Empty";
    else cout<<"Not empty";
    cout<<endl;

    return 0;
}

/*

pranto
1
8
10
5

*/

