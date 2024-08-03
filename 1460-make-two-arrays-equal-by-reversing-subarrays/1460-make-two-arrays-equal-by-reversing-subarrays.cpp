class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int a[1001];
        for(int i = 0;i<arr.size();i++){
            a[arr[i]]++;
            a[target[i]]--;
        }
        for(int i = 1; i<1001;i++){
            if(a[i]) return false;
        }
        return true;
    }
};