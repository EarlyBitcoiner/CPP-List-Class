#include "List.h"

int main() {

	List<int> demo;

	demo.push_back(5);
	demo.push_front(4);
	demo.insert(7);

	cout << "toString() example : " << demo.toString() << endl;

	cout << "front() example : " << demo.front() << endl;

	cout << "back() example : " << demo.back() << endl;

	cout << "empty() example : " << demo.empty() << endl;

	cout << "getSize() example : " << demo.getSize() << endl;

	demo.insert(6, 3);

	cout << "List demo : " << demo.toString() << endl;

	List<int> demo2(demo); cout << "copy constructor called\n";
	
	demo2.remove(4); cout << "Removed int 4 from demo2\n";

	cout << "List demo2 : " << demo2.toString() << endl;

	demo = demo2; cout << "demo = demo2 called\n";

	cout << "List demo : " << demo.toString() << endl;

	List<int>::iterator it = demo.begin();

	demo.insert(it, 4);

	for (List<int>::iterator it = demo.begin();it != demo.end();++it) {

		cout << *it << endl;
	}
	
	return 0;
}