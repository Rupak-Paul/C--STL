#include <bits/stdc++.h>
using namespace std;

int main() {
    //string
    //internally string is a character array maintained using vector<char>
    //string initilization
    string str1(3, 'A'); //fills the string with 3 consecutive copies of character A
    string str2("BBB");
    string str3 = "CCC";
    
    //string concatenation using + operator
    string str4 = str1 + str2 + str3 + "DDD" + 'E'; //str4: AAABBBCCCDDDE

    //some vector-like string operation
    str4.length(); //returns 13
    str4.push_back('F'); //str4: AAABBBCCCDDDEF
    str4.pop_back(); //str4: AAABBBCCCDDDE
    str4[12] = 'F'; //str4: AAABBBCCCDDDF

    //overloaded comparison operator (==, !=, <, >, <=, >=) in string 
    string str5 = "alpha";
    string str6 = "beta";
    if(str5 == str6) cout << "equal\n";
    if(str5 != str6) cout << "not equal\n";
    if(str5 < str6) cout << "less than\n";
    if(str5 > str6) cout << "greater than\n";
    
    //substring, first parameter is position and 2nd parameter is length
    string str7 ="We think in generalities, but we live in details";
    string str8 = str7.substr(3, 5); //"think"
    
    //find method returns position of the first character of the first match
    //If no matches were found, the function returns string::npos
    string str9 ("There are 2 needles in this haystack with needles");
    string str10 ("needle");
    int found = str9.find(str10); if(found != string::npos) cout << found; //12 will be printed
    found = str9.find("needles", found + 1); if(found != string::npos) cout << found; //42 will be printed
    found = str9.find("haystack"); if(found != string::npos) cout << found; //28 will be printed
    found = str9.find('2'); if(found != string::npos) cout << found; //10 will be printed
    
    //similar to find but only difference is it searches the string form end
    string str11("The sixth sick sheik's sixth sheep's sick.");
    string str12 ("sixth");
    str11.rfind(str12); //returns 23

    //replace function: 1st parameter is position, 2nd parameter is length, 3rd parameter is replace with string
    str11.replace (str11.find(str12), str12.length(), "seventh"); //str11: "The seventh sick sheik's sixth sheep's sick."

    //Returns const char* points to the internal array currently used by the string object to store the chars
    //The pointer returned may be invalidated by further calls to other member functions that modify the object
    string str12 = "This is a string";
    str12.c_str();
    char *str13 = new char [str12.length() + 1];
    strcpy(str13, str12.c_str());
    
    //string tokenizing
    string str14("Please split this sentence into tokens");
    vector<string> tokens;
    char *p = strtok ((char *)str14.c_str(), " ");
    while(p != NULL) {
        tokens.push_back(p);
        p = strtok(NULL, " ");
    }
}