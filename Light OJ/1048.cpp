//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
typedef unsigned long long ull;
typedef long long ll;

/*
                                        Conquering Keokradong 
                                       -----------------------

    This is a basic greedy+binary search problem. It's also a very good problem to learn the application of binary search
    technique

    Key idea: We will use binary search to find the minimized cost of the maximum amount of walking done in a single day. 
    And then, we'll use this answer to find the walkings done in per day.
    
    Steps:
    1. Binary Search for the ans:
        (i) Notice that the lowest we can walk in a single day is the highest distance between 2 camps. and highest we can walk
            in a single day is the summation of all the distance. So we found the range of our search.
        (ii) Now, see that, if our maximum distance is such that the number of camps we will visit using highest amount of
             walking  is less than k, then that maximum distance is valid. Because, if our maximum distance is 15.
             for the given test case, then,
                        taking 7+2+6 + stop + 4+5 we will get 1 stop. but that also means that we can use 3 stops if we want
                        because we took the highest walking each day. We could go by 7+stop + 8 + stop + 4 +stop+ 5.

        (iii) So every maximum distance is True if the minimum stop is less than K; And we need to find the first true.
    2. Use greedy approach for deriving the amounts of walking done in per day

*/

            


int b_search(vector <int> dist, int k, int low, int high){
    int ans = high, mid;
    while(low <= high) {
        mid = low + ((high - low)/2);
        int sum = 0, cnt = 0;
        for(int i = 0; i < dist.size(); i++){
            if(sum + dist[i] <= mid){
                sum += dist[i];
            }
            else{
                cnt++;
                sum = dist[i];
            }            
        } 

        if(cnt <= k){
            ans = min(ans, mid);
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    int T, cs = 1;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;

        vector <int> dist(n+1);
        int high = 0;
        for(int i = 0; i < dist.size(); i++){
            cin >> dist[i];
            high += dist[i];
        }
        int low = *max_element(all(dist));

        int ans = b_search(dist, k, low, high);
        
        cout << "Case "<<cs<<": "<<ans << endl;
        
        int cover = 0, sum = 0;
        bool done = 0;
        for(int i = 0; i < dist.size(); i++){
            if(n - cover == k-1){
                cout << sum <<endl;
                for(int j = i; j < dist.size(); j++){
                    cout << dist[j] << endl;
                }
                done = 1;
                break;
            }
            if(sum+dist[i] <= ans){
                sum += dist[i];
            }
            else{
                cout << sum <<endl;
                k--;
                sum = dist[i];
            }
            cover++;
        }
        if(!done) cout << sum <<endl;  
        cs++;      
    }
    


    return 0;
}


