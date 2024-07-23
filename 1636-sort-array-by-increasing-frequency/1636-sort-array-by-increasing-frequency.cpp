class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        for(int i : nums){
            m[i]++;
        }
        vector<pair<int, int>> v;
        for(auto it: m){
            v.push_back(make_pair(it.first, it.second));
        }
        sort(v.begin(), v.end(), [](auto a, auto b){
            if(a.second != b.second) return a.second < b.second;
            else return b.first < a.first;
        });
        // for(auto it: m){
        //     // cout<<it.first<<" "<<it.second<<"\n";
        //     v.push_back(make_pair(it.second, it.first));
        // }
        // sort(v.begin(), v.end());
        vector<int> ans;
        for(auto it : v){
            cout<<it.first<<" "<<it.second<<"\n";
            while(it.second --){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};