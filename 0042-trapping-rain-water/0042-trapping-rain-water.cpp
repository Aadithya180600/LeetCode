class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size()-1;
        int lm = h[0], rm = h[r], s = 0;
        while(l<r){
            if(lm < rm){
                l++;
                lm = max(h[l], lm);
                s+=(lm - h[l]);
            }
            else{
                r--;
                rm = max(rm, h[r]);
                s+=(rm - h[r]);
            }
        }
        return s;
    }
};