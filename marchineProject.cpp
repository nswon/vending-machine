//자판기 프로젝트 
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
    printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("   MARCHIN 가지고 있는 돈 : %d원       \n", money);   
  printf("┌┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛────────────────────┐\n");
  printf("│                                                        │\n");
  printf("│                                                        │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 1│   메뉴출력                                         │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 2│   음류수 구매                                      │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 3│   음류수 추가                                      │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 4│   돈벌기                                           │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 5│   상점                                             │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 6│   나가기                                           │\n");
  printf("│└──┘                                                    │\n");
  printf("│                                                        │\n");
  printf("│                                                        │\n");
  printf("└────────────────────────────────────────────────────────┘\n");

      
   }
   
   if(freepass == 1) {
    printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("   MARCHIN 가지고 있는 돈 : %d원       \n", money);   
  printf("┌┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛────────────────────┐\n");
  printf("│                                                        │\n");
  printf("│                                                        │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 1│   메뉴출력                                         │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 2│   음류수 구매                                      │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 3│   음류수 추가                                      │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 4│   돈벌기                                           │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 5│   상점                                             │\n");
  printf("│└──┘                                                    │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 6│   나가기                                           │\n");
  printf("│└──┘                                                    │\n");
  printf("│                                                        │\n");
  printf("│┌──┐                                                    │\n");
  printf("││ 7│   무료구매권 사용하기                              │\n");
  printf("│└──┘                                                    │\n");
  printf("│                                                        │\n");
  printf("└────────────────────────────────────────────────────────┘\n");

   }

}

int insert(linkedList_h *H) {
   printf("추가할 음료수의 이름을 적으세요 : \n");
   scanf("%s", adddrinkname);
   printf("%s의 가격을 정해주세요\n", adddrinkname);
   scanf("%d", &addprice);
   insertLastNode(adddrinkname,addprice,H);
   return 0;
}

int buy(linkedList_h *H) {
   listNode * p;
   p = H -> head;
   printf("구매할 음료수를 고르세요 : \n");
   scanf("%s", drinkname);
   while(p != NULL) {
      if(strcmp(drinkname, p -> name) == 0) {
      printf("%s의 수량을 고르세요 :\n", drinkname);
      scanf("%d", &count); 
      sum = p -> price * count;
      if(sum <= money) {
         money = money - sum;
         printf("구매하셨습니다!\n");
         printf("남아있는 돈은 %d원입니다\n", money);
         return 0;
      } 
      else {
         printf("돈이 부족합니다\n");
         return 0;
      }
   } 
      else {
         p = p -> link;
      }
   }
   printf("음료수가 없습니다\n");
   
}

int getmoney() {
   printf("돈벌려면 w를 누르세요\n나가고 싶으면 q를 누르세요\n");
   while(1) {
      scanf("%c", &w);
      if (w == 'w') {
         if (boster == 0) {
            money += 100;
            printf("돈이 100원 올랐습니다. 가지고있는 돈은 %d입니다\n", money);
         }
         else if (boster == 1) {
            money += 1000;
            printf("돈이 1000원 올랐습니다. 가지고있는 돈은 %d입니다\n", money);
         }
      }
      
      else if (w == 'q') {
         return 0;
      }
      
      else if( w == 'z') {
         if (esteregg == 1) {
            if (again == 1) {
               printf("양심이 없네요 벌 받으세요!\n");
               money -= 100000;
               return 0;
            }
            printf("이미 하셨잖아요 또 받아가려고요? 어림도 없죠\n");
            again = 1;
         }
         
         else {
            money += 100000;
            printf("와우 이스터에그! 발견한 기념으로 100000(십만)원이 추가되었습니다. 가지고 있는 돈은 %d원입니다\n", money);
            esteregg = 1;
         }
      }
      
   } 
}

int store() { 
   printf("부스터 : 50000원\n");
   printf("무료구매권 : 10000원\n");
   printf("무엇을 사시겠습니까? 부스터/무료구매권/ 나가기 (b/f/n) : \n");
   getchar();
   scanf("%c", &Answer);
   if(Answer == 'b') {
      printf("사시겠습니까?(y/n) :\n");
   getchar();
   scanf("%c", &answer);
   if(answer == 'y') {
      if (boster == 1) {
         printf("이미 구매하셨습니다\n");
         return 0;
      }
      else if (money < 50000) {
         printf("죄송합니다 구매할 수 없습니다\n");
         return 0;
      }
      else {
         boster = 1;
         money -= 50000;
         printf("구매하셨습니다!\n");
      }
   } else if (answer == 'n') {
      return 0;
   }
   } else if(Answer == 'f'){
      printf("사시겠습니까?(y/n) : \n");
      getchar();
      scanf("%c", &answerr);
      if(answerr == 'y') {
         if(freepass == 1) {
            printf("이미 구매하셨습니다\n");
            return 0;
         }
         else if(freepass == 0){
            money -= 10000;
            printf("구매하셨습니다\n");
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
      printf("어떤 음료수를 고르시겠습니까? : \n");
      scanf("%s", drinknamechoise);
      while(p != NULL) {
         if(strcmp(drinknamechoise, p -> name) == 0) {
         printf("구매하시겠습니까? (y/n) : \n");
         scanf("%c", &dncanswer);
         if(dncanswer == 'y') {
            printf("구매하셨습니다!\n");
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
      printf("음료수가 없습니다\n");
      return ;
   } else if(fbanswer == 'n') {
      return ;
   }
   
}

int main() {
    linkedList_h *H;
       listNode *N;
       H = CreateFirstNode();
   insertNode("포카리스웨트",1500,H);
   insertLastNode("레몬에이드",1800,H);
   insertLastNode("갈배사이다",2000,H);
   insertLastNode("콜라",1800,H);
   insertLastNode("사이다",1800,H);
   insertLastNode("래쓰비",1000,H);
   insertLastNode("환타",1800,H);
   while(1) {
      Menu();
      printf("번호를 고르세요 : \n"); 
      scanf("%d", &number);   
      switch(number) {
         case 1 : printAll(H); break; //메뉴출력 (구현 : O) 
         case 2 : buy(H); break; // 음료수 구매 (구현 : O) 
         case 3 : insert(H); break; // 음료수 추가 (구현 : X) 
         case 4 : getmoney(); break; // 돈벌기 (구현 : O) 
         case 5 : store(); break; // 상점 (구현 : O) 
         case 6 : return 0; break; // 나가기 (구현 : O) 
         case 7 : freebuy(H); break; // 무료구매권 사용하기 (구현 : O) 
   
      }
   }
}
