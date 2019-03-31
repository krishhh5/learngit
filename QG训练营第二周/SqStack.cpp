# include <Stdio.h>
# include <Stdlib.h>

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
	ElemType *elem;
	int top;
	int size;
} SqStack;

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
	s->elem = (ElemType *)malloc(sizes * sizeof(ElemType));
	if(NULL == s->elem)
	{
		return Status(0);
	}
	else 
	{
		s->top = -1;
		s->size = sizes;
		return Status(1); 
	}
	
}

bool isEmptyStack(SqStack *s) 
{
	return (-1 == s->top?true:false);
}

Status getTopStack(SqStack *s,ElemType *e) 
{
	if(NULL == s || s->top == -1)
		return Status(0);
	else
	{
		e = &(s->elem[s->top]); 
		printf("栈顶元素为:%d\n",*e);
		return Status(1);
	}
}

Status stackLength(SqStack *s,int *length)
{
	if(NULL ==s|| NULL == length)
	{
		return Status(0);
	}
	*length = s->top+1;
	return Status(1);
}

Status clearStack(SqStack *s)
{
	if(NULL == s)
	{
		return Status(0);
	}
	while(s->top) 
	{
		s->top--;
	}
	return Status(1);
}

Status destroyStack(SqStack *s)
{
	if(NULL == s)
	{
		return Status(0);
	}
	free(s->elem);
	return Status(1);
}

Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(NULL != s && s->top < s->size - 1)
	{
		s->top++;
		s->elem[s->top] = data;
		return Status(1);
	}
	else
	{	
		return Status(0);
	}	
}

Status popStack(SqStack *s,ElemType *data) 
{
	if(NULL == s || s->top == -1)
	{
		return Status(0);
	}
	*data = s->elem[s->top];
	s->top--;
	return Status(1);
}

int main ()
{
	printf("************************************************************************************************\n");
	printf("*                                  # 链栈操作演示        #                                     *\n");
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
	SqStack s;
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
 				case 0:int size;
 						printf("请以整数形式输入你要初始化的栈的大小!\n");
				 		scanf("%d",&size);
						(initStack(&s,size) == 1) ? printf("初始化成功!\n"):printf("初始化失败\n");break;
						
				case 1: (isEmptyStack(&s) == true) ? printf("此栈为空栈!\n"):printf("此栈非空栈!\n");break;
				 
				case 2: int a;(getTopStack(&s,&a) == 1) ? printf("出栈成功!\n") : printf("此栈没有栈顶元素!\n");break;
 				case 3:(clearStack(&s) == 1) ? printf("此栈已清空!\n"):printf("清空失败!\n");break;
 				case 4:(destroyStack(&s) == 1) ? printf("此栈已销毁!\n"):printf("销毁失败!\n");break;
 				case 5:int len ;
				 	   (stackLength(&s,&len) == 1) ? printf("长度获取成功为:%d\n",len):printf("长度获取失败!");break; 
				case 6:printf("请输入您要进栈的元素!\n");int num;scanf("%d",&num);
				 	   (pushStack(&s,num) == 1) ? printf("进栈成功!\n"):printf("进栈失败!\n"); break;
				
				case 7:ElemType n;(popStack(&s,&n) == 1) ? printf("出栈成功!\n"):printf("出栈失败!\n");break;
    		}
    		printf("请输入您要操作的序号:\n"); 
			scanf("%d",&choice);
		}
	}
}
