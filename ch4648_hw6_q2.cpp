#include <iostream>
using namespace std;

// It prints an n-line triangle, filled with symbol characters, shifted m
// spaces from the left margin.
void printShiftedTriangle(int n,int m,char symbol);

// It prints a sequence of n triangles of increasing sizes (the smallest
// triangle is a 2-line triangle), which form the shape of a pine tree. The
// triangles are filled with the symbol character.
void printPineTree(int n, char symbol);

int main() {
    int line, space, num_tri, choice;
    char character, character_pine;
    cout << "What shape do you want to print: enter 1 for a triangle or 2 for "
         << "a pine tree: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the number of the lines of the triangle: ";
        cin >> line;
        cout << "Enter the number of the spaces from the left margin: ";
        cin >> space;
        cout << "Enter the characters (eg. '*' or '+' or '$' etc) to fill the "
             << "triangle: ";
        cin >> character;
        printShiftedTriangle(line, space, character);
    } else if (choice == 2) {
        cout << "Enter the number of the triangles: ";
        cin >> num_tri;
        cout << "Enter the characters (eg. '*' or '+' or '$' etc) to fill the "
             << "triangle: ";
        cin >> character_pine;
        printPineTree(num_tri, character_pine);
    } else {
        cout << "Invalid option.\n";
    }

    return 0;
} 

void printShiftedTriangle(int n,int m,char symbol) {
    int line, space;
    char character;
    for (line = 1; line <= n; line++) {
        for (space = 1; space <= m + n - line; space++)
            cout << ' ';
        for (character = 1; character <= 2 * line - 1; character++)
            cout << symbol;
    cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    int count, line, space;
    char character;
    for(count = 1; count <= n; count++) {
        for (line = 1; line <= count + 1; line++) {
            for (space = n - line + 1; space > 0; space--)
                cout << ' ';
            for (character = 1; character <= 2 * line - 1; character++)
                cout << symbol;
        cout << endl;
        }
    }
}