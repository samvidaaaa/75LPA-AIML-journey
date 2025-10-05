#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mapping = {{')','('}, {'}','{'}, {']','['}};

    for(char c : s) {
        if(mapping.count(c)) { // closing bracket
            char top_element = st.empty() ? '#' : st.top();
            if(!st.empty()) st.pop();
            if(mapping[c] != top_element) return false;
        } else {
            st.push(c); // opening bracket
        }
    }
    return st.empty();
}

int main() {
    cout << isValid("()") << endl;        // 1 (true)
    cout << isValid("()[]{}") << endl;    // 1 (true)
    cout << isValid("(]") << endl;        // 0 (false)
    cout << isValid("([{}])") << endl;    // 1 (true)
    return 0;
}
