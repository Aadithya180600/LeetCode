class Solution {
public:
    bool isop(string s){
        if(s=="+" or s=="-" or s=="*" or s == "/") return true;
        return false;
    }
    long long eval(long long x, long long y, char s){
        switch(s){
            case '+': return x+y;
            case '-': return x-y;
            case '*': return x*y;
            case '/': return x/y;
        }
        return 0;
    }
    int evalRPN(vector<string>& t) {
        stack<long long> s;
        long long n = t.size(), x = 0, y = 0;
        for(int i=0;i<n;i++){
            if(isop(t[i])){
                x = s.top(); s.pop();
                y = s.top(); s.pop();
                x = eval(y, x, t[i][0]);
                s.push(x);
            }
            else{
                x = stoi(t[i]);
                s.push(x);
            }
        }
        return s.top();
    }
};