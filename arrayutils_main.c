#include <stdio.h>
#include "arrayutils.h"
#include <assert.h>



int main(void){
	int *ptr;
	ArrayUtil a=create(4,5);
	// ptr = (int *)a.base;
	ArrayUtil b=create(4,5);
		// *(int *)(a.base)=12;
	int ans=areEqual(a,b);
	printf("%d",ans);
	// *ptr=11;
	return 0;
}