class Solution {
public:
    vector<vector<int>> mm;
    int mod = 1e9 + 7;
    int fun(unordered_map<int, vector<int>>& m, int n, int l){
        if(n == 0) {
            return 1;
        }
        if(mm[n][l]!=0){
            return mm[n][l];
        }
        int k = 0;
        for(auto i: m[l]){
            k = (k%mod + fun(m, n-1, i)%mod)%mod;
        }
        mm[n][l] = k;
        return k;
    }
    
    int knightDialer(int n) {
        unordered_map<int, vector<int>> m;
        m[0] = {4, 6};
        m[1] = {6, 8};
        m[2] = {7, 9};
        m[3] = {4, 8};
        m[4] = {0, 3, 9};
        m[5] = {};
        m[6] = {0, 1, 7};
        m[7] = {2, 6};
        m[8] = {1, 3};
        m[9] = {2, 4};

        mm = vector(n+1, vector(10, 0));
        int a = 0;
        for(int i = 0;i<10;i++){
            a = (a + fun(m, n-1, i))%mod;
        }
        return a;
    }
};