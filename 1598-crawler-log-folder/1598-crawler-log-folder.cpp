class Solution {
public:
    int minOperations(vector<string>& logs) {
        int a = 0;
        for(auto s: logs){
            if(s == "../" and a != 0) {
                a--;
            }
            else if(s == "./" or s == "../") continue;
            else a++;
        }
        return a;
    }
};