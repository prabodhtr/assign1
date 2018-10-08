#include <stdio.h>
#include<stdlib.h>

void chk(int ch,int n)
{
    if(ch!=1||n<=0)
    {
        printf("invalid input\n");
        exit(0);
    }
}

struct linkdList{
    int data;
    struct linkdList *next;
};

typedef struct linkdList node;

node* createNode(int el)
{
    node *temp=NULL;
    temp=(node*)malloc(1*sizeof(node));
    if(temp==NULL)
    {
        printf("memory unavailable\n");
        exit(0);
    }
    temp->next=NULL;
    temp->data=el;
    
    return temp;
}

node* insertNode(node* head,node* cur)
{
    node *temp=head;
    
    if(head==NULL)
    return cur;
    else
    {
        while(temp->next!=NULL)
        temp=temp->next;
    
        temp->next=cur;
        return head;
    }
}

void display(node* ptr)
{
    while(ptr->next!=NULL)
    {
        printf("%d,",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}

node* prevNode(node* min_node,node* head)
{
    node* p=head,*prev=NULL;
    while(p!=min_node)
    {
        prev=p;
        p=p->next;
    }
    return prev;
}

node* swap(node* prev,node* p,node* prev_min,node* min,node* head)
{
    if(prev==NULL)
    {
        prev_min->next=p;
	p->next=min->next;
	min->next=head->next;
	printf("1");
        return min;
    }
    else
    {
        p->next=prev_min->next->next;
        min->next=prev->next->next;
        prev->next=min;
        prev_min->next=p;
        return head;
    }
    
}


int main() 
{
    
    int n,temp,el1,min_el;
    node *prev,*prev_min,*min_node,*head;
    prev=prev_min=min_node=NULL;
    
    printf("Enter the value of n\n");
    int ch=scanf("%d",&n);
    chk(ch,n);
   
    printf("enter the elements\n");
    
    for(temp=n;temp>0;temp--)
    {
        ch=scanf("%d",&el1);
        chk(ch,1);
        
        prev=createNode(el1);
       
        head=insertNode(head,prev);
    } 
    
    node* p=head,*ptr;
    
    while(p->next!=NULL)
    {
        node* temp=p;
	ptr=p->next;
	min_el=p->data;
        while(ptr!=NULL)
        {
            if(ptr->data<min_el)
            {
                min_el=ptr->data;
                min_node=ptr;
		printf("1");
            }
            ptr=ptr->next;
        }
	if(min_node!=NULL)
	{
        prev_min=prevNode(min_node,head);
	head=swap(prev,temp,prev_min,min_node,head);
    	}
    prev=min_node;
    p=min_node->next;
    }
    
    display(head);
return 0;
}

