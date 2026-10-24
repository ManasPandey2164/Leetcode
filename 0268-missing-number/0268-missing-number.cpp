class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<=nums[nums.size()-1];i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return nums[nums.size()-1]+1;
    }
};