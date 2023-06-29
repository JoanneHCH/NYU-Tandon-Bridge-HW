#include <iostream>
using namespace std;
int minInArray(int arr[], int arrSize);

int main() {
    int mini[20], size = 20;
    minInArray(mini, size);
    return 0;
}
int minInArray(int arr[], int arrSize) {
    cout << "Please enter 20 integers separated by a space:\n";
    int min = arr[0];
    for (int i = 0; i < arrSize; i++){
        cin >> arr[i]; 
        if (arr[i] < min)
            min = arr[i];  
    }
    cout << "The minimum value is " << min << ", and it is located in the "
         << "following indices: ";
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == min)
            cout << i << " ";
    }
    cout << endl;
    return min;
}

