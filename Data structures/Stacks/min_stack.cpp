/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
class MinStack {
public:
    long min;
    stack<long> stk;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(stk.empty()){
            stk.push(0l);
            min = x;
        }else{
            stk.push(x-min);
            if(stk.top()<0)
                min = x;
        }
    }
    
    void pop() {
        if(stk.empty())
            return;        
        long top = stk.top();
        if(top<0)
            min = min - top;
        stk.pop();
    }
    
    int top() {
        long top = stk.top();
        if(top > 0)
            return (int)top+min;
        else
            return (int)min;
    }
    
    int getMin() {
        return (int) min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */