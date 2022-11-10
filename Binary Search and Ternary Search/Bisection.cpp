#include <bits/stdc++.h>
using namespace std;

bool check(double mid, double x)
{
    if(mid*mid < x) return true;
    else return false;
}

double mysqrt(double x)
{
    double eps = 1e-9, l = 0.0, r = x;
    while(l <= r) {
        double mid = (l + r) / 2;
        if(check(mid, x)) l = mid + eps;
        else r = mid - eps;
    }
    return l - eps;
}

int main()
{
	int n;
	cin>>n;
	double ans = mysqrt(n);
	cout<<ans<<"\n";
}
