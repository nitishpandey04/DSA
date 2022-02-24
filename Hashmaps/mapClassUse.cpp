#include <iostream>
#include "OurMap.h"

using namespace std;

int main() {

    OurMap<int> si;

    cout << "load factors at 10 insertions:-\n";

    for (int i = 0 ; i < 10 ; i ++) {
        string s = "abc ";
        char c = (char)'0' + i;
        s += c;
        si.insert(s, i);
        cout << si.get_loadfactor() << "\n";
    }

    cout << "size of map = " << si.size() << "\n";

    si.print();

    cout << "load factors at two removals:-\n";
    si.remove("abc 3");
    cout << si.get_loadfactor() << "\n";
    si.remove("abc 7");
    cout << si.get_loadfactor() << "\n";

    cout << "size of map = " << si.size() << "\n";

    si.print();

    cout << "value of abc 8 = " << si.getValue("abc 8") << "\n";
}