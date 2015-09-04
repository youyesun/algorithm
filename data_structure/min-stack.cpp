/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {

    class Item{
      public:
        int val;
        int min;
        Item(int val, int min){
          this->val = val;
          this->min = min;
        }
    };
    

private:
    stack<Item> minsk;
    
public:
    void push(int x) {
        int mmin = minsk.empty()?x:min(x,minsk.top().min);
        minsk.push(Item(x,mmin));
    }

    void pop() {
        minsk.pop();
    }

    int top() {
        if(!minsk.empty())
            return minsk.top().val;
    }

    int getMin() {
        if(!minsk.empty())
            return minsk.top().min;
    }
};
