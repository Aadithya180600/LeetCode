class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0) return 1;
        int l = (int)log2(num)+1;
        int k = pow(2, l) - 1;
        return num^k;
    }
};