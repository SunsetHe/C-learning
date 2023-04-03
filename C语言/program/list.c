/*顺序表*/

#include <stdio.h>
#include <stdlib.h>

struct List{
    int * array;
    int capacity;//最大元素个数
    int size;//元素数量
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

_Bool insertList(struct List * list,int element,int index){

    if (index < 1 || index > list->size + 1){
        printf("insert failed\n");
        return 0;
    }

    for (int i = list->size;i >= index;i--){
        list->array[i] = list->array[i-1];
    }
    list->array[index-1] = element;
    list->size++;
    return 1;
}/*对顺序表进行插入一个元素的操作*/

void printList(struct List  * list){
    for (int i = 0; i < list->size; ++i) {
        printf("%d ",list->array[i]);
    }
    printf("    %d/%d",list->size,list->capacity);
    printf("\n");
}//打印顺序表

_Bool addList(struct List * list,int addCapacity){
    int newCapacity = list->capacity + addCapacity;
    int * NewArray = realloc(list->array, sizeof(int) * newCapacity);
    if(NewArray == NULL){
        printf("扩充列表失败\n");
        return 0;
    }
    list->array = NewArray;
    list->capacity = newCapacity;
    printf("扩充列表成功\n");
    return 1;
}//扩充列表长度

void deleteList(struct List * list,int index){
    if(index < 1 || index > list->size){
        printf("delete failed");
        return;
    }

    for (int i = index; i < (list->size - 1); i++) {
        list->array[i-1] = list->array[i];
    }
    list->size--;
    printf("delete succeeded\n");
}//删除列表元素

int * getList(struct List * list,int index){
    if(index <= list->size && index > 0){
        return &(list->array[index]);
    }
    return NULL;
}//获取列表指定序号的元素的地址

int findList(struct List * list,int element){
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) {
            return i;
        }
    }
    return -1;
}//寻找某个元素，并返回序号

int main(){
    struct List list;
    if(initList(&list)){
        insertList(&list,996,1);
        printList(&list);
        insertList(&list,2023,1);
        printList(&list);
        insertList(&list,7436,2);
        printList(&list);
        deleteList(&list,2);
        printList(&list);
    } else{
        printf("failed");
    }
    return 0;
}