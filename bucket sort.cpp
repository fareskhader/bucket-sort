#include <bits/stdc++.h>
using namespace std;

// Insertion Sort for sorting individual buckets
void insertionSort(vector<float>& bucket)
{
    for (int i = 1; i < bucket.size(); i++)
    {
        float key = bucket[i];
        int j = i - 1;

        // Move elements of bucket[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Bucket Sort function for numbers greater than 1
void bucketSort(float numbers[], int size)
{
    if (size <= 0) return; // Edge case: empty array

    // Find the minimum and maximum values in the array
    float minVal = *min_element(numbers, numbers + size);
    float maxVal = *max_element(numbers, numbers + size);

    // Calculate the range of the numbers
    float range = maxVal - minVal;

    // Handle edge case where all numbers are the same
    if (range == 0) return;

    // Create 10 buckets
    int base = 10;
    vector<float> bucket[base];

    // Distribute numbers into buckets
    for (int i = 0; i < size; i++)
    {
        // Scale the number to a value between 0 and 1
        float scaledValue = (numbers[i] - minVal) / range;

        // Calculate the bucket index
        int bucketIndex = static_cast<int>(scaledValue * (base - 1));
        bucket[bucketIndex].push_back(numbers[i]);
    }

    // Sort individual buckets using Insertion Sort
    for (int b = 0; b < base; b++)
    {
        insertionSort(bucket[b]);
    }

    // Merge sorted buckets back into the original array
    int sortedIndex = 0;
    for (int i = 0; i < base; i++)
    {
        for (int b = 0; b < bucket[i].size(); b++)
        {
            numbers[sortedIndex] = bucket[i][b];
            sortedIndex++;
        }
    }
}

int main()
{
    // Test array with numbers greater than 1
    float arr[] = {0.45, 0.5, 0.76, 0.75, 0.24, 0.234, 0.132,0.123};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bucketSort
    bucketSort(arr, size);

    // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
