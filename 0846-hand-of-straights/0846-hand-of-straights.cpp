class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) {
            return false;
        }
        map<int, int> m;
        for(int i: hand){
            m[i]++;
        }
        auto it = m.begin();
        n = m.size();
        while (n >= groupSize) {
            int k = it->first;
            if(m[k] != 0) {
            if(m[k] < 0) return false;
            int l = 1;
            while(l<groupSize){
                if(m.find(k+l) != m.end()){
                    m[k+l] -= m[k];
                }
                else{
                    return false;
                }
                l++;
            }
            
        }
            it++;
            n--;
            cout<<n<<" ";
        }
        while(it!=m.end()){
            if(it->second != 0){
                return false;
            }
            it++;
        }
        return true;
    }
};