#include <bits/stdc++.h>
using namespace std;

class Compare {
    //Comparison in ascending order. Inorder traversal of the BBST will print elements in ascending order
    /*public: bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if(p1.first < p2.first) return true;
        else if(p1.first == p2.first && p1.second < p2.second) return true;
        else return false;
    }*/

    //Comparison in descending order. Inorder traversal of the BBST will print elements in descending order
    public: bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if(p1.first > p2.first) return true;
        else if(p1.first == p2.first && p1.second > p2.second) return true;
        else return false;
    }
};

void containers() {
    pair<int, int> pairArr[] = {{2, 3}, {5, 9}, {3, 7}, {8, 3}, {3, 5}, {2, 3}, {2, 5}};
    int N = sizeof(pairArr) / sizeof(pair<int, int>);


    //Set: Set is a implementation of balanced binary search tree (Red-Black Tree)
    //Set does not store duplicate elements
    set<int> s1; 
    s1.insert(5);
    s1.find(5); //Returns pointer to the element if the element is present otherwiser return s1.end()
    s1.erase(5);
    s1.count(5); //Returns 1 if the element is present in the set otherwise returns 0   
    
    //It is similar to the lowerbound function described in STL_algorithm
    //if the set is {2, 5, 7, 9, 10}, then lower_bound(5) will return pointer to 5 in the set. If 5 is not present then returns s1.end()
    //Time complexity: O(logn)
    s1.lower_bound(5);

    //It is similar to the upperbound function described in STL_algorithm
    //If the set is {2, 5, 7, 9, 10}, then upper_bound(5) will return pointer to 7 in the set. If all elemnet is <= 5 then returns s1.end()
    //Time complexity: O(logn)
    s1.upper_bound(5);

    //This will create balanced BST such that if we do inorder traversal then elements will be printed in descending order
    set<int, greater<int>> s2;

    set<pair<int, int>, Compare> s3(pairArr, pairArr+N);
    for(auto p : s3) cout << p.first << " " << p.second << endl;



    //Multiset: it is similar to set. The only difference is that it can store duplicate values
    //Internally when an existing value is inserted, the data structure increases its count which is associated with each value.
    multiset<int> ms;
    ms.insert(10); ms.insert(10); ms.insert(10); ms.insert(15); //{10, 10, 10, 15}
    ms.count(10); //Returns 3
    ms.find(10); //Returs pointer to the element if the element is present in set otherwise returns ms.end()
    ms.erase(ms.find(10)); //It will remove only one instance of 10 from the set. {10, 10, 15}
    ms.erase(10); //It will remove all instance of 10 from the set. {15}
    


    //Unorderedset: It is similar to set but implemented using hash table. Duplicate elements are not stored
    unordered_set<int> us;
    us.insert(5);
    us.erase(5);
    if(us.find(5) != us.end()) cout << "Found" << endl; else cout << "Not found" << endl;



    //Unordered_multiset: It is similar to multiset but implemented using hash table. It can store duplicate values
    //Internally when an existing value is inserted, the data structure increases its count which is associated with each value.
    unordered_multiset<int> ums;



    //Map: It is a balanced BST on key. Every node in the BBST has a field "value" associated with them
    //Map does not store duplicate key.
    map<int, pair<int, int>> mp;
    mp.insert({5, {2, 5}}); //Takes a pair {key, value}. If key is already present then no change will happen in the map. mp: { (5, {2, 5}) }
    mp[5] = {2, 7}; //value in the key 5 will be changed from {2, 5} to {2, 7}. mp: { (5, {2, 7}) }
    mp.insert({5, {2, 8}}); //Duplicate key. So no change will happen. mp: { (5, {2, 7}) }
    mp[5] = {2, 9}; //value in the key 5 will be changed from {2, 7} to {2, 9}. mp: { (5, {2, 9}) }
    cout << endl; for(auto p : mp) cout << p.first << " " << p.second.first << " " << p.second.second << endl;
    
    if(mp.find(2) != mp.end()) cout << "Found\n"; else cout << "Not found\n";
    mp.erase(2); //Removes {2, {4, 5}} from the map
    mp.count(5); //Returns 1 if the key 5 is present in the map otherwise returns 0
    mp.lower_bound(5);  //Similar to set
    mp.upper_bound(5); //Similar to set

    map<pair<int, int>, int, Compare> mp2;
    mp2.insert({{2, 3}, 5});
    mp2[{3, 5}] = 8;
    mp2[{2, 5}] = 7;
    mp2[{2, 3}] = 6;
    mp2[{3, 8}] = 11;
    mp2[{7, 2}] = 9;
    cout << endl; for(auto p : mp2) cout << p.first.first << " " << p.first.second << "  " << p.second << endl;



    //Multimap: Similar to map, the only difference is that it can store duplicate values
    //Internally when an existing value is inserted, the data structure increases its count which is associated with each value.
    multimap<string, int> mmp;
    mmp.insert({"abc", 3}); //{(abc, 3)}
    mmp.insert({"abc", 6}); //{(abc, 3), {abc, 6}}
    mmp.insert({"abc", 3}); //{(abc, 3), {abc, 6}, {abc, 3}}
    mmp.insert({"aab", 4}); //{(aab, 4), {abc, 3}, {abc, 6}, {abc, 3}}
    mmp.erase(mmp.find("abc")); //Removes only one instance of "abc". {(aab, 4), {abc, 6}, {abc, 3}}
    mmp.erase("abc"); //Removes all instance of "abc". {(aab, 4)}



    //unordered_map: It is similar to map but implemented using hash table. Duplicate elements are not stored
    unordered_map<string, int> ump;
    ump["A"] = 65;
    ump["B"] = 66;
    ump["C"] = 67;
    cout << endl << ump["A"] << endl; //Prints 67
    auto ptr = ump.find("G");
    if(ptr != ump.end()) cout << ptr->second; else cout << "Not found" << endl;



    //unordered_multimap: Similar to multimap but it is implemented using hash table. It can store duplicate value.
    //Internally when an existing value is inserted, the data structure increases its count which is associated with each value.
    unordered_multimap<string, int> ummp;

}

int main() {
    containers();
}