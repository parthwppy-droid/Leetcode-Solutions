class MyQueue {
    stack<int> stack1; 
    stack<int> stack2;

public:
    MyQueue() {

    }

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        transfer();
        int val = stack2.top();
        stack2.pop();
        return val;
    }

    int peek() {
        transfer();
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }

private:
    void transfer() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }
};