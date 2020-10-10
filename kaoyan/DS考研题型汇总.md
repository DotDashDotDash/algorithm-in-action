--------------

## 目录

<!-- GMF-TOC -->

* [一、线性表](#一线性表)
  * [1.1线性表的合并问题](##1-1线性表的合并问题)
    * [Q1.两个递增单链表合并成递减单链表](####q1两个递增单链表合并成递减单链表)
  * [1.2线性表的集合类操作问题](##1-2线性表的集合类操作问题)
  * [1.3线性表的排序问题](##1-3线性表的排序问题)
  * [1.4线性表的重复值问题](##1-4线性表的重复值问题)

<!-- GFM-TOC -->



# 一、线性表

## 1.1线性表的合并问题

#### Q1.两个递增单链表合并成递减单链表

```cpp
//假设la和lb带头节点，因为是采用头插法，因此小的元素会被优先插入
void Merge_Desc(List* &la, List* &lb){
    List *tmp, *p = la->next, *q = lb->next;	//p和q分别为la和lb的工作指针
    la->next = NULL;	//最后的结果需要保存到la中，因此先把la清理出来
    while(p && q){
        if(p->data <= q->data){
            tmp = p->next;	//tmp暂存p的后继指针
            p->next = la->next;	
            la->next = p;	//头插法插入小节点
            p = tmp;		//la的工作指针继续后移
        }else{
            tmp = q->next;	//tmp暂存q的后继指针
            q->next = la->next;
            la->next = q;	//头插法插入b的节点
            q = tmp;		//lb的工作指针q继续后移
        }
        if(p)
            q = p;	//两个链表长度不相等的时候，处理非空的那个链表
        while(q){
            tmp = q->next;
            q->next = la->next;
            la->next = q;
            q = tmp;
        }
    }
    free(lb);
}
```



