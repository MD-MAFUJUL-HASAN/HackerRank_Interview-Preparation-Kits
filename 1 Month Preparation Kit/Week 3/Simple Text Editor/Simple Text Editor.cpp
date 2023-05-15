#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void appendString(string& s) {
    string str;
    getline(cin >> ws,str);
    s.append(str);
}

void deleteLastKChar(string& s) {
    int k;
    cin >> k;
    s.erase(s.size()-k,k);     
}

void printKChar(string& s) {
    int k;
    cin >> k;
    cout << s[k-1] << endl;
}

void undo(string& s,stack<string>& undoStack) {
    if(undoStack.size() > 1 ) {
        undoStack.pop();
        s = undoStack.top();
    } else {
        s = "";
    }
}

void editString(string& s,char t,stack<string>& undoStack) {

    switch (t) {
    case '1':
        appendString(s); 
        undoStack.push(s);
        break;
    case '2':
        deleteLastKChar(s);
        undoStack.push(s);
        break;
    case '3':
        printKChar(s);
        break;
    case '4':
        undo(s, undoStack);
        break;
    default:
        cout << "ERR 404" << endl;
        break;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack<string> undoStack;
    int q;
    cin >> q;
    string current;
    undoStack.push(current);
    for(int i = 0; i < q;i++) {
        char t;
        cin >> t;
        editString(current, t,undoStack);   
    }
    return 0;
}
