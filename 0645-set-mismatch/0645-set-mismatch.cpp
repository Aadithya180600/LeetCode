class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m;
        int k = 1;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int a = 0,b = 0;
        for(auto it : m){
            cout<<it.first<<" "<<it.second<<"\n";
            if(it.first != k) {
                a = k; 
                k++;
            }
            
            if(it.second>1){
                b = it.first;
            }
            k++;
        }
        if(a == 0) a = nums.size();
        return {b,a};
    }
};