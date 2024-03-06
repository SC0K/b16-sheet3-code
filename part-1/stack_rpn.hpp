#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

// WRITE YOUR CODE HERE
template <typename T> void plus(Stack<T> &stack){
    T a = stack.top();
    stack.pop();
    T b = stack.top();
    stack.pop();
    stack.push(a+b);
}

template <typename T> void minus(Stack<T> &stack){
    T a = stack.top();
    stack.pop();
    T b = stack.top();
    stack.pop();
    stack.push(b-a);
}

template <typename T> void multiplies(Stack<T> &stack){
    T a = stack.top();
    stack.pop();
    T b = stack.top();
    stack.pop();
    stack.push(a*b);
}

template <typename T> void divides(Stack<T> &stack){
    T a = stack.top();
    stack.pop();
    T b = stack.top();
    stack.pop();
    stack.push(b/a);
}

template <typename T> void negate(Stack<T> &stack){
    T a = stack.top();
    stack.pop();
    stack.push(-a);
}

#endif // __stack_rpn__