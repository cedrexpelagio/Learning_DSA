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

void printHeader();
void addNodes(LinkedList *list);

int main()
{
    LinkedList *list = new LinkedList;

    addNodes(list);
    list->display();
    list->search();

    return 0;
}

void addNodes(LinkedList *list)
{
    int value = 0;
    int numOfNodes = 0;

    cout << " Number of nodes : ";
    cin >> numOfNodes;

    for (int i = 0; i < numOfNodes; i++)
    {
        cout << "  Input data for node " << i + 1 << ": ";
        cin >> value;
        list->addFirst(value);
    }
}