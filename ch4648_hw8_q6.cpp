#include <iostream>
#include <string>
using namespace std;
bool all_digits(string text, int j, int l);
int main() {
    string text;
    cout << "Please enter a line of text: " << endl;
    getline(cin,text);

    int j = 0;
    bool flag = false;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            flag = all_digits(text, j, i);
            if (flag == true) {
                for(int k = j; k < i; k++) {
                    text[k] = 'x';
                }
            }
            j = i+1;
        }
    }
    
    flag = all_digits(text, j, text.length());
    if (flag == true) {
        for(int k = j; text[k] != '\0'; k++) {
            text[k] = 'x';
        }
    }
    cout << text << endl;
    return 0;
}

bool all_digits(string text, int j, int l) {
    for (int i = j; i < l; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}