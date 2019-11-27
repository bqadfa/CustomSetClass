#include "Set.h"
#include <iostream>
#include <vector>

using namespace std;

void main()
{
	vector<int> v1 = { 1, 3, 5, 7, 9, 11, 13 },
		v2 = { 1, 4, 3, 6, 8, 11, 17, 23, 13 };

	Set<int> s1(v1), s2(v1), s3, s4(v2);

	s2.push_element(-15);
	s1.push_element(15);
	s3 = s1 + s2;
	cout << "s1:\n";
	s1.show_set();
	cout << "s2:\n";
	s2.show_set();
	cout << "s3 = s1 + s2:\n";
	s3.show_set();
	cout << "s4:\n";
	s4.show_set();
	cout << "-------------------Crossing s1 and s4:-------------------\n";
	s1.crossing_elements(s4);


	system("pause");
}