#include <iostream>
using namespace std;

bool simulateTuringMachine(string input) {
    int len = input.length(), head = 0;
    
    // Repeat until all 'a', 'b', 'c' are marked
    while (true) {
        // Find the first unmarked 'a' and mark it
        while (head < len && input[head] != 'a') head++;
        if (head == len) break; // No more 'a's, end loop
        input[head] = 'X';
        
        // Move to find the first unmarked 'b' and mark it
        while (head < len && input[head] != 'b') head++;
        if (head == len) return false; // Mismatch in counts
        input[head] = 'Y';
        
        // Move to find the first unmarked 'c' and mark it
        while (head < len && input[head] != 'c') head++;
        if (head == len) return false; // Mismatch in counts
        input[head] = 'Z';
        
        // Reset head position
        head = 0;
    }

    // Accept if all symbols are marked
    for (char c : input)
        if (c == 'a' || c == 'b' || c == 'c') return false;
    return true;
}

int main() {
    string input;
    cout << "Enter the string (a^n b^n c^n): ";
    cin >> input;

    if (simulateTuringMachine(input))
        cout << "Accepted by the Turing Machine.\n";
    else
        cout << "Rejected by the Turing Machine.\n";
    return 0;
}