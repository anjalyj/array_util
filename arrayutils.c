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
	// int* base1 = array1.base;
	// int* base2 = array2.base;

	// if( (array1.length != array2.length) || (array1.type_size != array2.type_size) ){
	// 	return 0;
	// };
	// for(int i=0;i<(array1.length)*array1.type_size;i++){
	// 	if(base1[i]!=base2[i]){
	// 		return 0;
	// 	}
	// };
	// return 1;
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