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

void explainList() {
    list<int> ls;

    ls.push_back(2);      // {2}
    ls.emplace_back(4);   // {2, 4}

    ls.push_front(5);     // {5, 2, 4}
    ls.emplace_front(10); // {10, 5, 2, 4}

    // Iterating
    for (auto it = ls.begin(); it != ls.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    // Other functions
    cout << "Size: " << ls.size() << endl;

    ls.pop_back();   // removes 4
    ls.pop_front();  // removes 10

    ls.clear();      // removes all elements

    cout << "Is empty? " << ls.empty() << endl;
}

void explainDeque() {

    deque<int> dq;

    dq.push_back(1);      // (1)
    dq.emplace_back(2);   // (1, 2)

    dq.push_front(4);     // (4, 1, 2)
    dq.emplace_front(3);  // (3, 4, 1, 2)

    dq.pop_back();        // (3, 4, 1)
    dq.pop_front();       // (4, 1)

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    // Iterate
    for (auto it = dq.begin(); it != dq.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
}


void explainStack() {

    stack<int> st;

    st.push(1);  // {1}
    st.push(2);  // {2, 1}
    st.push(3);  // {3, 2, 1}
    st.push(3);  // {3, 3, 2, 1}

    st.emplace(5); // {5, 3, 3, 2, 1}

    cout << st.top() << endl;   // 5

    st.pop();  // removes 5 -> {3, 3, 2, 1}

    cout << st.top() << endl;   // 3

    cout << st.size() << endl;  // 4

    cout << st.empty() << endl; // 0 (false)

    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue() {

    queue<int> q;

    q.push(1);     // {1}
    q.push(2);     // {1, 2}
    q.emplace(4);  // {1, 2, 4}

    q.back() += 5; // modify last element -> {1, 2, 9}

    cout << q.back() << endl;   // 9

    cout << q.front() << endl;  // 1

    q.pop();  // removes 1 -> {2, 9}

    cout << q.front() << endl;  // 2

    cout << q.size() << endl;   // 2
    cout << q.empty() << endl;  // 0 (false)
}


void explainPQ() {

    // -------------------------
    // Max Heap (Default)
    // -------------------------
    priority_queue<int> pq;

    pq.push(5);    // {5}
    pq.push(2);    // {5, 2}
    pq.push(8);    // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top() << endl;  // 10

    pq.pop();  // removes 10 -> {8, 5, 2}

    cout << pq.top() << endl;  // 8

    cout << pq.size() << endl;
    cout << pq.empty() << endl;

    // -------------------------
    // Min Heap
    // -------------------------
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(5);    // {5}
    pq2.push(2);    // {2, 5}
    pq2.push(8);    // {2, 5, 8}
    pq2.emplace(10); // {2, 5, 8, 10}

    cout << pq2.top() << endl;  // 2
}


void explainSet() {

    set<int> st;

    st.insert(1);   // {1}
    st.emplace(2);  // {1, 2}
    st.insert(2);   // duplicate ignored -> {1, 2}
    st.insert(4);   // {1, 2, 4}
    st.insert(3);   // {1, 2, 3, 4}

    // begin(), end(), rbegin(), rend()
    for (auto it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // find()
    auto it = st.find(3);   // points to 3
    auto it2 = st.find(6);  // returns st.end() (not found)

    // erase by value
    st.erase(4);  // removes 4 (log n time)

    // count()
    int cnt = st.count(1);  // returns 1 if present, else 0

    // erase by iterator
    auto it3 = st.find(2);
    st.erase(it3);  // constant time

    // erase range [first, last)
    auto it1 = st.find(1);
    auto it4 = st.find(3);
    st.erase(it1, it4); // removes elements from 1 up to (not including) 3

    // lower_bound & upper_bound
    auto lb = st.lower_bound(2);
    auto ub = st.upper_bound(3);

    cout << "Size: " << st.size() << endl;
    cout << "Empty? " << st.empty() << endl;
}


void explainMultiSet() {

    multiset<int> ms;

    ms.insert(1);   // {1}
    ms.insert(1);   // {1, 1}
    ms.insert(1);   // {1, 1, 1}

    // count occurrences
    int cnt = ms.count(1);   // 3

    // erase all 1's
    ms.erase(1);   // removes ALL 1's

    // Insert again
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    // erase only ONE occurrence
    ms.erase(ms.find(1));  // removes one 1

    // erase range (careful!)
    auto it1 = ms.find(1);
    auto it2 = next(it1, 2);  // move iterator forward by 2
    ms.erase(it1, it2);       // erase 2 elements

}

void explainUSet() { 
 unordered_set<int> st;
 // lower_bound and upper_bound function 
 // does not works, fest all functions are same 
 // as above, it does not stores in any // particular order it has a better complexity 
 // than set in most cases, except some when collision happens
}


void explainMap() {

    // 1️⃣ Normal map<int, int>
    map<int, int> mpp;

    mpp[1] = 2;              // {1 -> 2}
    mpp.emplace(3, 1);       // {1->2, 3->1}
    mpp.insert({2, 4});      // {1->2, 2->4, 3->1}

    // Iterate (sorted by key)
    for (auto it : mpp) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << "Value at key 1: " << mpp[1] << endl;

    // ⚠ If key doesn't exist, it creates it with value 0
    cout << "Value at key 5: " << mpp[5] << endl;

    cout << "After accessing key 5, size: " << mpp.size() << endl;
}

void explainMap1() {

    // Map stores key-value pairs
    // Keys are unique and stored in sorted order (ascending by default)
    map<int, int> mpp;

    // Different types of map declarations:

    // Key = int, Value = pair<int, int>
    map<int, pair<int, int>> mpp1;

    // Key = pair<int, int>, Value = int
    map<pair<int, int>, int> mpp2;

    // Inserting elements

    mpp[1] = 2;                 // key = 1, value = 2

    mpp.emplace(3, 1);          // inserts key = 3, value = 1

    mpp.insert({2, 4});         // inserts key = 2, value = 4

    mpp2[{2,3}] = 10;           // key = {2,3}, value = 10

    // Iterating through map
    // Elements will be printed in sorted order of keys
    for(auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }

    // Accessing elements

    cout << mpp[1] << endl;     // prints value of key 1 (which is 2)

    cout << mpp[5] << endl;     
    // If key 5 does not exist, it creates key 5 with value 0 (default for int)

    // Finding an element
    auto it = mpp.find(3);

    if(it != mpp.end()) {
        cout << it->second << endl;   // prints value of key 3
    }

    // Finding non-existing key
    auto it2 = mpp.find(5);

    if(it2 == mpp.end()) {
        cout << "Key 5 not found" << endl;
    }
}

void explainMultimap(){
    //everything same as map, only ut can store multiple keys 
    //only mpp[key]cannot be used here
}


void explainUnorderedMap(){
    //same as set and unordered_set difference.
}

bool comp(pair<int,int> p1, pair<int,int> p2) {
    // First priority: sort according to second element (ascending)
    if (p1.second < p2.second) {
        return true;
    }
    // If second elements are equal
    else if (p1.second == p2.second) {
        // Second priority: sort according to first element (descending)
        if (p1.first > p2.first) {
            return true;
        }
    }
   return false;
}

bool comp(pair<int,int> p1, pair<int,int> p2) {

    // Sort by second element (ascending)
    if(p1.second < p2.second) return true;

    // If second is same, sort by first (descending)
    if(p1.second == p2.second && p1.first > p2.first) return true;

    return false;
}

void explainExtra() {

    // -------- Sorting --------

    int a[] = {5, 2, 4, 1, 3};
    int n = 5;

    sort(a, a + n);               // Sort full array in ascending order

    vector<int> v = {5, 2, 4, 1, 3};
    sort(v.begin(), v.end());     // Sort vector in ascending order

    sort(a + 2, a + 4);           // Sort only index 2 to 3 (end index excluded)

    sort(a, a + n, greater<int>()); 
    // Sort in descending order


    // -------- Sorting array of pairs --------

    pair<int, int> p[] = {{1,2}, {2,1}, {4,1}};
    int m = 3;

    // Sort according to second element
    // If second is same → sort by first descending
    sort(p, p + m, comp);

    // After sorting:
    // (4,1), (2,1), (1,2)


    // -------- Built-in Functions --------

    int num = 7;  
    // 7 in binary = 111 → 3 set bits
    int cnt = __builtin_popcount(num);
    cout << cnt << endl;  // Output: 3

    long long num2 = 165786578687LL;
    int cnt2 = __builtin_popcountll(num2);
    cout << cnt2 << endl;


    // -------- All Permutations --------

    string s = "123";

    // Prints all permutations in lexicographical order
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
}

int main(){
//    explainPair();
//    explainVector();
//    explainList();
//    explainDeque();
//    explainStack();
//    explainQueue()
//    explainPQ();
//    explainSet();
//    explainMultiSet();
//    explainSet();
//    explainMap();
//    explainExtra
}

