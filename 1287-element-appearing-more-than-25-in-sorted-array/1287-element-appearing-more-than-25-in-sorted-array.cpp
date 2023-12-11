class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int> m;
        for(int i:arr){
            m[i]++;
        }
        int n = arr.size();
        for(auto i:m){
            if(i.second>n/4){
                return i.first;
            }
        }
        return 0;
    }
};