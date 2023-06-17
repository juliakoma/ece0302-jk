#include <string>
using std::string;

#include <iostream>
#include <stack>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {
  std::stack<string> stack; // Stack to hold operands and intermediate results

  for (size_t i = 0; i < postfix.size(); i++) {
    char ch = postfix[i];

    if (isalpha(ch))
    {
      // Create a string with the current operand character with a length of 1
      std::string operand(1, ch); 

      // Push the operand onto the stack
      stack.push(operand); 
    } 
    else if (isoperator(ch)) 
    {
      // Get the top operand from the stack
      std::string operand2 = stack.top(); 

      // Pop the top operand
      stack.pop(); 

      // Get the next operand from the stack  
      std::string operand1 = stack.top(); 

      // Pop the next operand
      stack.pop(); 

      // Combine the operator and operands
      std::string result = ch + operand1 + operand2; 

      // Push the intermediate result back onto the stack
      stack.push(result); 
    } 
  }

  if (stack.size() == 1) 
  {
    // The final result is the only element left on the stack
    prefix = stack.top(); 
  } 
  else
   {
    // More than one element left on the stack
    prefix = "Invalid postfix expression"; 
  }
}
