class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int c=0,n=d.size();
        d[n-1]+=1;
        c=d[n-1]/10;
        d[n-1]%=10;
        for(int i=n-2;i>=0;i--) {
            d[i]+=c;
            c=d[i]/10;
            d[i]%=10;
        }
        if(c==1) d.insert(d.begin(),1);
        return d;
    }
};