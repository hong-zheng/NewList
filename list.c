#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x){
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// 单链表打印
void SListPrint(SListNode* plist){
	if (NULL == plist || plist->next == NULL){
		printf("链表为空或者该链表不存在\n");
		return;
	}
	SListNode* cur = plist->next;
	while (cur){
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x){
	if (NULL == pplist || NULL == *pplist){
		return;
	}
	SListNode* newnode = BuySListNode(x);
	SListNode* cur = *pplist;
	SListNode* prev = *pplist;;
	while (cur){
		prev = cur;
		cur = cur->next;
	}
	prev->next = newnode;
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x){
	if (NULL == pplist || NULL == *pplist){
		return;
	}
	SListNode* newH = *pplist;
	SListNode* newnode = BuySListNode(x);
	newnode->next = newH->next;
	newH->next = newnode;
	//*pplist = newH;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist){
	if (NULL == pplist || NULL == *pplist){
		return;
	}
	SListNode* prev = *pplist;
	SListNode* cur = *pplist;
	while (cur && cur->next){
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
}
// 单链表头删
void SListPopFront(SListNode** pplist){
	if (NULL == pplist || NULL == *pplist){
		return;
	}
	(*pplist)->next = (*pplist)->next->next;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x){
	if (NULL == plist){
		return NULL;
	}
	SListNode* cur = plist->next;
	while (cur){
		if (cur->data == x){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x){
	if (pos == NULL){
		return;
	}
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos){
	if (NULL == pos){
		return;
	}
	pos->next = pos->next->next;
}
// 单链表的销毁
void SListDestory(SListNode* plist){
	// 先保存头结点，最后销毁头结点
	SListNode* prev = plist;
	SListNode* cur = plist;
	while (cur){
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	plist = NULL;
	printf("销毁链表完成\n");
}
void test1(){
	SListNode* sln=BuySListNode(0);
	SListPushBack(&sln, 1);
	SListPushBack(&sln, 2);
	SListPushBack(&sln, 3);
	SListPushBack(&sln, 4);
	SListPushBack(&sln, 5);
	SListPrint(sln);
	SListPushFront(&sln, 6);
	SListPrint(sln);
	SListPushFront(&sln, 7);
	SListPrint(sln);
	SListPushFront(&sln, 8);
	SListPrint(sln);
	SListPushFront(&sln, 9);
	SListPrint(sln);
	SListPopBack(&sln);
	SListPrint(sln);
	SListPopBack(&sln);
	SListPrint(sln);
	SListPopBack(&sln);
	SListPrint(sln);
	SListPopFront(&sln);
	SListPrint(sln);
	SListPopFront(&sln);
	SListPrint(sln);
	SListNode* node = SListFind(sln, 1);
	printf("%d \n",node->data);
	SListInsertAfter(sln->next->next,23);
	SListPrint(sln);
	SListEraseAfter(sln->next);
	SListPrint(sln);
	SListEraseAfter(sln->next);
	SListPrint(sln);
	SListDestory(sln);
}
int main(){
	test1();
	system("pause");
	return 0;
}