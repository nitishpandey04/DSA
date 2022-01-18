#include <bits/stdc++.h>

using namespace std;

#include "templates.cpp"

int main() {

    Pair<int, int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << "\n";

    Pair<int, double> p2;
    p2.setX(30);
    p2.setY(40.4);
    cout << p2.getX() << " " << p2.getY() << "\n";

    Pair<double, char> p3;
    p3.setX(50.5);
    p3.setY('x');
    cout << p3.getX() << " " << p3.getY() << "\n";

    Pair<Pair<int, int>, int> p4;
    p4.setX(p1);
    p4.setY(60);
    cout << p4.getX().getX() << " " << p4.getX().getY() << " " << p4.getY() << "\n";

    Pair<char, Pair<int, double>> p5;
    p5.setX('y');
    p5.setY(p2);
    cout << p5.getX() << " " << p5.getY().getX() << " " << p5.getY().getY() << "\n";

    Pair<int, Pair<double, char>> p6;
    p6.setX(70);
    p6.setY(p3);
    cout << p6.getX() << " " << p6.getY().getX() << " " << p6.getY().getY() << "\n";

    return 0;
}
