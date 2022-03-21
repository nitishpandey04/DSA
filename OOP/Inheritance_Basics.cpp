#include <iostream>

using namespace std;

// Implementation of Inheritance

// Multiple Inheritance in C ++

// Order of Constructors and Destructors

class Parent1 {

    private:
    int pv;

    protected:
    int pt;

    public:
    int pb;

    Parent1() {

        cout << "Parent1 Default Constructor Called\n";
    }

    Parent1(int a, int b, int c) {

        pv = a;

        pt = b;

        pb = c;

        cout << "Parent1 Custom Constructor Called\n";
    }

    ~ Parent1() {

        cout << "Parent1 Destructor Called\n";
    }

    void print() {

        cout << "pv1 : " << pv << " pt1 : " << pt << " pb1 : " << pb << "\n";
    }
};

class Parent2 {

    private:
    int pv;

    protected:
    int pt;

    public:
    int pb;

    Parent2() {

        cout << "Parent2 Default Constructor Called\n";
    }
    
    Parent2(int a, int b, int c) {

        pv = a;

        pt = b;

        pb = c;

        cout << "Parent2 Custom Constructor Called\n";
    }

    ~ Parent2() {

        cout << "Parent2 Destructor Called\n";
    }

    void print() {

        cout << "pv2 : " << pv << " pt2 : " << pt << " pb2 : " << pb << "\n";
    }
};

class Child : public Parent1, public Parent2 {

    private:
    int pvc;

    protected:
    int ptc;

    public:
    int pbc;

    Child() {

        cout << "Child Default Constructor Called\n";
    }

    Child(int a, int b, int c) : Parent1(a + 1, b + 1, c + 1), Parent2(a + 2, b + 2, c + 2) {

        pvc = a;

        ptc = b;

        pbc = c;

        cout << "Child Custom Constructor Called\n";
    }

    ~ Child() {

        cout << "Child Destructor Called\n";
    }

    void print() {

        Parent1 :: print();

        Parent2 :: print();

        cout << "pvc : " << pvc << " ptc : " << ptc << " pbc : " << pbc << "\n";
    }
};

int main() {

    Child c(1, 2, 3);

    c.print();

    cout << c. Parent1 :: pb << "\n";

    return 0;
}
