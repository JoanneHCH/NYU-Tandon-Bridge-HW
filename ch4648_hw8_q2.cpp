#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string str);
int main() {
    string word;
    cout << "Please enter a word: ";
    cin >> word;

    if (isPalindrome(word))
        cout << word << " is a palindrome\n";
    else 
        cout << word << " is not a palindrome\n";

    return 0;
}

bool isPalindrome(string str) {
    const int length = str.length();
    string reverse[length], rev;
    for (int position = length - 1; position >= 0; position--) {
        int i = 0;
        reverse[i] = str.substr(position,1);
        rev = rev + reverse[i];
        i++;
    }
    return (rev == str);
}