#include <stdio.h>
#include <ctype.h>
#include <mem.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STUDREC {
    char No[13];
    char Name[25];
    char Cyr[10];
    float GWA;
    struct STUDREC *next;
} STUDREC;

void gotoxy(int x, int y);
void createList(STUDREC **START);
void displayList(STUDREC **START);
void addAtStart(STUDREC **START);
void addAtEnd(STUDREC **START);
void addBeforeNode(STUDREC **START);
void addAfterNode(STUDREC **START);
void deleteAtStart(STUDREC **START);
void deleteAtEnd(STUDREC **START);
void deleteBeforeNode(STUDREC **START);
void deleteAfterNode(STUDREC **START);
void deleteList(STUDREC **START);

int main(){
    STUDREC *START;
    int opr;
    char temp;
    START=NULL;
    do {
        system("cls");
        printf("***** MAIN MENU *****");
        printf("\n1:  Create a list\n2:  Display the list\n3:  Add a node at the beginning\n4:  Add a node at the end");
        printf("\n5:  Add a node before a given node\n6:  Add a node after a given node");
        printf("\n7:  Delete a node from the beginning\n8:  Delete a node from the end\n");
        printf("9:  Delete a node before a given node\n10: Delete a node after a given node\n11: Delete the entire list\n12: EXIT");
        printf("\n\nEnter your option: ");
        scanf("%d", &opr);
        switch(opr){
            case 1: createList(&START); break;
            case 2: scanf("%c",&temp); displayList(&START); break;
            case 3: scanf("%c",&temp); addAtStart(&START); break;
            case 4: scanf("%c",&temp); addAtEnd(&START); break;
            case 5: scanf("%c",&temp); addBeforeNode(&START); break;
            case 6: scanf("%c",&temp); addAfterNode(&START); break;
            case 7: scanf("%c",&temp); deleteAtStart(&START); break;
            case 8: scanf("%c",&temp); deleteAtEnd(&START); break;
            case 9: scanf("%c",&temp); deleteBeforeNode(&START); break;
            case 10: scanf("%c",&temp); deleteAfterNode(&START); break;
            case 11: scanf("%c",&temp); deleteList(&START); break;
            case 12: break;
        }
    } while (opr!=12);
    free(START);
    START = NULL;
    return 0;
}
void gotoxy(int x, int y){
    printf("%c[%d;%df", 0x1B, y, x);
}
void createList(STUDREC **START){
    STUDREC *NewNode;
    char resp, temp;
    *START=NULL;
    printf("Creating Student Records!");
    NewNode=(STUDREC*)malloc(sizeof(STUDREC));
    *START=NewNode;
    do {
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
            NewNode->next=(STUDREC*)malloc(sizeof(STUDREC));
            NewNode=NewNode->next;
        }
        NewNode->next=NULL;
    } while (toupper(resp)=='Y');
    printf("List created!");
    getch();
    NewNode=NULL;
}
void displayList(STUDREC **START){
    STUDREC *Current;
    int row=1;
    Current=*START;
    system("cls");

    if(Current==NULL) {
        printf("STUDENT GWA REPORT IS EMPTY!");
        getch();
    } else{
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
        while(Current != NULL){
            row++;
            gotoxy(6,row);        //6 - 20
            printf("%s", Current->No);
            gotoxy(29,row);       //29 - 53
            printf("%s", Current->Name);
            gotoxy(58,row);       //58 - 67
            printf("%s", Current->Cyr);
            gotoxy(79,row);       //79 - 86
            printf("%1.4f", Current->GWA);
            Current = Current->next;
        }
        Current=NULL;
    getch();
    }
}
void addAtStart(STUDREC **START) {
    STUDREC *NewNode;
    system("cls");
    printf("Adding Student at Beginning!\n");


        NewNode = (STUDREC*)malloc(sizeof(STUDREC));
        if (NewNode == NULL) {
            printf("Memory allocation failed. Exiting...");
            exit(1);
        }
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
        getchar();
        NewNode->next = *START;
        *START = NewNode;
        
        printf("Student added at Beginning");
        getch();
}
void addAtEnd(STUDREC **START) {
    STUDREC *NewNode, *temp;
    system("cls");
    printf("Adding Student at End!\n");
    

    NewNode = (STUDREC *)malloc(sizeof(STUDREC));
    
    if (NewNode == NULL) {
        printf("Memory allocation failed. Exiting...");
        exit(0);
    }

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
    getchar();
    NewNode->next = NULL;

    if (*START == NULL) {
        *START = NewNode;
    } else {
        temp = *START;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
 printf ("%s inserted at the end\n", NewNode->No);
 getch();
}
void addBeforeNode(STUDREC **START) {
    char beforeValue[13]; 
    char newNo[13]; 
    char newName[25]; 
    char newCyr[10]; 
    float newGWA; 
    
    system("cls");
        printf("Enter student number of before node: ");
        scanf("%s", beforeValue);
        getchar();
        printf("Enter Student Number: ");
        fgets(newNo, sizeof(newNo), stdin);
        printf("Enter Student Name: ");
        fgets(newName, sizeof(newName), stdin);
        printf("Enter Course and Year: ");
        fgets(newCyr, sizeof(newCyr), stdin);
        printf("Enter GWA: ");
        scanf("%f", &newGWA);
    
	int flag = 0;
    STUDREC *NewNode, *Current, *Previous;
    
    NewNode = (STUDREC*)malloc(sizeof(STUDREC));    
    if (NewNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    strcpy(NewNode->No, newNo);
    strcpy(NewNode->Name, newName);
    strcpy(NewNode->Cyr, newCyr);
    NewNode->GWA = newGWA;
    
    Current = *START;
    Previous = NULL;
    
    while (Current != NULL) {
        if (strcmp(beforeValue, Current->No) == 0) {
            flag = 1;
            break;
        }
        Previous = Current;
        Current = Current->next;
    }
    
    if (flag == 1) {
        NewNode->next = Current;
        if (Previous == NULL) {
            *START = NewNode;
        } else {
            Previous->next = NewNode;
        }
        printf("Node added successfully before %s.\n", beforeValue);
    } else {
        printf("The value where you want to insert the new node before does not exist!\n");
        free(NewNode); 
    }
    getch();
}
void addAfterNode(STUDREC **START) {
	STUDREC *NewNode, *Current = *START;
    char searchNumber[13];
    system("cls");
    printf("Enter Student Number to add after: ");
    gets(searchNumber);

    STUDREC *current = *START;
    while (current != NULL) {
        if (strcmp(current->No, searchNumber) == 0) {
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Student number not found.\n");
        getch();
        return;
    }

    NewNode = (STUDREC*)malloc(sizeof(STUDREC));
    if (NewNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter Student Number: ");
    gets(NewNode->No);
    printf("Enter Student Name: ");
    gets(NewNode->Name);
    printf("Enter Course and Year: ");
    gets(NewNode->Cyr);
    printf("Enter GWA: ");
    scanf("%f", &NewNode->GWA);

    NewNode->next = current->next;
    current->next = NewNode;
    printf("Student added after %s",searchNumber);
    getch();
}
void deleteAtStart(STUDREC **START){
    if (*START == NULL) {
        printf("List is empty\n");
        getch();
        return;
    }
    STUDREC *temp = *START;
    *START = (*START)->next;
    free(temp);
    printf("Node at the beginning deleted successfully\n");
    getch();
}
void deleteAtEnd(STUDREC **START) {
    if (*START == NULL) {
        printf("List is already empty!\n");
        getch();
        return;
    }
    STUDREC *temp = *START;
    STUDREC *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        free(temp);
        *START = NULL;
    } else {
        free(temp);
        prev->next = NULL;
    }
    printf("Node deleted from the end!\n");
    getch();
} 
void deleteBeforeNode(STUDREC **START){
  STUDREC *DelNode, *Current, *Previous;
  char Bfval[13];
  int Flag=0,y;
 printf("Enter Student number to delete a student record before it: ");
 scanf("%s",Bfval);
 Current=*START;
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
     DelNode=*START;
     *START=DelNode->next;
     DelNode->next=NULL;
     free(DelNode);
     DelNode=NULL;
	 printf("Deleted node before student no. %s", Bfval);
     }
     else{
     Previous->next=DelNode->next;
     free(DelNode);
     DelNode=NULL;
     printf("Deleted node before student no. %s", Bfval);
     }
 }
 	else
 		printf("The student number you inserted does not Exist!");
 		
	Previous=Current=NULL;
	getch();
}
void deleteAfterNode(STUDREC **START){
    STUDREC *Current, *NextNode;
    char val[13];
    int Flag=0;

    printf("Enter Student number to delete a student record after it: ");
    scanf("%s", val);

    Current = *START;

    while (Current != NULL) {
        if (strcmp(val, Current->No) == 0) {
            Flag = 1;
            break;
        }
        Current = Current->next;
    }

    if (Flag == 0 || Current->next == NULL) {
        printf("The specified student number does not exist or it is the last node!\n");
    } else {
        NextNode = Current->next;
        Current->next = NextNode->next;
        free(NextNode);
        printf("Node after the student with number %s deleted successfully!\n", val);

    }
    getch();
}
void deleteList(STUDREC **START){
    free(*START);
    *START=NULL;
    printf("List Deleted!");
    getch();
}
