#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
	p = new int*[n + 1];
	for(int i = 0; i <= n; i++){
		p[i] = new int[1];
		p[i][0] = 0; // size
	}
}

void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
	int size = p[x][0];
	int *newArr = new int[size + 2];
	newArr[0] = size + 1;
	for(int i = 1; i <= size; i++){
		newArr[i] = p[x][i];
	}
	newArr[size + 1] = y;
	delete[] p[x];
	p[x] = newArr;
}

int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
	return p[x][k];
}

void Clear(int **&p,int n){//回收空间
	for(int i = 0; i <= n; i++){
		delete[] p[i];
	}
	delete[] p;
}
