#include<bits/stdc++.h>
using namespace std;

// Pairs
void explainPair() {
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.second << " " << p2.second.first << endl;

    pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1} };
    cout << arr[1].second << endl;
}


//Vector,Iterator
void explainVector() {

    // Empty vector
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    // Vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    // Vector with 5 elements, each 100
    vector<int> v3(5, 100);

    // Vector with 5 elements, default value 0
    vector<int> v4(5);

    // Copying a vector
    vector<int> v1(5, 20);
    vector<int> v2(v1);

    // vector<int> v = {10, 20, 30, 40, 50};

    // Begin iterator
    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it) << " ";   // 20

    it = it + 2;
    cout << *(it) << " ";   // 40

    // End iterator
    vector<int>::iterator it2 = v.end();   // points AFTER last element

    // Reverse iterators
    vector<int>::reverse_iterator rit = v.rbegin();
    cout << *rit << " ";   // 50

    // Access methods
    cout << v[0] << " " << v.at(0) << " ";
    cout << v.back() << " ";

    cout << endl;

    // Normal iterator loop
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    // Auto iterator loop
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    // Range based loop (Best way)
    for (auto val : v) {
        cout << val << " ";
    }

    // Erase single element
    v.erase(v.begin() + 1);  
    // Now: (10, 12, 23)

    // Add 35 to demonstrate range erase
    v.push_back(35);
    // (10, 12, 23, 35)

    // Erase range [start, end)
    v.erase(v.begin() + 1, v.begin() + 3);
    // Removes 12, 23
    // Now: (10, 35)

    // Insert function
    vector<int> v2(2, 100); 
    // (100, 100)

    v2.insert(v2.begin(), 300);  
    // (300, 100, 100)

    v2.insert(v2.begin() + 1, 2, 10);  
    // (300, 10, 10, 100, 100)

    vector<int> copy(2, 50); 
    // (50, 50)

    v2.insert(v2.begin(), copy.begin(), copy.end());
    // (50, 50, 300, 10, 10, 100, 100)

    cout << "Size: " << v2.size() << endl;

    v2.pop_back(); 
    // Removes last element

    // Swap example
    vector<int> v1 = {10, 20};
    vector<int> v3 = {30, 40};

    v1.swap(v3);
    // v1 = (30, 40)
    // v3 = (10, 20)

    // Clear vector
    v.clear();

    cout << "Is v empty? " << v.empty() << endl;
}

int main(){
//    explainPair();
   explainVector();
}

