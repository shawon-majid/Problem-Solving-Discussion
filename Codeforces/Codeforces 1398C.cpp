//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int main(){
    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        string str;
        cin >> str;
        vector <ll> ara(n+1);
        for(ll i = 0; i < str.size(); i++){
            ara[i+1] = str[i] - '0';
        }
        vector <ll> pre(n+1);
        pre[0] = 0;
        map <ll, ll> m;
        m[0]++;
        ll ans = 0;
        // condition is r - (l - 1) = pre[r] - pre[l - 1];
        // so, pre[r] - r = pre[l-1] - (l - 1)
        for(ll i = 1; i <= n; i++){
            pre[i] = pre[i-1] + ara[i];
            ll need = pre[i] - i; 
            if(m.find(need) != m.end()){
                ans += m[need];
            }
            m[need]++;

        }
        cout << ans << endl;

    }

    return 0;
}
