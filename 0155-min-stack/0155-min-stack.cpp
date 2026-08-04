class MinStack {
public:
    long min; 
    std::stack<long> stk;
    MinStack() {
        
    }
    
    void push(int value) {
        if(stk.empty())
        {
            stk.push(0);
            min = value;
        }
        else
        {
            stk.push(value-min);
            if(value < min) min = value;
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        long pop = stk.top();
        stk.pop();

        if(pop < 0) min = min-pop;   
    }

    int top() {
        long top = stk.top();
        return (top > 0) ? (top + min):(int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */