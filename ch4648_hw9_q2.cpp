#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> CountFrequency(string str);

int main() {
    string first_str, second_str;
    cout << "Please enter the first string:\n";
    getline(cin, first_str);
    cout << "Please enter the second string:\n";
    getline(cin, second_str);

    vector<int> first_count = CountFrequency(first_str);
    vector<int> second_count = CountFrequency(second_str);

    int val = 0;
    for(int i = 0; i < 26; i++) {
        if (first_count[i] != second_count[i])
            val++;
    }

    if (val == 0)
        cout << "The two strings are anagrams\n";
    else 
        cout << "The two strings are not anagrams\n";

    return 0;
}

vector<int> CountFrequency(string str) {
    vector<int> count(26, 0);
    for (int i = 0; i < str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            count[str[i] - 'a']++;
        if(str[i] >= 'A' && str[i] <= 'Z')
            count[str[i] - 'A']++;
    }
    return count;
}