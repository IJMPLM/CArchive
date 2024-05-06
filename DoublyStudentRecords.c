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
    struct STUDREC *prev;
} STUDREC;
void gotoxy(int x, int y);
void createList(STUDREC **HEAD, STUDREC **TAIL);
void displayRecords(STUDREC **HEAD);
void addAtHead(STUDREC **HEAD, STUDREC **TAIL);
void addAtTail(STUDREC **HEAD, STUDREC **TAIL);
void addBeforeNode(STUDREC **HEAD);
void addAfterNode(STUDREC **HEAD, STUDREC **TAIL);
void deleteAtHead(STUDREC **HEAD, STUDREC **TAIL);
void deleteAtTail(STUDREC **HEAD, STUDREC **TAIL);
void deleteBeforeNode(STUDREC **HEAD, STUDREC **TAIL);
void deleteAfterNode(STUDREC **HEAD, STUDREC **TAIL);
void deleteList(STUDREC **HEAD, STUDREC **TAIL);
void displayRecordsTail(STUDREC **TAIL);
int main(){
    STUDREC *HEAD, *TAIL;
    int opr;
    char temp;
    HEAD=TAIL=NULL;
    do {
        system("cls");
        printf("***** MAIN MENU *****");
        printf("\n1:  Create a list\n2:  Display the list\n3:  Add a node at the beginning\n4:  Add a node at the end");
        printf("\n5:  Add a node before a given node\n6:  Add a node after a given node");
		printf("\n7:  Delete a node from the beginning\n8:  Delete a node from the end");
        printf("\n9:  Delete a node before a given node\n10: Delete a node after a given node\n11: Delete the entire list\n12: EXIT");
		printf("\n\nEnter your option: ");
        scanf("%d", &opr);
        switch(opr){
        	case 0: displayRecordsTail(&TAIL); break;
            case 1: createList(&HEAD, &TAIL); break;
            case 2: scanf("%c",&temp); displayRecords(&HEAD); break;
            case 3: scanf("%c",&temp); addAtHead(&HEAD, &TAIL); break;
            case 4: scanf("%c",&temp); addAtTail(&HEAD, &TAIL); break;
            case 5: scanf("%c",&temp); addBeforeNode(&HEAD); break;
            case 6: scanf("%c",&temp); addAfterNode(&HEAD, &TAIL); break;
            case 7: scanf("%c",&temp); deleteAtHead(&HEAD, &TAIL); break;
            case 8: scanf("%c",&temp); deleteAtTail(&HEAD, &TAIL); break;
            case 9: scanf("%c",&temp); deleteBeforeNode(&HEAD, &TAIL); break;
            case 10: scanf("%c",&temp); deleteAfterNode(&HEAD, &TAIL); break;
            case 11: scanf("%c",&temp); deleteList(&HEAD, &TAIL); break;
            case 12: break;
        }
    } while (opr!=12);
    free(HEAD);
    free(TAIL);
    HEAD=TAIL=NULL;
    return 0;
}
void gotoxy(int x, int y){
    printf("%c[%d;%df", 0x1B, y, x);
}
void createList(STUDREC **HEAD, STUDREC **TAIL){
    STUDREC *NewNode;
    char resp, temp;
    NewNode=(STUDREC *)malloc(sizeof(STUDREC));
    *HEAD=*TAIL=NewNode;
    (*HEAD)->prev=NULL;
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
            NewNode->next=(STUDREC *)malloc(sizeof(STUDREC));
            NewNode->next->prev=NewNode;
            NewNode=NewNode->next;
            *TAIL=NewNode;
        }
    } while (toupper(resp)=='Y');
    (*TAIL)->next=NewNode = NULL;
    printf("List Created!");
    getch();
}
void displayRecords(STUDREC **HEAD){
    STUDREC *TravNode;
    int row=1;
    TravNode=*HEAD;
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
        while(TravNode != NULL){
            row++;
            gotoxy(6,row);        //6 - 20
            printf("%s", TravNode->No);
            gotoxy(29,row);       //29 - 53
            printf("%s", TravNode->Name);
            gotoxy(58,row);       //58 - 67
            printf("%s", TravNode->Cyr);
            gotoxy(79,row);       //79 - 86
            printf("%1.4f", TravNode->GWA);
            TravNode = TravNode->next;
        }
    }
    TravNode=NULL;
    getch();
}
void addAtHead(STUDREC **HEAD, STUDREC **TAIL) {
    STUDREC *NewNode;
    system("cls");
	printf("Adding Student at Beginning!\n");
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
    NewNode->prev = NewNode->next = NULL;
    getchar();
    if (*HEAD == NULL) {
        *HEAD = *TAIL = NewNode;
    } else {
        NewNode->next = *HEAD;
        (*HEAD)->prev = NewNode;
        *HEAD = NewNode;
    }
    printf("Node added at the beginning!");
    getch();
}
void addAtTail(STUDREC **HEAD, STUDREC **TAIL){
	system("cls");
    STUDREC *NewNode;
    NewNode=(STUDREC *)malloc(sizeof(STUDREC));
    printf("Enter Student Number: ");
    gets(NewNode->No);
    printf("Enter Student Name: ");
    gets(NewNode->Name);
    printf("Enter Course and Year: ");
    gets(NewNode->Cyr);
    printf("Enter GWA: ");
    scanf("%f",&NewNode->GWA);
    NewNode->prev = NULL;
    NewNode->next = NULL;
    if((*TAIL)==NULL){
    	(*HEAD)=(*TAIL) = NewNode;
	}else{
		NewNode->prev =  *TAIL;
		(*TAIL)->next = NewNode;
		*TAIL = NewNode; 
	}
	NewNode = NULL;
    printf("Student added successfully at the end of the list!\n");
    getch();
}
void addBeforeNode(STUDREC **HEAD) {
	STUDREC *NewNode, *Current;
	char beforeValue[13];
	int Flag = 0;
	
	NewNode = (STUDREC *)malloc(sizeof(STUDREC));
	system("cls");
	printf("Enter student number of before node: ");
    scanf("%s", beforeValue);
    printf("Enter Student Number: ");
    scanf("%s", NewNode->No);
    printf("Enter Student Name: ");
    getchar();
    fgets(NewNode->Name, sizeof(NewNode->Name), stdin);
    NewNode->Name[strcspn(NewNode->Name, "\n")] = '\0';
    printf("Enter Course and Year: ");
    fgets(NewNode->Cyr, sizeof(NewNode->Cyr), stdin);
    NewNode->Cyr[strcspn(NewNode->Cyr, "\n")] = '\0';
    printf("Enter GWA: ");
    scanf("%f", &NewNode->GWA);

    NewNode->prev = NULL;
    NewNode->next = NULL;
    Current = *HEAD;
    
    if(Current==NULL) printf("List is Empty!");
    else{
    	while (Flag == 0 && Current != NULL) {
    	if (strcmp(Current->No, beforeValue) == 0)
            Flag = 1;
    	else
            Current = Current->next;
    }
    if (Flag == 0) {
        printf("The value where you want to insert the new node before does not exist.\n");
        free(NewNode);
    } else {
        	if (Current == *HEAD) {
	            NewNode->next = *HEAD;
	            (*HEAD)->prev = NewNode;
	            *HEAD = NewNode;
        	} else {
	            NewNode->next = Current;
	            NewNode->prev = Current->prev;
	            Current->prev->next = NewNode;
	            Current->prev = NewNode;
        	}
        	printf("Node added successfully before %s.\n", beforeValue);
    	}
	}
    getch();
}
void addAfterNode(STUDREC **HEAD, STUDREC **TAIL) {
    STUDREC *NewNode, *Current = *HEAD;
    int Flag = 0;
    char searchNumber[13];
    
	NewNode = (STUDREC*)malloc(sizeof(STUDREC));
	system("cls");
    printf("Enter Student Number: ");
    scanf("%s", NewNode->No);
    getchar(); 
    printf("Enter Student Name: ");
    scanf("%24[^\n]%*c", NewNode->Name);
    printf("Enter Course and Year: ");
    scanf("%9[^\n]%*c", NewNode->Cyr);
    printf("Enter GWA: ");
    scanf("%f",&NewNode->GWA);
    printf("Enter Student Number to add after: ");
    scanf("%s", searchNumber);
    NewNode->next = NULL;
    NewNode->prev = NULL;
    if (*HEAD == NULL) {
        printf("Double/Doubly Linked List is Empty!\n");
        getch();
        return;
    }
    while (Flag == 0 && Current != NULL) {
            if (strcmp(Current->No, searchNumber) == 0) 
				Flag = 1; 
			else
            	Current = Current->next;
        }
    if (Flag == 0) {
        printf("Student number not found.\n");
        free(NewNode);
        getch();
        return;
	} else {
		if (Current==(*TAIL)){
			NewNode->prev = *TAIL;
			(*TAIL)->next = NewNode;
			(*TAIL) = NewNode;
		} else {
			NewNode->next = Current->next;
	        NewNode->prev = Current;
	        Current->next->prev = NewNode;
	        Current->next = NewNode;
		}
		printf("Node added successfully after %s.\n", searchNumber);
		getch();
	}
	Current=NewNode = NULL;
}
void deleteAtHead(STUDREC **HEAD, STUDREC **TAIL){
	STUDREC *DelNode = *HEAD;
    if (*HEAD == NULL) {
        printf("List is already empty.");
        getch();
        return;
    } else{    
    	if ((*HEAD)->next != NULL) {
	        *HEAD = (*HEAD)->next;
	        (*HEAD)->prev = NULL;
	    } else {
	        *HEAD = NULL;
	        *TAIL = NULL;
    	}
    	free(DelNode);
    	DelNode = NULL;
    	printf("Deleted node from the start of the list.");
		getch();
	}
}
void deleteAtTail(STUDREC **HEAD, STUDREC **TAIL) {
    STUDREC *DelNode = *TAIL;
	if (*TAIL == NULL) {
        printf("List is empty!\n");
    } else{
    	if ((*TAIL)->prev==NULL) *HEAD = NULL;
    	*TAIL = (*TAIL)->prev;
        if ((*TAIL)!=NULL) (*TAIL)->next = NULL;
        DelNode->prev = NULL;
    	free(DelNode);
    	printf("Node deleted from the end!\n");
	}
		DelNode = NULL;
        getch();
}
void deleteBeforeNode(STUDREC **HEAD, STUDREC **TAIL){
  STUDREC *NewNode, *DelNode, *Current, *Previous;
  char Bfval[13];
  int Flag=0,y;
 printf("Enter Student number to delete a student record before it: ");
 scanf("%s",Bfval);
 Current=*HEAD;
 Previous=NULL;
 DelNode=NULL;
 do{
     if(strcmp(Bfval, Current->No)==0)
     Flag=1;
     else{
         Previous=DelNode;
         DelNode=Current;
         Current=Current->next;
     }
 }while(Flag!=1 && Current!=NULL);
 if(Flag==1)
 {
     if(DelNode==NULL){
     printf("There is no student record before this!!!");
     }
     else if(Previous==NULL){
     DelNode=*HEAD;
     *HEAD=DelNode->next;
     DelNode->next->prev = DelNode->prev;
     DelNode->next=NULL;
     free(DelNode);
     DelNode=NULL;
     printf("Node deleted");
     }
     else{
     Previous->next=DelNode->next;
     DelNode->next->prev=Previous;
     free(DelNode);
     DelNode=NULL;
     printf("Node deleted");
     }
 } else{
 	printf("Student Number not found!");
 }
 getch();
}
 void deleteAfterNode(STUDREC **HEAD, STUDREC **TAIL) {
    STUDREC *Current, *NextNode;
    char val[13];
    int Flag = 0;
    printf("Enter Student number to delete a student record after it: ");
    scanf("%s", val);
    Current = *HEAD;
    while (Current != NULL) {
        if (strcmp(val, Current->No) == 0) {
            Flag = 1;
            break;
        }
        Current = Current->next;
    }
    if (Flag == 0 || Current->next == NULL) {
        printf("The specified student number does not exist or it is the last node!\n");
        getch();
    } else {
        NextNode = Current->next;
        Current->next = NextNode->next;
        if (NextNode->next != NULL) {
            NextNode->next->prev = Current; 
        } else *TAIL = Current;
        free(NextNode);
        printf("Node after the student with number %s deleted successfully!\n", val);
        getch();
    }
}
void deleteList(STUDREC **HEAD, STUDREC **TAIL){
    STUDREC *DelNode = *TAIL;
    while(DelNode!=NULL){
        *TAIL=DelNode->prev;
        free(DelNode);
        DelNode=*TAIL;
    }
    printf("List deleted!");
    *HEAD=*TAIL=NULL;
    getch();
}
void displayRecordsTail(STUDREC **TAIL){
    STUDREC *TravNode;
    int row=1;
    TravNode=*TAIL;
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
        while(TravNode != NULL){
            row++;
            gotoxy(6,row);        //6 - 20
            printf("%s", TravNode->No);
            gotoxy(29,row);       //29 - 53
            printf("%s", TravNode->Name);
            gotoxy(58,row);       //58 - 67
            printf("%s", TravNode->Cyr);
            gotoxy(79,row);       //79 - 86
            printf("%1.4f", TravNode->GWA);
            TravNode = TravNode->prev;
        }
    }
    TravNode=NULL;
    getch();
}
