class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool a[26] = {0};
        for(char c: allowed){
            a[c-'a']=1;
        }
        int count = 0;
        bool flag = true;
        for(string s: words){
            flag = true;
            for(char c: s){
                if(!a[c-'a']) {
                    flag = false;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};