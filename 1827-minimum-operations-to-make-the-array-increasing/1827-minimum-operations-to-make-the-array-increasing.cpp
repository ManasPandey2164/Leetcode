class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=1;
        int cnt =0;
        while(i<nums.size()){
            if(nums[i-1]<nums[i]) i++;
            else{
                nums[i]++;
                cnt++;
            }
        }
        return cnt;
    }
};