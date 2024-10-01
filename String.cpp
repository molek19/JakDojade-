#include"String.h"
#include<iostream>



using namespace std;

// Konstruktor domyœlny
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

// Konstruktor, który tworzy obiekt String z podanego ci¹gu znaków
String::String(const char* str) {
    length = strlen(str);
    data = new char[length + 1];
    strcpy_s(data, length + 1, str);
}

// Konstruktor kopiuj¹cy
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

// Zwraca d³ugoœæ ci¹gu znaków
int String::size() const {
    return length;
}

// Zwraca wskaŸnik do ci¹gu znaków (const)
const char* String::c_str() const {
    return data;
}

// Czyœci zawartoœæ obiektu String
void String::clear() {
    delete[] data;
    length = 0;
    capacity = 1;
    data = new char[capacity];
    data[0] = '\n';
    
}

// Operator przypisania, który przypisuje ci¹g znaków do obiektu String
String& String::operator=(const char* str) {
    clear();
    length = strlen(str);
    capacity = length + 1;
    data = new char[length + 1];
    strcpy_s(data, capacity, str);
    return *this;
}

// Operator przypisania kopiuj¹cy, który przypisuje zawartoœæ innego obiektu String do tego obiektu
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

// Operator indeksowania, który zwraca znak o podanym indeksie
char& String::operator[](int index) {
    return data[index];
}

// Operator indeksowania (const), który zwraca znak o podanym indeksie (tylko do odczytu)
const char& String::operator[](int index) const {
    return data[index];
}

// Operator dodawania, który zwraca nowy obiekt String, bêd¹cy po³¹czeniem tego obiektu i podanego ci¹gu znaków
String String::operator+(const char* str) const {
    String result(*this);
    result += str;
    return result;
}

// Operator dodawania, który zwraca nowy obiekt String, bêd¹cy po³¹czeniem dwóch obiektów String
String String::operator+(const String& other) const {
    String result(*this);
    result += other;
    return result;
}

// Operator dodawania i przypisania, który dodaje podany ci¹g znaków do tego obiektu i zwraca referencjê do niego
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



