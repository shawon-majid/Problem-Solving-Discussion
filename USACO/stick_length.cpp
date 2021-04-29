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

    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w" , stdout);
    
    int n;
    cin >> n;
    vector <int > ara(n);
    for(int i = 0; i < n; i++) cin >> ara[i];
    ll ans = 0;
    sort(all(ara));

    int mid = n/2;

    for(int i = 0; i < n; i++){
        ans += abs(ara[mid] - ara[i]);
    }
    mid--;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += abs(ara[mid] - ara[i]);
    }
    ans = min(ans, sum);

    
    cout << ans << endl;

    
    return 0;
}