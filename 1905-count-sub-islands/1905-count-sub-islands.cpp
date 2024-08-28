class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vi(n, vector<bool> (m, 0));
        int x, y;
        stack<pair<int, int>> s;
        int c = 0;
        for(int i=0; i<n;i++){
            for(int j = 0; j<m; j++){
                bool flag = false;
                if(grid[i][j] == 1 and vi[i][j] == 0){
                    s.push({i,j});
                    while(!s.empty()) {
                        pair<int, int> p = s.top();
                        s.pop();
                        x = p.first;
                        y = p.second;
                        if(grid1[x][y] == 0) flag = true;
                        if(x+1 != n && grid[x+1][y] == 1 && vi[x+1][y] == 0) {
                            s.push(make_pair(x+1, y));
                            vi[x+1][y] = 1;
                        }
                        if(x != 0 && grid[x-1][y] == 1 && vi[x-1][y] == 0) {
                            s.push(make_pair(x-1, y));
                            vi[x-1][y] = 1;
                        }
                        if(y+1 != m && grid[x][y+1] == 1 && vi[x][y+1] == 0) {
                            s.push(make_pair(x, y+1));
                            vi[x][y+1] = 1;
                        }
                        if(y != 0 && grid[x][y-1] == 1 && vi[x][y-1] == 0) {
                            s.push(make_pair(x, y-1));
                            vi[x][y-1] = 1;
                        }
                    }
                    if(!flag) c++;
                }
            }
        }
        return c;
    }
};