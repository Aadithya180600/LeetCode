static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) != m.end()){
                return {i, m[nums[i]]};
            }
            else{
                m[target - nums[i]] = i;
            }
        }
        return {};
    }
};