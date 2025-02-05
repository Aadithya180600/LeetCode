class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int i = 0;
        while(i<n and s1[i] == s2[i]) i++;
        char c1, c2;
        if(i != n) { c1 = s1[i]; c2 = s2[i]; i++; }
        else return true;
        while(i<n and s1[i] == s2[i]) i++;
        if(i == n or c1 != s2[i] or c2 != s1[i]) return false;
        i++;
        while(i<n and s1[i] == s2[i]) i++;
        return i == n;
    }
};