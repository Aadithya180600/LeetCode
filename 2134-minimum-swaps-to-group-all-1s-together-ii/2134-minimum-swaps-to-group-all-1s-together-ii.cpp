class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), a = 0;
        for(int i :nums){
            if(i) a++;
        }
        if(a==n or a == 0) return 0;
        int z = 0, min = 0;
        for(int i=0;i<a;i++){
            if(!nums[i]) z++;
        }
        min = z;
        int i = 1, m = n*2-a;
        while(i<=m){
            if(nums[(i-1)%n] == 0) z--;
            if(nums[(i+a-1)%n] == 0) z++;
            if(min>z) min = z;
            i++;
        }
        return min;
    }
};