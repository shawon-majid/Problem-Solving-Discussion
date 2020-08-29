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
          In this problem, you have to find 1+a+a^2+a^3+a^4+.....+a^n-1 Mod m
          You're given a, n and m.
          
          Here, we will use Divide and Conquer Method for finding the answer.
          For this question you need to know how to implement bigMod function.
          If you don't know about it visit https://golammostaeen.wordpress.com/2012/10/20/big-mod-algorithm/
          
          Now we will divide the problem into 2 parts:
             1 + a + a^2 + a^3 + a^4 + a^5 = (1+a+a^2) + a^3(1+a+a^2)
             if n was odd,
             1 + a + a^2 + a^3 + a^4 + a^5 + a^6 = (1+a+a^2) + a^3(1+a+a^2) + a^6
          Now we will implement this idea. Let's roll!
          
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
