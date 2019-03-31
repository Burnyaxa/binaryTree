#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <algorithm>
#include <list>
#include "Header.h"


int main()
{
	srand(time(0));
	tree t;
	int result, quanity, diapason;
	cout << "How many elements to enter? "; cin >> quanity;
	cout << "Enter the random diapason : "; cin >> diapason;
	for (int i = 0; i < quanity; i++) {
		t.add(rand() % diapason);
	}
	
	cout << "Your tree : ";
	t.prt(t.top);

	system("pause");
	return 0;
}