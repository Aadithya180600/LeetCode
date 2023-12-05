class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int m = -1;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int r = nums[i]+ nums[j];
                if(r > m and r<k){
                    m = r;
                }
            }
        }
        return m;
    }
};