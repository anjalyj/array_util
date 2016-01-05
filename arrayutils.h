typedef struct {
	void * base;
	int type_size;
	int length;
} ArrayUtil;

ArrayUtil create(int type_size,int length);

int areEqual(ArrayUtil a,ArrayUtil b);

ArrayUtil resize(ArrayUtil util, int length);

int findIndex(ArrayUtil util, void* element);
