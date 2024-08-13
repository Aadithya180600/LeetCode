class Solution {
public:
    int s = 0;
    int mid(int a, int b) {
        if((a == 1 && b == 3) || (a == 3 && b == 1)) return 2;
        if((a == 1 && b == 7) || (a == 7 && b == 1)) return 4;
        if((a == 3 && b == 9) || (a == 9 && b == 3)) return 6;
        if((a == 7 && b == 9) || (a == 9 && b == 7)) return 8;
        if((a == 1 && b == 9) || (a == 9 && b == 1) || (a == 3 && b == 7) || (a == 7 && b == 3)) return 5;
        if((a == 2 && b == 8) || (a == 8 && b == 2)) return 5;
        if((a == 4 && b == 6) || (a == 6 && b == 4)) return 5;
        
        return -1; 
}

    void fun(vector<bool> a, int m, int n, int c, int r){
        if(c >= m and c <= n){
            s++;
        }
        if(c >= n) return;
        for(int i =1;i<10;i++){            
            if(!a[i]) {
                    int z = mid(r, i);
                    if(z == -1 or a[z]){
                    a[i] = 1;
                    fun(a, m, n, c+1, i);
                    a[i] = 0;
                }
            }
        }
    }
    int numberOfPatterns(int m, int n) {
        fun({0,0,0,0,0,0,0,0,0,0}, m, n, 0, 0);
        return s;
    }
};