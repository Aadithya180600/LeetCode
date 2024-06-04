class Solution {
public:
    int longestPalindrome(string s) {
        int a[26] = {0};
        int A[26] = {0};

        for(int i = 0;i<s.length();i++){
            if(s[i] >= 'a' and s[i]<= 'z') {
                a[s[i]-'a']++;
            }
            else {
                A[s[i]-'A']++;
            }
        }
        int c = 0;
        bool f = false;

        for(int i = 0;i<26;i++){
            if(a[i] %2 == 0) {
                c+=a[i];
            }
            else {
                if(a[i] > 1) {
                    c+=(a[i]-1);
                }
                f = true;
            }
            if(A[i] %2 == 0) {
                c+=A[i];
            }
            else{
                f = true;
                if(A[i] > 1) {
                    c+=(A[i]-1);
                }
            }
        }
        if(f == true) {
            c = c+1;
        }
        return c;
    }
};