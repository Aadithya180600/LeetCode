class MovingAverage {
public:
    int size;
    queue<int> q;
    int total;
    MovingAverage(int s) {
        size = s;
        queue<int> new_queue;
        q.swap(new_queue);
        total = 0;
    }
    
    double next(int val) {
        if(q.size() < size){
            q.push(val);
            total+=val;
        }
        else{
            total-=q.front();
            q.pop();
            total+=val;
            q.push(val);
        }
        return (double)total/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */