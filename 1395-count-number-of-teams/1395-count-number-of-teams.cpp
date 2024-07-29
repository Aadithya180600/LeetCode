class Solution {
public:
    long long k = 0;
//     void fun(vector<int>& rating, int i, int a, int b, int c){
//         if(!(a == 0 or b == 0 or c == 0)){
//         if((a < b && b < c) or ( a>b && b>c)){
//             k++; 
//         }
//         return;
//         }
//         for(int j = i; j<rating.size();j++){
//             if(a == 0) {
//                 a = rating[j];
//                 fun(rating, j+1, a, b, c);
//                 a = 0;
//             }
//             else if(b == 0) {
//                 b = rating[j];
//                 fun(rating, j+1, a, b, c);
//                 b = 0;
//             }
//             else if(c == 0) {
//                 c = rating[j];
//                 fun(rating, j+1, a, b, c);
//                 c = 0;
//             }
//         }
        
//     }
    int numTeams(vector<int>& v) {
        // fun(rating, 0, 0, 0, 0);
        // return k;
        int i = 0, j = 1, x, n = v.size();
        while(i < n-1){
            while(j< n and v[i] > v[j]) j++;
            if(j == n) {
                i++;
                j = i+1;
                continue;
            }
            x = j;
            while(x<n) {
                if(v[j] < v[x]) {
                    k++;
                }
                x++;
            }
            j++;
        }
        i = n-1, j = i-1;
        while(i > 1){
            while(j>=0 and v[i] > v[j]) j--;
            if(j == -1) {
                i--;
                j = i-1;
                continue;
            }
            x = j-1;
            while(x>=0){
                if(v[j] < v[x]) {
                    k++;
                }
                x--;
            }
            j--;
        }
        return k;
    }

};