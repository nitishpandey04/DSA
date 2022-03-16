#include <iostream>
#include "TrieClass.h"

using namespace std;

int main() {

    Trie t;

    t.insert("a");
    t.insert("as");
    t.insert("an");
    t.insert("ans");
    t.insert("and");

    t.insert("note");
    t.insert("not");
    t.insert("no");

    if (t.exists("and")) cout << "and exists\n";
    else cout << "and does not exists\n";

    t.remove("and");

    if (t.exists("and")) cout << "and exists\n";
    else cout << "and does not exists\n";

    return 0;
}