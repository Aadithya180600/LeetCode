class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l[n];
        int r[n];
        l[0] = nums[0];
        r[n-1] = nums[n-1];
        for(int i = 1; i<nums.size();i++){
            l[i] = nums[i]* l[i-1];
        }
        for(int i = n-2;i>=0;i--){
            r[i] = r[i+1]*nums[i];
        }
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            if(i == 0){
                ans[i] = r[i+1];
            }
            else if(i == n-1)
            {
                ans[i] = l[i-1];
            }
            else{
                ans[i] = l[i-1]*r[i+1];
            }
        }
        return ans;
    }
};