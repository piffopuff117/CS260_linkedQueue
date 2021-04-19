// linkedQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "node.h"

using std::cout;
using std::cin;
using std::endl;

void enqueue(node* current, int new_value);
void printQueue(node* current);
int dequeue(node* current);


int main(int argc, char **argv)
{
    cout << "Queue with linked nodes: " << endl << endl;
    //node my_node = {100, 42, 'J' };

    node my_node1, my_node2, my_node3;

    my_node1.value = 1;
    my_node1.next = &my_node2;
    my_node1.prev = nullptr;
    

    my_node2.value = 2;
    my_node2.next = &my_node3;
    my_node2.prev = &my_node1;

    my_node3.value = 3;
    my_node3.next = nullptr;
    my_node3.prev = &my_node2;

    node* current = &my_node1;

    printQueue(current);

    current = &my_node3;
    cout << "Value is dequeued: " << dequeue(current) << endl;

    current = &my_node1;
    printQueue(current);
    
    current = &my_node1;
    enqueue(current, 4);

    printQueue(current);

    return 0;
}

//enters new value into node1, slides following values
void enqueue(node* current, int new_value)
{
    //slides 2nd to 3rd
    current->next->next->value = current->next->value;

    //slides 1st to 2nd
    current->next->value = current->value;

    current->value = new_value;

    cout << "Value is enqueued: " << new_value << endl;
}

//removes last node's value, returns value
int dequeue(node* current)
{
    int front_value = 0;

    if (!current->value == 0)
    {
        front_value = current->value;
        current->value = 0;
    }
    else
    {
        if (!current->prev->value == 0)
        {
            front_value = current->prev->value;
            current->prev->value = 0;
        }
        else
        {
            front_value = current->prev->prev->value;
            current->prev->prev->value = 0;
        }
    }
    

    return front_value;
}

void printQueue(node* current)
{
    while (current != nullptr)
    {
        cout << "current.value: " << current->value << endl;
        cout << "current.next: " << current->next << endl;

        current = current->next;
    }
    cout << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
