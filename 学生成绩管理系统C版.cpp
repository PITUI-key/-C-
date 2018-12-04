#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _STU//����ڵ�
{
    char arrStuNum[10];
    char arrStuName[10];
    int nStuscore;
    struct _STU* pNext;
}STUNODE;
STUNODE* g_phead = NULL;
STUNODE* g_pend = NULL;


 void AddStuMSG(char *arrStuNum,char arrStuName[10],int nStuscore);

 //�������
 void FreeLinkDate();


 //��ӡ����
 void ShowStuMSG();
 //����ͷ���һ���ڵ�
 void AddStuMSGToLinkHead(char *arrStuNum,char arrStuName[10],int nStuscore);
 //����ָ��ѧ��
 STUNODE*FindStuByNum(char*arrStuNum);
 //ָ��λ�ò���ڵ�
 void InserNode(STUNODE*pTemp,char *arrStuNum,char arrStuName[10],int nStuscore);
 //��ʾĿ¼
 void Showlist();
 //ɾ��ָ��ѧ����Ϣ
 void DeleteStuNode(STUNODE*pNode);
 //���浽�ļ�
 void SaveStuToFile();
 //����ѧ����Ϣ
 void ReadStuFromFile();



int main(void)
{
    int nOrder = -1;  //��ʼ��
    int nFirstorder = -1;
    int nSecondorder = -1;
    char arrStuNum[10] = {0};
    char arrStuName[10] = {0};
    int nStuscore = -1;
    int nFlag = 1;


    STUNODE*pTemp = NULL;
    ReadStuFromFile();
	printf("************��ӭʹ��ѧ���ɼ�����ϵͳ***************\n");
        printf("            1.¼����Ϣ\n");
        printf("            2.��ӡ��Ϣ\n");
        printf("            3.������Ϣ\n");
        printf("            4.�޸���Ϣ\n");
        printf("            5.ɾ����Ϣ\n");
        printf("            6.������Ϣ\n");
        printf("            7.������Ϣ\n");
        printf("            0.�˳�ϵͳ\n");
        while(nFlag)
        {
             printf("����ָ��(����10�鿴Ŀ¼)��");
             scanf("%d",&nOrder);
        switch(nOrder)
        {
        case 1://���������Լ�����ڵ�

            printf("����1��β�����Ϣ��2��ͷ�����Ϣ��3��ָ��λ�������Ϣ\n");
            scanf("%d",&nFirstorder);
            switch(nFirstorder)
            {
            case 1://β��ӽڵ�
                 printf("����ѧ�ţ�\n");
            scanf("%s",arrStuNum);
            printf("����������\n");
            scanf("%s",arrStuName);
            printf("���������\n");
            scanf("%d",&nStuscore);


            AddStuMSG( arrStuNum, arrStuName, nStuscore);
            break;

            case 2://ͷ����ڵ�
                 printf("����ѧ�ţ�\n");
            scanf("%s",arrStuNum);
            printf("����������\n");
            scanf("%s",arrStuName);
            printf("���������\n");
            scanf("%d",&nStuscore);

           AddStuMSGToLinkHead(arrStuNum,arrStuName, nStuscore);
           break;

            case 3://ָ��λ�ò���ڵ�
                 printf("����ָ��ѧ�ţ�\n");
            scanf("%s",arrStuNum);
            pTemp = FindStuByNum(arrStuNum);
            if(NULL !=pTemp)
            {
                printf("����ѧ�ţ�\n");
                scanf("%s",arrStuNum);
                printf("����������\n");
                scanf("%s",arrStuName);
                printf("���������\n");
                scanf("%d",&nStuscore);
                InserNode(pTemp,arrStuNum,arrStuName, nStuscore);
            }
            break;
             default:
            printf("��������\n");
            }
            break;

        case 2: //��ӡѧ����Ϣ
             ShowStuMSG();
            break;
        case 3: //��ӡָ��ѧ����Ϣ
            printf("����ָ��ѧ�ţ�\n");
                 scanf("%s",arrStuNum);
                 //����
                  pTemp = FindStuByNum(arrStuNum);

                  //��ӡ��Ϣ
                  if(NULL != pTemp)
            {
                printf("ѧ�ţ�%s,������ %s, ������%d\n",pTemp->arrStuNum,pTemp->arrStuName,pTemp->nStuscore);
            }

            break;
        case 4: //�޸�ָprintf("ɾ���ɹ���\n");��ѧ����Ϣ
            printf("����ָ��ѧ�ţ�\n");
            scanf("%s",arrStuNum);
            pTemp = FindStuByNum(arrStuNum);
            if(NULL != pTemp)
            {
                //�޸�ѧ��
                printf("����ѧ�ţ�\n");
                scanf("%s",arrStuNum);
                strcpy(pTemp->arrStuNum,arrStuNum);

                //�޸�����
                printf("����������\n");
                scanf("%s",arrStuName);
                strcpy(pTemp->arrStuName,arrStuName);

                //�޸ķ���
                printf("���������\n");
                scanf("%d",&nStuscore);
                pTemp->nStuscore = nStuscore;
            }
            break;
        case 5:
             printf("����Ҫɾ����ѧ�ţ�\n");
             scanf("%s",arrStuNum);
                 //����
             pTemp = FindStuByNum(arrStuNum);
             //ɾ���ڵ�
             if(NULL != pTemp)
             {
                 //����ɾ����Ϣ�ĺ���
                 DeleteStuNode(pTemp);
                 printf("ɾ���ɹ���\n");
             }


            break;
        case 6:
            //����ѧ����Ϣ
            SaveStuToFile();
            break;
        case 7:
            //����ѧ����Ϣ
          ReadStuFromFile();
          break;
        case 10:
            Showlist();
            break;
        case 0:
            nFlag = 0;
            break;
        default:
            printf("��������\n");
        }
    }
    //���浽�ļ�
    SaveStuToFile();

        //�ͷ�����
        FreeLinkDate();
	system("pause");
	return 0;
 }

 //��ʾĿ¼
 void Showlist()
 {
   printf("************��ӭʹ��ѧ���ɼ�����ϵͳ***************\n");
        printf("            1.¼����Ϣ\n");
        printf("            2.��ӡ��Ϣ\n");
        printf("            3.������Ϣ\n");
        printf("            4.�޸���Ϣ\n");
        printf("            5.ɾ����Ϣ\n");
        printf("            6.������Ϣ\n");
        printf("            7.������Ϣ\n");
        printf("            0.�˳�ϵͳ\n");
 }
 //���ѧ����Ϣ
 void AddStuMSG(char *arrStuNum,char arrStuName[10],int nStuscore)
 {
     STUNODE * pTemp =(STUNODE*)malloc(sizeof (STUNODE));//�����ڴ�
     //��������Ϸ���
     if(NULL == arrStuNum || NULL == arrStuName || nStuscore<0)
     {
         printf("ѧ����Ϣ�������\n");
         return ;
     }
     //�����ڵ�

     //��һ����ʼֵ
     strcpy(pTemp->arrStuNum,arrStuNum);
     strcpy(pTemp->arrStuName,arrStuName);
     pTemp->nStuscore = nStuscore;
     pTemp->pNext = NULL;

     //��������
     if(NULL == g_phead)
     {
         g_phead = pTemp;

     }
     else
        {
          g_pend->pNext = pTemp; //����
          g_pend = pTemp;        //����ƶ�
        }
        g_pend  = pTemp;
 }
