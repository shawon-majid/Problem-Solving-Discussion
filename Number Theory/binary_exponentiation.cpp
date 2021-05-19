#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


// recursive approach
ll binPow(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a;

    ll half = binPow(a, b/2);
    if(b % 2 == 0){
        return half*half;
    }
    else return a*half*half;
}

//iterative approach

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b % 2 == 0){
            a = a*a;
            b /= 2;
        }
        else{
            res = a*res;
            b--;
        }
    }
    return res;
}


const long long int m = 5;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    cout << binPow(6, 9) << endl;
    cout << power(3, 5) << endl;

}