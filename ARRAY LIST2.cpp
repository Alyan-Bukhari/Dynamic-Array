#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyCircularLinkedList() : head(nullptr) {}

    // Function to check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to create a new node
    Node* createNode(int value) {
        return new Node(value);
    }

    // Function to insert data at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = createNode(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert data at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = createNode(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    // Function to insert data at any location within the list
    void insertAtLocation(int value, int location) {
        if (location <= 0) {
            std::cerr << "Invalid location\n";
            return;
        }
        if (location == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = createNode(value);
        Node* temp = head;
        for (int i = 1; i < location - 1 && temp->next != head; ++i) {
            temp = temp->next;
        }
        if (temp == head || temp->next == head) {
            std::cerr << "Invalid location\n";
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Function to delete a node at a specific location
    void deleteAtLocation(int location) {
        if (isEmpty()) {
            std::cerr << "List is empty\n";
            return;
        }
        if (location <= 0) {
            std::cerr << "Invalid location\n";
            return;
        }
        if (location == 1) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* lastNode = head->prev;
            head->next->prev = lastNode;
            lastNode->next = head->next;
            delete head;
            head = lastNode->next;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < location && temp->next != head; ++i) {
            temp = temp->next;
        }
        if (temp == head || temp->next == head) {
            std::cerr << "Invalid location\n";
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Function to display the contents of the linked list
    void displayList() {
        if (isEmpty()) {
            std::cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

int main() {
    DoublyCircularLinkedList myList;

    // Inserting nodes at the beginning
    myList.insertAtBeginning(1);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(3);

    std::cout << "List after inserting at the beginning: ";
    myList.displayList();

    // Inserting nodes at the end
    myList.insertAtEnd(4);
    myList.insertAtEnd(5);

    std::cout << "List after inserting at the end: ";
    myList.displayList();

    // Inserting nodes at specific locations
    myList.insertAtLocation(6, 3);
    myList.insertAtLocation(7, 6);

    std::cout << "List after inserting at specific locations: ";
    myList.displayList();

    // Deleting nodes at specific locations
    myList.deleteAtLocation(2);
    myList.deleteAtLocation(5);

    std::cout << "List after deleting nodes at specific locations: ";
    myList.displayList();

    return 0;
}
