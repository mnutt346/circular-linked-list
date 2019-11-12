/**************************************************************************************
** Program name: queue.cpp
** Author: Michael Nutt
** Date: 11/11/2019
** Description: Implementation file for the Queue class.
**************************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "menu.hpp"
#include "inputValidation.hpp"
#include "queue.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

Queue::Queue()
{
    head = nullptr;
}

Queue::~Queue()
{
    deallocateMemory();
}

void Queue::deallocateMemory()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        QueueNode *currentNode = head;

        do
        {
            QueueNode *temp = currentNode->next;

            currentNode->prev = nullptr;
            currentNode->next = nullptr;
            delete currentNode;

            currentNode = temp;
        } while (currentNode != head);

        head->next = nullptr;
        head->prev = nullptr;
        head = nullptr;
    }
}

bool Queue::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::addBack(int newVal)
{
    QueueNode *newNode = new QueueNode(newVal);

    // If the Queue is empty
    if (isEmpty())
    {
        head = newNode;
        head->next = newNode;
        head->prev = newNode;
    }
    // If the Queue is not empty
    else
    {
        // Set the new node's next value to the current head
        newNode->next = head;
        // Set the new node's prev value to the previous back of the list (pointed to by the head's prev value)
        QueueNode *oldBack = head->prev;
        newNode->prev = oldBack;
        // Set the previous back node's next value to the new node
        oldBack->next = newNode;
        // Set the head's prev value to the new node
        head->prev = newNode;
    }
}

int Queue::getFront()
{
    return head->val;
}

void Queue::removeFront()
{
    if (isEmpty())
    {
        cout << "No items in Queue. Nothing to remove" << endl;
    }
    else
    {
        // If there is only 1 item in the queue
        if (head == head->next)
        {
            head->next = nullptr;
            head->prev = nullptr;
            delete head;
            head = nullptr;
        }
        else
        {
            QueueNode *oldHead = head;
            // Set the new head to the old head's next value
            QueueNode *newHead = oldHead->next;
            head = newHead;
            QueueNode *lastNode = oldHead->prev;
            // Set the new head's previous value to point to the last node in the Queue
            newHead->prev = lastNode;
            // Set the last node's next value to point to the new head
            lastNode->next = newHead;

            oldHead->next = nullptr;
            oldHead->prev = nullptr;
            delete oldHead;
            oldHead = nullptr;
        }
        cout << "Head removed from Queue." << endl;
    }
}

void Queue::printQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing to print." << endl;
    }
    else if (head->next == head)
    {
        cout << "Your Queue: " << head->val << endl;
    }
    else
    {
        QueueNode *currentNode = head;

        cout << "Your Queue: ";

        do
        {
            cout << currentNode->val << " ";
            // Reset currentNode to the next node in the Queue
            currentNode = currentNode->next;
        } while (currentNode != head);

        cout << endl;
    }
}

void Queue::setHeadNode(QueueNode *newHead)
{
    if (newHead != nullptr)
    {
        if (isEmpty())
        {
            newHead->next = newHead;
            newHead->prev = newHead;
        }
        else
        {
            newHead->next = head;
            newHead->prev = head->prev;
            head->prev = newHead;
        }
    }

    head = newHead;
}

void Queue::runProgram()
{
    const string TITLE = "Circular Linked-List";
    const string OPTION_1 = "Add a value to the back of the queue.";
    const string OPTION_2 = "Display the front value.";
    const string OPTION_3 = "Remove the front node.";
    const string OPTION_4 = "Display the queue's contents.";
    const string OPTION_5 = "Exit.";

    vector<string> options{OPTION_1, OPTION_2, OPTION_3, OPTION_4, OPTION_5};

    bool programSelection = startMenu(TITLE);

    if (!programSelection)
    {
        cout << "Exiting program..." << endl;
        options.clear();
        exit(0);
    }
    else
    {
        int menuSelection = multiOptionMenu(options);

        while (menuSelection)
        {
            if (menuSelection == 5)
            {
                options.clear();
            }
            handleSelection(menuSelection);

            menuSelection = multiOptionMenu(options);
        }
    }
}

void Queue::handleSelection(int selection)
{
    if (selection == 1)
    {
        string instruction = "a new node value";
        int newNodeVal = gameMenuRange(instruction, 0, 1000);
        addBack(newNodeVal);
    }
    else if (selection == 2)
    {
        if (isEmpty())
        {
            cout << "The Queue is empty. Nothing to print." << endl;
        }
        else
        {
            cout << "The first node value is: " << getFront() << endl;
        }
    }
    else if (selection == 3)
    {
        removeFront();
    }
    else if (selection == 4)
    {
        printQueue();
    }
    else if (selection == 5)
    {
        cout << "Exiting program..." << endl;
        exit(0);
    }
}