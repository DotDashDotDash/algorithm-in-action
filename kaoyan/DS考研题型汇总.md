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
//假设la和lb带头节点
void Merge_Desc(List* &la, List* &lb){
    List *p = la->next, *q = lb->next;	//p,q分别为链表la和lb的工作指针
    la->next = null;	//la作结果链表，先将结果链表初始化为空
    while(p && q){		//两个链表均不为空指针
        if(p->data <= q->data){
            List *tmp = p->next;
            p->next = la->next;
            la->next = tmp;
            p = tmp;
        }else{
            if(p)
                q = p;
            while(q){
                List *tmp = q->next;
                q->next = la->next;
                la->next = q;
                q = tmp;
            }
        }
    }
}
```



