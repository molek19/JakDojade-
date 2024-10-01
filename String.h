#pragma once
#include <iostream>

class String {
private:
    char* data=nullptr;
    size_t length=0;
    int capacity=1;
    void resize(int new_capacity);
    bool isFirst;

public:
    String();
    String(const char* str);
    String(const String& other);
    ~String();

    int size() const;
    const char* c_str() const;
    void clear();
    String& operator=(const char* str);
    String& operator=(const String& other);
    char& operator[](int index);
    const char& operator[](int index) const;
    String operator+(const char* str) const;
    String operator+(const String& other) const;
    String& operator+=(const char* str);
    String& operator+=(const String& other);
    String& operator+=(char c);

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
    bool operator==(const char* str) const;
    bool operator==(const String& other) const;
    bool operator!=(const char* str) const;
    bool operator!=(const String& other) const;
    bool is_empty() const;
};