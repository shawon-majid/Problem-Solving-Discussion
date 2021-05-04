//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

vector < vector <int > > v;
int dp[500][500];

int f(int pos1, int pos2)
{
	if(pos1 >= v.size()){
		return 0;
	}
	if(pos2 >= v[pos1].size()){
		return 0;
	}
	if(v[pos1][pos2] == -5){
		return 0;
	}
	if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
	
	return dp[pos1][pos2] = max( (v[pos1][pos2] + f(pos1+1, pos2)) , (v[pos1][pos2] + f(pos1+1, pos2+1)) );
}


int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, cs = 1;
	cin >> T;
	while(T--) {
	    int n;
	    cin >> n;
	    for(int i = 0; i <= 2*n; i++){
	    	for(int j = 0; j < n+4; j++){
	    		dp[i][j] = -1;
	    	}
	    }
	    
	    for(int i = 1; i <= n; i++){
	    	vector <int> temp;
	    	for(int j = 1; j <= i; j++){
	    		int x;
	    		cin >> x;
	    		temp.push_back(x);
	    	}	 
	    	v.push_back(temp);
	    }	 
	    int minus = 1;
	    for(int i = 1; i <= n-1; i++){
	    	vector <int> temp;

	    	for(int j = 1; j <= n; j++){	    		
	    		if(j <= minus){
	    			temp.push_back(-5);
	    		}
	    		else{
	    			int x;
	    			cin >> x;
	    			temp.push_back(x);
	    		} 
	    	}
	    	v.push_back(temp);
	    	minus++;
	    }

	    // for(auto x: v){
	    // 	for(auto y: x){
	    // 		cout << y << " ";
	    // 	}
	    // 	cout << endl;
	    // }

	    cout <<"Case "<<cs<<": " << f(0, 0) << endl;
	    v.clear();
	    cs++;
	}

    return 0;
}