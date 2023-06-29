#include <fstream> 
#include <iostream> 
#include <string>

using namespace std;

void openInputFile (ifstream& infile) {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    infile.open(filename);
    while (!infile) {
        cout << "FILE FAILED TO OPEN!\n";
        cout << "Enter the filename: ";
        cin >> filename;
        infile.clear();
        infile.open(filename);
    }
}

class Node {
    double paid;
    string name;
    double owed;
    Node* prev;
    Node* next;
public:
    Node() : paid(0), name("NA"), owed(0), prev(nullptr), next(nullptr) {};
    Node(double each_owed) : owed(each_owed) {};
    Node(double each_paid, string each_name, Node *linkN, Node *linkP) 
        : paid(each_paid), name(each_name), next(linkN), prev(linkP) {};
    
    void setPaid(double each_paid) {paid = each_paid;}
    void setName(string each_name) {name = each_name;}
    void setOwed(double each_owed) {owed = each_owed;}
    void setNext(Node* linkN) {next = linkN;}
    void setPrev(Node* linkP) {prev = linkP;}
    
    double getPaid() const {return paid;}
    string getName() const {return name;}
    double getOwed() const {return owed;}
    Node* getNext() const {return next;}
    Node* getPrev() const {return prev;}

    friend class LinkedList;
};

class LinkedList {
    Node* head;      
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {};
    ~LinkedList();

    void headInsert(double each_paid, string each_name); 
    double countAve()const;
    void countOwed(double ave);
    void mergeSort();
    Node* merge(Node* left, Node* right);
    Node* mergeSortRecursive(Node* node);
    void PrintList(double ave); 
};

LinkedList :: ~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->getNext();
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

void LinkedList :: headInsert(double each_paid, string each_name) {
    Node *temp_ptr = new Node(each_paid, each_name, head, nullptr);
    if (head != nullptr) {
        head->prev = temp_ptr;
    } else {
        tail = temp_ptr;
    }
    head = temp_ptr;
}

double LinkedList :: countAve() const{
    double total = 0;
    int count = 0;

    for (Node *iter = head; iter != nullptr; iter = iter -> getNext()) {
        total += iter->getPaid();
        count++;
    }

    return total / count;
}

void LinkedList :: countOwed(double ave) {
    for (Node *iter = head; iter != nullptr; iter = iter -> getNext())
        iter -> setOwed(ave - (iter->getPaid())); 
}

void LinkedList::mergeSort() {
    head = mergeSortRecursive(head);
}

Node* LinkedList::mergeSortRecursive(Node* node) {
    if (node == nullptr || node->getNext() == nullptr) 
        return node;

    Node* slow = node;
    Node* fast = node->getNext();
    while (fast != nullptr) {
        fast = fast->getNext();
        if (fast != nullptr) {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }
    Node* right = slow->getNext();
    slow->setNext(nullptr);

    Node* leftSorted = mergeSortRecursive(node);
    Node* rightSorted = mergeSortRecursive(right);

    return merge(leftSorted, rightSorted);
}

Node* LinkedList::merge(Node* left, Node* right) {
    Node* result = nullptr;

    if (left == nullptr) 
        return right;

    if (right == nullptr) 
        return left;

    if (left->getOwed() <= right->getOwed()) {
        result = left;
        result->setNext(merge(left->getNext(), right));
    } else {
        result = right;
        result->setNext(merge(left, right->getNext()));
    }

    return result;
}

void LinkedList :: PrintList(double ave) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    for (Node *iter1 = head; iter1 != nullptr; iter1 = iter1 -> getNext()) {
        double owed = iter1->getOwed();
        if (owed == 0)
            cout << iter1->getName() << ", you don't need to do anything" << endl;
        if (owed > 0) {
            for (Node *iter2 = tail; iter2 != nullptr; iter2 = iter2 -> getPrev()) {
                if (iter2 != iter1 && iter2->getOwed() < 0) {
                    double transfer = min(owed, abs(iter2->getOwed()));
                    cout << iter1->getName() << ", you give " << iter2->getName() 
                         << " $" << setprecision(6) << transfer << endl;
                    iter2->setOwed(iter2->getOwed() + transfer);
                    iter1->setOwed(owed - transfer);
                    owed = iter1->getOwed();
                    if (owed == 0) 
                        break;
                }
            }
        } 
    }

    cout << "In the end, you should all have spent around $" << setprecision(2) << ave << endl;
}

int main() {
    ifstream infile;
    openInputFile (infile);

    LinkedList list;
    double paid;
    string name;
    
    while(infile >> paid) {
        infile.ignore(9999,'\t');
        getline(infile, name);
        list.headInsert(paid, name);
    }
    infile.close();

    double ave = list.countAve();
    list.countOwed(ave);
    list.mergeSort();
    list.PrintList(ave);

    return 0;
}