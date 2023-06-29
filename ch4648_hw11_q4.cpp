#include <iostream>
using namespace std;
int miniSum(int arr[], int arrSize);

int main() {
    int arr[] = {0, 3, 80, 6, 57, 10};
    cout << miniSum(arr, 6) << endl;
    return 0;
}

int miniSum(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0];
    } else if (arrSize == 2) {
        return arr[0] + arr[1];
    } else {
        int one_step = arr[0] + miniSum(arr + 1, arrSize - 1);
        int two_step = arr[0] + miniSum(arr + 2, arrSize - 2);
        if (one_step > two_step)
            return two_step;
        else
            return one_step;
    }
}