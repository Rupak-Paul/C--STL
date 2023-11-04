#include <bits/stdc++.h>
using namespace std;

//We need to check whether p1 p2 order is correct or not. If correct then return true otherwise false
bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first < p2.first) return true;
    else if(p1.first == p2.first && p1.second < p2.second) return true;
    else return false;
}

//If we use this function in binary_search as a comprator function then binary_search will only consider
//the first value. second value of the key, and all the pairs in pair array will be ignored.
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first < p2.first) return true;
    else return false;
}

void algorithm() {
    int arr[5] = {5, 3, 9, 1, 2};
    vector<int> v = {3, 5, 1, 2, 10};
    pair<int, int> pairArr[6] = {{1, 2}, {4, 5}, {3, 7}, {4, 11}, {7, 10}, {4, 9}};
    
    //max and min element
    int _max = *max_element(v.begin(), v.end());
    int _min = *min_element(v.begin(), v.end());
    int __max = max(10, 12);
    int ___max = max({10, 20, 30, 40});
    int __min = min(5, 3);


    //Reverse the vector
    reverse(v.begin(), v.end());


    //Sort in ascending (by default) or custom order (using comparator function)
    //Time complexity: O(nlogn)
    sort(arr, arr+5);
    sort(arr, arr+5, greater<int>()); //Sort in descending order
    sort(v.begin(), v.end());
    sort(pairArr, pairArr+6, compare); //We don't need to write custom comparator function for pair of primitive data types
    //Because <, >, <=, >= and == operator is already overloded in pair class, it works for primitve data types
    sort(pairArr, pairArr+6, greater<pair<int, int>>()); //Sorts the pair in descending order {7, 10}, {4, 11}, {4, 9}, ... 
    sort(v.begin(), v.begin()); //First 0 elements will be sorted
    sort(v.begin(), v.begin() + 3); //First 3 elements will be sorted


    //Binary search
    //Time complexity: O(logn)
    binary_search(v.begin(), v.end(), 2);
    binary_search(pairArr, pairArr+6, make_pair(4, 6), compare); //False
    binary_search(pairArr, pairArr+6, make_pair(1, 8), comp); //True
    binary_search(pairArr, pairArr+6, make_pair(2, 10), comp); //False
    

    //Returns pointer to the position of num if the container contains only one occurrence of num. 
    //Returns a pointer to the first position of num if the container contains multiple occurrences of num.
    //Returns pointer to the position of a number just higher than num, if the container does not contain an occurrence of num.
    //Subtracting the first position i.e vect.begin() from the pointer, returns the actual index.
    //Time complexity: O(logn)
    vector<int> arr1 = { 10, 15, 20, 20, 20, 25, 30, 35 };
    vector<int> arr2 = { 50, 40, 40, 40, 30, 20, 10, 5};
    cout << lower_bound(arr1.begin(), arr1.end(), 25) - arr1.begin() << endl; //prints 5
    cout << lower_bound(arr1.begin(), arr1.end(), 20) - arr1.begin() << endl; //prints 2
    cout << lower_bound(arr1.begin(), arr1.end(), 21) - arr1.begin() << endl; //prints 5
    lower_bound(arr2.begin(), arr2.end(), 40, greater<int>()) - arr2.begin(); //prints 1
    lower_bound(arr2.begin(), arr2.end(), 35, greater<int>()) - arr2.begin(); //prints 4


    //Returns an iterator pointing to the first element greater than __val, or end() if no elements are greater than __val.
    //Time complexity: O(logn)
    vector<int> arr2 = { 10, 15, 20, 20, 25, 30, 35 };
    cout << upper_bound(arr2.begin(), arr2.end(), 15) - arr2.begin() << endl; //prints 2
    cout << upper_bound(arr2.begin(), arr2.end(), 20) - arr2.begin() << endl; //prints 4
    cout << upper_bound(arr2.begin(), arr2.end(), 26) - arr2.begin() << endl; //prints 5


    //Returns no. of on bit (1) in the number
    int num = 7;
    long long num2 = 12;
    cout << __builtin_popcount(num) << endl; //prints 3
    cout << __builtin_popcountll(num2) << endl; //prints 2


    //Generates all the permutations
    vector<int> v = {1, 2, 3, 4};
    do {
        for(int e : v) cout << e << " ";
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));


    //abs funtion
    abs(-23); //23
    llabs(-432592160LL); //432592160
}

int main() {
    algorithm();
}