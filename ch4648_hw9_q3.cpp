#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr,
                 int* outPosArrSizePtr);
void printArr(int* arr, int outPosArrSize);

int main() {
    int size = 6, outPosArrSize;
    int arr[] = {3, -1, -3, 0, 6, 4};

    int* posArr1 = getPosNums1(arr, size, outPosArrSize);
    printArr(posArr1, outPosArrSize);
    delete[] posArr1;

    int* posArr2 = getPosNums2(arr, size, &outPosArrSize);
    printArr(posArr2, outPosArrSize);
    delete[] posArr2;

    int* posArr3;
    getPosNums3(arr, size, posArr3, outPosArrSize);
    printArr(posArr3, outPosArrSize);
    delete[] posArr3;

    int* posArr4;
    getPosNums4(arr, size, &posArr4, &outPosArrSize);
    printArr(posArr4, outPosArrSize);
    delete[] posArr4;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    outPosArrSize = 0;
    int* newArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            newArr[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    } 
    return newArr;   
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    int* newArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            newArr[*outPosArrSizePtr] = arr[i];
            (*outPosArrSizePtr)++;
        }
    } 
    return newArr;  
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = 0;
    outPosArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    } 
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr,
                 int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    *outPosArrPtr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[*outPosArrSizePtr] = arr[i];
            (*outPosArrSizePtr)++;
        }
    } 
}

void printArr(int* arr, int outPosArrSize) {
    for (int i = 0; i < outPosArrSize; i++)
        cout << arr[i] << ' ';
    cout << endl;
}