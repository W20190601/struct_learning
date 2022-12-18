#include <stdio.h>
#include<stdlib.h>

typedef int E;

struct list{
    E *array;//指向顺序表的底层数组
    int capacity;//表示底层数组的容量
    int size;//表中的元素数量
};

typedef struct list *Arraylist;

//初始化函数
void Init_list(Arraylist list){
    list->array = malloc(sizeof(E) * list->capacity);
    if(list->array == NULL) return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}

//list 待操作的表 element 需要插入的元素 index 插入的位置 按位序进行计算
int insertlist(Arraylist list,E element,int index){
    if(index < 1 || index > list->size+1) return 0;
    if(list->size == list->capacity){
        int newCapacity = list->capacity + (list->capacity >> 1);
        E * newArray = realloc(list->array,newCapacity *sizeof(E));
        if(newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }
    for(int i = list->size;i > index - 1;++i){
        list->array = list->array[i - 1];
    }
    list->array[index  -1] = element;
    list->size++;
    return 1;
}

int main(){

    struct list list;//创建结构体变量
    if(Init_list(&list)){//初始化结构体，失败直接结束

    }else{
        printf("内存不足分配失败");
    }

    system("pause");
    return 0;
}