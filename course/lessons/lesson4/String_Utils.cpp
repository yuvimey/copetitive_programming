//
// Created by Gili on 04/01/2022.
//

// Function to print a substring str[low..high]
void printSubStr( string str, int low, int high )
{
    for( int i = low; i <= high; ++i )
        cout << str[i];
}

// Transform S into new string with special characters inserted.
//for example: "abc" -> "@#a#b#c#@"
string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}