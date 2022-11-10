#include<iostream>
#include<queue>
//#include<deque>
using namespace std;

void show(deque<int>que)
{
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop_front();
    }
    cout<<endl;
}

int main()
{
    int n, x;
    deque<int>q, q2(5, 0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        q.push_back(x);
        q.push_front(x);
    }
    show(q);

    auto p=q.begin();
    q.insert(p, 5, 1);
    //q.insert(p, 1);
    //q.insert(p, q.begin(), q.end());
    show(q);

    q.erase(q.begin(), q.begin()+5);
    show(q);

    cout<<"Size: "<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    q.pop_front();
    q.pop_back();

    for(int i: q) cout<<i<<" ";
    cout<<endl;

    swap(q, q2);

    for(int i=0; i<q.size(); i++) cout<<q[i]<<" ";
    cout<<endl;
}

/*

5
2 4 6 8 10

*/
