#include <iostream>
#include <string>

using namespace std;

class Queue
{
    struct Node
    {
        Node(int64_t value) : value(value), next(nullptr) { }

        int64_t value;
        Node* next;
    };

    Node* head;
    Node* tail;
    int count;

public:
    Queue() : head(nullptr), tail(nullptr), count(0) { }

    bool isEmpty() 
    {
        return head == nullptr;
    }

    void push(int64_t value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
        cout << "ok" << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "error" << endl;
            return;
        }

        int64_t value = head->value;
        Node* prevHead = head;
        head = head->next;
        delete prevHead;
        count--;
        if (head == nullptr)
            tail = nullptr;

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

    void size()
    {
        cout << count << endl;
    }

    void clear()
    {
        while (head)
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
    Queue queue;
    string command;

    while (cin >> command)
    {
        if (command == "push")
        {
            int64_t value;
            cin >> value;
            queue.push(value);
        }
        else if (command == "pop")
        {
            queue.pop();
        }
        else if (command == "front")
        {
            queue.front();
        }
        else if (command == "size")
        {
            queue.size();
        }
        else if (command == "clear")
        {
            queue.clear();
        }
        else if (command == "exit")
        {
            cout << "bye" << endl;
            break;
        }
    }
}