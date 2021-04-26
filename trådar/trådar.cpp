#include <iostream>
#include <thread>
#include <ctime>
#include <ratio>
#include <chrono>

// antal element i arrayen som ska sorteras
#define MAX 20

// antal maximala trådar
#define THREAD_MAX 4

using namespace std;
using namespace std::chrono;

// array med storleken MAX
int array_to_sort[MAX];
int part = 0;



int array_to_sort1[MAX];
int part1 = 0;





//Metod som byter två tal
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Funktion som implementerar bubblesort
void bubbleSort(int arr[], int start, int end)
{
    int i, j;
    for (i = start; i < end; i++)
        // Last i elements are already in place 
        for (j = start; j < end /*- i - 1*/; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

//Metod som skriver ut arrayen
void printArray(int arr[], int start, int end)
{
    int i;
    for (i = start; i < end; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{

    //Fyll arrayen med slumpade tal mellan 0 - 99
    for (int i = 0; i < MAX; i++)
        array_to_sort[i] = rand() % 100;



    //Få total storlek av arrayen
    //int n = sizeof(array_to_sort) / sizeof(array_to_sort[0]);

    cout << "Osorted array: " << endl;
    printArray(array_to_sort, 0, MAX);

    high_resolution_clock::time_point t6 = high_resolution_clock::now();


    thread t = thread(bubbleSort, array_to_sort, 0, 4);
    thread t2 = thread(bubbleSort, array_to_sort, 5, 9);
    thread t3 = thread(bubbleSort, array_to_sort, 10, 14);
    thread t4 = thread(bubbleSort, array_to_sort, 15, MAX);


    t.join();
    t2.join();
    t3.join();
    t4.join();
    thread t5 = thread(bubbleSort, array_to_sort, 0, MAX);
    t5.join();

    high_resolution_clock::time_point t7 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t7 - t6);

    cout << "Sorterad array: " << endl;
    printArray(array_to_sort, 0, MAX);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;

    return 0;



    //NYTT


    //Fyll arrayen med slumpade tal mellan 0 - 99
    for (int i = 0; i < MAX; i++)
        array_to_sort1[i] = rand() % 100;

    //Få total storlek av arrayen
    //int n = sizeof(array_to_sort) / sizeof(array_to_sort[0]);

    cout << "Osorted array: " << endl;
    printArray(array_to_sort1, 0, MAX);

    high_resolution_clock::time_point a6 = high_resolution_clock::now();


    thread a = thread(bubbleSort, array_to_sort1, 0, 4);
    thread a2 = thread(bubbleSort, array_to_sort1, 5, 9);
    thread a3 = thread(bubbleSort, array_to_sort, 10, 14);
    thread a4 = thread(bubbleSort, array_to_sort, 15, MAX);
 


    a.join();
    a2.join();
    a3.join();
    a4.join();
    thread a5 = thread(bubbleSort, array_to_sort1, 0, MAX);
    a5.join();

    high_resolution_clock::time_point a7 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(a7 - a6);

    cout << "Sorterad array: " << endl;
    printArray(array_to_sort, 0, MAX);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;

    return 0;
}


