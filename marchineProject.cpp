//���Ǳ� ������Ʈ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number, money=1000, count, boster, sum=0, esteregg, again, freepass, addprice;
char answer, w, answerr, Answer, fbanswer, dncanswer;
char drinkname[100];
char drinknamechoise[100];
char adddrinkname[100];

typedef struct listNode{
   char name[100];
   int price;
   struct listNode *link;
}listNode;

typedef struct {
   listNode * head;
}linkedList_h;

linkedList_h* CreateFirstNode(){
   linkedList_h *FirstNode;
   FirstNode = (linkedList_h *)malloc(sizeof(linkedList_h));
   FirstNode -> head = NULL;
   return FirstNode;
}

void insertNode(char *name, int price, linkedList_h *H){
   listNode *newNode; 
   newNode = (listNode *)malloc(sizeof(listNode));
   strcpy(newNode -> name,name);
   newNode -> price = price;
   newNode -> link = NULL; 
   H -> head = newNode;
}

void insertLastNode(char name[], int price, linkedList_h *H){
   listNode *newNode;
   listNode *temp = H -> head;
   newNode = (listNode *)malloc(sizeof(listNode));
   while(temp -> link != NULL){
     temp = temp -> link; 
   }
   temp -> link = newNode;
   strcpy(newNode ->name,name);
   newNode -> price = price;
   newNode -> link = NULL;   
}

void printAll(linkedList_h *H){
   listNode *temp = H -> head;
   while(temp != NULL){
      printf("%s %d\n",temp -> name,temp -> price);
      temp = temp -> link;
   }
   
}

int showmenu(linkedList_h *H) {
       listNode *N;
   printAll(H);
}

void Menu() {
   if(freepass == 0) {
    printf(" ������������������������������������������������������������������������\n");
  printf("   MARCHIN ������ �ִ� �� : %d��       \n", money);   
  printf("��������������������������������������������������������������������������������������������������������������������\n");
  printf("��                                                        ��\n");
  printf("��                                                        ��\n");
  printf("����������                                                    ��\n");
  printf("���� 1��   �޴����                                         ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 2��   ������ ����                                      ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 3��   ������ �߰�                                      ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 4��   ������                                           ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 5��   ����                                             ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 6��   ������                                           ��\n");
  printf("����������                                                    ��\n");
  printf("��                                                        ��\n");
  printf("��                                                        ��\n");
  printf("��������������������������������������������������������������������������������������������������������������������\n");

      
   }
   
   if(freepass == 1) {
    printf(" ������������������������������������������������������������������������\n");
  printf("   MARCHIN ������ �ִ� �� : %d��       \n", money);   
  printf("��������������������������������������������������������������������������������������������������������������������\n");
  printf("��                                                        ��\n");
  printf("��                                                        ��\n");
  printf("����������                                                    ��\n");
  printf("���� 1��   �޴����                                         ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 2��   ������ ����                                      ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 3��   ������ �߰�                                      ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 4��   ������                                           ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 5��   ����                                             ��\n");
  printf("����������                                                    ��\n");
  printf("����������                                                    ��\n");
  printf("���� 6��   ������                                           ��\n");
  printf("����������                                                    ��\n");
  printf("��                                                        ��\n");
  printf("����������                                                    ��\n");
  printf("���� 7��   ���ᱸ�ű� ����ϱ�                              ��\n");
  printf("����������                                                    ��\n");
  printf("��                                                        ��\n");
  printf("��������������������������������������������������������������������������������������������������������������������\n");

   }

}

int insert(linkedList_h *H) {
   printf("�߰��� ������� �̸��� �������� : \n");
   scanf("%s", adddrinkname);
   printf("%s�� ������ �����ּ���\n", adddrinkname);
   scanf("%d", &addprice);
   insertLastNode(adddrinkname,addprice,H);
   return 0;
}

int buy(linkedList_h *H) {
   listNode * p;
   p = H -> head;
   printf("������ ������� ������ : \n");
   scanf("%s", drinkname);
   while(p != NULL) {
      if(strcmp(drinkname, p -> name) == 0) {
      printf("%s�� ������ ������ :\n", drinkname);
      scanf("%d", &count); 
      sum = p -> price * count;
      if(sum <= money) {
         money = money - sum;
         printf("�����ϼ̽��ϴ�!\n");
         printf("�����ִ� ���� %d���Դϴ�\n", money);
         return 0;
      } 
      else {
         printf("���� �����մϴ�\n");
         return 0;
      }
   } 
      else {
         p = p -> link;
      }
   }
   printf("������� �����ϴ�\n");
   
}

