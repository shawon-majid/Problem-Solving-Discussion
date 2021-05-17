//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;



ll bigMod(ll p, ll q, ll m)
{
    if(q == 0) return 1;
    if(q == 1) return p;
    ll ans = bigMod(p, q/2, m);
    if(q % 2 == 0){
        return (ans * ans) % m;
    }
    else{
        return ((p % m) * ((ans * ans) % m)) % m;
    }

}

const int mod = 1e9+7;

int main() {

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cout << bigMod(a, b, mod) << endl;
    }

    return 0;
}