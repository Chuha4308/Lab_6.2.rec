#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;


void create(int* arr, int SIZE, int MIN, int MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        create(arr, SIZE, MIN, MAX, ++i);
    }
}


void Print(int* arr, const int SIZE, int i)
{
    cout << setw(4) << arr[i];
    if (i < SIZE - 1)
        Print(arr, SIZE, i + 1);
    else
        cout << endl;
}


int FindingTheArithmetic(int* arr, int SIZE, int i, int largestOdd)
{
    if (i == SIZE)
        return largestOdd;

    if (arr[i] % 2 != 0) 
    {
        if (largestOdd == -1 || arr[i] > largestOdd)
        {
            largestOdd = arr[i];
        }
    }

    return FindingTheArithmetic(arr, SIZE, i + 1, largestOdd);
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    int MIN = -10;
    int MAX = 10;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX, 0); 

    Print(arr, SIZE, 0); 
    cout << "\n\n";

    int largestOdd = FindingTheArithmetic(arr, SIZE, 0, -1);

    if (largestOdd != -1)
        cout << "Найбільший непарний елемент: " << largestOdd << endl;
    else
        cout << "Непарних елементів немає." << endl;

    delete[] arr;

    return 0;
}
