#include <iostream>
#include <string>

using namespace std;

class Deque
{
    struct Node
    {
        Node(int64_t value) : value(value), next(nullptr), prev(nullptr) { }

        int64_t value;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    int count;

public:
    Deque() : head(nullptr), tail(nullptr), count(0) { }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void push_front(int64_t value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
        cout << "ok" << endl;
    }

    void push_back(int64_t value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
        cout << "ok" << endl;
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "error" << endl;
            return;
        }

        int64_t value = head->value;
        Node* prevHead = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else 
        {
            tail = nullptr;
        }
        delete prevHead;
        count--;

        cout << value << endl;
    }

    void pop_back()
    {
        if (isEmpty())
        {
            cout << "error" << endl;
            return;
        }

        int64_t value = tail->value;
        Node* prevTail = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete prevTail;
        count--;

        cout << value << endl;
    }

    void front()
    {
        if (isEmpty())
        {
            cout << "error" << endl;
            return;
        }
        cout << head->value << endl;
    }

    void back()
    {
        if (isEmpty())
        {
            cout << "error" << endl;
            return;
        }
        cout << tail->value << endl;
    }

    void size()
    {
        cout << count << endl;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node* prevHead = head;
            head = head->next;
            delete prevHead;
        }
        tail = nullptr;
        count = 0;
        cout << "ok" << endl;
    }
};

int main()
{
    Deque deque;
    string command;

    while (cin >> command)
    {
        if (command == "push_front")
        {
            int64_t value;
            cin >> value;
            deque.push_front(value);
        }
        else if (command == "push_back")
        {
            int64_t value;
            cin >> value;
            deque.push_back(value);
        }
        else if (command == "pop_front")
        {
            deque.pop_front();
        }
        else if (command == "pop_back")
        {
            deque.pop_back();
        }
        else if (command == "front")
        {
            deque.front();
        }
        else if (command == "back")
        {
            deque.back();
        }
        else if (command == "size")
        {
            deque.size();
        }
        else if (command == "clear")
        {
            deque.clear();
        }
        else if (command == "exit")
        {
            cout << "bye" << endl;
            break;
        }
    }
}