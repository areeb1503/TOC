#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Q6 :Write a program to simulate an FA that accepts
a. Union of the languages L1 and L2
b. Intersection of the languages L1 and L2
c. Language L1 L2 (concatenation)
*/

bool simulateFA(const vector<vector<int>> &transitionTable, int startState, const unordered_set<int> &finalStates, const string &input) {
    int currentState = startState;
    for (char ch : input) {
        int inputSymbol = (ch == 'a') ? 0 : 1;
        currentState = transitionTable[currentState][inputSymbol];
    }
    return finalStates.count(currentState)>0;
}

bool unionFA(const vector<vector<int>> &transitionTable1, int startState1, const unordered_set<int> &finalStates1,
             const vector<vector<int>> &transitionTable2, int startState2, const unordered_set<int> &finalStates2, const string &input) {
    return simulateFA(transitionTable1, startState1, finalStates1, input) || simulateFA(transitionTable2, startState2, finalStates2, input);
}

bool intersectionFA(const vector<vector<int>> &transitionTable1, int startState1, const unordered_set<int> &finalStates1,
                    const vector<vector<int>> &transitionTable2, int startState2, const unordered_set<int> &finalStates2, const string &input) {
    return simulateFA(transitionTable1, startState1, finalStates1, input) && simulateFA(transitionTable2, startState2, finalStates2, input);
}

bool concatenationFA(const vector<vector<int>> &transitionTable1, int startState1, const unordered_set<int> &finalStates1,
                     const vector<vector<int>> &transitionTable2, int startState2, const unordered_set<int> &finalStates2, const string &input) {
    for (size_t i = 0; i <= input.length(); ++i) {
        if (simulateFA(transitionTable1, startState1, finalStates1, input.substr(0, i)) &&
            simulateFA(transitionTable2, startState2, finalStates2, input.substr(i))) {
            return true;
        }
    }
    return false;
}

int main() {
    int numStates1, numStates2, alphabetSize = 2, numFinalStates1, numFinalStates2;
    
    // Input for FA1
    cout << "Enter the number of states in FA1: ";
    cin >> numStates1;
    vector<vector<int>> transitionTable1(numStates1, vector<int>(alphabetSize));
    cout << "Enter the transition table for FA1 (rows represent states, columns represent inputs 'a' and 'b'):\n";
    for (int state = 0; state < numStates1; ++state) {
        cout << "For state " << state << " -> enter next states for input 'a' and input 'b': ";
        cin >> transitionTable1[state][0] >> transitionTable1[state][1];
    }
    int startState1;
    cout << "Enter the start state for FA1: ";
    cin >> startState1;
    cout << "Enter the number of accepting states for FA1: ";
    cin >> numFinalStates1;
    unordered_set<int> finalStates1;
    cout << "Enter the final states for FA1: ";
    for (int i = 0; i < numFinalStates1; ++i) {
        int state;
        cin >> state;
        finalStates1.insert(state);
    }

    // Input for FA2
    cout << "Enter the number of states in FA2: ";
    cin >> numStates2;
    vector<vector<int>> transitionTable2(numStates2, vector<int>(alphabetSize));
    cout << "Enter the transition table for FA2 (rows represent states, columns represent inputs 'a' and 'b'):\n";
    for (int state = 0; state < numStates2; ++state) {
        cout << "For state " << state << " -> enter next states for input 'a' and input 'b': ";
        cin >> transitionTable2[state][0] >> transitionTable2[state][1];
    }
    int startState2;
    cout << "Enter the start state for FA2: ";
    cin >> startState2;
    cout << "Enter the number of accepting states for FA2: ";
    cin >> numFinalStates2;
    unordered_set<int> finalStates2;
    cout << "Enter the final states for FA2: ";
    for (int i = 0; i < numFinalStates2; ++i) {
        int state;
        cin >> state;
        finalStates2.insert(state);
    }

    string input;
    cout << "Enter the input string to process: ";
    cin >> input;

    cout << "Union FA: " << (unionFA(transitionTable1, startState1, finalStates1, transitionTable2, startState2, finalStates2, input) ? "Accepted" : "Not Accepted") << endl;
    cout << "Intersection FA: " << (intersectionFA(transitionTable1, startState1, finalStates1, transitionTable2, startState2, finalStates2, input) ? "Accepted" : "Not Accepted") << endl;
    cout << "Concatenation FA: " << (concatenationFA(transitionTable1, startState1, finalStates1, transitionTable2, startState2, finalStates2, input) ? "Accepted" : "Not Accepted") << endl;

    return 0;
}