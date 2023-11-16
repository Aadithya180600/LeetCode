class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        stringstream ss;
        int k;
        int i;
        int m = 1;
        for(i = 0;i<n;i++){
            k=0;
            m=1;
            for(int j = n-1;j>=0;j--){
                if(nums[i][j] == '1'){
                    k+= m;
                }
                m*=2;
            }
            if(k != i) break;
        }
        cout<<i<<"\n";
        string t = "";
        while(i!=0){
            if(i%2){
                t+='1';
            }
            else{
                t+='0';
            }
            i/=2;
        }
        cout<<t;
        while(t.length() < n) t+='0';
        reverse(t.begin(), t.end());
        return t;
    }
};