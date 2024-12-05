#include <iostream>
#include <string>
using namespace std;

/*
Q1 : Design a Finite Automata (FA) that accepts all strings over S={0, 1} having three consecutive 1's as
a substring. Write a program to simulate this FA.
*/

void state2(string w, int i);
void state3(string w, int i);
void state4(string w, int i);

void state1(string w, int i) {
    cout << "state 1\n";
    if (i == w.length()) {
        cout << "string is rejected\n";
        return;
    } else {
        if (w[i] == '0') {
            state1(w, i + 1);
        } else if (w[i] == '1') {
            state2(w, i + 1);
        }
    }
}

void state2(string w, int i) {
    cout << "state 2\n";
    if (i == w.length()) {
        cout << "string is rejected\n";
        return;
    } else {
        if (w[i] == '0') {
            state1(w, i + 1);
        } else if (w[i] == '1') {
            state3(w, i + 1);
        }
    }
}

void state3(string w, int i) {
    cout << "state 3\n";
    if (i == w.length()) {
        cout << "string is rejected\n";
        return;
    } else {
        if (w[i] == '0') {
            state1(w, i + 1);
        } else if (w[i] == '1') {
            state4(w, i + 1);
        }
    }
}

void state4(string w, int i) {
    cout << "state 4\n";
    if (i == w.length()) {
        cout << "string is accepted\n";
        return;
    } else {
        if (w[i] == '0') {
            state4(w, i + 1);
        } else if (w[i] == '1') {
            state4(w, i + 1);
        }
    }
}

int main() {
    string w;
    cout << "Enter the binary string:\n";
    cin >> w;
    state1(w, 0);
    return 0;
}