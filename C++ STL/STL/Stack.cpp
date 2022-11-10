#include<iostream>
#include<stack>
using namespace std;

void show(stack<int>stk)
{
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}

int main()
{
    int n, i, x;
    stack<int>s;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        s.push(x);//push_front
    }
    show(s);

    cout<<"Size: "<<s.size()<<endl;
    cout<<s.top()<<endl;

    s.pop();//pop_front
    show(s);

    return 0;
}

