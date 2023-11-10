class Solution {
public:
    int countHomogenous(string s) {
        long long c = 0;
        long long a = 1;
        char d = s[0];
        for(int i = 1;i<s.length();i++){
            if(d!=s[i]){
                c = ((a * (a+1))/2)  + c;
                d = s[i];
                a = 0;
            }
            a++;
        }
        c = ((a * (a+1))/2)  + c;
        return c%1000000007;
    }
};