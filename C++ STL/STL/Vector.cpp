#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void show(vector<int>vec)
{
    vector<int>::iterator p;
    for(p=vec.begin(); p!=vec.end(); p++){
        cout<<*p<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, i, x;
    vector<int>v;
    vector<int>::iterator p;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }

    cout<<"Size: "<<v.size()<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;

    cout<<"Enter a number for count: ";
    cin>>x;
    int c=count(v.begin(), v.end(), x);
    cout<<c<<" element are "<<x<<endl;

    p=v.begin();
    p+=2;
    v.insert(p, 5, 1);
    //v.insert(p, 1);
    //v.insert(p, v.begin(), v.end());
    for(int i: v) cout<<i<<" ";
    cout<<endl;

    v.erase(v.begin(), v.begin()+2);
    //v.erase(v.begin());
    show(v);

    sort(v.begin(), v.end());
    //sort(v.begin()+2, v.begin()+5);
    show(v);

    cout<<"Maximum element of vector is: "<<*max_element(v.begin(), v.end());
    cout<<" at position : "<<max_element(v.begin(), v.end())-v.begin()<<endl;
    cout<<"Minimum element of vector is: "<<*min_element(v.begin(), v.end());
    cout<<" at position : "<<min_element(v.begin(), v.end())-v.begin()<<endl;
    cout<<"The summation of vector elements is: "<<accumulate(v.begin(), v.end(), 0)<<endl;

    cout<<"Enter a number for search: ";
    cin>>x;
    p=find(v.begin(), v.end(), x);
    if(p!=v.end()) cout<<"Found "<<*p<<" at position: "<<distance(v.begin(), p);
    else cout<<"Not found";
    cout<<endl;

    if(binary_search(v.begin(), v.end(), x)) cout<<"Found at position: "<<distance(v.begin(), p);
    else cout<<"Not found";
    cout<<endl;

    p=lower_bound(v.begin(), v.end(), x);
    int lb=lower_bound(v.begin(), v.end(), x)-v.begin();
    cout<<"The lower bound of "<<*p<<" is at position: "<<lb<<endl;

    p=upper_bound(v.begin(), v.end(), x);
    int ub=upper_bound(v.begin(), v.end(), x)-v.begin();
    cout<<"The upper bound of "<<*p<<" is at position: "<<ub<<endl;

    v.pop_back();
    show(v);

    p=unique(v.begin(), v.end());
    v.resize(distance(v.begin(), p));
    show(v);

    v.assign(5, 0);
    show(v);

    v.clear();
    cout<<"After clear size: "<<v.size()<<endl;

    cout<<"Enter resize: ";
    cin>>x;
    v.resize(x);

    fill(v.begin(), v.end(), 5);
    fill_n(v.begin(), 2, 1);

    show(v);

    if(v.empty()) cout<<"Empty";
    else cout<<"Not empty";
    cout<<endl;

    return 0;
}

/*

5
2 4 6 8 10

*/
