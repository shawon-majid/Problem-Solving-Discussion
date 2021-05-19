#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const long long int mod = 1e9+7;

vector < vector <ll> >matMult(vector < vector <ll> > A, vector < vector <ll> > B, int m){
    vector < vector <long long > > res(m+1, vector <long long>(m+1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            res[i][j] = 0;
            for(int k = 1; k <= m; k++){
                res[i][j] += (A[i][k] % mod)*(B[k][j] % mod) % mod;
            }
        }
    }
    return res;
}

vector < vector <ll> > binPow(vector < vector <ll> > mat, int m, int n){
    //initiating identity
    vector < vector <long long > > res(m+1, vector <long long>(m+1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            if(i == j) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }

    // binary exponentiation of matrix
    while(n){
        if(n % 2 == 0){
            mat = matMult(mat, mat, m);
            n /= 2;
        }
        else{
            res = matMult(res, mat, m);
            n--;
        }
    }
    return res;
}


int main() {

    int T;
    cin >> T;
    while(T--){
        int m, n;
        cin >> m >> n;

        vector < vector <long long> > mat(m+1, vector<long long>(m+1)), res;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                cin >> mat[i][j];
            }
        }

        res = binPow(mat, m, n);
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

}