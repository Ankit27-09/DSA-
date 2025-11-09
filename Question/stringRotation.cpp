// String Rotated by 2 Places
// Given two strings s1 and s2. Return true if the string s2 can be obtained by rotating (in any direction) string s1 by exactly 2 places, otherwise, false.
#include <string>
#include <iostream>
using namespace std;

void rotationClockwise(string& s) {
    char c = s[s.size() - 1];
    int index = s.size() - 2;
    while(index >= 0) {
        s[index + 1] = s[index];
        index--;
    }
    s[0] = c;
}

void rotationAntiClockwise(string& s) {
    char c = s[0];
    int index = 1;
    while(index < s.size()) {
        s[index - 1] = s[index];
        index++;
    }
    s[s.size() - 1] = c;
}
int main() {
    string s1 = "amazon";
    string s2 = "azonam";
    string temp = s1;
    // Clockwise Rotation
    rotationClockwise(s1);
    rotationClockwise(s1);
    if (s1 == s2) {
        cout << "True" << endl;
        return 0;
    }
    s1 = temp;
    // Anti-Clockwise Rotation
    rotationAntiClockwise(s1);
    rotationAntiClockwise(s1);
    if (s1 == s2) {
        cout << "True" << endl;
        return 0;
    }
}