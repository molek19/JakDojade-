#include"String.h"
#include<iostream>



using namespace std;

// Konstruktor domy�lny
String::String() : data(nullptr), length(0) {}

void String::resize(int new_capacity) {
    char* new_data = new char[new_capacity];
    if (data != nullptr)
    {
        std::memcpy(new_data, data, length + 1);
        delete[] data;
    }
    data = new_data;
    capacity = new_capacity;
    memset(data + length, 0, new_capacity - length);
}

// Konstruktor, kt�ry tworzy obiekt String z podanego ci�gu znak�w
String::String(const char* str) {
    length = strlen(str);
    data = new char[length + 1];
    strcpy_s(data, length + 1, str);
}

// Konstruktor kopiuj�cy
String::String(const String& other) {
    length = other.length;
    if (other.data != nullptr)
    {
        data = new char[length + 1];
        strcpy_s(data, length + 1, other.data);
    }
    else
        data = nullptr;
  
}

// Destruktor
String::~String() {
    delete[] data;
}

// Zwraca d�ugo�� ci�gu znak�w
int String::size() const {
    return length;
}

// Zwraca wska�nik do ci�gu znak�w (const)
const char* String::c_str() const {
    return data;
}

// Czy�ci zawarto�� obiektu String
void String::clear() {
    delete[] data;
    length = 0;
    capacity = 1;
    data = new char[capacity];
    data[0] = '\n';
    
}

// Operator przypisania, kt�ry przypisuje ci�g znak�w do obiektu String
String& String::operator=(const char* str) {
    clear();
    length = strlen(str);
    capacity = length + 1;
    data = new char[length + 1];
    strcpy_s(data, capacity, str);
    return *this;
}

// Operator przypisania kopiuj�cy, kt�ry przypisuje zawarto�� innego obiektu String do tego obiektu
String& String::operator=(const String& other) {
    if (this == &other)
    {
        return *this;
    }
    clear();
    if (other.length > 0 && other.data != nullptr) {
        length = other.length;
        data = new char[length + 1];
        strcpy_s(data, length + 1, other.data);
    }
    return *this;
}

// Operator indeksowania, kt�ry zwraca znak o podanym indeksie
char& String::operator[](int index) {
    return data[index];
}

// Operator indeksowania (const), kt�ry zwraca znak o podanym indeksie (tylko do odczytu)
const char& String::operator[](int index) const {
    return data[index];
}

// Operator dodawania, kt�ry zwraca nowy obiekt String, b�d�cy po��czeniem tego obiektu i podanego ci�gu znak�w
String String::operator+(const char* str) const {
    String result(*this);
    result += str;
    return result;
}

// Operator dodawania, kt�ry zwraca nowy obiekt String, b�d�cy po��czeniem dw�ch obiekt�w String
String String::operator+(const String& other) const {
    String result(*this);
    result += other;
    return result;
}

// Operator dodawania i przypisania, kt�ry dodaje podany ci�g znak�w do tego obiektu i zwraca referencj� do niego
String& String::operator+=(const char* str) {
    int new_length = length + static_cast<int>(std::strlen(str));
    if (new_length >= capacity) {
        int new_capacity = capacity * 2;
        while (new_capacity <= new_length) {
            new_capacity *= 2;
        }
        resize(new_capacity);
        data[length] = '\0';
    }
    strcat_s(data, new_length + 1, str);
    length = new_length;
    return *this;
}

String& String::operator+=(const String& other) {
    return (*this += other.data);
}
String& String::operator+=(char c) {
    char temp[2] = { c, '\0' };
    return (*this += temp);
}

ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data;
    return os;
}

istream& operator>>(std::istream& is, String& str) {
    char buffer[4096];
    is >> buffer;
    str = buffer;
    return is;
}
bool String::operator==(const char* str) const {
    return strcmp(data, str) == 0;
}
bool String::operator==(const String& other) const {
    return strcmp(data, other.data) == 0;
}

bool String::operator!=(const char* str) const {
    return strcmp(data, str) != 0;
}

bool String::operator!=(const String& other) const {
    return strcmp(data, other.data) != 0;
}

bool String::is_empty() const {
    return (data == nullptr || *data == '\0');
}



