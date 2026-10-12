
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size());
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            mp[nums2[i]] = ans[i];
            st.push(nums2[i]);
        }

        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(mp[nums1[i]]);
        }

        return result;
    }
};
