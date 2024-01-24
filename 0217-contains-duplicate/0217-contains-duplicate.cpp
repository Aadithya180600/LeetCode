class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(int i:nums){
            if(m.find(i) != m.end()){
                return true;
            }
            m[i] = 1;
        }
        return false;
    }
};