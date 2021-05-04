//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


int n;
ll ara[20][20];

bool chk(int musk, int i){
	return (bool)(musk & (1 << i));
}
int on(int musk, int i)
{
	return musk |= (1 << i);
}
int dp[20][1 << 17];

ll f(int row, int musk)
{
	if(row >= n){
		return 0;
	}
	if(dp[row][musk] != -1) return dp[row][musk];
	ll ans = -1;
	for(int i = 0; i < n; i++){
		if(!chk(musk, i)){			
			ll val1 = ara[row][i] + f(row+1, on(musk, i));
			ans = max(ans, val1);
		}		
	}

	return dp[row][musk] = ans;

}

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int T, cs = 1;
    cin >> T;
    while(T--) {
        cin >> n;
        memset(dp, -1 , sizeof(dp));

        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n; j++){
        		cin >> ara[i][j];
        	}
        }

        cout <<"Case "<<cs<<": " <<f(0, 0) << endl;
        cs++;
    }

    return 0;
}