// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>

int 
partition(int *arr, int low, int high) 
{
    int pivot_index = high; // low + (std::rand() % (high - low + 1));
    int pivot = arr[pivot_index];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            if (arr[i] != arr[j])
            {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }

    if (arr[i + 1] != arr[high])
    {
        int aux = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = aux;
    }
    return i + 1;
}

bool
quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
        return true;
    }
    return false;
}

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.
bool
sort_array(int *arr, int n)
{
    return quick_sort(arr, 0, n - 1);
}

// Main function
int main(){
    srand(time(NULL));

    // The following array will be treated as an array of length len. 
    const int len = 1000; // Don't exceed the length of the array below!
    int array[len];

    for (int i = 0; i < len; i++)
        array[i] = rand();

    // Print the original array
    /* std::cout << "Original Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush; */

    sort_array(array, len); // Sort the array

    // Print the sorted array
    /* std::cout << "  Sorted Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush; */

    return 0;
}
