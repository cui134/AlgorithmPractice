class Stack {
 public:
  queue<int> q1;
  queue<int> q2;
  // Push element x onto stack.
  void push(int x) {
   if (!q1.empty()) q1.push(x);
   else if (!q2.empty()) q2.push(x);
   else q1.push(x);
  }
  // Removes the element on top of the stack.
  void pop() {
   if (!q1.empty()){
    while (q1.size() > 1){
     q2.push(q1.front());
     q1.pop();
    }
    q1.pop();
   }
   else{
    while (q2.size() > 1){
     q1.push(q2.front());
     q2.pop();
    }
    q2.pop();
   }
  }
  // Get the top element.
  int top() {
   if (!q1.empty()){
    while (q1.size() > 1){
     q2.push(q1.front());
     q1.pop();
    }
    int val= q1.front();
    q2.push(q1.front());
    q1.pop();
    return val;
   }
   else{
    while (q2.size() > 1){
     q1.push(q2.front());
     q2.pop();
    }
    int val = q2.front();
    q1.push(q2.front());
    q2.pop();
    return val;
   }
  }
  // Return whether the stack is empty.
  bool empty() {
   return q1.empty() && q2.empty();
  }
 };