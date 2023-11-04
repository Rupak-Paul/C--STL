#include <bits/stdc++.h>
using namespace std;

class Compare {
    //Comparison in ascending order. Builds max heap
    public: bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if(p1.first < p2.first) return true;
        else if(p1.first == p2.first && p1.second < p2.second) return true;
        else return false;
    }

    //Comparison in descending order. Builds min heap
    /*public: bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if(p1.first > p2.first) return true;
        else if(p1.first == p2.first && p1.second > p2.second) return true;
        else return false;
    }*/
};

void containers() {
    //Pair
    pair<int, int> p1 = {1, 2};
    pair<int, pair<int, int>> p2 = {1, {3, 5}};
    pair<int, int> p3[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << p1.first << p1.second;
    cout << p2.first << p2.second.first << p2.second.second;
    pair<int, int> p4 = {3, 2};
    pair<int, int> p5 = {3, 3}; //>, <, >=, <=, == operators are overloded in pair, it works for primitive data types
    if(p4 > p5) cout << "Greater"; //{3, 2} > {3, 3}: false  {3, 4} > {3, 2}: true  {3, 2} > {2, 5}: true
    if(p4 == p5) cout << "Equal"; //{3, 3} == {3, 3}: true  {3, 2} == {3, 1}: false


    //Vector: It is implementation of dynamic array
    //when space exhausted then a new array is created and all elements are copied
    vector<vector<int>> vv(5, vector<int>(6, INT_MAX)); //Create an 5x6 integer 2D-array and all the element will be intitilized to INT_MAX 
    vector<pair<int, int>> v;
    v.push_back({2, 3}); v.push_back({5, 7}); //Insert at at end
    v.front(); v.back(); //Returns a reference to the first and last element in the vector
    v.pop_back(); //Removes last element but nothing is returned 
    v.begin(); //Returns an iterator pointing to the first element in the vector
    v.end(); //Returns an iterator pointing to a location immediately next to the last element
    v.clear(); //Removes all elements from the vector, leaving the container with a size of 0.
    v.resize(15, {0, 0}); //resize the vector so that it contains 15 elements, the new cells will be initilized with the pair {0, 0}

    //Different way of accessing vector elements
    vector<int> v2 = {1, 5, 3, 7};
    for(int i = 0; i < v2.size(); i++) { //array like access
        cout << v2[i] << " ";
    }
    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++) { //access elements using iterator
        cout << *it << " ";
    }
    for(auto it = v2.begin(); it != v2.end(); it++) { //same as previous. Here use of auto keyword is shown
        cout << *it << " ";
    }
    for(auto e : v2) { //enhanced for loop
        cout << e << " ";
    }

    //Quickly checking 2 vectors are equal or not
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3};
    if(v1 == v2) cout << "Both vector are equal" << endl;
    else cout << "Both vector are not equal" << endl;


    //List: It is implementation of doubly linked list
    //All the operations are similar to vector
    list<int> l1;
    l1.push_back(2);
    l1.push_front(5);
    l1.pop_front();
    l1.pop_back();


    //Stack
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    cout << stk.top();
    stk.pop(); //Pop first element but no element is returned
    

    //Queue
    queue<int> qe;
    qe.push(10); //Add at the end of the queue
    qe.push(20);
    cout << qe.front(); //Returns front element
    cout << qe.back(); //Returns last element
    qe.pop(); //Delets first element of the queue




    //Priority queue: It is implementation of heap. By default it is max heap.
    //We can customize it accordingly by writing a custom comparator function
    int arr[] = {5, 9, 10, 12, 3}; int N = sizeof(arr) / sizeof(int);
    vector<pair<int, int>> vPair = {{2, 5}, {7, 5}, {7, 6}, {2, 7}, {5, 7}, {9, 5}, {10, 9}, {2, 5}};

    priority_queue<int> pq;
    for(int i = 0; i < N; i++) pq.push(arr[i]); //One by one insert takes O(nlogn) time to build the heap
    while(!pq.empty()) {
        cout << endl << pq.top();
        pq.pop();
    }

    priority_queue<int> pq1(arr, arr+N); //all the array element will be copied into the heap first. then builds the heap in O(n) time
    while(!pq1.empty()) {
        cout << endl << pq1.top();
        pq1.pop();
    }

    //Template parameters:
    //1st: The type of the stored elements
    //2nd: The type of the underlying container to use to store the elements (default vlaue: std::vector<T>)
    //3rd: comparator object (default value: std::less<typename Container::value_type>)
    priority_queue<int, vector<int>, greater<int>> pq2(arr, arr+N); //builds min heap in O(n) time
    while(!pq2.empty()) {
        cout << endl << pq2.top();
        pq2.pop();
    }

    //We will see the ordering from bottom to top. So, if i say that the order is ascending then it means 
    //that the smaller elements will be at the bottom and the higher elements will be at the top
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq3(vPair.begin(), vPair.end()); //Custom comparator
    while(!pq3.empty()) {
        cout << endl << pq3.top().first << " " << pq3.top().second;
        pq3.pop();
    }
}


int main() {
    containers();
}