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

  
    ll a, b, c;
    cin >> a >> b >> c;
    // a = usb, b = ps/2, c = both
    ll m;
    cin >> m;
    vector <pair <ll, string> > vp(m);
            // price, type
    for(ll i = 0; i < m; i++){
        cin >> vp[i].F >> vp[i].S;
    }
    sort(all(vp));
    ll product = 0, cost = 0;
    for(ll i = 0; i < m; i++){
        if(vp[i].S == "USB"){
            if(a){
                a--;
                product++;
                cost += vp[i].F;
            }
            else if(c){
                c--;
                product++;
                cost += vp[i].F;
            }
        }
        else{
            if(b){
                b--;
                product++;
                cost += vp[i].F;
            }
            else if(c){
                c--;
                product++;
                cost += vp[i].F;
            }
        }

    }
    cout << product << " " << cost << endl;

    return 0;
}