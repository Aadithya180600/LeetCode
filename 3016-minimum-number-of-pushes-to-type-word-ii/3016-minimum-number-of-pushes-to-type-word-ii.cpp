class Solution {
public:
    int minimumPushes(string word) {
        vector<int> a(26, 0);
        for(char c: word){
            a[c-'a']++;
        }
        sort(a.begin(), a.end(), greater<int>());
        int r = 0, l=1, s = 0;
        for(int i: a){
            s+= i*l;
            r++;
            if(r%8 == 0){
                l++;
            }
        }
        return s;
    }
};