class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> m; // For count of each color
        map<int, int> btc; // ball to color
        int c = 0; // Number of unique colors
        vector<int> result;
        for(auto v: queries){
            if(btc.find(v[0]) != m.end()){
                int currColor = btc[v[0]];
                if(currColor == v[1]) {
                    result.push_back(c);
                    continue;
                }
                m[currColor]--;
                if(m[currColor] == 0) c--;
                btc[v[0]] = v[1];
                m[v[1]]++;
                if(m[v[1]] == 1) c++;
            }
            else{
                btc[v[0]] = v[1];
                m[v[1]]++;
                if(m[v[1]] == 1){
                    c++;
                }
                // else if(m[v[1]] == 2){
                //     c--;
                // }
            }
            result.push_back(c);
        }
        return result;
    }
};