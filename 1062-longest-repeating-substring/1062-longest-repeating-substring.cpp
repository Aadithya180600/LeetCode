class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        for(int w = n-1;w>=1;w--){
            int j = 0;
            set<string> m;
            while(j <= n-w){
                string t = s.substr(j,w);
                if(m.find(t) != m.end()){
                    return t.length();
                }
                else{
                    m.insert(t);
                }
                j++;
            }
        }
        return 0;
    }
};