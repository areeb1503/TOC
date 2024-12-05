#include <iostream>
#include <stack>
using namespace std;

bool simulatePDA(string input) {
    stack<char> st;
    int i = 0;

    // Push 'a's on stack in state q0
    while (i < input.size() && input[i] == 'a') {
        st.push('a');
        i++;
    }

    // Match 'b's with 'a's in state q1
    while (i < input.size() && input[i] == 'b') {
        if (st.empty()) return false;
        st.pop();
        i++;
    }

    // Accept if end of input and stack is empty
    return (i == input.size() && st.empty());
}

int main() {
    string input;
    cout << "Enter the string (only a^n b^n): ";
    cin >> input;

    if (simulatePDA(input))
        cout << "Accepted by the PDA.\n";
    else
        cout << "Rejected by the PDA.\n";
    return 0;
}