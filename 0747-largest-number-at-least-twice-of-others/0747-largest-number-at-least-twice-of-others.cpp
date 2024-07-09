class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m = 0, mm = -1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[m]){
                mm = nums[m];
                m = i;
            }
            else if(nums[i] > mm){
                mm = nums[i];
            }
        }
        if(nums[m] >= mm*2) return m;
        return -1;
    }
};