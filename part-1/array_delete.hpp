#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    assert(index < A.size());
    for (size_t j = index; j < A.size() - 1; ++j) {
    A[j] = A[j + 1];
    }
    A.resize(A.size() - 1);
     // if (index >= A.size()) {
    //     index = A.size() - 1;
    // }

    // A.erase(A.begin() + index);
}
#endif // __array_delete__
