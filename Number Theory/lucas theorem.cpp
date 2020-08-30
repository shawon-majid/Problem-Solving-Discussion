//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define PI acos(-1)
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef vector< int > vi;

/*
            Lucas Theorem
            -------------

*/

ll nCr(ll n, ll r)
{
    if(r == 0 || n == r){
        return 1;
    }
    if(r == 1){
        return n;
    }
    if(r > n) return 0;

    else return (nCr(n-1, r-1)  +  nCr(n-1, r));
}

ll lucas(ll A, ll B, ll p)
{
    vector <int> a, b;
    while(A){
        a.push_back(A % p);
        A /= p;
    }               
    while(B) {
        b.push_back(B % p);
        B /= p;
    }
    while(a.size() > b.size()) {
        b.push_back(0);
    }
    while(a.size() < b.size()) {
        a.push_back(0);
    }
    ll ans = 1;
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i]){
            return 0;
        }
        ans *= (nCr(a[i], b[i]) % p);
    }
    return ans % p;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    while(T--) {
        ll n, k, p;
        cin >> n >> k >> p;
        cout << lucas(n, k, p) << endl;
    }

    return 0;
}

