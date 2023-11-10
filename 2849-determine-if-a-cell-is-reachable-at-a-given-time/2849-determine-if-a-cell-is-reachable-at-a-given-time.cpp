class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(fx - sx);
        int y = abs(fy - sy);
        int m = min(x, y);
        int d = x + y - m;
        if(d>t) return false;
        if(d ==0 && t == 1) return false;
        return true;
    }
};