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

    int n;
    cin >> n;
    map <int, int> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x] = 1;        
    }
    int m;
    cin >> m;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(mp[x] == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}