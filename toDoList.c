#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct myToDo{
	char data[100];
	struct todo *next;
	int count;
};
typedef struct myToDo todo;
time_t tm;

todo *head=NULL;

void viewToDo(){
	todo *temp;
	temp=head;
	if(head==NULL){
		printf("\nEmpty TODO");
	}
	printf("\n");
	time(&tm);
	printf("Todo list created on : %s\n",ctime(&tm));
	while(temp!=NULL){
		
		printf("%d) ",temp->count);
		puts(temp->data);
		fflush(stdin);
		temp=temp->next;
	}
}

void countupdate(){
	todo *temp;
	int i=1;
	temp=head;
	while(temp!=NULL){
		temp->count=i;
		i++;
		temp=temp->next;
	}
}

void createToDo(){
	if(head!=NULL){
		printf("\nList already created!");
	}
	else
	{
		char text='y';
	todo *t, *temp;
	while(1){
		printf("\nDo you want to add?y/n:");
		fflush(stdin);
		scanf("%c",&text);
		if(text=='n')
			break;
		else if(text=='y'){
			if(head==NULL){
				t=(todo*)calloc(1,sizeof(todo));
				head=t;
				fflush(stdin);
				gets(t->data);
				t->count=1;
				t->next=NULL;
			}
			else{
				temp=(todo*)calloc(1,sizeof(todo));
				fflush(stdin);
				gets(temp->data);
				temp->next=NULL;
				t->next=temp;
				t=t->next;
			}
			countupdate();
		}
		else{
			printf("Invalid input!");
		}
		
	}
	}
	
}

void updateToDo(){
	char text;
	todo *t, *temp;
	while(1){
		printf("\nWant to add? y/n:");
		fflush(stdin);
		scanf("%c",&text);
		if(text=='n')
			break;
		temp=(todo*)calloc(1,sizeof(todo));
		fflush(stdin);
		gets(temp->data);
		temp->next=NULL;
		t=head;
		while(t->next!=NULL)
			t=t->next;
		}
		t->next=temp;
		countupdate();
}


void deleteToDo(){
	int d;
	todo *temp,*temp1;
	printf("\nEnter the no of the todo you want to remove:");
	scanf("%d",&d);
	temp1=head;
	temp=head->next;
	while(1){
		if(temp1->count==d){
			head=head->next;
			free(temp1);
			countupdate();
			break;
		}		
		if(temp->count==d){
			temp1->next=temp->next;
			free(temp);
			countupdate();
			break;
		}
		else{
			temp1=temp;
			temp=temp->next;
		}
	}
}

void count(){
	struct myToDo *t=head;
	int count=0;
	if(head==NULL){
		printf("No to-do list");
	}
	else{
		while(t!=NULL){
			count++;
			t=t->next;
		}
	}
	printf("%d",count);
}

int main(){
	int choice;
	while(1){
		printf("\n1. View todo list\n2. Create my todo list\n3. Delete my todos\n4. Update my ToDos\n5.No. of toDos\n6.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:viewToDo();break;
			case 2:createToDo();break;
			case 3:deleteToDo();break;
			case 4:updateToDo();break;
			case 5:count();break;
			case 6:exit(0);
		}
	}
}
