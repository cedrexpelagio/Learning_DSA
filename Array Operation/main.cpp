#include <iostream>

using namespace std;

void display(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "Index: " << i << "| Value: " << arr[i] << endl;
    }
}

void deletion(int arr[], int size, int indexToDel)
{

    cout << "\nDeletion in index " << indexToDel << endl;

    while (indexToDel < size)
    {
        arr[indexToDel] = arr[indexToDel + 1];
        indexToDel++;
    }
}

void insertion(int arr[], int size, int indexToIn, int value)
{
    cout << "\nInsert in index " << indexToIn << endl;
    while (size > indexToIn)
    {
        arr[size] = arr[size - 1];
        size--;
    }

    arr[indexToIn] = value;
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int size = 5;

    display(array, size);

    deletion(array, size - 1, 3);
    display(array, size - 1);

    insertion(array, size, 0, 10);
    display(array, size);
}