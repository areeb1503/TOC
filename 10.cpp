#include <iostream>
using namespace std;

string incrementBinary(string input) {
    int i = input.size() - 1;

    // Process the binary number from the right
    while (i >= 0 && input[i] == '1') {
        input[i] = '0';
        i--;
    }
    
    // If all were '1's, add '1' at the beginning
    if (i < 0)
        input = '1' + input;
    else
        input[i] = '1';

    return input;
}

int main() {
    string binary;
    cout << "Enter the binary number: ";
    cin >> binary;

    cout << "Incremented binary number: " << incrementBinary(binary) << endl;
    return 0;
}