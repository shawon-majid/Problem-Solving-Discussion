//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9+9;

int main() {
    
    int n, d;
    cin >> n >> d;

    vector<int> ara(n);
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }

    sort(all(ara));
    ll ans = 1;
    for(int i = 1, j = 0; i < n; i++){
        while(j < n and ara[j]+d < ara[i]) {
            j++;
        }
        ans = ((ans%mod)*((i-j+1)%mod))%mod;
    }

    cout << ans << endl;
        
    return 0;
}