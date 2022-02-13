// Define an alphabet reflection as follows: a turns into z, b turns into y, c turns into x, ..., n turns into m, m turns into n, ..., z turns into a.

// Define a string reflection as the result of applying the alphabet reflection to each of its characters.

// Reflect the given string.

// Example

// For inputString = "name", the output should be
// reflectString(inputString) = "mznv".

#include <iostream>
using namespace std;

string reflectString(string inputString) {
    string res = "";
    for (char c : inputString)
    {
        res += (122 + 97 - (int)c);
    }
    return res;
}

int main()
{
    return 0;
}