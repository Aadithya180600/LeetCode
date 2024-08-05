class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for(string i: arr){
            m[i]++;
        }
        for(string i: arr){
            if(m[i] == 1){
                if(k == 1) {
                    return i;
                }
                k--;
            }
        }
        return "";
    }
};