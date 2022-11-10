#include<iostream>
#include<queue>
using namespace std;

void show(priority_queue<int>pque)
{
    while(!pque.empty())
    {
        cout<<pque.top()<<" ";
        pque.pop();
    }
    cout<<endl;
}

int main()
{
    int n, x;
    priority_queue<int> pq;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        pq.push(x);//sort reverse
    }
    show(pq);

    cout<<"Size: "<<pq.size()<<endl;
    cout<<pq.top()<<endl;

    pq.pop();//pop_front
    show(pq);

    return 0;
}

/*

5
5 9 1 7 3

*/
