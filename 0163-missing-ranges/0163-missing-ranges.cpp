class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {        
        int s = nums.size();
        if(s == 0) {
            return {{lower, upper}};
        }
        vector<vector<int>> v;
        int l = 0, i;
        for(i = 0; i < s; i++){
            if(nums[i] == lower) {
                lower++;
            }
            else{
                v.push_back({lower, nums[i]-1});
                lower = nums[i]+1;
            }
        }
        if(nums[i-1] < upper) {
            v.push_back({nums[i-1]+1, upper});
        }
        return v;
    }
};