#pragma once
#include "Node.h"
#include "String.h"

class List {
private:
	int size=1;

public:
	Node* head;
	void add_value_at_index(String val, int index);
	void add_value_at_index(int num, int index);
	String getValueAtIndexString(int index);
	int getValueAtIndexInt(int index);
	Node* getNode(int index);
	int find_index(int val) const;
	int find_index(String val) const;
	bool contains_value(String value);
	bool contains_value(int value);
	int getSize();
};