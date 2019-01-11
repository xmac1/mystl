#include <iostream>
#include "slice.h"

using namespace std;

int main(int argc, char* argv[])
{	
	slice<int> s(2, 2);
	cout << "slice length: " << s.len() << endl
		<< "slice cap: " << s.cap() << endl;
}
