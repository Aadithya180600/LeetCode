class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int n = v.size(), i=0,j;
        if(n==0) return 0;
        while(1){
            if(v[i]==val) {
                for(j=i+1;j<n;j++){
                    if(v[j]!=val) {
                        swap(v[i],v[j]);
                        i++;
                        break;
                    }
                }
                if(j==n) {
                    return i;
                }
            }
            else {
                i++;
                if(i==n)  break;
            }
        }
        return i;
    }
};