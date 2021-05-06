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
        ll hot, cold, t;
        cin >> hot >> cold >> t;
        ll mid = (hot+cold)/2;
        if((int)t <= (int)mid){
            cout << 2 << endl;
        } 
        else{
            ll mid = (hot - t)/(2*t - hot - cold);
 
            ll v1 = abs((mid+1)*hot + mid*cold - t*(2*mid+1));
            ll v2 = abs((mid+2)*hot + (mid+1)*cold - t*(2*mid + 3));
            
            if(v1*(2*mid + 3) <= v2*(2*mid+1)){
                cout << 2*mid+1 << endl;
            }
            else{
                cout << 2*mid+3 << endl;
            }
        }
        

    }
    
    return 0;
}