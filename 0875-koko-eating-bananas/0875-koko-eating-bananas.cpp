class Solution {
public:
    int fun(vector<int>& piles, int& num, int& h){
        int s = 0;
        for(int it: piles){
            s+= ((it-1)/num);
            s+=1;
        }
        return s;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = 0;
        for_each(piles.begin(), piles.end(), [&](int a){
            m = max(m, a);
        });
        if(n == h) return m;
        int hi = m, lo =1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            int l = fun(piles, mid, h);
            if(l <= h){
                hi = mid;
            }
            else lo = mid+1;
        }
        return lo;
    }
};