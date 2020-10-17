//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
typedef unsigned long long ull;
typedef long long ll;
                      /* Determinant using co-factor expansion method*/


ll det(vector < vector <int> > mat, int n){
    if(n == 2){
        return (mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0]);
    }
    else{
        ll ans = 0;

        for(int k = 0; k < n; k++){
            // form the new matrix
            vector < vector <int> > newMat(n-1);
            int x = 0, y = 0;

            for(int i = 1; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(j == k){
                        continue;
                    }
                    else{
                        newMat[x].push_back(mat[i][j]);
                        y++;
                        if(y == n-1){
                            y = 0;
                            x++;
                        }
                    }
                }
            }

            if(k % 2 == 0){
                ans += mat[0][k] * det(newMat, n-1);
            }
            else ans += -(mat[0][k] * det(newMat, n-1));

        }
        return ans;
    }
}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector < vector <int> > mat(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            mat[i].push_back(x);
        }
    }

    cout << det(mat, n) << endl;

    return 0;
}
