class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = 0, n=nums.size();
        for(int i=0;i<nums.size();i++) s+=nums[i];
        int e = (n*(n+1))/2;
        return e-s;
    }
};