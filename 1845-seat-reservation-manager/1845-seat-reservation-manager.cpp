class SeatManager {
public:

    int s;
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        s = 0;
    }
    
    int reserve() {
        if(!pq.empty()){
        int r = pq.top();
        pq.pop();
        return r;
        }
        else return ++s;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */