class Solution {
public:
    vector<int> v;
    void fun(int l, int h, int r, int m) {
        if(m == 9) return;
        long k = r*10 + m+1;
        long g = (m+1)*10;
        if(k>l and k<h){
            v.push_back(k);
            fun(l, h, k, m+1);
        }
        if(k<l){
            fun(l, h, k, m+1);
        }
        if(k>h) return;
        fun(l, h, g, m+2);
    }
    vector<int> sequentialDigits(int low, int high) {
        // fun(low, high, 1, 1);
        vector<int> ans;
        for(int i = 1;i<10;i++){
            long k = i;
            for(int j = i+1;j<10;j++){
                k = k*10 + j;
                 if(k>=low and k<=high){
                    ans.push_back(k);
                }
                else if(k>high) {
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};