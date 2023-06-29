#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

vector<int> InsertionSort(vector<int> a) { //Insertion sort
    for (int i = 1; i < a.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i--;
            }
        }
    }
    return a;
}

vector<int> ShellSort(vector<int> a) { //Shell sort
    for (int gap = a.size() / 2; gap > 0; gap--) {
        for (int j = gap; j < a.size(); j++) {
            int temp = a[j];
			int i = 0;
			
			for(i = j; (i >= gap) && (a[i - gap] > temp); i-=gap) {
				a[i] = a[i - gap];
			}
			a[i] = temp;
        }   
    }
    return a;
}

void Heapify(vector<int>& a, int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && a[left] > a[largest])
      largest = left;
  
    if (right < n && a[right] > a[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(a[i], a[largest]);
      Heapify(a, n, largest);
    }
}
  
  // main function to do heap sort
vector<int> HeapSort(vector<int> a) { 
    // Build max heap
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
      Heapify(a, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(a[0], a[i]);
  
      // Heapify root element to get highest element at root again
      Heapify(a, i, 0);
    }
    return a;
}

void merge (vector<int>& a, vector<int>& temp, int leftStart, int leftEnd, int rightEnd) {
  int tempIndex = leftStart;
  int originalStart = leftStart;
  int rightStart = leftEnd + 1;
  while (leftStart <= leftEnd && rightStart <= rightEnd) {
    if (a[leftStart] < a[rightStart])
      temp[tempIndex++] = a[leftStart++];
    else
      temp[tempIndex++] = a[rightStart++];
  }
  while (leftStart <= leftEnd)
    temp [tempIndex++] = a[leftStart++];
  while (rightStart <= rightEnd)
    temp [tempIndex++] = a[rightStart++];
  for (int i = originalStart; i <= rightEnd; i++)
    a[i] = temp[i];
}
void MergeSort (vector<int>& a, vector<int>& temp, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    MergeSort(a, temp, start, mid);
    MergeSort(a, temp, mid + 1, end);
    merge(a, temp, start, mid, end);
  }
}
vector<int> MergeSort (vector<int> a){ //Driver
  vector<int> temp;
  temp.resize(a.size());
  MergeSort(a, temp, 0, a.size() - 1);
  return a;
}

int partition(vector<int>& a, int start, int end) {
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (a[i] <= pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap (a[pIndex], a[end]);

    return pIndex;
}
void QuickSort(vector<int>& a, int start, int end) {
    if (start >= end) 
        return;
    
    int pivot = partition(a, start, end);
    QuickSort(a, start, pivot - 1);
    QuickSort(a, pivot + 1, end);
}
vector<int> QuickSort(vector<int> a){ //Driver
  QuickSort(a, 0, a.size() - 1);
  return a;
}

// Function to get the largest element from an array
int getMax(vector<int>& a, int n) {
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}
// Using counting sort to sort the elements in the basis of significant places
void countingSort(vector<int>& a, int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++) // Calculate count of elements
    count[(a[i] / place) % 10]++;

  for (int i = 1; i < max; i++) // Calculate cumulative count
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) { // Place the elements in sorted order
    output[count[(a[i] / place) % 10] - 1] = a[i];
    count[(a[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    a[i] = output[i];
}
// Main function to implement radix sort
vector<int> RadixSort(vector<int> a) { 
  int size = a.size();
  int max = getMax(a, size); // Get maximum element

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(a, size, place);

  return a;
}

vector<int> BubbleSort(vector<int> a) {
    int i, j;
    for (i = 0; i < a.size() - 1; i++) {
       // Last i elements are already in place
        for (j = 0; j < a.size() - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        } 
    }
    return a;
}
 
int main() {
  vector<int> arr = {4, 67, 98, 39, 2, 178, 90, 34, 12, 54};
  Print(InsertionSort(arr));
  Print(ShellSort(arr));
  Print(HeapSort(arr));
  Print(MergeSort(arr));
  Print(QuickSort(arr));
  Print(RadixSort(arr));
  Print(BubbleSort(arr));

    return 0;
}


