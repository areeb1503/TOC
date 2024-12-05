#include <iostream>
#include <string>
using namespace std;

/*
Q5 :Design a Finite Automata (FA) that accepts language EVEN-EVEN over S={a, b}. Write a program
to simulate this FA
*/

void state0(string w, int i);
void state1(string w, int i);
void state2(string w, int i);
void state3(string w, int i);

void state0(string w, int i) {
    if (i == w.length()) {
        cout << "String is accepted (even a's and even b's)\n";
        return;
    } else {
        if (w[i] == 'a') {
            state1(w, i + 1);
        } else if (w[i] == 'b') {
            state2(w, i + 1);
        } else {
            cout << "String is rejected (invalid character)\n";
        }
    }
}

void state1(string w, int i) {
    if (i == w.length()) {
        cout << "String is rejected (odd a's)\n";
        return;
    } else {
        if (w[i] == 'a') {
            state0(w, i + 1);
        } else if (w[i] == 'b') {
            state3(w, i + 1);
        } else {
            cout << "String is rejected (invalid character)\n";
        }
    }
}

void state2(string w, int i) {
    if (i == w.length()) {
        cout << "String is rejected (odd b's)\n";
        return;
    } else {
        if (w[i] == 'a') {
            state3(w, i + 1);
        } else if (w[i] == 'b') {
            state0(w, i + 1);
        } else {
            cout << "String is rejected (invalid character)\n";
        }
    }
}

void state3(string w, int i) {
    if (i == w.length()) {
        cout << "String is rejected (odd a's and odd b's)\n";
        return;
    } else {
        if (w[i] == 'a') {
            state2(w, i + 1);
        } else if (w[i] == 'b') {
            state1(w, i + 1);
        } else {
            cout << "String is rejected (invalid character)\n";
        }
    }
}

int main() {
    string w;
    cout << "Enter the string (over {a, b}):\n";
    cin >> w;

    state0(w, 0);

    return 0;
}