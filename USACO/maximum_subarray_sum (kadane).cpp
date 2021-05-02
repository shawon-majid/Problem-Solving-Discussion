//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


int main(){
	
  	int n;
  	cin >> n;
  	vector <ll> ara(n);

  	for(int i = 0; i < n; i++){
  		cin >> ara[i];
  	}
  	ll local_max = ara[0], global_max = ara[0];

  	for(int i = 1; i < n; i++){
  		if(local_max + ara[i] > ara[i]){
  			local_max += ara[i];
  		}
  		else{
  			local_max = ara[i];
  		}
  		global_max = max(global_max, local_max);
  	}


  	cout << global_max << endl;

    return 0;
}