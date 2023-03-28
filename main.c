/*顺序表*/

#include <stdio.h>
#include <stdlib.h>

struct List{
    int * array;
    int capacity;
    int size;
};/*顺序表结构*/

_Bool initList(struct List * list){
    list->array = malloc(sizeof(int)*10);
    if (list->array == NULL)
    {
        return 0;
    }

    list->capacity = 10;
    list->size = 0;
    return 1;
}/*初始化（生成）一个初始顺序表*/

void insertList(struct List * list,int element,int index){
    for (int i = list->size;i >= index;i--){
        list->array[i] = list->array[i-1];
    }
    list->array[index-1] = element;
    list->size++;
}/*对顺序表进行插入一个元素的操作*/

void printList(struct List  * list){
    for (int i = 0; i < list->size; ++i) {
        printf("%d ",list->array[i]);
    }
    printf("\n");
}//打印顺序表

int main(){
    struct List list;
    if(initList(&list)){
        insertList(&list,996,1);
        printList(&list);
        insertList(&list,2023,1);
        printList(&list);
        insertList(&list,7436,2);
        printList(&list);
    } else{
        printf("failed");
    }
    return 0;
}