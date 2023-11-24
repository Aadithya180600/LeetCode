class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int s = 0;
        for(int i = n/3; i<n;i+=2){
            s+=piles[i];
        }
        return s;
    }
};