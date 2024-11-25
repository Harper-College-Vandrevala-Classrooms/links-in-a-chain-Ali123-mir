#include <iostream>
#include <string>
using namespace std;

class ChainLink {
private:
string color;
public:
ChainLink(string color) {
this->color = color;
}
string get_color() {
return this->color;
}
};

class Node {
private:
ChainLink* link;
Node* next_node;
public:
Node(ChainLink* link, Node* next_node = nullptr) {
this->link = link;
this->next_node = next_node;
}

ChainLink* data() {

return link;
}

Node* next() {
return next_node;
}

void set_next(Node* next_node) {
this->next_node = next_node;
}
};

class ChainLinkList {
private:
Node* head;
public:
ChainLinkList() : head(nullptr) {}
~ChainLinkList() {
Node* current = head;
while (current != nullptr) {
Node* temp = current;
current = current->next();
delete temp;
}
}

void append(ChainLink* link) {
Node* new_node = new Node(link);
if (head == nullptr) {
head = new_node;
} else {
Node* current = head;
while (current->next() != nullptr) {
current = current->next();
}
current->set_next(new_node);
}
}

ChainLink* get(int index) {
if (index < 0) {
cout << "Invalid index." << endl;
return nullptr;
}
Node* current = head;
int count = 0;
while (current != nullptr) {
if (count == index) {
return current->data();
}
current = current->next();
count++;
}
cout << "Index out of bounds." << endl;
return nullptr;
}

void print_all() {
Node* current = head;
while (current != nullptr) {
cout << current->data()->get_color() << " -> ";
current = current->next();
}
cout << "null" << endl;
}
};

int main() {
ChainLinkList list;

ChainLink link_one("red");
list.append(&link_one);
ChainLink link_two("blue");
list.append(&link_two);

ChainLink link_three("green");
list.append(&link_three);

cout << "ChainLink list: ";
list.print_all();

int index = 1;
ChainLink* retrieved_link = list.get(index);
if (retrieved_link) {
cout << "ChainLink at index " << index << ": " << retrieved_link->get_color() << endl;
}

index = 5;
ChainLink* invalid_link = list.get(index);
if (invalid_link) {
cout << "ChainLink at index " << index << ": " << invalid_link->get_color() << endl;
}
return 0;
}