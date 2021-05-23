//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif
    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        string str;
        cin >> str;
        str  = "0"+str;
        vector <ll> pre(n+1);
        pre[0] = 0;
        for(ll i = 1; i <= n; i++){
            pre[i] = pre[i-1] + (str[i] - '0');
        }
        ll sum = 0, ans = 0;
        map <ll, ll> m;
        for(ll i = 1; i <= n; i++){
            m[pre[i-1] - i + 1]++; // portion that i need to substract
            if(m.find(pre[i] - i) != m.end()){ // portion that i am currently adding
                ans+= m[pre[i]- i];            // if addition == substraction than answer will be increased
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}