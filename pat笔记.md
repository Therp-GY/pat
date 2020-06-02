# 链表

## 链表

- bug1

  head建立时没有malloc，即head指针指向一个空的值，那么head->i就会内存错误

  同时，insert又将一个新的表项插在head前面，此时整个链表混乱

  **修改前**

  ```c
  	List head;
  	head->i = 1;
  	head->next = NULL;
  	for(int i = 1; i<=n; i++){
  		insert(head, i,i);
  	}
  ```

  **修改后**

  ```c
  	List head = (List)malloc(sizeof(node));
  	head->i = 1;
  	head->next = NULL;
  	for(int i = 2; i<=n; i++){
  		insert(head, i,i);
  	}
  ```

## 链表实现队列

![1590824389529](C:\Users\GY\AppData\Roaming\Typora\typora-user-images\1590824389529.png)

- bug1

  malloc会将struct内部的指针也赋值，因此内部指针部位NULL，应该主动给它们赋值为NULL

  ```
  typedef struct node{
  	int element;
  	struct node* next;	
  }node;
  
  typedef node* ptrNode;
  typedef struct qnode{
  	ptrNode front;
  	ptrNode reer;
  }qnode;
  
  typedef qnode* ptrQnode; 
  int main(){
  	ptrQnode ptrQ = (ptrQnode)malloc(sizeof(qnode));
  	//	bug修改
  	ptrQ->front = NULL;
  	ptrQ->reer = NULL;
  	//	bug修改
  	....
  	}
  ```

# 树

![1590829138753](C:\Users\GY\AppData\Roaming\Typora\typora-user-images\1590829138753.png)

![1590829207551](C:\Users\GY\AppData\Roaming\Typora\typora-user-images\1590829207551.png)

**一般树都可表示为二叉树**（儿子兄弟表示法）

![1590829599615](C:\Users\GY\AppData\Roaming\Typora\typora-user-images\1590829599615.png)

## 数组存储

![1590830023430](C:\Users\GY\AppData\Roaming\Typora\typora-user-images\1590830023430.png)

## 链表存储

![1590829990317](C:\Users\GY\AppData\Roaming\Typora\typora-user-images\1590829990317.png)

## 静态链表存储

![1590937952943](C:\Users\GY\AppData\Roaming\Typora\typora-user-images\1590937952943.png)



# 栈、队

## 循环队列实现【数组】

- bug1

  循环队列front所指向的那个位置是空的，即出队时`(++front)%MAXSIZE`再`return queue[front]`

  reer指向的是队尾元素，入队时`(++reer)%MAXSIZE`再`queue[reer] = ele`

  判断已满`(reer+1)%MAXSIZE == front`

  

  

# 指针

# 题目

- 1032

  - bug1赋值问题
  
    修改结构体数组中得值不可以 Node nd  = nodeList[i]; nd.flag = true;
  
    修改得时nd而不是数组中得结构
  
  - bug2格式问题
  
    输出为5个数字，则为printf("%05d\n",i)
  
  - bug3边界问题，如输入节点为0

- 1052

  - bug1

    注意链表可能有多条，因此我们仍然得先建立链表数组，从表头开始遍历筛选所选链表上得节点并置flag=true

  - bug2

    给得头节点地址可能不存在，此时直接输出0 -1

  - bug3
  
    sort(起始地址，结束地址下一个地址，比较函数)
  
    其中比较函数必须遵循严格弱排序，即两者相等时取false

24、25、27、31、35、42



