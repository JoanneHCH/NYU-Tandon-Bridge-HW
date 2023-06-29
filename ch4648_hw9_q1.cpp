#include <iostream>
#include <string>
using namespace std;
int main() {
    string input;
    cout << "Please enter a line of text:\n";
    getline(cin, input);

    int word = 1, count[26] = {0};
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') 
            word++;
        if(input[i] >= 'a' && input[i] <= 'z')
            count[input[i] - 'a']++;
        if(input[i] >= 'A' && input[i] <= 'Z')
            count[input[i] - 'A']++;
    }
    cout << word << "\twords\n"; 

    for(int i = 0; i < 26; i++) {
        if (count[i] > 0)
            cout << count[i] << "\t" << (char)('a'+ i) << endl;
    }

    return 0;
}