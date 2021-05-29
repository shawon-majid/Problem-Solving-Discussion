//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

vector <int > ara{11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    ll T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        bool ok = 0;
        for(int i = 0; i < 11; i++){
            int temp = n - 111*i;
            if(temp >= 0 and temp % 11 == 0){
                ok = 1;
                break;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}