class Solution {
public:
    bool fun(vector<int> v){
        int n = v.size();
        if(n<=2) return true;
        int k = v[1]-v[0];
        for(int i =2;i<n;i++){
            if(v[i]-v[i-1] != k) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i = 0;i<l.size();i++){
            vector<int> v(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(v.begin(), v.end());
            res.push_back(fun(v));
        }
        return res;
    }
};