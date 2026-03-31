#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
	p = new int*[n + 1];
	for(int i = 0; i <= n; i++){
		p[i] = nullptr;
	}
}

void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
	// Array structure: [size, capacity, element1, element2, ...]
	if(p[x] == nullptr){
		// Initialize with capacity 4
		int *arr = new int[6]; // 2 (metadata) + 4 (capacity)
		arr[0] = 1;  // size
		arr[1] = 4;  // capacity
		arr[2] = y;  // first element
		p[x] = arr;
	} else {
		int size = p[x][0];
		int capacity = p[x][1];
		if(size < capacity){
			// Still have space
			p[x][size + 2] = y;
			p[x][0] = size + 1;
		} else {
			// Need to expand
			int newCapacity = capacity * 2;
			int *newArr = new int[newCapacity + 2];
			newArr[0] = size + 1;
			newArr[1] = newCapacity;
			for(int i = 0; i < size; i++){
				newArr[i + 2] = p[x][i + 2];
			}
			newArr[size + 2] = y;
			delete[] p[x];
			p[x] = newArr;
		}
	}
}

int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
	return p[x][k + 1];
}

void Clear(int **&p,int n){//回收空间
	for(int i = 1; i <= n; i++){
		if(p[i] != nullptr){
			delete[] p[i];
		}
	}
	delete[] p;
}
