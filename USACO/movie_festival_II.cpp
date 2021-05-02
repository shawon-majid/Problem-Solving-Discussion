//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

struct custom_compare final
{
    bool operator() (const pair<ll,ll>& left, const pair<ll, ll>& right) const
    {
        return left.second < right.second;
    }
};
 
int main() {
 
    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w" , stdout);
 
    ll n, k;
    cin >> n >> k;
    multiset <pair <ll, ll>, custom_compare > ms;
    for(ll i = 0; i < n; i++){
        pair <ll, ll> x;
        cin >> x.first >> x.second;
        ms.insert(x);
    }
    ll ans = 0;
    
    multiset <int > pq;

    for(int i = 0; i < k; i++){
        pq.insert(0);
    }
    for(auto x: ms){
        auto it = pq.lower_bound(x.first);
        it--;
        if(it == pq.end()) continue;
        if(x.first >= *it){
            ans++;
            pq.erase(it);
            pq.insert(x.second);
        }
    }
    cout << ans << endl;

    return 0;
}