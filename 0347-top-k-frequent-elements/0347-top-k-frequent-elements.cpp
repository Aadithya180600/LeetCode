class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        auto comp = [&m](int a, int b) { return m[a] > m[b];};

        priority_queue<int, vector<int>, decltype(comp)> heap(comp);

        for(auto i : m){
            heap.push(i.first);
            if(heap.size() > k) heap.pop();
        }

        vector<int> res(k);
        for(int i = k-1; i>=0;i--){
            res[i] = heap.top();
            heap.pop();
        }
        return res;
    }
};