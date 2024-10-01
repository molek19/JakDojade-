#include "Node.h"

Node::Node(String val) {
    value = val;
    next = nullptr;
}

Node::Node(int num)
{
    number = num;
    wart1 = num;
    next = nullptr;
}
Node::Node() {
    next = nullptr;
}
