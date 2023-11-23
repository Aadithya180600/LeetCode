class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mi = 100001, ma = -100001;
        int mi1 = 100001, ma1 = -100001;
        int l,l1;
        int t,t1;
        for(int i = 0;i<arrays.size();i++){
            vector<int> v = arrays[i];
            if(v[0] <= mi) {
                if(mi1 > mi){
                    l1 = l;
                    mi1 = mi;
                }
                l = i;
                mi = v[0];

            }
            else if(v[0]<mi1){
                l1 = i;
                mi1 = v[0];
            }
            if(v.back() >= ma) {
                if(ma1 < ma){
                    t1 = t;
                    ma1 = ma;
                }
                t = i;
                ma = v.back();
            }
            else if(v.back() >= ma1){
                t1 = i;
                ma1 = v.back();
            }
        }
        if(l == t){
            return max(abs(ma - mi1), abs(ma1 - mi));
        }
        return ma-mi;
    }
};