#include <iostream>
#include <string>
using namespace std;

/*
Q2 :Design a Finite Automata (FA) that accepts all strings over S={0, 1} having either exactly two 1's or
exactly three 1's, not more nor less. Write a program to simulate this FA.
*/

void state1(string w, int i);
void state2(string w, int i);
void state3(string w, int i);
void state4(string w, int i);

void state1(string w, int i) {
    cout<<"State 1"<<endl;
    if (i == w.length()) {
        cout << "String is rejected\n";
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
    cout<<"State 2"<<endl;
    if (i == w.length()) {
        cout << "String is rejected\n";
        return;
    } else {
        if (w[i] == '0') {
            state2(w, i + 1);
        } else if (w[i] == '1') {
            state3(w, i + 1);
        }
    }
}

void state3(string w, int i) {
    cout<<"State 3"<<endl;
    if (i == w.length()) {
        cout << "String is accepted (exactly two 1's)\n";
        return;
    } else {
        if (w[i] == '0') {
            state3(w, i + 1);
        } else if (w[i] == '1') {
            state4(w, i + 1);
        }
    }
}

void state4(string w, int i) {
    cout<<"State 4"<<endl;
    if (i == w.length()) {
        cout << "String is accepted (exactly three 1's)\n";
        return;
    } else {
        if (w[i] == '0') {
            state4(w, i + 1);
        } else if (w[i] == '1') {
            cout << "String is rejected (more than three 1's)\n";
            return;
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