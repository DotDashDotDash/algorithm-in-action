--------------

## 目录

<!-- GMF-TOC -->

* [一、线性表](#一线性表)
  * [1.1线性表的合并问题](##1-1线性表的合并问题)
    * [Q1.两个递增单链表合并成递减单链表](####q1两个递增单链表合并成递减单链表)
    * [Q2.两个递增单链表合并成递增单链表](####q2两个递增单链表合并成递增单链表)
    * [Q3.一个递增单链表和一个递减单链表哦合并成一个递增单链表](####q3一个递增单链表和一个递减单链表哦合并成一个递增单链表)
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
    }
    //到这一步肯定有一个链表访问完了
    if(p)
    	q = p;	//两个链表长度不相等的时候，处理非空的那个链表
    while(q){
        tmp = q->next;
        q->next = la->next;
        la->next = q;
        q = tmp;
    }
    free(lb);
}
```

#### Q2.两个递增单链表合并成递增单链表

```cpp
//假设la和lb带头节点，采用的是尾插法，小的元素会被优先插入
void Merge_Asc(List* &la, List* &lb){
    List *tmp, *p = la->next, *q = lb->next;	//p和q分别为la和lb的工作指针
    la->next = NULL;	//最后的结果需要保存到la中，因此先把la清理出来
    List *tail = la;	//tail表示最后链表的尾节点所在位置
    while(p && q){
        if(p->data <= q->data){
            tmp = p->next;	//保存la的下一个工作指针的位置
            p->next = NULL;	//将p从原来的la中断开
            tail->next = p;	//直接把p连接到la的尾部
            tail = tail->next;	//同时更新tail
            p = tmp;		//la的工作指针继续后移
        }else{
            tmp = q->next;	//保存lb的下一个工作指针的位置
            q->next = NULL;	//将q从原来的lb的中断开
            tail->next = q;	//将q链接到la的我尾部
            tail = tail->next;	//更新tail
            q = tmp;		//lb的工作指针继续后移
        }
    }
    //到这一步肯定有一个链表访问完了
    if(p){	//如果la还没访问完
		tail->next = p;	//直接把剩余的原来的la连接到新的la尾部    
    }else{
        tail->next = q;	//同理如果lb没有访问完，链接剩下的lb到新的la尾部
    }
}
```

#### Q4.一个递增单链表和一个递减单链表哦合并成一个递增单链表

```cpp
//假设la和lb带头节点
void Merge_Diverse(List* &la, List* &lb){
    
}
```



