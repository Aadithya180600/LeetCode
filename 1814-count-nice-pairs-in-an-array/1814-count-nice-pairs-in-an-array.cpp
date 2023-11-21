class Solution {
public:
    int get_rev(int n){
        int r = 0;
        while(n){
            r*=10;
            r+=(n%10);
            n/=10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i<nums.size();i++){
            m[nums[i]-get_rev(nums[i])]++;
        }
        long long c = 0, k;
        for(auto it:m){
            k = it.second;
            c = c + ((k) * (k-1))/2;
            c%=1000000007;
        }
        return c;
    }
};