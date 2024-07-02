class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int a[1001] = {0};
        vector<int> v;
        for(int i = 0; i< nums1.size(); i++){
            a[nums1[i]]++;
        }
        for(int i = 0; i< nums2.size(); i++){
            if(a[nums2[i]]) {
                v.push_back(nums2[i]);
                a[nums2[i]]--;
            }
        }
        return v;
    }
};