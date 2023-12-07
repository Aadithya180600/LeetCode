class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length(),f=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]!=' ') f++;
            else if(f) return f;
        }
        return f;
    }
};