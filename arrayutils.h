typedef struct {
	void * base;
	int type_size;
	int length;
} ArrayUtil;

ArrayUtil create(int type_size,int length);

int areEqual(ArrayUtil a,ArrayUtil b);

ArrayUtil resize(ArrayUtil util, int length);

int findIndex(ArrayUtil util, void* element);

void dispose(ArrayUtil util);

typedef int MatchFunc (void *, void *);

int isEven(void* hint, void* item);

int isDivisible(void* hint, void* item);

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);

void* findLast(ArrayUtil util, MatchFunc* match, void* hint);

int count(ArrayUtil util, MatchFunc* match, void* hint);

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );

typedef void ConvertFunc (void *, void *,void *);

void increment(void* hint, void* sourceItem, void* destinationItem);

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);

void times(void* hint, void* item);

typedef void OperationFunc( void* , void*);

void forEach(ArrayUtil util, OperationFunc* operation, void* hint);

typedef void* ReducerFunc( void* , void*, void*);

void *sum(void* hint, void* previousItem, void* item);

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* initialValue);





