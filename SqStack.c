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
		printf("初始化失败!\n");
		return Status(0);
	}
	else 
	{
		s->top = -1;
		s->size = sizes;
		return Status(1); 
	}
	
}
//
//bool isEmptyStack(SqStack *s)   //判断栈是否为空
//{
//	
////} 
//Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
//
//Status clearStack(SqStack *s)   //清空栈
//
//Status destroyStack(SqStack *s)  //销毁栈
//
//Status stackLength(SqStack *s,int *length)   //检测栈长度

Status pushStack(SqStack *s,ElemType data)  //入栈
{
	int n,m;
	if(((s->top)+n) <= Stack_Size-1)
	{
		printf("请按顺序输入您要插入的元素:\n");
		for(n = 0; n<data; n++)
		{
			scaanf("%d",&m);
			s->top++;
			s->elem[s->top] = m;
		}
		printf("%d个元素依次进栈成功\n",data);
	}
	else
	{
		printf("空间不足!进栈失败!请重新操作!\n");	
		return Status(0);
	}
	return Status(1); 
//} 
//Status popStack(SqStack *s,ElemType *data)   //出栈
//{
//	
//}

int main ()
{
	printf("************************************************************************************************\n");
	printf("*                                  # 顺序栈操作演示      #                                     *\n");
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
				case 0:(initStack(&s) == 1) ? printf("初始化成功!\n"):printf("初始化失败\n");break;
//				case 1:(isEmptyLStack(&s) == true) ? printf("此栈为空栈!\n"): printf("此栈非空栈\n") ;break; 
//				case 2:int result;
//				 		(getTopLStack(&s,&result) == 1) ? printf("已得到栈顶元素!元素为:%d\n",result):printf("未得到栈顶元素!\n");break;
//				case 3:(clearLStack(&s) == 1) ? printf("栈已清空\n") : printf("清空失败!");break; 
//				case 4: (destroyLStack(&s) == 1) ? printf("已销毁!\n"): printf("销毁失败!\n");break;
//   
//				case 5:int length;
//					   LStackLength(&s,&length);printf("此栈的长度为:%d\n",length);break; 
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
//				case 7: int n;
//						(popLStack(&s,&n) == 1) ? printf("已出栈,出栈元素为:%d!\n",n) : printf("出栈失败\n");break;

			}
			printf("请输入您要操作的序号:\n"); 
			scanf("%d",&choice);
		}
	} 
}
