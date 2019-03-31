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

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
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
		printf("ջ��Ԫ��Ϊ:%d\n",*e);
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

Status pushStack(SqStack *s,ElemType data)  //��ջ
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
	printf("*                                  # ��ջ������ʾ        #                                     *\n");
	printf("************************************************************************************************\n");
	printf("*                                  # 0:��ʼ��ջ          #                                     *\n");
	printf("*                                  # 1:�ж�ջ�Ƿ�Ϊ��    #                                     *\n");
	printf("*                                  # 2:�õ�ջ��Ԫ��      #                                     *\n");
	printf("*                                  # 3:���ջ            #                                     *\n");
	printf("*                                  # 4:����ջ            #                                     *\n");
	printf("*                                  # 5:���ջ����        #                                     *\n");
	printf("*                                  # 6:��ջ              #                                     *\n");
	printf("*                                  # 7:��ջ              #                                     *\n");
	printf("*                                  # 8:����              #                                     *\n");
	printf("************************************************************************************************\n");
	printf("��������Ҫ���������:\n"); 
	SqStack s;
	int choice;
	scanf("%d",&choice);
	while(choice != 8)
	{
		if(choice<0||choice>8||choice-(int)choice != 0)
		{
			printf("���޴����,������������Ҫ���������!\n");
			scanf("%d",&choice);
		}
		else
		{	
			switch(choice)
			{
 				case 0:int size;
 						printf("����������ʽ������Ҫ��ʼ����ջ�Ĵ�С!\n");
				 		scanf("%d",&size);
						(initStack(&s,size) == 1) ? printf("��ʼ���ɹ�!\n"):printf("��ʼ��ʧ��\n");break;
						
				case 1: (isEmptyStack(&s) == true) ? printf("��ջΪ��ջ!\n"):printf("��ջ�ǿ�ջ!\n");break;
				 
				case 2: int a;(getTopStack(&s,&a) == 1) ? printf("��ջ�ɹ�!\n") : printf("��ջû��ջ��Ԫ��!\n");break;
 				case 3:(clearStack(&s) == 1) ? printf("��ջ�����!\n"):printf("���ʧ��!\n");break;
 				case 4:(destroyStack(&s) == 1) ? printf("��ջ������!\n"):printf("����ʧ��!\n");break;
 				case 5:int len ;
				 	   (stackLength(&s,&len) == 1) ? printf("���Ȼ�ȡ�ɹ�Ϊ:%d\n",len):printf("���Ȼ�ȡʧ��!");break; 
				case 6:printf("��������Ҫ��ջ��Ԫ��!\n");int num;scanf("%d",&num);
				 	   (pushStack(&s,num) == 1) ? printf("��ջ�ɹ�!\n"):printf("��ջʧ��!\n"); break;
				
				case 7:ElemType n;(popStack(&s,&n) == 1) ? printf("��ջ�ɹ�!\n"):printf("��ջʧ��!\n");break;
    		}
    		printf("��������Ҫ���������:\n"); 
			scanf("%d",&choice);
		}
	}
}
