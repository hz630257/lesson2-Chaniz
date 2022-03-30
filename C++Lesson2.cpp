// C++Lesson2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lesson2.h"

int main()
{
    //3
    UseOparators();
    //8
    char str[] = "abcd";
    std::cout << "The permutations of the string are :\n";
    PrintPermutations(str,0,strlen(str)-1);
    //14
    int arr[5] = { 5,6,2,3,5 };
    std::cout << "The array is:\n";
    SortArray(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i]<<"\n";
    }
    std::cout <<"\n";
    //17
    std::cout << "The array reverse is:\n";
    SortArrayReverse(arr, 5);
    //תרגיל מרכזי
    simulation();

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
