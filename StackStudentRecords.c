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
void createList(STUDREC **TOP);
void displayRecords(STUDREC **TOP);
void addAtStart(STUDREC **TOP);
void addAtEnd(STUDREC **TOP);
void addBeforeNode(STUDREC **TOP);
void addAfterNode(STUDREC **TOP);
void deleteAtStart(STUDREC **TOP);
void deleteAtEnd(STUDREC **TOP);
void deleteBeforeNode(STUDREC **TOP);
void deleteAfterNode(STUDREC **TOP);
void deleteList(STUDREC **TOP);
int main(){
    STUDREC *TOP = NULL;
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
            case 1: createList(&TOP); break;
            case 2: scanf("%c",&temp); displayRecords(&TOP); break;
            case 3: scanf("%c",&temp); addAtStart(&TOP); break;
            case 4: scanf("%c",&temp); addAtEnd(&TOP); break;
            case 5: scanf("%c",&temp); addBeforeNode(&TOP); break;
            case 6: scanf("%c",&temp); addAfterNode(&TOP); break;
            case 7: scanf("%c",&temp); deleteAtStart(&TOP); break;
            case 8: scanf("%c",&temp); deleteAtEnd(&TOP); break;
            case 9: scanf("%c",&temp); deleteBeforeNode(&TOP); break;
            case 10: scanf("%c",&temp); deleteAfterNode(&TOP); break;
            case 11: scanf("%c",&temp); deleteList(&TOP); break;
            case 12: break;
        }
    } while (opr!=12);
    free(TOP);
    TOP=NULL;
    return 0;
}
void gotoxy(int x, int y){
    printf("%c[%d;%df", 0x1B, y, x);
}
void createList(STUDREC **TOP){
    STUDREC *PushNode;
    char resp, temp;
    PushNode=(STUDREC *)malloc(sizeof(STUDREC));
    PushNode->next = NULL;
    *TOP = PushNode;
    do{
        system("cls");
        scanf("%c",&temp);
        printf("Enter Student Number: ");
        gets(PushNode->No);
        printf("Enter Student Name: ");
        gets(PushNode->Name);
        printf("Enter Course and Year: ");
        gets(PushNode->Cyr);
        printf("Enter GWA: ");
        scanf("%f",&PushNode->GWA);
        printf("Add Another Student? [Y/N]: ");
        scanf(" %c",&resp);
        if(toupper(resp)=='Y'){
            PushNode = (STUDREC *)malloc(sizeof(STUDREC));
            PushNode->next = *TOP;
            *TOP = PushNode;
        }
    } while (toupper(resp)=='Y');
    PushNode = NULL;
    printf("List Created!");
    getch();
}
void displayRecords(STUDREC **TOP){
    STUDREC *PopNode =  *TOP, *TempTop = NULL;
    int row=1;
    system("cls");
    if(PopNode==NULL) {
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
        while((*TOP)!=NULL){
            row++;
            gotoxy(6,row);        //6 - 20
            printf("%s", PopNode->No);
            gotoxy(29,row);       //29 - 53
            printf("%s", PopNode->Name);
            gotoxy(58,row);       //58 - 67
            printf("%s", PopNode->Cyr);
            gotoxy(79,row);       //79 - 86
            printf("%1.4f", PopNode->GWA);
            *TOP = (*TOP)->next;
            PopNode->next = NULL;
        	if (TempTop==NULL)	TempTop = PopNode;
        	else {
        		PopNode->next = TempTop;
        		TempTop = PopNode;
			}
            PopNode = *TOP;
        }
        while(TempTop!=NULL){
        	PopNode = TempTop;
        	TempTop = TempTop->next;
        	PopNode->next = NULL;
        	if (*TOP==NULL) *TOP = PopNode;
        	else {
        		PopNode->next = *TOP;
        		*TOP = PopNode;
			}
        }
    }
    PopNode=TempTop=NULL;
    getch();
}
void addAtStart(STUDREC **TOP){
	STUDREC *PushNode;
	PushNode = (STUDREC *)malloc(sizeof(STUDREC));
	system("cls");
    printf("Enter Student Number: ");
    gets(PushNode->No);
    printf("Enter Student Name: ");
    gets(PushNode->Name);
    printf("Enter Course and Year: ");
    gets(PushNode->Cyr);
    printf("Enter GWA: ");
    scanf("%f",&PushNode->GWA);
    PushNode->next = NULL;
    if(*TOP==NULL) *TOP = PushNode;
    else {
    	PushNode->next = *TOP;
    	*TOP = PushNode;
	}
	PushNode = NULL;
	printf("Student Added at the Beginning!");
	getch();
}
void addAtEnd(STUDREC **TOP){
	STUDREC *PushNode, *PopNode, *TempTop = NULL;
	PushNode = (STUDREC *)malloc(sizeof(STUDREC));
	system("cls");
    printf("Enter Student Number: ");
    gets(PushNode->No);
    printf("Enter Student Name: ");
    gets(PushNode->Name);
    printf("Enter Course and Year: ");
    gets(PushNode->Cyr);
    printf("Enter GWA: ");
    scanf("%f",&PushNode->GWA);
    PushNode->next = NULL;
    while(*TOP!=NULL){
    	PopNode = *TOP;
    	*TOP = (*TOP)->next;
    	PopNode->next = NULL;
    	if(TempTop==NULL) TempTop = PopNode;
    	else {
    		PopNode->next = TempTop;
    		TempTop = PopNode;
		}	    	
	}
	*TOP = PushNode;
	while(TempTop!=NULL){
    	PopNode = TempTop;
    	TempTop = TempTop->next;
    	PopNode->next = NULL;
    	if(*TOP==NULL) *TOP = PopNode;
    	else {
    		PopNode->next = *TOP;
    		*TOP = PopNode;
		}	    	
	}
	printf("Student Added at the End!");
	getch();
}
void addBeforeNode(STUDREC **TOP){
	STUDREC *PushNode, *PopNode, *TempTop = NULL;
	char searchNumber[13];
	int flag = 0;
	if(*TOP==NULL) printf("Student list is empty!");
	else {
		system("cls");
		printf("Enter student number to add before: ");
		gets(searchNumber);
		while(flag==0 && *TOP!=NULL){
			PopNode = *TOP;
			if(strcmp(PopNode->No,searchNumber)==0) flag = 1;
    		*TOP = (*TOP)->next;
    		PopNode->next = NULL;
    		if(TempTop==NULL) TempTop = PopNode;
    		else {
    			PopNode->next = TempTop;
    			TempTop = PopNode;
			}	    	
		}
		PopNode = NULL;
		if (flag==0){
			printf("Student Number does not exist!");
		} else {
			PopNode = TempTop;
	    	TempTop = TempTop->next;
	    	PopNode->next = NULL;
	    	if(*TOP==NULL) *TOP = PopNode;
	    	else {
	    		PopNode->next = *TOP;
	    		*TOP = PopNode;
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
		    PushNode->next = NULL;
		    PushNode->next = *TOP;
		    *TOP = PushNode;
		    printf("Student added before %s",searchNumber);
		}
		while(TempTop!=NULL){
	    	PopNode = TempTop;
	    	TempTop = TempTop->next;
	    	PopNode->next = NULL;
	    	if(*TOP==NULL) *TOP = PopNode;
	    	else {
	    		PopNode->next = *TOP;
	    		*TOP = PopNode;
			}	    	
		}
	}
	PushNode=PopNode=TempTop = NULL;
	getch();
}
void addAfterNode(STUDREC **TOP){
	STUDREC *PushNode, *PopNode, *TempTop = NULL;
	char searchNumber[13];
	int flag = 0;
	if(*TOP==NULL) printf("Student list is empty!");
	else {
		system("cls");
		printf("Enter student number to add after: ");
		gets(searchNumber);
		while(flag==0 && *TOP!=NULL){
			PopNode = *TOP;
			if(strcmp(PopNode->No,searchNumber)==0) flag = 1;
    		*TOP = (*TOP)->next;
    		PopNode->next = NULL;
    		if(TempTop==NULL) TempTop = PopNode;
    		else {
    			PopNode->next = TempTop;
    			TempTop = PopNode;
			}	    	
		}
		PopNode = NULL;
		if (flag==0){
			printf("Student Number does not exist!");
		} else {  
			PushNode = (STUDREC *)malloc(sizeof(STUDREC));
			printf("Enter Student Number: ");
		    gets(PushNode->No);
		    printf("Enter Student Name: ");
		    gets(PushNode->Name);
		    printf("Enter Course and Year: ");
		    gets(PushNode->Cyr);
		    printf("Enter GWA: ");
		    scanf("%f",&PushNode->GWA);
		    PushNode->next = NULL;
		    PushNode->next = *TOP;
		    *TOP = PushNode;
		}
		while(TempTop!=NULL){
	    	PopNode = TempTop;
	    	TempTop = TempTop->next;
	    	PopNode->next = NULL;
	    	if(*TOP==NULL) *TOP = PopNode;
	    	else {
	    		PopNode->next = *TOP;
	    		*TOP = PopNode;
			}	    	
		}
		printf("Student added after %s",searchNumber);
	}
	PushNode=PopNode=TempTop = NULL;
	getch();
}
void deleteAtStart(STUDREC **TOP){
	STUDREC *PopNode = *TOP;
	if (PopNode == NULL){
		printf("Stack is empty!");
	}
	else {
		*TOP = (*TOP)->next;
	}
	free(PopNode);
    PopNode == NULL;
    printf("Student deleted from the beginning!");
    getch();
}
void deleteAtEnd(STUDREC **TOP){
	STUDREC *PopNode, *TempTop = NULL;
	if(*TOP==NULL){
		printf("Stack is empty!");
	} else {
		while((*TOP)->next!=NULL){
	    	PopNode = *TOP;
	    	*TOP = (*TOP)->next;
	    	PopNode->next = NULL;
	    	if(TempTop==NULL) TempTop = PopNode;
	    	else {
	    		PopNode->next = TempTop;
	    		TempTop = PopNode;
			}	    	
		}
		free(*TOP);
		*TOP = NULL;
		while(TempTop!=NULL){
	    	PopNode = TempTop;
	    	TempTop = TempTop->next;
	    	PopNode->next = NULL;
	    	if(*TOP==NULL) *TOP = PopNode;
	    	else {
	    		PopNode->next = *TOP;
	    		*TOP = PopNode;
			}	    	
		}
		printf("Student deleted at the End!");
		getch();
	}
}
void deleteBeforeNode(STUDREC **TOP){
	STUDREC *PopNode, *TempTop = NULL;
	char searchNumber[13];
	int flag = 0;
	if(*TOP==NULL) printf("Student list is empty!");
	else if ((*TOP)->next==NULL) printf("There is only one student in the list!");
	else {
		system("cls");
		printf("Enter student number to delete before: ");
		gets(searchNumber);
		while(flag==0 && *TOP!=NULL){
			PopNode = *TOP;
    		*TOP = (*TOP)->next;
    		PopNode->next = NULL;
    		if(TempTop==NULL) TempTop = PopNode;
    		else {
    			PopNode->next = TempTop;
    			TempTop = PopNode;
			}	    	
			if(strcmp(TempTop->No,searchNumber)==0) flag = 1;
		}
		PopNode = NULL;
		if (flag==0){
			printf("Student Number does not exist!");
		} else {
			PopNode = TempTop;
		    TempTop = TempTop->next;
		    PopNode->next = NULL;
	    	if(*TOP==NULL) *TOP = PopNode;
	    	else {
	    		PopNode->next = *TOP;
	    		*TOP = PopNode;
			}
			if(TempTop==NULL) printf("There is no student before %s", searchNumber);
			else {
				PopNode = TempTop;
		    	TempTop = TempTop->next;
		    	PopNode->next = NULL;
		    	free(PopNode);
		    	PopNode = NULL;
				printf("Student deleted before %s",searchNumber);	
			}
		}	    
		while(TempTop!=NULL){
	    	PopNode = TempTop;
	    	TempTop = TempTop->next;
	    	PopNode->next = NULL;
	    	if(*TOP==NULL) *TOP = PopNode;
	    	else {
	    		PopNode->next = *TOP;
	    		*TOP = PopNode;
			}	    	
		}
	}
	PopNode=TempTop = NULL;
	getch();
}
void deleteAfterNode(STUDREC **TOP){
	STUDREC *PopNode, *TempTop = NULL;
	char searchNumber[13];
	int flag = 0;
	if(*TOP==NULL) printf("Student list is empty!");
	else if ((*TOP)->next==NULL) printf("There is only one student in the list!");
	else {
		system("cls");
		printf("Enter student number to delete after: ");
		gets(searchNumber);
		while(flag==0 && *TOP!=NULL){
			PopNode = *TOP;
			if(strcmp(PopNode->No,searchNumber)==0) flag = 1;
    		*TOP = (*TOP)->next;
    		PopNode->next = NULL;
    		if(TempTop==NULL) TempTop = PopNode;
    		else {
    			PopNode->next = TempTop;
    			TempTop = PopNode;
			}	    	
		}
		PopNode = NULL;
		if (flag==0){
			printf("Student Number does not exist!");
		} else {
			PopNode = *TOP;
			if(PopNode==NULL) printf("There is no student after %s", searchNumber);
			else {
				*TOP = (*TOP)->next;
		    	PopNode->next = NULL;
		    	free(PopNode);
		    	PopNode = NULL;	
				printf("Student deleted after %s",searchNumber);
			}
		}	    
		while(TempTop!=NULL){
	    	PopNode = TempTop;
	    	TempTop = TempTop->next;
	    	PopNode->next = NULL;
	    	if(*TOP==NULL) *TOP = PopNode;
	    	else {
	    		PopNode->next = *TOP;
	    		*TOP = PopNode;
			}	    	
		}
	}
	PopNode=TempTop = NULL;
	getch();
}
void deleteList(STUDREC **TOP){
	STUDREC *PopNode;
	while(*TOP!=NULL){
		PopNode = *TOP;
		*TOP = (*TOP)->next;
		PopNode->next = NULL;
		free(PopNode);
	}
	PopNode = NULL;
	printf("List Deleted!");
	getch();
}
