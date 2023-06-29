#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void openInputFile(ifstream& inFile) {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    inFile.open(filename);
    while(!inFile) {
        cout << "FILE FAILED TO OPEN!\n";
        cout << "Enter the filename: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

bool balanceChecker(ifstream& inFile) {
    string words;
    stack<char> symbols;
    bool start = false;

    while (inFile >> words) {
        if (words == "begin")
            start = true;

        if (start) {
            for (char c : words) {
                switch(c) {
                    case '{':
                    case '(':
                    case '[':
                        symbols.push(c);
                        break;
                    case '}':
                        if (symbols.empty() || symbols.top() != '{')
                            return false;
                        symbols.pop();
                        break;
                    case ')':
                        if (symbols.empty() || symbols.top() != '(')
                            return false;
                        symbols.pop();
                        break;
                    case ']':
                        if (symbols.empty() || symbols.top() != '[')
                            return false;
                        symbols.pop();
                        break;
                }
            }
        }

        if (words == "end" && start && symbols.empty())
            return true;
    }

    return false;
}

int main() {
    ifstream inFile;
    openInputFile(inFile);

    if (balanceChecker(inFile))
        cout << "Symbols are balanced.\n";
    else
        cout << "Symbols are not balanced.\n"; 
    
    inFile.close();

    return 0;
}