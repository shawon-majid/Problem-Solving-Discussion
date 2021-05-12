//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int n, k;
vector <int> ara;

bool f(double m)
{
    int cnt = 0;
    for(int i = 0;i < n; i++){
        cnt += floor((double)ara[i]/m);
    }
    return cnt >= k;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ara.push_back(x);
    }
    cout << setprecision(20);
    double l = 0, r = 1e8;
    for(int i = 0; i < 180; i++){
        double m = (l+r)/2;
        if(f(m)){
            l = m;
        }
        else r = m;
    }
    cout << l << endl;

    
    return 0;
}