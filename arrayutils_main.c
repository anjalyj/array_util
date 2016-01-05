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

void test_findIndex(){
	ArrayUtil a=create(1,5);
	ArrayUtil b=create(4,5);
	((char *)a.base)[0]='a';
	((char *)a.base)[1]='b';
	((char *)a.base)[2]='c';
	((char *)a.base)[3]='d';
	char num='c';
	assert(2==findIndex(a,&num));
	((int *)b.base)[0]=1;
	((int *)b.base)[1]=2;
	((int *)b.base)[2]=3;
	((int *)b.base)[3]=4;
	int num1=2;
	assert(1==findIndex(b,&num1));
	int num2=10;
	assert(-1==findIndex(b,&num2));




	 // int *val=&num;
	// printf("%d\n",index);
}

int main(void){
	test_areEqual();
	test_resize();
	test_findIndex();
	return 0;
}