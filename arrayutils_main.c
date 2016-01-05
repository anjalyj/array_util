#include <stdio.h>
#include "arrayutils.h"
#include <assert.h>

void test_areEqual(){
	ArrayUtil a=create(4,5);
	ArrayUtil b=create(4,5);
	ArrayUtil c=create(1,5);
	assert(1==areEqual(a,b));
	assert(0==areEqual(b,c));
	 *(int *)(a.base)=12;
	assert(0==areEqual(a,b));


}

void test_resize(){
	ArrayUtil a=create(4,5);
	assert(5==a.length);
	ArrayUtil b=resize(a,10);
	assert(10==b.length);
}

int main(void){
	test_areEqual();
	test_resize();
	return 0;
}