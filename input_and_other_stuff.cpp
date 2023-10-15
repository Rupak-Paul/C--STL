#include <bits/stdc++.h>
using namespace std;

void inputMethod1() {
    //It will keep on taking input from stdinput until: (i) EOF is encounted ("ctrl+z" in windows)
    //OR (ii) some invaild input is given (some non integer input in this case)
    int a, b;
    while(cin >> a >> b) {
        cout << "Sum of this two is : " << (a+b) << endl;
    }
}

void inputMethod2() {
    //It will keep on taking input until EOF ("ctrl+Z" in windows) is encounted
    int a, b;
    while(scanf("%d -> %d", &a, &b) != EOF) {
        cout << "The edge is : " << b << " ---> " << a << endl;
    }
}

void inputMethod3() {
    //It will keep on reading a line (Enter-Key is end of one line but '\n' will not be added at the end of the string)
    //until EOF ("ctrl+z" in windows) is encounted
    string line;
    while(getline(cin, line)) {
        cout << "The line is : " << line << endl;
    }
}

int main() {
    //sprintf function
    char outputStr[50];
    sprintf(outputStr, "sum of %d and %d is = %d", 5, 10, 5+10);
    
    //sscanf function
    char inputStr[50] = "sum of 50 and 100 is 150";
    int a , b, sum;
    sscanf(inputStr, "sum of %d and %d is %d", &a, &b, &sum);

    //swap function
    vector<int> vtor = {50, 60};
    swap(vtor[0], vtor[1]);
    cout << vtor[0] << " " << vtor[1];

    //printf function
    printf("Two decimal digit : %.2f\n", 52.234243);
    
    //scanf function
    scanf("%d -> %d", &a, &b); //if input is "10 -> 20", then a will be 10 and b will be 20
}