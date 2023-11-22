class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        int n = nums.size();
        int m = 0;
        for(auto i : nums){
            if(i.size() > m) m = i.size();
        }
        vector<vector<bool>> v(n, vector<bool>(m, 0));
        vector<int> res;
        q.push(make_pair(0,0));
        v[0][0] = 1;
        int x, y;
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            res.push_back(nums[x][y]);
            if(x+1<n and y<nums[x+1].size() and !v[x+1][y]) {
                q.push(make_pair(x+1, y));
                v[x+1][y] = 1;
            }
            if(y+1<nums[x].size() and !v[x][y+1]) {
                q.push(make_pair(x, y+1));
                v[x][y+1] = 1;
            }
        }
        return res;
    }
};