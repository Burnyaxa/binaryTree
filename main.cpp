#include "tree.h"

void main(){
	srand(time(0));
	tree t;
	int result, quanity, diapason;
	cout << "How many elements to enter? "; cin >> quanity;
	cout << "Enter the random diapason : "; cin >> diapason;
	for (int i = 0; i < quanity; i++){
		t.add(rand() % diapason);
	}
	for (int i = 0; i < diapason; i++){
		if (t.find(i)) result = i;
	}
	cout << "Your tree : ";
	t.infix(t.top);
	cout << endl;
	cout << "The maximum element is : " << result << endl;
	system("pause");
}