#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        // finding first and last w
        int first_w = -1, last_w = -1;
        for(int i = 0; i < n; i++){
            if(str[i] == 'W'){
                first_w = i;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(str[i] == 'W'){
                last_w = i;
            }
        }

        // finding all the holes and index of those holes
        int hole_size = 0;
        vector <pair <int, int> > vp;
                // holes, ind
        for(int i = first_w; i < last_w; i++){
            if(str[i] == 'W'){
                if(hole_size) vp.back().F = hole_size;
                hole_size = 0;
            }
            else{
                hole_size++;
                if(hole_size == 1){
                    pair <int, int> temp;
                    temp.first = 0, temp.second = i;
                    vp.push_back(temp);
                }
            }
        }
        if(hole_size) vp.back().F = hole_size;     
        
        sort(all(vp)); // start filling from small holes to large

        // fill up the holes
        for(int i = 0; i < vp.size(); i++){
            for(int j = vp[i].S, c = 0; c < vp[i].F; c++, j++){
                if(k == 0) break;
                str[j] = 'W';
                k--;
            }
            if(k == 0) break;
        }

        // now fill the sides
        if(k){
            if((first_w != -1)){ // there is atleast 1 w        
                if((first_w - 0) < (n-1 - last_w)){ // fill the left side first                    
                    for(int i = first_w; i >= 0; i--){
                        if(k == 0) break;
                        if(str[i] != 'W'){
                            str[i] = 'W';
                            k--;
                        }   
                    }
                    for(int i = last_w; i < n; i++){
                        if(k == 0) break;
                        if(str[i] != 'W'){
                            str[i] = 'W';
                            k--;
                        }
                    }
                }
                else{ // fill the right side first
                    for(int i = last_w; i < n; i++){
                        if(k == 0) break;
                        if(str[i] != 'W'){
                            str[i] = 'W';
                            k--;
                        }
                    }
                    for(int i = first_w; i >= 0; i--){
                        if(k == 0) break;
                        if(str[i] != 'W'){
                            str[i] = 'W';
                            k--;
                        }   
                    }
                }
            }
            else { // there is no w
                for(int i = 0 ; i < n; i++){
                    if(k == 0) break;
                    if(str[i] != 'W'){
                    str[i] = 'W';
                    k--;
                    }
                }
            }
        }   
        // calculate the answer
        char last = 'L';
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == 'W' and last == 'L'){
                ans++;
            }
            else if(str[i] == 'W' and last == 'W'){
                ans+=2;
            }
            last = str[i];
        }
        cout << ans << endl;
    }

}