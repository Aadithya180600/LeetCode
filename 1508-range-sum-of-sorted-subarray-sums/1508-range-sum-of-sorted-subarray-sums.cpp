class Solution {
public:

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int w = 1;
        int mod = 1000000007;
        vector<long long> v(nums.begin(), nums.end());
        for(int w = 2;w<=n;w++){
            int s = 0;
            int i = 0;
            while(i<w){
                s+=nums[i];
                i++;
            }
            v.push_back(s);
            for(i = 1;i<=n-w;i++){
                s = s - nums[i-1] + nums[i+w-1];
                v.push_back(s);
            }
        }
        sort(v.begin(), v.end());
        long long res = 0;
       
        for(int i = left-1;i<right;i++){
            res = (res % mod + v[i] % mod) % mod;
        }
        return res;
    }
};