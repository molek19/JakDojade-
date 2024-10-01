#pragma once

#include "String.h"


class Node {
private:

public:
    String value; // wartoœæ, któr¹ przechowuje wêze³
    String wart;
    int number;
    int wart1;
    Node* next; // wskaŸnik na kolejny wêze³ w liœcie
    Node(String val);
    Node(int num);
    Node();
};
