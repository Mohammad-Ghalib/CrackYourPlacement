// Class to implement stack using Deque
class Stack : public Deque {
public:

    void push(int element) {
        insert_last(element);
    }

    void pop() {
        remove_last();
    }
};

// class to implement queue using deque
class Queue : public Deque {
public:

    void enqueue(int element) {
        insert_last(element);
    }

    void dequeue() {
        remove_first();
    }
};