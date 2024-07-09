class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int w = c[0][0]+c[0][1];
        double s = c[0][1];
        for(int v = 1; v<c.size();v++){
            if(c[v][0] > w) {
                w = c[v][0];
            }
            w += c[v][1];
            s+=(w-c[v][0]);
        }
        return s/(c.size());
    }
};