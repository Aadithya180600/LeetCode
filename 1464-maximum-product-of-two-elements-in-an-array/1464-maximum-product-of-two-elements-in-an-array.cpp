class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int c = 0, n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((nums[i]-1)*(nums[j]-1) > c) c = (nums[i]-1)*(nums[j]-1);
            }
        }
        return c;
    }
};