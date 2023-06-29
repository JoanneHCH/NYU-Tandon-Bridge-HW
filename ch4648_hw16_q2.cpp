#include <iostream>
#include <vector>

using namespace std;

template <class T>
class vectorQueue {
    vector<T> data;
    int start;
    int end;
public:
    vectorQueue() : start(0), end(0) {};
    void enqueue(T newItem) { data.push_back(newItem); end++; }
    void dequeue();
    T top() const {return data[start];}
    bool isEmpty() const { return data.empty(); }
    void Print();
};

template <class T>
void vectorQueue<T>::dequeue() {
    start++;
    if (start == end) {
        data.clear();
        start = 0;
        end = 0;
    }
}

template <class T>
void vectorQueue<T>::Print() {
    if (isEmpty())
        cout << "Queue is empty.\n";
    else {
        for (int i = start; i < end; i++)
            cout << data[i] << ' ';
        cout << endl;
    }
}

int main() {
    vectorQueue<int> a;

    for (int i = 0; i < 5; i++)
        a.enqueue(i);

    a.dequeue();
    a.dequeue();

    cout << a.isEmpty() << endl;
    cout << a.top() << endl;
    a.Print();

    return 0;
}