#include "Node.h"

namespace containers {

    template<typename T>
    Node<T>::Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}


    template class Node<int>;

}
