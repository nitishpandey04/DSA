#include <bits/stdc++.h>

using namespace std;

int main() {

    /* creating a 2d array on heap */

    int r, l;

    cin >> r >> l;

    int ** arr = new int * [r];

    // making the 2-d array

    for (int i = 0 ; i < r ; i ++) {

        arr[i] = new int [l];
    }

    // filling it

    for (int i = 0 ; i < r ; i ++) {

        for (int j = 0 ; j < l ; j ++) {

            cin >> arr[i][j];
        }
    }

    // printing it

    for (int i = 0 ; i < r ; i ++) {

        for (int j = 0 ; j < l ; j ++) {

            cout << arr[i][j] << ((j == l - 1) ? "\n" : " ");
        }
    }

    // deleting it

    for (int i = 0 ; i < r ; i ++) {

        delete [] arr[i];
    }

    delete [] arr;

    return 0;
}