int getmoney() {
   printf("�������� w�� ��������\n������ ������ q�� ��������\n");
   while(1) {
      scanf("%c", &w);
      if (w == 'w') {
         if (boster == 0) {
            money += 100;
            printf("���� 100�� �ö����ϴ�. �������ִ� ���� %d�Դϴ�\n", money);
         }
         else if (boster == 1) {
            money += 1000;
            printf("���� 1000�� �ö����ϴ�. �������ִ� ���� %d�Դϴ�\n", money);
         }
      }
      
      else if (w == 'q') {
         return 0;
      }
      
      else if( w == 'z') {
         if (esteregg == 1) {
            if (again == 1) {
               printf("����� ���׿� �� ��������!\n");
               money -= 100000;
               return 0;
            }
            printf("�̹� �ϼ��ݾƿ� �� �޾ư������? ��� ����\n");
            again = 1;
         }
         
         else {
            money += 100000;
            printf("�Ϳ� �̽��Ϳ���! �߰��� ������� 100000(�ʸ�)���� �߰��Ǿ����ϴ�. ������ �ִ� ���� %d���Դϴ�\n", money);
            esteregg = 1;
         }
      }
      
   } 
}

int store() { 
   printf("�ν��� : 50000��\n");
   printf("���ᱸ�ű� : 10000��\n");
   printf("������ ��ðڽ��ϱ�? �ν���/���ᱸ�ű�/ ������ (b/f/n) : \n");
   getchar();
   scanf("%c", &Answer);
   if(Answer == 'b') {
      printf("��ðڽ��ϱ�?(y/n) :\n");
   getchar();
   scanf("%c", &answer);
   if(answer == 'y') {
      if (boster == 1) {
         printf("�̹� �����ϼ̽��ϴ�\n");
         return 0;
      }
      else if (money < 50000) {
         printf("�˼��մϴ� ������ �� �����ϴ�\n");
         return 0;
      }
      else {
         boster = 1;
         money -= 50000;
         printf("�����ϼ̽��ϴ�!\n");
      }
   } else if (answer == 'n') {
      return 0;
   }
   } else if(Answer == 'f'){
      printf("��ðڽ��ϱ�?(y/n) : \n");
      getchar();
      scanf("%c", &answerr);
      if(answerr == 'y') {
         if(freepass == 1) {
            printf("�̹� �����ϼ̽��ϴ�\n");
            return 0;
         }
         else if(freepass == 0){
            money -= 10000;
            printf("�����ϼ̽��ϴ�\n");
            freepass = 1;
         }
      } else if(answerr == 'n') {
         return 0;
      }
   } else if(Answer == 'n') {
      return 0;
   }
}

void freebuy(linkedList_h *H) {
   listNode * p;
   p = H -> head;
   if(fbanswer == 'y') {
      printf("� ������� ���ðڽ��ϱ�? : \n");
      scanf("%s", drinknamechoise);
      while(p != NULL) {
         if(strcmp(drinknamechoise, p -> name) == 0) {
         printf("�����Ͻðڽ��ϱ�? (y/n) : \n");
         scanf("%c", &dncanswer);
         if(dncanswer == 'y') {
            printf("�����ϼ̽��ϴ�!\n");
            freepass = 0;
            return ;
         }
         else if(dncanswer == 'n') {
            break;
            return ;
         }
      }
      p = p->link;
      }
      printf("������� �����ϴ�\n");
      return ;
   } else if(fbanswer == 'n') {
      return ;
   }
   
}

int main() {
    linkedList_h *H;
       listNode *N;
       H = CreateFirstNode();
   insertNode("��ī������Ʈ",1500,H);
   insertLastNode("�����̵�",1800,H);
   insertLastNode("������̴�",2000,H);
   insertLastNode("�ݶ�",1800,H);
   insertLastNode("���̴�",1800,H);
   insertLastNode("������",1000,H);
   insertLastNode("ȯŸ",1800,H);
   while(1) {
      Menu();
      printf("��ȣ�� ������ : \n"); 
      scanf("%d", &number);   
      switch(number) {
         case 1 : printAll(H); break; //�޴���� (���� : O) 
         case 2 : buy(H); break; // ����� ���� (���� : O) 
         case 3 : insert(H); break; // ����� �߰� (���� : X) 
         case 4 : getmoney(); break; // ������ (���� : O) 
         case 5 : store(); break; // ���� (���� : O) 
         case 6 : return 0; break; // ������ (���� : O) 
         case 7 : freebuy(H); break; // ���ᱸ�ű� ����ϱ� (���� : O) 
   
      }
   }
}
