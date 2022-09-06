//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;

const int mx = 1e6;

vector < int > primes;

int mark[mx]; // 0 means prime

int check(int n, int pos){
    return (n & (1 << pos));
}


int on(int n, int k){
    return n = n | (1 << k); 
}

void bitwiseSieve(int limit){

    mark[1/32] = on(mark[1/32], 1);
    mark[0] = on(mark[0], 0);

    for(int i = 2; i*i <= limit; i++){
        if(check(mark[i/32], i % 32) == 0){ // means prime
            for(int j = i*i; j <= limit; j+=i){
                mark[j/32] = on(mark[j/32], j % 32);
            }
        }
    }

    for(int i = 2; i <= limit; i++){
        if(check(mark[i/32], i % 32) == 0){
            primes.push_back(i);
        }
    }

}


vector < int > isComposite;

void segSieve(long long L, long long R){

    bitwiseSieve(R);

    isComposite.resize((((R-L+1) + 32 - 1)/32) + 1);

    if(L == 1){
        L++;
    }

    for(ll i = 0; primes[i]*primes[i] <= R; i++){

        ll p = primes[i];

        ll j = p*p;
        
        (j < L)  ? j = ((L+p-1)/p)*p : j = j; // if j is not in range, put it in range

        for(; j <= R; j += p){
            ll index = j-L;
            
            isComposite[index/32] = on(isComposite[index/32], index % 32);
        }
    }
}




int main(){


    ll l, r;
    cin >> l >> r;

    segSieve(l, r);

    for(ll i = l; i <= r; i++){
        if(!check(isComposite[(i-l)/32], (i-l)%32)){
            cout << i << endl;
        }
    }


    return 0;
}