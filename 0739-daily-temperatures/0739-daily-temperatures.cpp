class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        int n = t.size();
        vector < int > v(n);
        for(int i=0;i<n;i++){
            if(s.empty()) s.push(i);
            else{
                while(!s.empty() and t[s.top()]<t[i]) {
                    v[s.top()] = i-s.top();
                    s.pop();
                }
                s.push(i);
            }
        } 
        return v;
    }
};