# include <Stdio.h>
# include <Stdlib.h>

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
} StackNode,*LinkStackPtr;

//定义链栈的结构类型
typedef struct LinkStack{
    LinkStackPtr top;//栈顶指针
    int count;
} LinkStack;

//初始化 
Status initLStack(LinkStack *s)
{
	s->top == NULL;
	s->count == 0;
	return Status(1);
}

//判断是否为空栈
bool isEmptyLStack(LinkStack *s) 
{
	if(s->top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}

Status clearLStack(LinkStack *s) 
{
	LinkStackPtr p;
    while(s->top){
        p = s->top;
        s->top = s->top->next;
        s->count--;
        free(p);
    }
    return Status(1);
}

//销毁栈 
Status destroyLStack(LinkStack *s)
{
	if(s->top != NULL) 
		clearLStack(s);
    free(s);
    return Status(1);
}

// 
Status LStackLength(LinkStack *s,int *length) 
{
	*length = s->count-1;
	return Status(1);
}

//入栈 
Status pushLStack(LinkStack *s,ElemType data) 
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(s->count == 0)	//栈空 
	{
		s->top = p;
		p->data = data; 
		p->next = NULL; 
	}
	else
	{
		p->data = data;
		p->next = s->top; 
		s->top = p; 
	}
	s->count++;
	return Status(1);
}

//出栈 
Status popLStack(LinkStack *s,ElemType *e)
{
	if (isEmptyLStack(s))
	{
	return Status(0);
	}
	else
	{
		
		Node *p=s->top;
		*e=p->data;
		s->top = p->next;
		s->count--;
		free(p);
		return Status(1); 
	}

	
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e)
{
	LinkStackPtr p;
	if(isEmptyLStack(s)) 
	{
		return Status(0);
	}
	*e = s->top->data;
	return Status(1);
} 

int main ()
{
	printf("************************************************************************************************\n");
	printf("*                                  # 栈操作演示          #                                     *\n");
	printf("************************************************************************************************\n");
	printf("*                                  # 0:初始化栈          #                                     *\n");
	printf("*                                  # 1:判断栈是否为空    #                                     *\n");
	printf("*                                  # 2:得到栈顶元素      #                                     *\n");
	printf("*                                  # 3:清空栈            #                                     *\n");
	printf("*                                  # 4:销毁栈            #                                     *\n");
	printf("*                                  # 5:检测栈长度        #                                     *\n");
	printf("*                                  # 6:入栈              #                                     *\n");
	printf("*                                  # 7:出栈              #                                     *\n");
	printf("*                                  # 8:结束              #                                     *\n");
	printf("************************************************************************************************\n");
	printf("请输入您要操作的序号:\n"); 
	LinkStack s ;
	int choice;
	scanf("%d",&choice);
	while(choice != 8)
	{
		if(choice<0||choice>8||choice-(int)choice != 0)
		{
			printf("暂无此序号,请重新输入您要操作的序号!\n");
			scanf("%d",&choice);
		}
		else
		{	
			switch(choice)
			{
				case 0:(initLStack(&s) == 1) ? printf("初始化成功!\n"):printf("初始化失败\n");break;
				case 1:(isEmptyLStack(&s) == true) ? printf("此栈为空栈!\n"): printf("此栈非空栈\n") ;break; 
				case 2:int result;
				 		(getTopLStack(&s,&result) == 1) ? printf("已得到栈顶元素!元素为:%d\n",result):printf("未得到栈顶元素!\n");break;
				case 3:(clearLStack(&s) == 1) ? printf("栈已清空\n") : printf("清空失败!");break; 
				case 4: (destroyLStack(&s) == 1) ? printf("已销毁!\n"): printf("销毁失败!\n");break;
   
				case 5:int length;
					   LStackLength(&s,&length);printf("此栈的长度为:%d\n",length);break; 
				case 6:printf("请以整数形式输入您要入栈的元素!\n");
					   int num;
					   scanf("%d",&num);
					   if(num - (int)num != 0)
					   	{
					   		printf("请输入整数!\n");
					   		 scanf("%d",&num);
						}
					   (pushLStack(&s,num) == 1) ? printf("已入栈\n"):printf("入栈失败!\n");
					    break;
				case 7: int n;
						(popLStack(&s,&n) == 1) ? printf("已出栈,出栈元素为:%d!\n",n) : printf("出栈失败\n");break;

			}
			printf("请输入您要操作的序号:\n"); 
			scanf("%d",&choice);
		}
	} 
}
