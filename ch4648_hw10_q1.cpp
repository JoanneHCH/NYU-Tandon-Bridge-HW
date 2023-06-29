#include <iostream>
#include <string>
#include <vector>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    int outWordsArrSize;
    string str1 = "You can do it";
    string* str2 = createWordsArray(str1, outWordsArrSize);

    cout << '[';
    for (int i = 0; i < outWordsArrSize; i++) {
        if(i != outWordsArrSize - 1)
            cout << '"' << str2[i] << '"'<< " , ";
        else
            cout << '"' << str2[i] << '"' << "]\n";
    }
    cout << "The array size is " << outWordsArrSize << endl;

    delete [] str2;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    outWordsArrSize = 1;
    int i = 0;
    vector<int> index;
    while (sentence.find(" ", i) != string::npos) {
        int pos = sentence.find(" ", i);
        index.push_back(sentence.find(" ", i));
        i = pos + 1;
        outWordsArrSize++;
    }

    index.push_back(sentence.length());

    string* str = new string[outWordsArrSize];
    int k = 0, n = 0;
    for (int j = 0; j < index.size(); j++) {
        str[n] = sentence.substr(k, index[j] - k);
        k = index[j] + 1;
        n++;
    }

    return str;
}