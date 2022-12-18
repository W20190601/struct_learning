#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode{
    E element;  //保存当前元素
    struct ListNode * next;  //指向下一个节点
};


typedef struct ListNode * Node;
 
//初始化函数 头结点默认下一个为NULL
void InitList(Node node){
    node->next = NULL;
}
 
//head 头结点  element 插入的元素 index 插入的位置
bool InsertList(Node head,E element,int index){
    if(index < 1) return 0;  //插入的位置小于1时返回0

    while(--index){
        head = head->next; //位移结点
        if(head == NULL) return 0; 
    }

    Node node = malloc(sizeof(struct ListNode)); //扩容一个相同大小的结点
    if (node == NULL) return 0;

    node->element = element;  //将元素保存到新的节点中
    node->next = head->next;  //新插入的节点指向原本位置上的节点
    head->next = node;  //前驱结点指向新的结点
    return 1;
}

//删除结点 head 头结点 index 删除结点的位序
bool Deleatlist(Node head,int index){
    if(index < 1) return 0;
    //head = head->next;
    while(--index){
        if(head == NULL) return 0;
        head = head->next;
    }
    if(head->next == NULL) return 0;  //删除的结点为空时返回0
    Node temp = head->next;  //创建一个临时变量存放需要删除的节点
    head->next = head->next->next;  //前驱节点链接到下下个节点
    free(temp);  //删除不需要的节点
    return 1;
}

//index 查询的下标
E * getlist(Node head,int index){
    if(index < 1) return 0;
    do{
        head = head->next;
        if(head == NULL) return 0;
    } while (--index);
    return head->element;    
}

//查找元素位置
int findList(Node head,E element){
    head = head->next;
    int i = 1;
    while(head){
        if(head->element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}

//查询链表个数
int SizeList(Node head){
    int i = 0;
    while(head->next){
        head = head->next;
        i++;
    }
    return i;
}

//打印链表
void Printflist(Node head){
    while(head->next){
        head = head->next;
        printf("%d\n",head->element);
    }
}

int main(){
    struct ListNode * head;  //定义头结点
    InitList(head);

    for (int i = 1; i <= 3; ++i){
        InsertList(head,i*100,1);
    }
    Deleatlist(head,3);
    InsertList(head,99,2);
    Printflist(head);
    printf("%d",SizeList(head));
    system("pause");
    return 0;
}