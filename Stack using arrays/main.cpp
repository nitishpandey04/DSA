#include <bits/stdc++.h>

using namespace std;

#include "StackUsingArray.cpp"

int main() {

	Stack<int> s;
	
	int value = 0;
	cout << "inserting elements\n";

	// we can insert as many elements as we want
	// dynamic array is used to implement stack

	for (int i = 0 ; i < 10 ; i ++) {
		cout << i << " ";
		s.push(i);
	}

	cout << "\nremoving elements\n";
	
	while (!s.isEmpty()) {
		cout << s.pop() << " ";
	}

	cout << "\nAs shown above, stack follows the principle of LIFO\n";

	s.push(10);

	cout << s.size() << "\n";
	cout << s.top() << "\n";

	s.deallocate();
}
