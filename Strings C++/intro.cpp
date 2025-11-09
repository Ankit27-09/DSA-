#include <iostream>
using namespace std;
#include <string>

//  Basic String format in CPP

// int main()
// {
 
//     string s;
//     cout << "Enter String" << endl;
//     getline(cin, s);
//     cout << "String is: " << s << endl;
//     return 0;
// }

// For Finding the string length we use .size();

// int main()
// {
//     string s;
//     cout << "Enter String" << endl;
//     getline(cin, s);
//     int length = s.size();
//     cout << "String size: " << length << endl;
//     return 0;
// }


// Combining the two strings;

// int main()
// {
//     string s1;
//     cout << "Enter String1" << endl;
//     getline(cin, s1);

//     string s2;
//     cout << "Enter String2" << endl;
//     getline(cin, s2);

//     string s3 = s1 + s2;
//     cout << s3;
//     return 0;
// }

// TO push or pop the character from the string :--
int main() {
    string s1;
    cout <<" Enter the string" << endl;
    cin >> s1;
    s1.push_back('p');
    cout << s1;
    s1.pop_back();
    cout << s1;
}