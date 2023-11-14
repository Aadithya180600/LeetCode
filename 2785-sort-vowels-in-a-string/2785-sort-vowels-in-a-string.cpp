class Solution {
public:
    string sortVowels(string s) {
        map<char, int> m;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(s[i]=='A' || s[i] == 'E' || s[i]=='I' || s[i] == 'O' || s[i] == 'U'){
                m[s[i]]++;
            }
            else if(s[i]=='a' || s[i] == 'e' || s[i]=='i' || s[i] == 'o' || s[i] == 'u'){
                m[s[i]]++;
            }
        }
        auto it = m.begin();
        string t = "";
        for(int i = 0;i<n;i++){
            if(m.find(s[i]) == m.end()) t+=s[i];
            else{
                t+=it->first;
                it->second--;
                if(it->second == 0) it++;
            }
        }
        return t;
    }
};