//�����б�
void FreeLinkDate()
 {
     STUNODE*pTemp = g_phead;
     while(g_phead != NULL)
     {
         pTemp = g_phead;
         g_phead = g_phead->pNext;//����ƶ�һ��

         //ɾ���ڵ�
         free(pTemp);
     }
 }

 void ShowStuMSG()
 {
    STUNODE*pTemp = g_phead;
     while(pTemp!= NULL)
     {
         printf("ѧ�ţ�%s��������%s��������%d\n",pTemp->arrStuNum,pTemp->arrStuName,pTemp->nStuscore);
         pTemp = pTemp->pNext;


     }
 }
 //��ͷ��ӽڵ�
 void AddStuMSGToLinkHead(char *arrStuNum,char arrStuName[10],int nStuscore)
 {
     //���Ϸ���
     STUNODE * pTemp =(STUNODE*)malloc(sizeof (STUNODE));
     if(NULL == arrStuNum || NULL == arrStuName || nStuscore <0)
     {
          printf("ѧ����Ϣ�������\n");
          return ;
     }
     //�����½ڵ�

     strcpy(pTemp->arrStuNum,arrStuNum);
     strcpy(pTemp->arrStuName,arrStuName);
     pTemp->nStuscore = nStuscore;
     pTemp->pNext = NULL;

     if (NULL == g_phead || NULL == g_pend)
     {
         //����Ϊ��
         g_phead = pTemp;
         g_pend = pTemp;
     }
     else
        {
            //�½ڵ����һ��ָ��ͷ
            pTemp->pNext = g_phead;
            g_phead = pTemp;
        }
        g_phead = pTemp;


 }
 // ����ѧ����Ϣ
  STUNODE* FindStuByNum(char* arrStuNum)
{
    STUNODE*pTemp = g_phead;
    //�������Ϸ���
    if(NULL == arrStuNum)
    {
        printf("ѧ���������\n");
        return NULL;
    }
    //�ж������Ƿ�Ϊ��
    if(NULL == g_phead || NULL == g_pend)
    {
         printf("δ�鵽����\n");
        return NULL;
    }
    //��������


    while(pTemp != NULL)
    {
        if(0 == strcmp(pTemp->arrStuNum,arrStuNum))
        {
            return pTemp;

        }
        pTemp = pTemp->pNext;
    }
    printf("δ�鵽���ݣ�\n");
    return NULL;
}
//ָ��λ�ò���ѧ����Ϣ
void InserNode(STUNODE*pTemp,char *arrStuNum,char arrStuName[10],int nStuscore)
{
    //�����ڵ�
    STUNODE*pNewTemp = (STUNODE*)malloc(sizeof(STUNODE));


    //��Ա��ֵ
     strcpy(pNewTemp->arrStuNum,arrStuNum);
     strcpy(pNewTemp->arrStuName,arrStuName);
     pNewTemp->nStuscore = nStuscore;
     pNewTemp->pNext = NULL;


    //����
    if(pTemp == g_pend)
    {
        g_pend->pNext = pNewTemp;
        g_pend = pNewTemp;
    }
    else
    {
        //
        pNewTemp->pNext = pTemp->pNext;
        pTemp->pNext = pNewTemp;
    }
}
//ɾ���ڵ�
void DeleteStuNode(STUNODE*pNode)
{
    //ֻ��һ���ڵ�
    if(g_phead == g_pend)
    {
        free(g_phead);
        g_phead = NULL;
        g_pend = NULL;
    }
    //ֻ�����ڵ�
    else if(g_phead->pNext == g_pend)
    {
        if(g_phead == pNode)
        {
            free(g_phead);
            g_phead = g_pend;
        }
        else
        {
            free(g_pend);
            g_pend = g_phead;
            g_phead->pNext = NULL;
        }
    }
    else//���ڵ�������
    {
        STUNODE*pTemp = g_phead;
        //�ж�ͷ�ڵ��Ƿ���Ҫɾ����
        if(g_phead == pNode)
        {
            pTemp = g_phead;
            g_phead = g_phead->pNext;
            free(pTemp);
            pTemp = NULL;
            return ;
        }

        while(pTemp)
        {
            if(pTemp->pNext == pNode)
            {
                //ɾ��
                if(pNode == g_pend)
                {

                    free(pNode);
                    pNode = NULL;
                    g_pend = pTemp;
                    g_pend->pNext=NULL;
                    return ;

                }
                else
                {
                   //����һ���ڵ�����סҪɾ���Ľڵ�
                   STUNODE*pDel =pTemp->pNext;
                   pTemp->pNext = pNode->pNext->pNext;
                   free(pDel);
                   pDel = NULL;
                   return ;
                }
            }
            pTemp = pTemp->pNext;
        }
    }
}
//���浽�ļ�
void SaveStuToFile()
{
    //�ж������Ƿ�Ϊ��
    FILE*pFILE = NULL;
    STUNODE*pTemp = g_phead;
    char strBuf[30] = {0};
    char strScore[10]= {0};

    if(NULL == g_phead || NULL == g_pend)
    {
        printf("Ŀǰû����\n");
        return ;
    }
    //���ļ�
    pFILE = fopen("dat.dat","wb+");
    if(NULL == pFILE)
    {
        printf("�ļ���ʧ��\n");
        return ;

    }

    //�����ļ�ָ��
    while(pTemp)
    {
       //ѧ�Ÿ���
       strcpy(strBuf,pTemp->arrStuNum);
       strcat(strBuf,"-");
       //����
       strcat(strBuf,pTemp->arrStuName);
       strcat(strBuf,"-");
       //����
       itoa(pTemp->nStuscore,strScore,10);
       strcat(strBuf,strScore);

       fwrite(strBuf,1,strlen(strBuf),pFILE);
       fwrite("\r\n",1,strlen("\r\n"),pFILE);
       pTemp = pTemp->pNext;
    }

    //�ر��ļ�
    fclose(pFILE);
}
 //����ѧ����Ϣ
 void ReadStuFromFile()
 {
     FILE*pFILE = fopen("dat.dat","rb+");
     char strBuf[30] = {0};
     char strStuNum[10]={0};
     char strStuName[10]={0};
     char strStuScore[10]={0};

     int nCount = 0;
    int j = 0;

     if(NULL == pFILE )
     {
         printf("�ļ���ʧ��\n");
         return ;
     }

     //���뺯��

     while(EOF != fgets(strBuf,30,pFILE))
     {
         int i = 0;
         for(i = 0;strBuf[i] != '\r';i++)
         {
             if(0 == nCount)//ÿ����-��
             {
                 strStuNum[i] = strBuf[i];
                 if('-' == strBuf[i])
                    {
                        nCount++;
                    }
             }
             else if(1 == nCount)//��һ����-��
             {

                 strStuName[j]=strBuf[i];
                 if('-' == strBuf[i])
                    {
                        nCount++;
                        j = 0;
                        continue;
                    }
                j++;
             }
             else //�ڶ�����-��
             {
                 int j = 0;
                 strStuScore[j] == strBuf[j];
                 j++;
             }
         }
     }


     fclose(pFILE);
 }



















