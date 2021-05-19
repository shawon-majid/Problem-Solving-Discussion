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

const long long int m = 1e9+7;

int main() {

    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w" , stdout);
    
    int n;
    cin >> n;
    while(n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll phiM = m-1, power; // see the relevent blog

        ll nModPhiM = bigMod(b, c, phiM);
        if(nModPhiM == 0) power = 0;
        else power = phiM + nModPhiM; // see the relevent blog
        
        cout << bigMod(a, power, m) << endl;
    }
  
    return 0;
}