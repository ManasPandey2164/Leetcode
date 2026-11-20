class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, bool> mp;

        for(int num : nums) {
            mp[num] = true;
        }

        int ans = 0;

        for(auto it : mp) {

            int num = it.first;

            if(mp.find(num - 1) == mp.end()) {

                int cnt = 1;

                while(mp.find(num + cnt) != mp.end()) {
                    cnt++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};