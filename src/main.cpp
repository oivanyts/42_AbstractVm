#include <iostream>
#include <stack>
#include "IOperand.h"
#include "main.h"

int main() {
  std::stack<IOperand *> a;
  IOperand  *op1;
  IOperand  *op2;

  std::cout << a.size() << " size start\n";
  a.push(op1);
  a.push(op2);
  std::cout << a.size() << " size finale" << std::endl;
  std::cout << a.top() << " top" << std::endl;
  a.pop();
  std::cout << a.top() << " top" << std::endl;
  return 0;
}