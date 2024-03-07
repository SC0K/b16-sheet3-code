#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <vector>
#include <memory>

// A class representing a binary tree
template <typename V> struct BinaryTreeEnhanced {
    V _value;
    std::unique_ptr<BinaryTreeEnhanced<V>> _left;
    std::unique_ptr<BinaryTreeEnhanced<V>> _right;

    // WRITE YOUR CODE HERE
    BinaryTreeEnhanced<V> *_parent;
    friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
    friend const V &value(const BinaryTreeEnhanced *t)
    {
        return t->_left_value;
    }
    friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
    {
        // WRITE YOUR CODE HERE
        return t->_parent;
    }
};

// A helper function to build an enhanced binary tree
template <typename V>
std::unique_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          std::unique_ptr<BinaryTreeEnhanced<V>> l,
                          std::unique_ptr<BinaryTreeEnhanced<V>> r)
{
    // WRITE YOUR CODE HERE
    auto tree = std::unique_ptr<BinaryTreeEnhanced<V>>{
        new BinaryTreeEnhanced<V>{value, std::move(l), std::move(r)}}; // std::move(l) and std::move(r) are used to transfer the ownership of the unique pointers to the new tree
        if (left(tree.get())) {
            left(tree.get())->_parent = tree.get();
        }
        if (right(tree.get())) {
            right(tree.get())->_parent = tree.get();
        }
        return tree;
}

#endif // __binary_tree_enhanced__