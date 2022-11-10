#include<iostream>
#include<queue>
using namespace std;

void show(queue<int>que)
{
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop();
    }
    cout<<endl;
}

int main()
{
    int n, x;
    queue<int>q;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        q.push(x);//push_back
    }
    show(q);

    cout<<"Size: "<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    q.pop();//pop_front
    show(q);
}

/*

5
2 4 6 8 10

*/
