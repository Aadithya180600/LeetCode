class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        vector<int> a(26, -1);
        int count = 0;
        for(char c: tasks){
            m[c]++;
        }
        priority_queue<pair<int, char>> q;
        for(auto it : m){
            q.push(make_pair(it.second, it.first));
        }
        bool f = 0;
        while(!q.empty()){
            f= 0;
            vector<pair<int, char>> v;
            while(!q.empty()){
                auto temp = q.top();
                q.pop();
                if(count > a[temp.second - 'A']){
                    a[temp.second - 'A'] = count+n;
                    count++;
                    if(temp.first != 1) v.push_back(make_pair(temp.first - 1, temp.second));
                    f=1;
                    break;
                }
                v.push_back(temp);
            }
            for(auto it: v){
                q.push(it);
            }
            if(!f and !q.empty()) {
                count++;
            }
        }
        return count;
    }
};