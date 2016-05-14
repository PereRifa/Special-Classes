
#include "Vector.h"
#include <stdio.h>

int main()
{
	{
		int i;
		bool t;
	
		mVector<int> a(20);
		mVector<int> b(a);

		b.push_back(5);
		b.push_front(7);
		
		b.pop_back();
		i = b[0];
		b[0] = 10;
		i = b[0];
		b.pop_front();
		i = a.size();
		i = b.size();
		a.push_back(0);
		b.push_front(5);
		i = a.nelements();
		i = b.nelements();
		t = a.empty();
		b.pop_back();
		t = b.empty();
		b.clean();
		a.clean();
		
		getchar();
		
	}
	
	return 0;
}