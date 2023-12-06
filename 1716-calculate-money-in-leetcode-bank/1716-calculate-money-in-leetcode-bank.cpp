class Solution {
public:
    int totalMoney(int n) {
        int r = 0;
        int c = 0;
        int l = 0;
        int z = 0;
        while(l<n){
          if(l%7 == 0){
            r++;
            z = r;
          }
          else{
            z++;
          }
          c+=z;
          l++;
        }
        return c;
    }
};