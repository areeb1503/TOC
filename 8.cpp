#include <iostream>
#include <stack>
using namespace std;

bool simulatePDA(string input) {
    stack<char> st;
    int i = 0;

    // Push 'w' characters onto the stack
    while (i < input.size() && input[i] != 'X') {
        st.push(input[i]);
        i++;
    }

    // Check if we have reached the 'X' symbol
    if (i == input.size() || input[i] != 'X') return false;
    i++; // Move past 'X'

    // Match characters with reversed 'w'
    while (i < input.size()) {
        if (st.empty() || st.top() != input[i])
            return false;
        st.pop();
        i++;
    }

    // Accept if stack is empty
    return st.empty();
}

int main() {
    string input;
    cout << "Enter the string (wXwr): ";
    cin >> input;

    if (simulatePDA(input))
        cout << "Accepted by the PDA.\n";
    else
        cout << "Rejected by the PDA.\n";
    return 0;
}