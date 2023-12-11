class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int c = 1;
        double f = arr.size()/4;
        for(int i = 1;i<arr.size();i++){
            if(arr[i] == arr[i-1]){
                c++;
                if(c > f) return arr[i];
            }
            else{
                c = 1;
            }
        }
        return arr[0];
    }
};