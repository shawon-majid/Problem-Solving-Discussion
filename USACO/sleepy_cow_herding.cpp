#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define F first
#define S second

void setIO(string name = "") { // name is nonempty for USACO file I/O

    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output

    // alternatively, cin.tie(0)->sync_with_stdio(0);

    if (name.size()) {

        freopen((name+".in").c_str(), "r", stdin); // see Input & Output

        freopen((name+".out").c_str(), "w", stdout);

    }

}


int main() {

    setIO("herding");

    int n;
    cin >> n;
    vector<int> ara(n);
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }   
    
    sort(all(ara));

    // find the minimum number of moves
    int mn = 0;
    // corner cases
    if(ara[n-2] - ara[0] == n-2 and ara[n-1] - ara[n-2] > 2){
        mn = 2;
    }
    else if(ara[n-1] - ara[1] == n-2 and ara[1] - ara[0] > 2){
        mn = 2;
    }
    // Two pointer cases
    else{
        int best = 0;
        for(int i = 0, j = 0; i < n; i++){
            while(j < n-1 and ara[j+1]-ara[i]+1 <= n) {
                j++;
            }
            best = max(best, j-i+1);
        }
        mn = n - best;
    }

    // find the maximum number of moves

    int mx = max(((ara[n-1] - ara[1] + 1) - (n-1)), ((ara[n-2]-ara[0] + 1) - (n-1)));

    cout << mn << endl;
    cout << mx << endl;
    
    
    return 0;

}