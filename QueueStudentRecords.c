#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <malloc.h>
#include <mem.h>
#include <stdlib.h>

typedef struct STUDREC {
    char No[13];
    char Name[25];
    char Cyr[10];
    float GWA;
    struct STUDREC *next;
} STUDREC;
void gotoxy(int x, int y);
void createList(STUDREC **FRONT, STUDREC **REAR);
void displayRecords(STUDREC **FRONT, STUDREC **REAR);
void addAtStart(STUDREC **FRONT, STUDREC **REAR);
void addAtEnd(STUDREC **FRONT, STUDREC **REAR);
void addBeforeNode(STUDREC **FRONT, STUDREC **REAR);
void addAfterNode(STUDREC **FRONT, STUDREC **REAR);
void deleteAtStart(STUDREC **FRONT, STUDREC **REAR);
void deleteAtEnd(STUDREC **FRONT, STUDREC **REAR);
void deleteBeforeNode(STUDREC **FRONT, STUDREC **REAR);
void deleteAfterNode(STUDREC **FRONT, STUDREC **REAR);
void deleteList(STUDREC **FRONT, STUDREC **REAR);
int main(){
    STUDREC *FRONT = NULL, *REAR = NULL;
    int opr;
    char temp;
    do {
        system("cls");
        printf("***** MAIN MENU *****");
        printf("\n1:  Create a list\n2:  Display the list\n3:  Add a node at the beginning\n4:  Add a node at the end\n5:  Add a node before a given node\n6:  Add a node after a given node");
        printf("\n7:  Delete a node from the beginning\n8:  Delete a node from the end\n9:  Delete a node before a given node\n10: Delete a node after a given node\n11: Delete the entire list\n12: EXIT");
        printf("\n\nEnter your option: ");
        scanf("%d", &opr);
        switch(opr){
            case 1: createList(&FRONT, &REAR); break;
            case 2: scanf("%c",&temp); displayRecords(&FRONT, &REAR); break;
            case 3: scanf("%c",&temp); addAtStart(&FRONT, &REAR); break;
            case 4: scanf("%c",&temp); addAtEnd(&FRONT, &REAR); break;
            case 5: scanf("%c",&temp); addBeforeNode(&FRONT, &REAR); break; 
            case 6: scanf("%c",&temp); addAfterNode(&FRONT, &REAR); break;
            case 7: scanf("%c",&temp); deleteAtStart(&FRONT, &REAR); break;
            case 8: scanf("%c",&temp); deleteAtEnd(&FRONT, &REAR); break;
            case 9: scanf("%c",&temp); deleteBeforeNode(&FRONT, &REAR); break;
            case 10: scanf("%c",&temp); deleteAfterNode(&FRONT, &REAR); break;
            case 11: scanf("%c",&temp); deleteList(&FRONT, &REAR); break;
            case 12: break;
        }
    } while (opr!=12);
    free(FRONT);
    free(REAR);
    FRONT=REAR=NULL;
    return 0;
}
void gotoxy(int x, int y){
    printf("%c[%d;%df", 0x1B, y, x);
}
void createList(STUDREC **FRONT, STUDREC **REAR){
    STUDREC *NewNode;
    char resp, temp;
    NewNode = (STUDREC *)malloc(sizeof(STUDREC));
    NewNode->next = NULL;
    *FRONT = *REAR = NewNode;
    do{
        system("cls");
        scanf("%c",&temp);
        printf("Enter Student Number: ");
        gets(NewNode->No);
        printf("Enter Student Name: ");
        gets(NewNode->Name);
        printf("Enter Course and Year: ");
        gets(NewNode->Cyr);
        printf("Enter GWA: ");
        scanf("%f",&NewNode->GWA);
        printf("Add Another Student? [Y/N]: ");
        scanf(" %c",&resp);
        if(toupper(resp)=='Y'){
            NewNode->next = (STUDREC *)malloc(sizeof(STUDREC));
            *REAR=NewNode = NewNode->next;
        }
    } while (toupper(resp)=='Y');
    (*REAR)->next=NewNode = NULL;
    printf("List Created!");
    getch();
}
void displayRecords(STUDREC **FRONT, STUDREC **REAR){
    STUDREC *TravNode = *FRONT, *TempFront = NULL, *TempRear = NULL;
    int row=1; 
    system("cls");
    if(TravNode==NULL) {
        printf("Student Record List is Empty!"); 
    } else {
        gotoxy(40,row);
        printf("STUDENT GWA REPORT");
        row++;
        gotoxy(6,row);                  //6 - 20
        printf("STUDENT NO.");
        gotoxy(29,row);                 //29 - 53
        printf("STUDENT NAME");
        gotoxy(58,row);                 //58 - 67
        printf("COURSE & YEAR");
        gotoxy(79,row);                //79 - 86
        printf("GWA");
        while(TravNode!=NULL){
            row++;
            gotoxy(6,row);        //6 - 20
            printf("%s", TravNode->No);
            gotoxy(29,row);       //29 - 53
            printf("%s", TravNode->Name);
            gotoxy(58,row);       //58 - 67
            printf("%s", TravNode->Cyr);
            gotoxy(79,row);       //79 - 86
            printf("%1.4f", TravNode->GWA);
            *FRONT = TravNode->next;
            if (*FRONT==NULL) *REAR = NULL;
            TravNode->next = NULL;
            if (TempFront==NULL) TempFront=TempRear = TravNode;
            else {
            	TempRear->next = TravNode;
            	TempRear = TempRear->next;
			}
			TravNode = *FRONT;
        }
        while(TempFront!=NULL){
        	TravNode = TempFront;
        	TempFront = TempFront->next;
        	TravNode->next = NULL;
        	if (*REAR==NULL) *FRONT=*REAR = TravNode;
        	else {
        		(*REAR)->next = TravNode;
        		*REAR = (*REAR)->next;
			}
        }
    }
    TempFront=TempRear = NULL;
    getch();
}
void addAtStart(STUDREC **FRONT, STUDREC **REAR){
	STUDREC *NewNode, *TravNode, *TempFront = NULL, *TempRear = NULL;
	NewNode = (STUDREC *)malloc(sizeof(STUDREC));
	system("cls");
    printf("Enter Student Number: ");
    gets(NewNode->No);
    printf("Enter Student Name: ");
    gets(NewNode->Name);
    printf("Enter Course and Year: ");
    gets(NewNode->Cyr);
    printf("Enter GWA: ");
    scanf("%f",&NewNode->GWA);
    NewNode->next = NULL;
    while(*FRONT!=NULL){
    	TravNode = *FRONT;
    	*FRONT = (*FRONT)->next;
    	TravNode->next = NULL;
    	if(TempFront==NULL) TempFront=TempRear = TravNode;
    	else {
    		TempRear->next = TravNode;
    		TempRear = TravNode;
		}
	}
	TravNode = NULL;
	*FRONT=*REAR = NewNode;
	while(TempFront!=NULL){
		TravNode = TempFront;
		TempFront = TempFront->next;
		TravNode->next = NULL;
		(*REAR)->next = TravNode;
		*REAR = TravNode;
	}
	printf("Student added at the start!");
	getch();
}
void addAtEnd(STUDREC **FRONT, STUDREC **REAR) {
    STUDREC *NewNode;
    system("cls");
    NewNode = (STUDREC *)malloc(sizeof(STUDREC));
	
    printf("Enter Student Number: ");
    scanf("%s", NewNode->No);
    getchar();

    printf("Enter Student Name: ");
    fgets(NewNode->Name, sizeof(NewNode->Name), stdin);
    NewNode->Name[strcspn(NewNode->Name, "\n")] = '\0';

    printf("Enter Course and Year: ");
    fgets(NewNode->Cyr, sizeof(NewNode->Cyr), stdin);
    NewNode->Cyr[strcspn(NewNode->Cyr, "\n")] = '\0';

    printf("Enter GWA: ");
    scanf("%f", &NewNode->GWA);

    NewNode->next = NULL;

    if (*REAR == NULL) {
        *FRONT = *REAR = NewNode;
    } else {
        (*REAR)->next = NewNode;
        *REAR = NewNode;
    }
    NewNode = NULL;
    printf("Student is added at the end!");
    getch();
}
void addBeforeNode(STUDREC **FRONT, STUDREC **REAR){
	STUDREC *PushNode, *PopNode, *TravNode, *PrevNode = NULL;
	char searchNumber[13];
	int flag = 0;
	if (*FRONT == NULL) printf("Student list is empty.");
    else {
    system("cls");
	printf("Enter student number to add before: ");
	gets(searchNumber);
    TravNode = *FRONT;
    while (TravNode != NULL) {
        if (strcmp(TravNode->No, searchNumber) == 0) {
            flag = 1;
            break;
        }
        PopNode = TravNode;
        PrevNode = TravNode;
        TravNode = TravNode->next;
    }
    if (flag == 0) {
        printf("Student Number does not exist!");
        getch();
        return;
    }
    PushNode = (STUDREC *)malloc(sizeof(STUDREC));
    printf("Enter Student Number: ");
    gets(PushNode->No);
    printf("Enter Student Name: ");
	gets(PushNode->Name);
    printf("Enter Course and Year: ");
    gets(PushNode->Cyr);
    printf("Enter GWA: ");
    scanf("%f",&PushNode->GWA);
    PushNode->next = TravNode;
    if (PrevNode == NULL) {
        *FRONT = PushNode;
    } else {
        PrevNode->next = PushNode;
    } if (TravNode == *FRONT) {
        *REAR = PushNode;
    }
    printf("Node added before %s", searchNumber);
    getch();
    }
}
void addAfterNode(STUDREC **FRONT, STUDREC **REAR) {
	STUDREC *NewNode, *TravNode = NULL, *TempRear = NULL, *TempFront = NULL;
	char searchNumber[13];
	int flag = 0;
	if (*FRONT==NULL){
		printf("The list is empty!");
	} else {
		system("cls");
		printf("Enter student number to add after: ");
		gets(searchNumber);
		while (flag==0 && *FRONT!=NULL){
			TravNode = *FRONT;
			if(strcmp(TravNode->No,searchNumber)==0) flag = 1;
			*FRONT = (*FRONT)->next;
			TravNode->next = NULL;
			if(TempFront==NULL) TempFront=TempRear = TravNode;
			else {
				TempRear->next = TravNode;
				TempRear = TravNode;
			}
		}
		TravNode = NULL;
		if (flag == 0){
			printf("Student Number not found");
		}else {
			NewNode = (STUDREC *)malloc(sizeof(STUDREC));
			printf("Enter Student Number: ");
		    gets(NewNode->No);
		    printf("Enter Student Name: ");
		    gets(NewNode->Name);
		    printf("Enter Course and Year: ");
		    gets(NewNode->Cyr);
		    printf("Enter GWA: ");
		    scanf("%f",&NewNode->GWA);
		    NewNode->next = NULL;
			TempRear->next = NewNode;
			printf("Student added after %s", searchNumber);
		}
		while(TempFront!=NULL){
			TravNode = TempFront;
			TempFront = TempFront->next;
			TravNode->next = NULL;
			if(*FRONT==NULL) *FRONT=*REAR = TravNode;
			else {
				(*REAR)->next = TravNode;
				*REAR = TravNode;
			    TravNode = *FRONT;
			}
		}
	}
	getch();
}
void deleteAtStart(STUDREC **FRONT, STUDREC **REAR) {
    if (*FRONT == NULL) {
        printf("The Queue is empty!\n");
    } else {
        STUDREC *DelNode = *FRONT;
        *FRONT = (*FRONT)->next;
        free(DelNode);
        if (*FRONT == NULL) {
            *REAR = NULL; 
        }
        printf("Node deleted.\n");
    }
    getch();
}
void deleteAtEnd(STUDREC **FRONT, STUDREC **REAR){
	STUDREC *DelNode, *TravNode, *TempFront = NULL, *TempRear = NULL;
	if (*FRONT==NULL) printf("List is empty!");
	else{
		while((*FRONT)->next!=NULL){
	    	TravNode = *FRONT;
	    	*FRONT = (*FRONT)->next;
	    	TravNode->next = NULL;
	    	if(TempFront==NULL) TempFront=TempRear = TravNode;
	    	else {
	    		TempRear->next = TravNode;
	    		TempRear = TravNode;
			}
		}
		TravNode = NULL;
		DelNode = *FRONT;
		*FRONT = (*FRONT)->next;
		free(DelNode);
		DelNode = NULL;
		while(TempFront!=NULL){
			TravNode = TempFront;
			TempFront = TempFront->next;
			TravNode->next = NULL;
			if (*FRONT==NULL) *FRONT=*REAR = TravNode;
			else{
				(*REAR)->next = TravNode;
				*REAR = TravNode;
			}
		}
		printf("Student deleted at the End!");
	}   
	getch();
}
void deleteBeforeNode(STUDREC **FRONT, STUDREC **REAR){
  STUDREC *TravNode = *FRONT, *TempFront = NULL, *TempRear = NULL, *DelNode;
  char Bfval[13];
  int Flag=0,y;
 printf("Enter Student number to delete a student record before it: ");
 scanf("%s",Bfval);
 DelNode=NULL;
 do{
     if(strcmp(Bfval, TravNode->No)==0)
     Flag=1;
     else{
        *FRONT = TravNode->next;
            if (*FRONT==NULL) *REAR = NULL;
            TravNode->next = NULL;
            if (TempFront==NULL) TempFront=TempRear = TravNode;
            else {
            	TempRear->next = TravNode;
            	TempRear = TempRear->next;
        }
        TravNode = *FRONT;
     }
 }while(Flag!=1 && TravNode!=NULL);
 if(Flag==1)
 {
     if(TempFront==NULL){
     printf("There is no student record before this!!!");
     }
     else{
     DelNode=TempFront;   
     TempFront=TempFront->next;
     DelNode->next=NULL;
     free(DelNode);
     DelNode=NULL;
     printf("Deleted student before student number %s",Bfval);
     }
 }
    else{
        printf("The student number you entered does not Exist!");
    }
    while(TempFront!=NULL){
        	TravNode = TempFront;
        	TempFront = TempFront->next;
        	TravNode->next = NULL;
        	if (*REAR==NULL) *FRONT=*REAR = TravNode;
        	else {
        		(*REAR)->next = TravNode;
        		*REAR = (*REAR)->next;
			}
        }
        TempFront=TempRear=NULL;
        getch();
}
void deleteAfterNode(STUDREC **FRONT, STUDREC **REAR) {
  STUDREC *TravNode = *FRONT, *PrevNode = NULL, *DelNode;
  char Bfval[13];
  int Flag = 0;
  if (*FRONT == NULL) {
    printf("The list is empty!\n");
  } else {
    system("cls");
    printf("Enter Student number to delete a student record after it: ");
    scanf("%s", Bfval);
    while (Flag == 0 && TravNode != NULL) {
      if (strcmp(TravNode->No, Bfval) == 0) {
        if (TravNode->next == NULL) {
          printf("There is no student record after this!!!\n");
          getch();
          return;
        } else {
          Flag = 1;
        }
      }
      PrevNode = TravNode;
      TravNode = TravNode->next;
    }
    if (Flag == 0) {
      printf("The student number you entered does not Exist!\n");
    } else {
      DelNode = TravNode;
      PrevNode->next = DelNode->next;
      if (DelNode == *REAR) {
        *REAR = PrevNode;
      }
      free(DelNode);
      DelNode = NULL;
      printf("Deleted student after student number %s\n", Bfval);
    }
  }
  getch();
}
void deleteList(STUDREC **FRONT, STUDREC **REAR){
	STUDREC *DelNode;
	while(*FRONT!=NULL){
		DelNode = *FRONT;
		*FRONT = (*FRONT)->next;
		DelNode->next = NULL;
		free(DelNode);
	}
	DelNode=*REAR = NULL;
	printf("List Deleted!");
	getch();
}
