#include <iostream>
#include <vector>
using namespace std;
void oddsKeepEvensFlip(int arr[], int arrSize);
int main() {
    int a[] = {5, 2, 11, 7, 6, 4}, size = 6;
    oddsKeepEvensFlip(a, size);
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    vector<int> odd, even, rev_even;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            odd.push_back(arr[i]);
        } else {
            even.push_back(arr[i]);
        }
    }
    for (int i = even.size() - 1; i >= 0; i--) {
        rev_even.push_back(even[i]);
    }
    for (int i = 0; i < rev_even.size(); i++) {
        odd.push_back(rev_even[i]);
    }
    for (int i = 0; i < odd.size(); i++) {
        cout << odd[i] << ' ';
    }
    cout << endl;
}