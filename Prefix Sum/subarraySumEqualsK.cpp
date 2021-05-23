//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector <int> pre(nums.size()+1);
        for(int i = 1; i <= nums.size(); i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        map <int, int> m;
        int ans = 0;
        m[0] = 1;
        for(int i = 1; i <= nums.size(); i++){
            
            if(m.find(pre[i] - k) != m.end()){  // what I need to add 
                ans += m[pre[i] - k];           // if addition == subtraction ans++;
            }
            m[pre[i]]++;  // what i need to subtract
            
        }
        return ans;
    }
    
};

int main() {

    int n, k;
    cin >> n >> k;
    vector <int> ara(n);
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }

    Solution s = Solution();
    cout << s.subarraySum(ara, k) << endl;
    
    return 0;
}
