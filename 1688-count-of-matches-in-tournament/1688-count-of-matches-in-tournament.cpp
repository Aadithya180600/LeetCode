class Solution {
public:
    int numberOfMatches(int n) {
        int c = 0;
        while(n!=1){
            if(n%2==0){
                n/=2;
                c+=n;
            }
            else{
                n = ((n-1)/2);
                c+=n;
                n++;
            }
        }
        return c;
    }
};