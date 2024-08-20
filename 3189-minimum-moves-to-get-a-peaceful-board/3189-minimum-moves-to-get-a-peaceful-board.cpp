class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int n = rooks.size();
        vector<vector<int>> v(rooks.begin(), rooks.end());
        sort(v.begin(), v.end());
        int k = 0;
        int s = 0;
        for(int i = 0; i<n;i++){
            s+=(abs(v[i][0] - k));
            k++;
        }
        sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        k = 0;
        for(int i = 0; i<n;i++){
            s+=(abs(v[i][1] - k));
            k++;
        }
        return s;
    }
};