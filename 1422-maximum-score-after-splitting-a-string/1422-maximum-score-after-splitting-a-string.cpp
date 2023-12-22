class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int m = 0, zz=0, oo=0;
        vector<int> z(n), o(n);
        for(int i = 0;i<n;i++){
            if(s[i] == '0') {
                zz++;
                z[i] = zz;
            }
            if(s[n-i-1] == '1') {
                oo++;
                o[n-i-1] = oo;
            }
            // cout<<i<<"\n";
        }
        for(int i = 0;i<n-1;i++){
            cout<<z[i]<<" "<<o[i+1]<<"\n";
            if(m < z[i]+o[i+1]) m = z[i]+o[i+1];
        }
        return m;
    }
};