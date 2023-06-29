#include <iostream>
#include <vector>
using namespace std;

int* main1(int& index);
vector<int> main2();

int main() {
    int index;
    int* a = new int [index + 1];
    a = main1(index);

    for (int i = 0; i < index + 1; i++) {
        if (i != index)
            cout << a[i] << ", ";
        else
            cout << a[i] << ".";
    }
    cout << endl;

    delete [] a;

    vector<int> b = main2();

    for (int i = 0; i < b.size(); i++) {
        if (i != b.size() - 1)
            cout << b[i] << ", ";
        else
            cout << b[i] << ".";
    }
    cout << endl;

    return 0;
}

int* main1(int& index) {
    cout << "Please enter a sequence of positive integers, each in a separate " 
         << "line.\n"; 
    cout << "End you input by typing -1.\n";
    
    int size = 1;
    int* input = new int[size];

    for (int count = 0; count < size; count++) {
        cin >> input [count];
        if (input [count] != -1)
            size++;
    }

    int num;
    cout << "Please enter a number you want to search.\n";
    cin >> num;
    cout << num << " shows in lines ";

    index = 0;
    int* result = new int[index + 1];

    for (int i = 0; i < size; i++) {
        if (input[i] == num) {
            result[index] = i + 1;
            index++;
        }
    }
    index--;

    delete [] input;
    
    return result;
}

vector<int> main2() {
    cout << "Please enter a sequence of positive integers, each in a separate " 
         << "line.\n"; 
    cout << "End you input by typing -1.\n";
    
    int input;
    vector<int> seq_num;

    while (input != -1) {
        cin >> input;
        seq_num.push_back(input);
    }
    
    int num;
    cout << "Please enter a number you want to search.\n";
    cin >> num;
    cout << num << " shows in lines ";

    vector<int> find;

    for (int i = 0; i < seq_num.size(); i++) {
        if (seq_num[i] == num) {
            find.push_back(i + 1);
        }
    }

    return find;
}