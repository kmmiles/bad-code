#include <stdlib.h>

int* MergeTwoArrays(int array1[], int arr1Size, int array2[], int arr2Size);
int* MergeSort(int* array, int size);

int main()
{

    int unSortedArray[] = { -17, 1, 1, 10, 100, -20, 13, 14, 15, 255, 9, -24, 0, -5, 1, 2, 3, 10, -12, -14, 1, 0, 1, 100 };

    int const arraySize = sizeof(unSortedArray) / sizeof(unSortedArray[0]);

    //just assuming this array was on the heap with heavy objects
    int* unSortedHeapArray = (int*)malloc(sizeof(int) * arraySize);

    for (int i = 0; i < arraySize; ++i)
    {
        unSortedHeapArray[i] = unSortedArray[i];
    }

    int* sortedArray = MergeSort(unSortedHeapArray, arraySize);
}

int* MergeTwoArrays(int array1[], int arr1Size, int array2[], int arr2Size)
{
    int const totalElements = arr1Size + arr2Size;

    int* mergedArray = (int*)malloc(sizeof(int) * totalElements);

    int i = 0; //for the index of array1
    int j = 0; //for the index of array2

    for (int k = 0; k < totalElements; ++k)
    {
        if (array1[i] > array2[j])
        {
            mergedArray[k] = array2[j];
            ++j;
        }
        else
        {
            mergedArray[k] = array1[i];
            ++i;
        }

        //------ if we are at the end of one of the arrays, append the remaining of the array and break;
        if (j == arr2Size)
        {
            for (int t = i; k < totalElements; ++t)
            {
                mergedArray[++k] = array1[t];
            }
            break;
        }
        else if (i == arr1Size)
        {
            for (int t = j; k < totalElements; ++t)
            {
                mergedArray[++k] = array2[t];
            }
            break;
        }
    }

    return mergedArray;
}

int* MergeSort(int* array, int size)
{
    if (size < 2)
    {
        return array;
    }
    int mid = (size + 1) / 2;

    int* lhs = MergeSort(array, mid);
    int* rhs = MergeSort(&array[mid], size - mid);

    return MergeTwoArrays(lhs, mid, rhs, size - mid);
}
