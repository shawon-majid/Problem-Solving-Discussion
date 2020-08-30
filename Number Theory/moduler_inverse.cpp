//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define PI acos(-1)
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef vector< int > vi;
/*
                                    Modular inverse
                                    ---------------
        In many CP problems you're often asked to find the value of ans % p. If the calculation
        of answer consist of addition, substraction and multiplications then there is no problem.
        But if there is division, we canntot say (a/b) % m = a % m / b % m.



*/
int mark[MAX];

void sieve(){
    mark[0] = mark[1] = 1;
    for(int i = 2; i*i <= MAX; i++){
        if(!mark[i]){
            for(int j = i+i; j < MAX; j+=i){
                mark[j] = 1;
            }
        }
    }
}

int phi(int n)
{
    int ret = n;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            ret -= (ret/i);  // it simply means ret*(1 - 1/i)
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1){ // which means n is a prime number
        ret -= (ret/n); 
    }
    return ret;
}
int bigMod(int a, int b, int M){
    if(b == 0) return 1 % M;

    int x = bigMod(a, b/2, M);

    if(b % 2 == 1){
        return (x*x*a) % M;
    }

    return (x*x) % M;
}



ll inverse(ll a, ll m)
{
    if(__gcd(a, m) != 1) return -1; // not possible
    if(!mark[m]){ // m is prime
        return bigMod(a, m-2, m);
    }
    else{
        return bigMod(a, phi(m)-1, m);
    }
}



int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    int x, y;
    cin >> x >> y;
    cout << inverse(x, y) << endl;

    return 0;
}

