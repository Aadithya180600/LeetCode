class Solution {
public:
    int firstUniqChar(string s) {
        int a[26];
        memset(a, -1, 26*4);
        char c;
        int k = -1;
        for(int i=0;i<s.length();i++) {
            c = s[i]-'a';
            if(a[c] == -1) a[c] = i;
            else if(a[c]>-1) a[c] = -2;
        }

        for(int i=0;i<26;i++){
            cout<<a[i]<<" ";
            if(a[i]>=0){
                if(k == -1) k=a[i];
                else if(k>a[i]) k = a[i];
            }
        }

        return k;
    }
};