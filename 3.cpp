#include <iostream>
#include <string>
using namespace std;

/*
Q3 :Design a Finite Automata (FA) that accepts language L1, over S={a, b}, comprising of all strings (of
length 4 or more) having first two characters same as the last two. Write a program to simulate this
FA.
*/

void checkstring(string w){
    if(w.length()<4){
        cout<<"string rejected\n";
        return;
    }
    if((w[0]==w[w.length()-1]) && (w[1]==w[w.length()-2])){
        cout<<"string accepted\n";
    }
    else{
        cout<<"string rejected\n";
    }
}
int main() {
    string w;
    cout << "Enter the string (over {a, b}):\n";
    cin >> w;

    checkstring(w);

    return 0;
}