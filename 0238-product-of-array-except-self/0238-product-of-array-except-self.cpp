class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        vector<int> r(n);
        r[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            r[i] = r[i+1]*nums[i];
        }

        for(int i = 0;i<n-1;i++){
            r[i] = l*r[i+1];
            l = l * nums[i];
        }
        r[n-1] = l;
        return r;
    }
};