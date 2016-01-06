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
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	ArrayUtil b=resize(a,10);
	assert(10==b.length);
	int num=4;
	int num1=0;
	assert(3==findIndex(b,&num));
	assert(4==findIndex(b,&num1));
	ArrayUtil c=resize(a,2);
	int num2=3,num3=2;
	assert(-1==findIndex(c,&num2));
	assert(1==findIndex(c,&num3));	
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
}

void test_dispose(){
	ArrayUtil a=create(4,5);
	assert(5==a.length);
	dispose(a);
}

void test_findFirst_isEven(){
	ArrayUtil a = create(4,5);
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	int num = 2;
	int * result = findFirst(a,&isEven,&num);
	assert(2==*result);
}

void test_findFirst_isDivisible(){
	ArrayUtil a = create(4,5);
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	int num = 3;
	int * result = findFirst(a,&isDivisible,&num);
	assert(3==*result);
}

void test_findLast_isEven(){
	ArrayUtil a = create(4,5);
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	((int *)a.base)[4]=5;

	int num = 2;
	int * result = findLast(a,&isEven,&num);
	assert(4==*result);
}

void test_findLast_isDivisible(){
	ArrayUtil a = create(4,5);
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	((int *)a.base)[4]=5;
	int num = 2;
	int * result = findLast(a,&isDivisible,&num);
	assert(4==*result);
}

void test_count_isEven(){
	ArrayUtil a = create(4,5);
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	((int *)a.base)[4]=5;
	int num = 2;
	int result = count(a,&isEven,&num);
	assert(2==result);
}

void test_count_isDivisible(){
	ArrayUtil a = create(4,5);
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	((int *)a.base)[4]=5;
	int num = 1;
	int result = count(a,&isDivisible,&num);
	assert(5==result);
}

void test_filter_isEven(){
	ArrayUtil a = create(4,5);
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	((int *)a.base)[4]=5;
	int num = 1,maxItem=5;
	int * destination[5];
	int result = filter(a,&isEven,&num,(void**)destination,maxItem);
	assert(result==2);
	assert(*(int*)destination[0]==2);
	assert(*(int*)destination[1]==4);
}

void test_filter_isDivisible(){
	ArrayUtil a = create(4,5);
	((int *)a.base)[0]=1;
	((int *)a.base)[1]=2;
	((int *)a.base)[2]=3;
	((int *)a.base)[3]=4;
	((int *)a.base)[4]=5;
	int num = 3,maxItem=5;
	int * destination[5];
	int result = filter(a,&isDivisible,&num,(void**)destination,maxItem);
	assert(result==1);
	assert(*(int*)destination[0]==3);
} 
	
int main(void){
	test_areEqual();
	test_resize();
	test_findIndex();
	test_dispose();
	test_findFirst_isEven();
	test_findFirst_isDivisible();
	test_findLast_isEven();
	test_findLast_isDivisible();
	test_count_isEven();
	test_count_isDivisible();
	test_filter_isEven();
	test_filter_isDivisible();
	return 0;
}