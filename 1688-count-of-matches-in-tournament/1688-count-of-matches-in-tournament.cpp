class Solution {
public:
    int numberOfMatches(int n) {
        int r = 0;
        while(n!=1){
            if(n%2==0){
                n/=2;
                r+=n;
            }
            else{
                n = ((n-1)/2);
                r+=n;
                n++;
            }
        }
        return r;
    }
};