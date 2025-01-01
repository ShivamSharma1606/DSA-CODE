// Heap Sort

// steps:
//  1. Build a max heap from the input data
//  2. The largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of the heap by 1
//  3. Heapify the root of the tree
//  4. Repeat the above steps until the size of the heap is greater than 1
//  5. The array is now sorted
//! Time Complexity: O(n log n)
//! Space Complexity: O(1)

// Heap sort is based on the selection sort algortihm

#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int ind, int size)
{
	int left = 2 * ind + 1;
	int right = 2 * ind + 2;
	int largest = ind;

	if (left < size && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < size && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (ind != largest)
	{
		swap(arr[ind], arr[largest]);
		maxHeapify(arr, largest, size);
	}
}

vector<int> buildHeap(vector<int> &arr, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		maxHeapify(arr, i, n);
	}

	return arr;
}

vector<int> heapSort(vector<int> &given, int n)
{

	vector<int> arr = given;
	buildHeap(arr, n);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);
		maxHeapify(arr, 0, i);
	}

	return arr;
}

int main()
{
	vector<int> arr = {5, 3, 8, 4, 2};
	int n = arr.size();

	vector<int> sorted = heapSort(arr, n);

	for (int i = 0; i < n; i++)
	{
		cout << sorted[i] << " ";
	}
	cout << endl;

	return 0;
}