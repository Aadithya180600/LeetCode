class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int r = nums[0];
        vector<vector<int>> v;
        int c = 0;
        vector<int> z;
        for(int i = 0;i<nums.size();i++){
            // cout<<nums[i]<<" "<<r<<"\n";
            if(nums[i]- r > k) return {};
            else {
                c++;
                z.push_back(nums[i]);
                // r = nums[i];
            }
            if(c == 3){
                c = 0;
                v.push_back(z);
                z.clear();
                r = nums[i+1];
            }
        }
        return v;
    }
};