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
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string str;
    cin >> str;
    int vertical = 0, horizontal = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == 'U') vertical++;
        else if(str[i] == 'D') vertical--;
        else if(str[i] == 'L') horizontal--;
        else if(str[i] == 'R') horizontal++;
    }
    ll low = 0, high = LLONG_MAX, mid;
    ll ans = LLONG_MAX;
    while(low <= high) {
        mid = low + (high - low) / 2;
        ll x, y, scale, rem;
        scale = mid / n;
        rem = mid % n; 
        ll v = vertical*scale, h = horizontal*scale;
        x = x1 + h, y = y1 + v;
        for(int i = 0; i < rem; i++){
            if(str[i] == 'U') y++;
            else if(str[i] == 'D') y--;
            else if(str[i] == 'L') x--;
            else if(str[i] == 'R') x++;       
        }
        ll len = abs(x2 - x) + abs(y2 - y);
        if(len <= mid){
            ans = min(ans, mid);
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if(ans == LLONG_MAX) ans = -1;
    cout << ans << endl; 

    return 0;
}