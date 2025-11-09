// Recursion in String

// 1. Check Palindrome
#include <iostream>
using namespace std;
#include <string>

bool checkPalindrome(string s, int start, int end) {
    if(start >= end) {
        return true;
    }
    if(s[start] != s[end]) {
        return false;
    }
    return checkPalindrome(s, start + 1, end - 1);
}
int main() {
    string s = "madam";
    if(checkPalindrome(s, 0, s.length() - 1)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
} 

// 2. count Vowels 

int count(string str, int index) {
    // Base case: if index reaches the end of the string, return 0
    if(index == str.length()) {
        return 0;
    }
    if(str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u'){
        return 1 + count(str, index + 1);
    } else {
        return count(str, index + 1);
    }
}
int main() {
    string str = "hello world";
    int vowelCount = count(str, 0);
    cout << "Number of vowels in the string: " << vowelCount << endl;
    return 0;
}

//3. Reverse a string using recursion

void reverseString(string &str, int start, int end) {
    if(start >= end) {
        return;
    }
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}

int main() {
    string str = "hello";
    reverseString(str, 0, str.length() - 1);
    cout << "Reversed string: " << str << endl;
    return 0;
}

// 4. Lowercase to Uppercase conversion using recursion
// If we want to convert any letter from lowercase to uppercase, we can subtract 32 from the ASCII value of the character.

void toUpperCase(string &str, int index) {
    if(index == str.length()) {
        return;
    }
    if(str[index] >= 'a' && str[index] <= 'z') {
        str[index] = str[index] - 32; // Convert to uppercase
    }
    toUpperCase(str, index + 1);
}
 
int main() {
    string str = "hello world";
    toUpperCase(str, 0);
    cout << "String in uppercase: " << str << endl;
    return 0;
}

//Uppercase to Lowercase conversion using recursion
// If we want to convert any letter from uppercase to lowercase, we can add 32 to the ASCII value of the character.

void toLowerCase(string &str, int index) {
    if(index == str.length()) {
        return;
    }
    if(str[index] >= 'A' && str[index] <= 'Z') {
        str[index] = str[index] + 32; // Convert to lowercase
    }
    toLowerCase(str, index + 1);
}

int main() {
    string str = "HELLO WORLD";
    toLowerCase(str, 0);
    cout << "String in lowercase: " << str << endl;
    return 0;
}