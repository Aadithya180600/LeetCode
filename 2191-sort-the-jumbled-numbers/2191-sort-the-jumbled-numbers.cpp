class Solution {
public:
    int mapped(vector<int> mapping, int num){
        if(num == 0) return mapping[0];
        int res = 0;
        int i = 1;
        while(num){
            int rem = (num%10);
            res += mapping[rem] * i;
            i*=10;
            num/=10;
        }
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> res;
        for(int i: nums){
            res.push_back(mapped(mapping, i));
        }
        vector<int> ind(nums.size());
        iota(ind.begin(), ind.end(), 0);
        stable_sort(ind.begin(), ind.end(), [&res](int a, int b){
            return res[a] < res[b];
        });
        vector<int> ans;
        for(int i: ind){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};