class Solution {
public:
    int fun(int n){
        if(n !=1){
            for(int i = 2;i<=n;i++){
                if(n%i == 0){
                    return fun(n/i) + i;
                }
            }
        }
        return 0;
    }
    int minSteps(int n) {
        return fun(n);
    }
};