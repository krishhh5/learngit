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
		printf("��ʼ��ʧ��!\n");
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
//bool isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
//{
//	
////} 
//Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
//
//Status clearStack(SqStack *s)   //���ջ
//
//Status destroyStack(SqStack *s)  //����ջ
//
//Status stackLength(SqStack *s,int *length)   //���ջ����

Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	int n,m;
	if(((s->top)+n) <= Stack_Size-1)
	{
		printf("�밴˳��������Ҫ�����Ԫ��:\n");
		for(n = 0; n<data; n++)
		{
			scaanf("%d",&m);
			s->top++;
			s->elem[s->top] = m;
		}
		printf("%d��Ԫ�����ν�ջ�ɹ�\n",data);
	}
	else
	{
		printf("�ռ䲻��!��ջʧ��!�����²���!\n");	
		return Status(0);
	}
	return Status(1); 
//} 
//Status popStack(SqStack *s,ElemType *data)   //��ջ
//{
//	
//}

int main ()
{
	printf("************************************************************************************************\n");
	printf("*                                  # ˳��ջ������ʾ      #                                     *\n");
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
				case 0:(initStack(&s) == 1) ? printf("��ʼ���ɹ�!\n"):printf("��ʼ��ʧ��\n");break;
//				case 1:(isEmptyLStack(&s) == true) ? printf("��ջΪ��ջ!\n"): printf("��ջ�ǿ�ջ\n") ;break; 
//				case 2:int result;
//				 		(getTopLStack(&s,&result) == 1) ? printf("�ѵõ�ջ��Ԫ��!Ԫ��Ϊ:%d\n",result):printf("δ�õ�ջ��Ԫ��!\n");break;
//				case 3:(clearLStack(&s) == 1) ? printf("ջ�����\n") : printf("���ʧ��!");break; 
//				case 4: (destroyLStack(&s) == 1) ? printf("������!\n"): printf("����ʧ��!\n");break;
//   
//				case 5:int length;
//					   LStackLength(&s,&length);printf("��ջ�ĳ���Ϊ:%d\n",length);break; 
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
//				case 7: int n;
//						(popLStack(&s,&n) == 1) ? printf("�ѳ�ջ,��ջԪ��Ϊ:%d!\n",n) : printf("��ջʧ��\n");break;

			}
			printf("��������Ҫ���������:\n"); 
			scanf("%d",&choice);
		}
	} 
}
