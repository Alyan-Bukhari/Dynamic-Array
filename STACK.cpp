#include <iostream>
#include <string>

class Node {
public:
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}

    void setData(int data) {
        this->data = data;
    }

    void setNext(Node *next) {
        this->next = next;
    }

    int getData() const {
        return data;
    }

    Node *getNext() const {
        return next;
    }

    void display() {
        std::cout << data << std::endl;
    }

private:
    int data;
    Node *next;
};

class Stack {
public:
    Stack() : size(0), top(nullptr) {}

    void push(int data) {
        Node *temp = new Node(data);
        if (top == nullptr) {
            top = temp;
        } else {
            temp->setNext(top);
            top = temp;
        }
        size++;
    }

    void pop() {
        if (top != nullptr) {
            Node *temp = top;
            top = top->getNext();
            delete temp;
            size--;
        } else {
            std::cout << "Stack -- Already Empty !!" << std::endl;
        }
    }

    void display() {
        Node *temp = top;
        while (temp != nullptr) {
            temp->display();
            temp = temp->getNext();
        }
    }

    int getSize() const {
        return size;
    }

    int getTopElement() const {
        return top->getData();
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    Node *getTop() const {
        return top;
    }

    void setTop(Node *top) {
        this->top = top;
    }

    bool isBalanced(const std::string& expression) {
        Stack stack;

        for (char bracket : expression) {
            if (bracket == '(' || bracket == '[' || bracket == '{') {
                stack.push(bracket);
            } else if (bracket == ')' || bracket == ']' || bracket == '}') {
                if (stack.isEmpty()) {
                    return false;
                }
                char top = stack.getTopElement();
                stack.pop();
                if ((bracket == ')' && top != '(') ||
                    (bracket == ']' && top != '[') ||
                    (bracket == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }

private:
    int size;
    Node *top;
};

int main() {
    std::string input;
    std::cout << "Enter expression: ";
    std::getline(std::cin, input);

    Stack stack;
    if (stack.isBalanced(input)) {
        std::cout << "This expression is correct.\n";
    } else {
        std::cout << "This expression is NOT correct.\n";
    }

    return 0;
}
