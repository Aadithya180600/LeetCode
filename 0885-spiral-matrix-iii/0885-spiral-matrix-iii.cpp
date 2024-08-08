class Solution {
public:
    bool inRange(int rows, int cols, int rs, int cs){
        return rs >=0 and rs < rows and cs>=0 and cs < cols;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        int stsz = 1;
        int i = 0, j = 0;
        vector<vector<int>> v;
        v.push_back({rs,cs});
        while(v.size() < rows*cols){
            int k = 0;
            while(k<stsz){
                ++cs;
                if(inRange(rows, cols, rs, cs)) v.push_back({rs,cs});
                k++;
            }
            k = 0;
            while(k<stsz){
                ++rs;
                if(inRange(rows, cols, rs, cs)) v.push_back({rs,cs});
                k++;
            }
            stsz++;
            k = 0;
            while(k<stsz){
                --cs;
                if(inRange(rows, cols, rs, cs)) v.push_back({rs,cs});
                k++;
            }
            k = 0;
            while(k<stsz){
                --rs;
                if(inRange(rows, cols, rs, cs)) v.push_back({rs,cs});
                k++;
            }
            stsz++;
        }
        return v;
    }
};