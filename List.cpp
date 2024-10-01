#include "List.h"


void List::add_value_at_index(String val, int index) { // dodanie nowego w�z�a z dan� warto�ci� na wybran� pozycj� w li�cie
    if (val != "")
    {
        if (index < 1 || index > size) { // je�li podany indeks jest niepoprawny, zwracamy pust� warto��
            return;
        }
        Node* newNode = new Node(val); // tworzenie nowego w�z�a z dan� warto�ci�
        if (index == 1) { // je�li chcemy doda� w�ze� na pocz�tku listy, ustawiamy wska�nik na kolejny w�ze� nowego w�z�a na obecny pierwszy w�ze� i ustawiamy wska�nik na pierwszy w�ze� na nowy w�ze�
            newNode->next = head;
            head = newNode;
            size++;
        }
        else { // w przeciwnym razie, idziemy do w�z�a o poprzednim indeksie i ustawiamy wska�niki nowego w�z�a i poprzedniego w�z�a na odpowiednie w�z�y
            Node* current = head;
            for (int i = 1; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }
}
void List::add_value_at_index(int val, int index) { // dodanie nowego w�z�a z dan� warto�ci� na wybran� pozycj� w li�cie 
    if (index < 1 || index > size) { // je�li podany indeks jest niepoprawny, zwracamy pust� warto��
        return;
    }
    Node* newNode = new Node(val); // tworzenie nowego w�z�a z dan� warto�ci�
    if (index == 1) { // je�li chcemy doda� w�ze� na pocz�tku listy, ustawiamy wska�nik na kolejny w�ze� nowego w�z�a na obecny pierwszy w�ze� i ustawiamy wska�nik na pierwszy w�ze� na nowy w�ze�
        newNode->next = head;
        head = newNode;
        size++;
    }
    else { // w przeciwnym razie, idziemy do w�z�a o poprzednim indeksie i ustawiamy wska�niki nowego w�z�a i poprzedniego w�z�a na odpowiednie w�z�y
        Node* current = head;
        for (int i = 1; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

}

String List::getValueAtIndexString(int index) {
    Node* node = getNode(index);
    if (node == nullptr) {
        return "";
    }
    return node->value;
}
int List::getValueAtIndexInt(int index)
{
    Node* node = getNode(index);
    if (node == nullptr) {
        return 0;
    }
    return node->number;
}
Node* List::getNode(int index) {
    if (index < 1) return nullptr;
    Node* current = head;
    int i = 1;
    while (current != nullptr && i < index) {
        current = current->next;
        i++;
    }
    return current;
}
int List::find_index(int val) const {
    int index = 1;
    Node* current = head;

    while (current != nullptr) {
        if (current->number == val) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}
int List::find_index(String val) const {
    int index = 1;
    Node* current = head;

    while (current != nullptr) {
        if (current->value != "" && current->value == val) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

bool List::contains_value(String val) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}
bool List::contains_value(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->number == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}


int List::getSize() {
    return size;
}

