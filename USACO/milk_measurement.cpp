#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using vi = vector<int>;
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define F first
#define S second

void setIO(string name = "") { // name is nonempty for USACO file I/O

    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output

    // alternatively, cin.tie(0)->sync_with_stdio(0);

    if (name.size()) {

        freopen((name+".in").c_str(), "r", stdin); // see Input & Output

        freopen((name+".out").c_str(), "w", stdout);

    }

}


int main() {

    setIO("measurement");
    int n, g;
	cin >> n >> g;
	map <int, int> milk;
      // day, milk
	map <int, int> id;
      // day, id
    map <int, int> cow;
     // id, milk
    set <int> ids;
    for(int i = 0; i < n; i++){
        int d, idd, m;
        cin >> d >> idd >> m;
        ids.insert(idd);
        milk[d] = m;
        id[d] = idd;
    }
    map <int, int, greater <int> > score;
       // score, cnt
    score[0] = n;
    int curMax = 0;
    for(auto x: ids){
        cow[x] = 0;
    }
    int ans = 0;
    for(auto x: milk){
        int day = x.F;
        int prev_score = cow[id[day]];
        int prev_cnt = score[prev_score];
        int cur_score = prev_score + milk[day];
        cow[id[day]] = cur_score;
        if(prev_cnt == 1){
            score.erase(prev_score);
        }
        else{
            score[prev_score]--;
        }
        /// insert current scores
        score[cur_score]++;
        int new_cnt = score[cur_score];

        if(prev_score < curMax and cur_score >= curMax){
            ans++;
        }
        else if(prev_score == curMax and cur_score > curMax and score[prev_score] > 1){
            ans++;
        }
        auto it =  score.begin();
        int newMax = it -> F;

        if(prev_score == curMax and cur_score < newMax){
            ans++;
        }
        else if(prev_score == curMax and cur_score == newMax and score[newMax] > 1){
            ans++;
        }

        curMax = newMax;
    }
    cout << ans << endl;

	return 0;

}