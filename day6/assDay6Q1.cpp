#include <iostream>
#include <stack>
using namespace std;
class CustomStack {
   stack<int> stk;
   int stack_max;
   public:
   void getMax() {
      if (stk.empty())
         cout << "Stack is empty"<<endl;
      else
         cout << "Maximum Element in the stack is: "<< stack_max <<endl;
   }
   void peek() {
      if (stk.empty()) {
         cout << "Stack is empty ";
         return;
      }
      int top = stk.top(); // Top element.
      cout << "Top Most Element is: "<<endl;
      (top > stack_max) ? cout << stack_max : cout << top;
   }
   void pop() {
      if (stk.empty()) {
         cout << "Stack is empty"<<endl;
         return;
      }
      cout << "Top Most Element Removed: ";
      int top = stk.top();
      stk.pop();
      if (top > stack_max) {
         cout << stack_max <<endl;
         stack_max = 2 * stack_max - top;
      } else
         cout << top <<endl;
   }
   void push(int element) {
      if (stk.empty()) {
         stack_max = element;
         stk.push(element);
         cout << "Element Inserted: " << element <<endl;
         return;
      }
      if (element > stack_max) {
         stk.push(2 * element - stack_max);
         stack_max = element;
      } else
      stk.push(element);
      cout << "Element Inserted: " << element <<endl;
   }
};
int main() {
   CustomStack stk;
   stk.push(4);
   stk.push(6);
   stk.getMax();
   stk.push(8);
   stk.push(20);
   stk.getMax();
   stk.pop();
   stk.getMax();
   stk.pop();
   stk.peek();
}
