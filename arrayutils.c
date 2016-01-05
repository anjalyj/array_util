#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayutils.h"

ArrayUtil create(int type_size,int length){
	ArrayUtil element;
	element.base = calloc(length,type_size);
	element.type_size = type_size;
	element.length = length;
	return element;
}

int areEqual(ArrayUtil array1,ArrayUtil array2){
	int length = array1.length > array2.length ? array1.length : array2.length;
	int checkValue = memcmp(array1.base,array2.base,length);
	if(checkValue == 0 && array1.length == array2.length && array1.type_size == array2.type_size)
		return 1;
	return 0;
}

ArrayUtil resize(ArrayUtil util, int length){
	util.base = realloc(util.base,length * util.type_size);
	util.length = length;
	return util;
}

int findIndex(ArrayUtil util, void *element){
	void *base = util.base; 
	for(int i=0;i<util.length;i++){
	 	if(memcmp(base,element,util.type_size)==0){
			return i;
		}
	 	base+=util.type_size;
	}
	return -1;

}
