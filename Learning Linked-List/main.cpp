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

    void addEnd(int value)
    {
        Node *newNode = new Node;
        Node *lastNode = head;

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            while (lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
        }
    }

    void addInPosition(int position, int value)
    {
        if (position <= 0)
        {
            cout << "Invalid!\n";
            return;
        }

        Node *newNode = new Node;
        newNode->data = value;

        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *currentNode = head;
        int currentPosition = 1;

        while (currentNode != NULL && currentPosition < position - 1)
        {
            currentNode = currentNode->next;
            currentPosition++;
        }

        if (currentNode == NULL)
        {
            cout << "No position\n";
        }
        else
        {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    void display()
    {
        Node *temp = head;

        cout << "\n Linked List:  ";

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "null\n";
    }

    void search()
    {

        Node *temp = head;
        int item = 0;
        int position = 0;

        cout << "\nSearch: ";
        cin >> item;

        while (temp != NULL)
        {
            position++;
            if (temp->data == item)
            {
                cout << " Found: " << temp->data << " | Position: " << position << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Not Found\n";
    }
};

string getNodeOperation();
void addNodes(LinkedList *list, string operation);
void insertNode(LinkedList *list);

int main()
{
    LinkedList *list = new LinkedList;
    string operation = "";

    operation = getNodeOperation();

    addNodes(list, operation);
    list->display();
    list->search();

    insertNode(list);
    list->display();

    return 0;
}

string getNodeOperation()
{

    int choice = 0;
    cout << "1. Add First\n";
    cout << "2. Add End\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        return "first";
    }
    else if (choice == 2)
    {
        return "end";
    }
}

void addNodes(LinkedList *list, string operation)
{
    int value = 0;
    int numOfNodes = 0;

    cout << " Number of nodes : ";
    cin >> numOfNodes;

    for (int i = 0; i < numOfNodes; i++)
    {
        cout << "  Input data for node " << i + 1 << ": ";
        cin >> value;
        if (operation == "first")
        {
            list->addFirst(value);
        }
        else if (operation == "end")
        {
            list->addEnd(value);
        }
    }
}

void insertNode(LinkedList *list)
{

    int position = 0;
    int value = 0;
    cout << "Position: ";
    cin >> position;
    cout << "Value: ";
    cin >> value;

    list->addInPosition(position, value);
}