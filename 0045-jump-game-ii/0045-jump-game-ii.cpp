class Solution {
public:
    int jump(vector<int>& nums) {
        int j = 0, cm = 0, m = 0;

        if(nums.size() == 1) return 0;

        for(int i=0;i<nums.size()-1;i++){
            cm = max(cm, i+ nums[i]);

            if(i == m){
                j++;
                m = cm;
            }
        }

        return j;
    }
};