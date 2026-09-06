class MinStack {
public:
    int minEle=INT_MAX;
    stack<int>st,mn;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minEle>value) minEle=value;
        mn.push(minEle);
    }
    
    
    void pop() {
        st.pop();
        mn.pop();
        minEle=st.size()?mn.top():INT_MAX;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minEle;
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