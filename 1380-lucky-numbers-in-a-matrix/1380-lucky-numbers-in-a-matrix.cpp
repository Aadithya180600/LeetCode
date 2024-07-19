class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> minl, maxl;
        for(auto v : matrix){
            minl.push_back(*min_element(v.begin(), v.end()));
        }
        cout<<"here1\n";
        for(int i = 0; i<matrix[0].size();i++){
            int maxv = 0;
            cout<<"here2\n";
            for(int j = 0;j<matrix.size();j++){
                if(maxv < matrix[j][i]){
                    maxv = matrix[j][i];
                }
            }
            cout<<"here3\n";
            if(find(minl.begin(), minl.end(), maxv) != minl.end()){
                maxl.push_back(maxv);
            }
        }
        cout<<"here4\n";
        return maxl;
    }
};