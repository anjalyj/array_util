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
	void *base;
	int smallestLength = (length <= util.length?length:util.length)*util.type_size;
	int newlength = length;
	length = (length >= util.length) ? length : util.length;
	base = calloc(length,util.type_size);
	memcpy(base,util.base,smallestLength);
	util.base=base;
	util.length = newlength;
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

void dispose(ArrayUtil util){
	util.length =0;
	util.type_size=0;
	util.base =0;
	free(util.base);	
}

int isEven(void* hint, void* item){
	return (*(int *)item %2 == 0);
}

int isDivisible(void* hint, void* item){
	int num = *(int *)item;
	int  diviser = *(int *)hint;
	return num % diviser == 0;
}

void increment(void* hint, void* sourceItem, void* destinationItem){
	*(int *)destinationItem = *(int *)sourceItem + *(int *)hint;
}

void square(void* hint,void* sourceItem, void* destinationItem){
	int square = (*(int *)sourceItem) * (*(int *)sourceItem);
	*(int *)destinationItem = square; 
}

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	void *base = util.base;
	for(int i=0; i<util.length; i++){
		if(match(hint,base)==1)
			return base;
		base+=util.type_size;
	}
	return NULL;
}

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	void *base = util.base+(util.length-1)*util.type_size;
	for(int i=0; i<util.length; i++){
		if(match(hint,base)==1)
			return base;
		base-=util.type_size;
	}
	return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int count=0;
	void *base = util.base;
	for(int i=0; i<util.length; i++){
		if(match(hint,base)==1)
			count++;
		base+=util.type_size;
	}
	return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int count=0;
	void *base=util.base;
	for(int i=0;(i<util.length && count<maxItems);i++){
		if(match(hint,base)==1){
			destination[count]=base;
			++count;
		}
		base+=util.type_size;
	}
	return count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	void *base=source.base;
	void *base1=destination.base;
	for(int i=0; i<source.length;i++){
		convert(hint,base,base1);
		base+=source.type_size;
		base1+=destination.type_size;
	}
}


