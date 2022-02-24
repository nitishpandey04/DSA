#include<vector>
#include<unordered_map>
#include<string>
#include<iostream>
#include<utility>

using namespace std;

int main() {

    unordered_map<string, int> ourmap;

    ourmap.insert({"abc", 1});
    ourmap["cdf"] = 2;
    ourmap.insert(pair<string, int>("ghi", 3));
    ourmap["jkl"] = 4;
    ourmap["mno"] = 5;
    ourmap["pqr"] = 6;

    unordered_map<string, int> :: iterator it1 = ourmap.begin();

    while (it1 != ourmap.end()) {
        cout << it1 -> first << " " << it1 -> second << "\n";
        it1 ++;
    }

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int> :: iterator it2 = v.begin();

    while (it2 != v.end()) {
        cout << *it2 << " ";
        it2 ++;
    }
    
    cout << "\n";

    // iterator functions

    cout << v.size() << "\n";

    v.erase(v.begin(), v.end());

    cout << v.size() << "\n";

    unordered_map<string, int> :: iterator it3 = ourmap.find("abc");

    cout << it3 -> first << " " << it3 -> second;
}
