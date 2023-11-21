class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int n = b.size();
        for(int i = 0; i<9; i = i+3){
            for(int j = 0; j<9; j = j+3) {
                int a[10] = {0};
                for(int x = i;x<i+3;x++){
                    for(int z = j;z<j+3;z++){
                        if(b[x][z] != '.')
                            a[b[x][z] - '0']++;
                    }
                }
                for(int z = 0;z<10;z++) {
                    if(a[z] > 1) return false;
                }
            }
        }
        for(int i = 0;i<9;i++){
            int a[10] = {0};
            for(int j = 0;j<9;j++) {
                if(b[i][j] != '.'){
                    a[b[i][j] - '0']++;
                }
            }
            for(int j = 0;j<10;j++) {
                if(a[j] > 1) return false;
            }
        }
        for(int i = 0;i<9;i++){
            int a[10] = {0};
            for(int j = 0;j<9;j++) {
                if(b[j][i] != '.')
                    a[b[j][i] - '0']++;
            }
            for(int j = 0;j<10;j++) {
                if(a[j] > 1) return false;
            }
        }
        
        return true;
    }
};