class CustomStack {
public:
    vector <int> stack ;
    vector <int> inc ;
    int n ;
    CustomStack(int maxSize) {
        n = maxSize ;
    }
    
    void push(int x) {
        if(stack.size() < n){
            stack.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if(stack.empty()){
            return -1 ;
        }
        int index = stack.size() -1 ;

        if(index > 0 ) {
            inc[index-1] += inc[index] ;
        }

        int topval = stack[index] + inc[index] ;
        stack.pop_back() ;
        inc.pop_back() ;

        return topval ;
    }
    
    void increment(int k, int val) {
        int index = min(k,(int)stack.size()) -1 ;

        if(index >=0){
            inc[index] += val ;
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