#include "List.h"


void List::add_value_at_index(String val, int index) { // dodanie nowego wêz³a z dan¹ wartoœci¹ na wybran¹ pozycjê w liœcie
    if (val != "")
    {
        if (index < 1 || index > size) { // jeœli podany indeks jest niepoprawny, zwracamy pust¹ wartoœæ
            return;
        }
        Node* newNode = new Node(val); // tworzenie nowego wêz³a z dan¹ wartoœci¹
        if (index == 1) { // jeœli chcemy dodaæ wêze³ na pocz¹tku listy, ustawiamy wskaŸnik na kolejny wêze³ nowego wêz³a na obecny pierwszy wêze³ i ustawiamy wskaŸnik na pierwszy wêze³ na nowy wêze³
            newNode->next = head;
            head = newNode;
            size++;
        }
        else { // w przeciwnym razie, idziemy do wêz³a o poprzednim indeksie i ustawiamy wskaŸniki nowego wêz³a i poprzedniego wêz³a na odpowiednie wêz³y
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
void List::add_value_at_index(int val, int index) { // dodanie nowego wêz³a z dan¹ wartoœci¹ na wybran¹ pozycjê w liœcie 
    if (index < 1 || index > size) { // jeœli podany indeks jest niepoprawny, zwracamy pust¹ wartoœæ
        return;
    }
    Node* newNode = new Node(val); // tworzenie nowego wêz³a z dan¹ wartoœci¹
    if (index == 1) { // jeœli chcemy dodaæ wêze³ na pocz¹tku listy, ustawiamy wskaŸnik na kolejny wêze³ nowego wêz³a na obecny pierwszy wêze³ i ustawiamy wskaŸnik na pierwszy wêze³ na nowy wêze³
        newNode->next = head;
        head = newNode;
        size++;
    }
    else { // w przeciwnym razie, idziemy do wêz³a o poprzednim indeksie i ustawiamy wskaŸniki nowego wêz³a i poprzedniego wêz³a na odpowiednie wêz³y
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

