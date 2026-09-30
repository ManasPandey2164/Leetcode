class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cnt = 0;
        int sum = 0;
        int ans = 0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]+sum>0){
                sum = sum+nums[i];
                cnt++;
            }
            else{
                sum = 0;
            }
            ans = max(ans,sum);
            i++;
        }
        if(!cnt){
            sum = nums[0];
            for(int i=1;i<nums.size();i++){
                sum = max(sum,nums[i]);
            }
            ans = sum;
        }
        return ans;
    }
};