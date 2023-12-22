class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int m = 0, o = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '1') o++;
        }
        
        int nz = 0;
        for(int i = 0;i<n-1;i++){
            if(s[i] == '0'){
                nz++;
            }
            else{
                o--;
            }
            if(m < o+nz){
                m = o+nz;
            }
        }
        return m;
    }
};