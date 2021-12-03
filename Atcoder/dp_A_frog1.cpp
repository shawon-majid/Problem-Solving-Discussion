//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const ll mx = 2e5 + 10;


ll n;

vector <ll> ara;

// return value is the minimum difference

ll dp[mx];

//Approach
// Dhori amar jana ase je pos-1 e ashte ar pos-2 te ashte total koto khoroch hoyeche f(pos-1) ar f(pos-2) theke
// ekhon jekunu pos e pos-1 theke ashte je khoroch hoy tar shathe jodi ami f(pos-1) jug kori tahole pos-1 theke pos e ashte total khoroch ber hobe
// same kaj pos-2 er jonno o korbo
// minimum ta return korbo

int f(int pos){


    //f(pos-1) -> oilo 
    if(dp[pos] != -1){
        return dp[pos];
    }

    if(pos <= 0){
        return 0;
    }
    if(pos <= 1){ // jate ara[-1] e RTE na khai
        dp[pos] = (abs(ara[pos] - ara[pos-1]) + f(pos - 1));
    }
    return dp[pos] = min((abs(ara[pos] - ara[pos-1]) + f(pos - 1)), (abs(ara[pos] - ara[pos-2]) + f(pos - 2) ) );
}


int main(){


    cin >> n;

    ara.resize(n);
        
    for(ll i = 0; i <= n; i++) dp[i] = -1;

    for(ll i = 0; i < n; i++){
        cin >> ara[i];
    }

    cout << f(n-1) << endl;

    return 0;
}
