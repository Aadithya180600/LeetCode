class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int f[26] = {[0 ... 25] = -1};
        int l[26] = {0};
        // for(int i = 0;i<26;i++){
        //     cout<<f[i]<<" ";
        // }
        for(int i = 0;i<s.length();i++){
            if(f[s[i]-'a'] == -1){
                f[s[i]-'a'] = i;
            }
            l[s[i]-'a'] = i;
        }
        // for(int i = 0;i<26;i++){
        //     cout<<i+'a'<<" "<<f[i]<<" "<<l[i]<<"\n";
        // }
        int c = 0;
        for(int i = 0;i<26;i++){
            if(f[i]<l[i])
                c += unordered_set<char>(s.begin()+f[i]+1, s.begin()+l[i]).size();
        }
        return c;
    }
};