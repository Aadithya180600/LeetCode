class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long l = 0, r = 0;
        long long t = 0, c = 0;
        while(r<n){
            t+=nums[r];
            while((nums[r] * (r-l+1)*1LL) > (t + k)){
                t-=nums[l];
                l++;
            }

            c = max(c, (r-l+1)*1LL);
            r++;
        }
        return c;
    }
};