#pragma once

#include "String.h"


class Node {
private:

public:
    String value; // warto��, kt�r� przechowuje w�ze�
    String wart;
    int number;
    int wart1;
    Node* next; // wska�nik na kolejny w�ze� w li�cie
    Node(String val);
    Node(int num);
    Node();
};
