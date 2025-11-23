#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isPalindrome(string str) {
    stack<char> s;
    string filteredStr = "";

    for (char c : str) {
        if (isalnum(c)) {
            char lowerChar = tolower(c);
            filteredStr += lowerChar;
            s.push(lowerChar);
        }
    }

    for (char c : filteredStr) {
        if (s.top() != c)
            return false;
        s.pop();
    }
    return true;
}

int main() {
    cout << isPalindrome("A man a plan a canal Panama") << endl; // True
    cout << isPalindrome("hello") << endl; // False
    return 0;
}
