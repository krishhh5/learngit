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

//������ջ�Ľṹ����
typedef struct LinkStack{
    LinkStackPtr top;//ջ��ָ��
    int count;
} LinkStack;

//��ʼ�� 
Status initLStack(LinkStack *s)
{
	s->top == NULL;
	s->count == 0;
	return Status(1);
}

//�ж��Ƿ�Ϊ��ջ
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

//����ջ 
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

//��ջ 
Status pushLStack(LinkStack *s,ElemType data) 
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(s->count == 0)	//ջ�� 
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

//��ջ 
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

//�õ�ջ��Ԫ��
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
	printf("*                                  # ջ������ʾ          #                                     *\n");
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
	LinkStack s ;
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
				case 0:(initLStack(&s) == 1) ? printf("��ʼ���ɹ�!\n"):printf("��ʼ��ʧ��\n");break;
				case 1:(isEmptyLStack(&s) == true) ? printf("��ջΪ��ջ!\n"): printf("��ջ�ǿ�ջ\n") ;break; 
				case 2:int result;
				 		(getTopLStack(&s,&result) == 1) ? printf("�ѵõ�ջ��Ԫ��!Ԫ��Ϊ:%d\n",result):printf("δ�õ�ջ��Ԫ��!\n");break;
				case 3:(clearLStack(&s) == 1) ? printf("ջ�����\n") : printf("���ʧ��!");break; 
				case 4: (destroyLStack(&s) == 1) ? printf("������!\n"): printf("����ʧ��!\n");break;
   
				case 5:int length;
					   LStackLength(&s,&length);printf("��ջ�ĳ���Ϊ:%d\n",length);break; 
				case 6:printf("����������ʽ������Ҫ��ջ��Ԫ��!\n");
					   int num;
					   scanf("%d",&num);
					   if(num - (int)num != 0)
					   	{
					   		printf("����������!\n");
					   		 scanf("%d",&num);
						}
					   (pushLStack(&s,num) == 1) ? printf("����ջ\n"):printf("��ջʧ��!\n");
					    break;
				case 7: int n;
						(popLStack(&s,&n) == 1) ? printf("�ѳ�ջ,��ջԪ��Ϊ:%d!\n",n) : printf("��ջʧ��\n");break;

			}
			printf("��������Ҫ���������:\n"); 
			scanf("%d",&choice);
		}
	} 
}
