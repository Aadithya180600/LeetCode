class CustomStack {
public:
    vector<int> v;
    int i;
    CustomStack(int maxSize) {
        v = vector<int>(maxSize);
        i = 0;
    }
    
    void push(int x) {
        if(i != v.size()){
            v[i] = x;
            i++;
        }
    }
    
    int pop() {
        if(i == 0) return -1;
        i--;
        return v[i];
    }
    
    void increment(int k, int val) {
        int j = 0;
        while(j<k and j<i){
            v[j] += val;
            j++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */