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
                Problem from mahbubul hasan contest book page 63
*/
int bigMod(int a, int b, int M){
    if(b == 0) return 1 % M;

    int x = bigMod(a, b/2, M);

    if(b % 2 == 1){
        return (x*x*a) % M;
    }

    return (x*x) % M;
}

int bigSum(int a, int n, int M)
{
    if(n == 1) return 1 % M; // base case
    //if(n == 2) return (1 % M + a % M) % M

    if(n % 2 == 0){
        int x = bigSum(a, n/2, M);
        int y = bigMod(a, n/2, M);
        return (x + y*x) % M;
    }
    else{
        n--;
        int x = bigSum(a, n/2, M);
        int y = bigMod(a, n/2, M);
        int z = bigMod(a, n, M);
        return (x + y*x + z) % M;
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a, n, M;
    cin >> a >> n >> M;

    cout << bigSum(a, n, M) << endl;
    
    return 0;
}