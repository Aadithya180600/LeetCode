class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int a[1001] = {0};
        int n = (int)nums.size();
        vector<int> v;
        for(int i = 0;i<n;i++){
            for(int j:nums[i]){
                a[j]++;
            }
        }
        for(int i=0;i<1001;i++){
            if(a[i]==n){
                v.push_back(i);
            }
        }
        return v;
    }
};