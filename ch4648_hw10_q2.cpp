#include <iostream>
using namespace std;
int* findMissing(int arr[], int n, int& resArrSize);
int main() {
    int resArrSize;
    int arr[] = {3, 1, 3, 0, 6, 4};
    int* result = findMissing(arr, 6, resArrSize);

    for (int i = 0; i < resArrSize; i++) 
        cout << result[i] << " ";
    cout << endl;

    cout << "The array size is " << resArrSize << endl;

    delete [] result;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int temp[n+1];
    for (int i = 0; i < n + 1; i++) {
        temp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        temp[arr[i]]++;
    }

    resArrSize = 0;
    for (int i = 0; i < n + 1; i++) {
        if (temp[i] == 0)
            resArrSize++;
    }

    int* resArr = new int [resArrSize];
    int j = 0;
    for (int i = 0; i < n + 1; i++) {
        if (temp[i] == 0) {
            resArr[j] = i;
            j++;
        }       
    }

    return resArr;
}