class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int cnti = 1;
        int cntd = 1;
        for(int i=1;i<nums.size();i++){
            cnti = (nums[i]>nums[i-1]) ? cnti+1 : 1;
            cntd = (nums[i]<nums[i-1]) ? cntd+1 : 1;
            ans = max(ans,max(cnti,cntd));
        }
        return ans;
    }
};