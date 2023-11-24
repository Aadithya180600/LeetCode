class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int n = piles.size();
        int j = n-1;
        int i = 1, s = 0;
        while(i<=j){
            s+=piles[i];
            i+=2;
            j--;
        }
        return s;
    }
};