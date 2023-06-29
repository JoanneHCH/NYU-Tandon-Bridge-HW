#include <iostream>
using namespace std;
int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr[4] = {2, -1, 3, 10};
    cout << sumOfSquares(arr, 4) << endl;

    int arr1[4] = {2, -1, 3, 10};
    if (isSorted(arr1, 4) == 1)
        cout << "true\n";
    else
        cout << "false\n"; 
    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 0) {
        return 0;
    } else {
        return arr[0] * arr[0] + sumOfSquares(arr + 1, arrSize - 1);
    }
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize == 1) {
        return true;
    } else if (*arr > *(arr + 1)) { 
        return false;
    } else {
        return isSorted(arr + 1, arrSize - 1);
    }
}