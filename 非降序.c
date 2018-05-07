#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	int value;
	struct _node* next;
}Node;

Node* Add(Node*head,int number);
Node* Combine(Node *head1 , Node *head2);
void Print(Node *head);

void main(){
  Node *head1=NULL;
  Node *head2=NULL;
  Node *head;
  int number;
  
  do{
  	scanf("%d",&number);
  	if(number!=-1){
  		head1=Add(head1,number);
	  }
  }while(number!=-1);
  
  do{
  	scanf("%d",&number);
  	if(number!=-1){
  		head2=Add(head2,number);
	  }
  }while(number!=-1);
  
  head=Combine(head1,head2);
  Print(head);
  }



Node* Add(Node*head,int number){
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	Node *last=head;
	if(last){
		while(last->next){
			last=last->next;
		}
		last->next=p;
	}
	else{
	head=p;
	}
	return head;
}

Node * Combine(Node *head1 , Node *head2){  
  if(head1==NULL)return head2;
  if(head2==NULL)return head1;  
  Node *head=(Node*)malloc(sizeof(Node)); 
  
  if(head1->value<head2->value)  
  {  
    head=head1;  
    head->next=Combine(head1->next,head2);  
  }  
  else
  {  
    head=head2;  
    head->next=Combine(head1,head2->next);  
  }   
  return head;  
}  
 
void Print(Node *head){
	if(head==NULL) printf("NULL");
    while(head->next!=NULL){
	 printf("%d ",head->value);
 	 head=head->next;
}printf("%d\n",head->value);
}
