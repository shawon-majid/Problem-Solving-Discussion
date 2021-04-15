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

    int n;
    cin >> n;
    string str;
    cin >> str;
    int q;
    cin >> q;
    while(q--) {
        int m;
        char c;
        cin >> m >> c;
        int gap  = 0, j = 0, ans = 0;
        char last = c;
        for(int i = 0; i < n; i++){
            if(last != c){
                gap--;
            }
            while(j < n) {
                if(str[j] != c){
                    gap++;
                }
                if(gap == m+1) {
                    gap--;
                    break;
                }
                j++;
            }
            ans = max(ans, ((j-1)-i+1));
            last = str[i];
        }
        cout << ans << endl;
    }
    
    return 0;
}