#include <bits/stdc++.h>

using namespace std;

#include "StackUsingLL.cpp"

int main() {

	Stack<int> s;

	cout << "inserting elements\n";

	// we can insert as many elements as we want
	// linked list is used to implement stack

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

	cout << s.getSize() << "\n";
	cout << s.top() << "\n";

	s.deallocate();
}
