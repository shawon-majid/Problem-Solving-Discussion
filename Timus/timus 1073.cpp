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
    
    vector<int> coins, num(60005);
    for(int i = 1; i <= 244; i++){
        coins.push_back(i*i);
    }
    // base cases
    num[0] = 0, num[1] = 1, num[2] = 2, num[3] = 3, num[4] = 1;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int mn = INT_MAX;
        for(int j = 0;  j < coins.size(); j++){
            if(i >= coins[j]){
                num[i] = num[i-coins[j]] + 1;
            }
            if(num[i] < mn){
                mn = num[i];
            }
        }
        num[i] = mn;
    }
    cout << num[n] << endl;
    
    return 0;
}
