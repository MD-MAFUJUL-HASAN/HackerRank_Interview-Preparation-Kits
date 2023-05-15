#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int>* deque_;
    stack<int>* enque_;        
    int size_;
public:
    Queue();
    ~Queue();
    void push(int number);
    int pop();
    int peek();
    int size() {return this->size_;};
private:
    void restructuralization();
};

Queue::Queue() {
    this->deque_ = new stack<int>;
    this->enque_ = new stack<int>;
    this->size_ = 0;
}

Queue::~Queue() {
    delete this->deque_;
    delete this->enque_;
    this->size_ = 0;
    this->deque_ = nullptr;
    this->enque_ = nullptr;
}

int Queue::peek() {
    if(this->size_ == 0) {
        throw std::logic_error("QUEUE IS EMPTY - cant process peek!");
    } else if(deque_->empty()) {
        this->restructuralization();
    }
    return this->deque_->top();      
}

int Queue::pop() {
    int popItem;
    if(this->size_ == 0) {
        throw std::logic_error("QUEUE IS EMPTY - cant process pop!");
    } else if(deque_->empty()) {
        this->restructuralization();
    }
    popItem = this->deque_->top();      
    this->deque_->pop();
    this->size_--;
    return popItem;
}

void Queue::push(int number) {
    this->enque_->push(number);
    this->size_++;
}

void Queue::restructuralization() {
    while (!this->enque_->empty()) {
        this->deque_->push(this->enque_->top());
        this->enque_->pop();
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Queue queue;
    int numberOfQueries;
    int firstValue;
    int secondValue;
    cin >> numberOfQueries;
    for(int i = 0; i < numberOfQueries ; i++) {
        cin >> firstValue;
        if(firstValue == 1) {
            cin >> secondValue;
            queue.push(secondValue);
        } else if (firstValue == 2) {
            queue.pop();
        } else if (firstValue == 3) {
            cout << queue.peek() << endl;
        }
    }   
    return 0;
}
