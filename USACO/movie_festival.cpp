//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;



bool cmp(pair <int, int> a, pair <int, int> b){
    return a.S < b.S;
}


int main() {

    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w" , stdout);
    
    int n;
    cin >> n;
    vector <pair <int, int> > vp(n);
    for(int i =0; i < n; i++){
        cin >> vp[i].F >> vp[i].S;
    }
    sort(all(vp), cmp);
    
    pair <int, int> last = vp[0];
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(vp[i].first >= last.second){
            ans++;
            last = vp[i];
        }
    }
    cout << ans << endl;

    return 0;
}