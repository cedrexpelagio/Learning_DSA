#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{

    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void addFirst(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = head;

        head = newNode;
    }

    void display()
    {
        Node *temp = head;

        cout << "\n\n Linked List:  ";

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "null\n";
        cout << "------------------------------------------------------------------------------\n";
    }
};

void printHeader();
void addNodes(LinkedList *list);

int main()
{
    LinkedList *list = new LinkedList;

    printHeader();
    addNodes(list);
    list->display();

    return 0;
}

void printHeader()
{
    cout << "------------------------------------------------------------------------------\n";
    cout << "Name    :\n";
    cout << "Course  :\n";
    cout << "------------------------------------------------------------------------------\n\n";
    cout << "Linked List |  INSERTION OPERATION\n\n";
    cout << "Insert a new node at the beginning Linked List:\n";
    cout << "------------------------------------------------------------------------------\n\n";
}

void addNodes(LinkedList *list)
{
    int value = 0;
    int numOfNodes = 0;

    cout << " SET the number of nodes : ";
    cin >> numOfNodes;

    for (int i = 0; i < numOfNodes; i++)
    {
        cout << "  Input data for node " << i+1 << ": ";
        cin >> value;
        list->addFirst(value);
    }
}