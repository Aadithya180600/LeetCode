class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int l = 0, r = 0;
        vector<int> d, m;
        d.push_back(0);
        m.push_back(0);
        for(int i = 1;i<nums.size();i++){
            d.push_back(nums[i]-nums[i-1]);
            m.push_back(d[i]+m[i-1]);
        }
        for(int i:m) {
            r+=i;
        }
        vector<int> res;
        int n = d.size();
        
        for(int i = 0;i<d.size();i++){
            l+=(d[i] * i);
            r-=(d[i]*(n-i));
            res.push_back(l+r);
        }
        return res;
    }
};