class Solution {
public:
    bool isB(int x, int y, int n){
        if(x >= 0 and x <n and y >=0 and y<n) return true;
        return false;
    }
    int findMin(int a, int b, int c) {
        int min = a;

        if (b < min) {
            min = b;
        }
        if (c < min) {
            min = c;
        }

        return min;
    }
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int s = INT_MAX;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                int a=INT_MAX, b=INT_MAX, c=INT_MAX;
                if(isB(i-1, j-1, n)){
                    a = v[i-1][j-1];
                }
                if(isB(i-1, j, n)){
                    b = v[i-1][j];
                }
                if(isB(i-1, j+1, n)){
                    c = v[i-1][j+1];
                }
                v[i][j] += findMin(a, b, c);
            }
        }
        for(int i: v[n-1]){
            if(s > i){
                s = i;
            }
        }
        return s;
    }
};