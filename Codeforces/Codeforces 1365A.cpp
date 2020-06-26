//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 32000
#define PI acos(-1)
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
typedef unsigned long long ull;
typedef long long ll;
  
int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n, m, r_zero(0), c_zero(0), move;
        bool flag;
        cin >> n >> m;
        
        int row[n] ={0};
        int col[m] = {0};
        int grid[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];   
            }
        }
        for(int i = 0; i < n; i++){
            flag = true;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    flag = false;
                }
            }
            if(!flag) row[i] = 1;
        }
        for(int j = 0; j < m; j++){
            flag = true;
            for(int i = 0; i < n; i++){
                if(grid[i][j] == 1){
                    flag = false;
                }
            }
            if(!flag) col[j] = 1;
        }
       
        for(int i = 0; i < n; i++){
            
            if(row[i] == 0) r_zero++;
        }
        
        for(int i = 0; i < m; i++){
            
            if(col[i] == 0) c_zero++;
        }
 
        move = min(r_zero, c_zero);
        if(move % 2 != 0) cout << "Ashish" << endl;
        else cout << "Vivek" << endl;
 
    }
    return 0;
}
