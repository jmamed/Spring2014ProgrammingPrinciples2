#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


struct node{
	char numbers[20];
	char first[20];
	struct node *prev;
	struct node *next;
};

struct node *head = NULL, *tail = NULL;
int nodenum = 0;

void setlist(){ //struct node *head, struct node *tail

	head = (struct node*)malloc(sizeof(struct node));
	tail = (struct node*)malloc(sizeof(struct node));

	head->next = tail;
	tail->prev = head;
	head->prev = NULL;
	tail->next = NULL;
}

struct node *madelist(char *tempnum, char *tempfirst){    //struct node *head, struct node *tail, 
	struct node *p = NULL, *t = NULL, *ptr = NULL;

	int i = 0;
	ptr = (struct node*)malloc(sizeof(struct node));
	strcpy(ptr->numbers, tempnum);
	strcpy(ptr->first, tempfirst);

	if (nodenum == 0){
		p = tail;
	}
	else{
		for (p = head->next; p != tail; p = p->next, i++){
			if (strcmp(tempfirst, ptr->first) == -1){
				break;
			}
		}
	}
	t = p->prev;

	t->next = ptr;
	ptr->next = p;
	p->prev = ptr;
	ptr->prev = t;

	nodenum++;
	return ptr;
}

void deletelist(char *temp){          //struct node *head, struct node *tail, 

	struct node *p = NULL, *t = NULL, *ptr = NULL;

	if (nodenum > 0){

		for (p = head->next; p != tail; p = p->next){
			if (strcmp(temp, p->first) == -1)
				break;
		}

		t = p->prev;

		if (p != tail && p != head){
			t->next = p->next;
			(p->next)->prev = t;
			p->next = NULL;
			p->prev = NULL;
			free(p);
		}

		nodenum--;
	}

}

void printlist(FILE *wp){            //struct node *head, struct node *tail
	struct node *p = NULL;

	for (p = head->next; p != tail; p = (p->next)){
		fprintf(wp, "%s %s\n", p->numbers, p->first);
	}
}

void search(FILE *wp, char *temp){
	struct node *p = NULL, *t = NULL, *ptr = NULL;

	if (nodenum > 0){

		for (p = head->next; p != tail; p = p->next){
			if (strcmp(temp, p->first) == 0)
				break;
		}
		printf("%s %s", p->numbers, p->first);
		fprintf(wp, "%s %s\n", p->numbers, p->first);
		}
	}

int main(int argc, char *argv[]) {
	FILE *p;
	FILE *wp;
	char print[20];
	char priority[20];

	int i;

	setlist();

	for (i = 0; i < argc; i++){
		if (strcmp(argv[i], "-i") == 0){       //initialize new file
			p = fopen(argv[i + 1], "r+");
			while (fscanf(p, "%s %s", &print, &priority) != EOF) {

				printf("%s %s\n", print, priority);
				madelist(print, priority);
			}

			printf("\n");
			fclose(p);
		}

		else if (strcmp(argv[i], "-o") == 0){  //output file
			wp = fopen(argv[i + 1], "w+");
			printlist(wp);

		}

		else if (strcmp(argv[i], "-s") == 0){ //Retrieves records of printer jobs
			search(wp, argv[i + 1]);
			printlist(wp);

		}

		else if (strcmp(argv[i], "-d") == 0){ //deletes printer jobs
			deletelist(argv[i + 1]);
			printlist(wp);
		}
	}
	fclose(wp);
	getchar();
	return 0;
}
