#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node {
    char *name;
    int mid_score;
    int end_score;
  };

struct node *root = NULL;

int compare(const void *cp1, const void *cp2){
  return strcmp(((struct node *)cp1)->name,
		((struct node *)cp2)->name);
}

void print_node(const void *nodeptr, VISIT order, int level){
  if (order == preorder || order == leaf)
    printf("\n이름 : %-20s\n 중간 점수 : %d\n 기말 점수 : %d\n",
	   (*(struct node **)nodeptr)->name,
	   (*(struct node **)nodeptr)->mid_score,
	   (*(struct node **)nodeptr)->end_score);
}

void main(){
  struct node **ret;
  int student, i=0;
  
  printf("학생 수를 입력해주세요 : ");
  scanf("%d",&student);
  printf("\n");

  char nametable[student];
  struct node nodetable[student];

  char *nameptr = nametable;
  struct node *nodeptr = nodetable;

  nodeptr = (struct node*)malloc(sizeof(struct node));
  
  while (scanf("%s %d %d", nameptr,
	       &nodeptr->mid_score,
	       &nodeptr->end_score) != EOF && i++ < student){
    nodeptr->name = nameptr;

    ret = (struct node**)tsearch((void *)nodeptr, (void **)&root, compare);

    printf("\"%s\" 님이 ", (*ret)->name);
    if (*ret == nodeptr)
      printf("트리에 추가되었습니다.\n\n");
    else
      printf("트리에 이미 존재합니다.\n\n");
    nameptr += strlen(nameptr) + i;
    nodeptr++;
  }
  twalk((void *)root, print_node);

  free(nodeptr);
  
}

