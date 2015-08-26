class Queue {
 public:
  stack<int> s1;
  stack<int> s2;
  // Push element x to the back of queue.
  void push(int x) {
   s1.push(x);
  }
  // Removes the element from in front of queue.
  void pop(void) {
   if (s2.size() == 0){
    int len = s1.size();
    for (int i = 0; i < len; i++){
     s2.push(s1.top());
     s1.pop();
    }
    s2.pop();
   }
   else{
    s2.pop();
   }
   
  }
  // Get the front element.
  int peek(void) {
   if (s2.size() == 0){
    int len = s1.size();
    for (int i = 0; i < len; i++){
     int a = s1.top();
     s2.push(s1.top());
     s1.pop();
    }
    return s2.top();
   }
   else{
    return s2.top();
   }
  }
  // Return whether the queue is empty.
  bool empty(void) {
   return s1.empty() && s2.empty();
  }
 };