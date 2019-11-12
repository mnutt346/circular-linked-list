/**************************************************************************************
** Program name: queue.hpp
** Author: Michael Nutt
** Date: 11/11/2019
** Description: Header file for the Queue class.
**************************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

struct QueueNode
{
    int val;
    QueueNode *next;
    QueueNode *prev;

    QueueNode(int newVal = 0, QueueNode *nxt = nullptr, QueueNode *previous = nullptr)
    {
        val = newVal;
        next = nxt;
        prev = previous;
    }
};

class Queue
{
private:
    QueueNode *head;

public:
    Queue();
    ~Queue();
    void deallocateMemory();
    bool isEmpty();
    void addBack(int);
    int getFront();
    void removeFront();
    void printQueue();
    void setHeadNode(QueueNode *);
    int getHeadVal();
    void runProgram();
    void handleSelection(int);
};

#endif