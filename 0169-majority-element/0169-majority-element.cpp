class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(),c=0,mx=0;
        map<int,int> m;
        for(int i=0;i<n;i++) m[nums[i]]++;
        for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
            if(it->second > mx) mx = it->second,c=it->first;
        }
        return c;
    }
};