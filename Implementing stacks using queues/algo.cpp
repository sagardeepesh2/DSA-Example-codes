class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        //keep 'x' at the front of q1
        while(!q1.empty()){
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }
        q1.push(x);
         while(!q2.empty()){
            int val = q2.front();
            q2.pop();
            q1.push(val);
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        else
            return false;
    }
};
