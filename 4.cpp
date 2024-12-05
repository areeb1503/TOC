#include <iostream>
#include <string>
using namespace std;

/*
Q4 :Design a Finite Automata (FA) that accepts language L2, over S= {a, b} where L2= a(a+b)*b. Write
a program to simulate this FA.
*/

void state2(string w, int i);
void state3(string w, int i);

void state1(string w,int i){
    cout<<"state 1\n";
    if(w.length()==i){
        cout<<"string is rejected\n";
        return;
    }
    if(w[i]=='b'){
        cout<<"string rejected\n";
        return;
    }
    else if(w[i]=='a'){
        state2(w,i+1);
    }
}
void state2(string w, int i){
    cout<<"state 2\n";
    if(w.length()==i){
        cout<<"string is rejected\n";
        return;
    }
    if(w[i]=='a'){
        state2(w,i+1);
    }
    else if(w[i]=='b'){
        state3(w,i+1);
    }
}
void state3(string w, int i){
    cout<<"state 3\n";
    if(w.length()==i){
        cout<<"string is accepted\n";
        return;
    }
    if(w[i]=='a'){
        state2(w,i+1);
    }
    else if(w[i]=='b'){
        state3(w,i+1);
    }
}
int main() {
    string w;
    cout << "Enter the binary string:\n";
    cin >> w;
    state1(w, 0);
    return 0;
}