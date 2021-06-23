//19001215

//Two Polynomials Addition and Multiplication

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node * next;
};

struct node * poly1, * poly2, * poly3;

void my_create_poly(struct node ** node, int n) 
{
    int i;
    struct node * tmp_node; 
    tmp_node = (struct node *) malloc(sizeof(struct node));
    tmp_node->next = NULL;
    *node = tmp_node;
    for(i=1; i<=n; i++)
	{
        printf(" Enter Coefficient: ");
        scanf("%d", &tmp_node->coeff);
        
        printf(" Enter Power: ");
        scanf("%d", &tmp_node->pow);
        
        if(i != n)
        {
        	tmp_node->next = (struct node *) malloc(sizeof(struct node));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
		}
		printf("\n");
    }
}


void my_show_poly(struct node * node) 
{
	struct node * p = node;
    
	while(p != NULL) {
        printf("%dX^%d", p->coeff, p->pow);
        p = p->next;
        if(p != NULL)
            printf(" + ");
    }
    printf("\n");
}

void my_sort_poly(struct node * sort)
{
	struct node *p1 = sort, *p2;
	int temp;
	
	while(p1 != NULL)
	{
		p2 = p1->next; 
		while(p2 != NULL)
		{
			if(p1->pow < p2->pow)
			{
				temp= p1->pow;
				p1->pow = p2->pow;
				p2->pow = temp;
				
				temp= p1->coeff;
				p1->coeff = p2->coeff;
				p2->coeff = temp;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}
 
void my_add_poly(struct node ** result, struct node * poly1, struct node * poly2) 
{
    struct node * tmp_node;
    tmp_node = (struct node *) malloc(sizeof(struct node));
    tmp_node->next = NULL;
    *result = tmp_node;
    struct node *p1, *p2; 
    p1=poly1;
    p2=poly2;
    
	while(p1 && p2) 
	{
        if (p1->pow > p2->pow) 
		{
            tmp_node->pow = p1->pow;
            tmp_node->coeff = p1->coeff;
            p1 = p1->next; 
        }
        else if (p1->pow < p2->pow)
		{
            tmp_node->pow = p2->pow;
            tmp_node->coeff = p2->coeff;
            p2 = p2->next; 
        }
        else
		{
            tmp_node->pow = p1->pow;
            tmp_node->coeff = p1->coeff + p2->coeff; 
            p1 = p1->next;
            p2 = p2->next;
        }
 
        if(p1 && p2) 
		{
            tmp_node->next = (struct node *) malloc(sizeof(struct node)); 
            tmp_node = tmp_node->next; 
            tmp_node->next = NULL; 
        }
    }
 
    while(p1 || p2) 
	{
        tmp_node->next = (struct node *) malloc(sizeof(struct node)); 
        tmp_node = tmp_node->next;
        tmp_node->next = NULL; 
 
        if(p1)
		{
            tmp_node->pow = p1->pow;
            tmp_node->coeff = p1->coeff;
            p1 = p1->next; 
        }
        
        if(p2) 
		{
            tmp_node->pow = p2->pow;
            tmp_node->coeff = p2->coeff;
            p2 = p2->next; 
        }
    }
}

void my_mul_poly(struct node **result, struct node * poly1, struct node * poly2)
{
	struct node * tmp_node;
    tmp_node = (struct node *) malloc(sizeof(struct node));
    tmp_node->next = NULL;
    *result = tmp_node;
    struct node *p1, *p2;
    p1=poly1;
    p2=poly2;
    
    if(!p1 && !p2) 
    {
    	*result= NULL;
    	free(tmp_node);
    	printf("\n No polynomials to multiplication");
    	return;
	}
	
	if(!p1 && p2) 
	{
		*result = p2;
		return;
	}
	    
	if(p1 && !p2)
	{
		*result = p1;
		return;
	}
	
	p1= poly1;      
    while(p1) 
    {
    	p2= poly2; 
    	while(p2) 
    	{
    		tmp_node->coeff = p1->coeff * p2->coeff; 
    		tmp_node->pow = p1->pow + p2->pow; 
    		p2 = p2->next; 
    		
    		if(p2) 
    		{
    			tmp_node->next = (struct node *) malloc(sizeof(struct node));
                tmp_node = tmp_node->next;
                tmp_node->next = NULL;
			}
		}
		
		p1 = p1->next; 
		if(p1)
		{
			tmp_node->next = (struct node *) malloc(sizeof(struct node));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
		}
	}
	
	my_sort_poly(poly3); 
	p1=poly3; 
	p2=p1->next; 
	struct node * p;
	
	while(p2) 
	{
		if(p1->pow == p2->pow) 
		{
			p1->coeff = p1->coeff + p2->coeff;
			p=p2;
			p2= p2->next; 
			p1->next=p2; 
			free(p);
		}
		else
		{
			p1=p1->next;
			p2=p2->next;
		}
    }
}

void main(void) 
{
	int num;

    printf(" Number of terms in 1st polynomial expression : ");
    scanf("%d", &num);
    my_create_poly(&poly1, num);
    printf(" Stored 1st polynomial expression : ");
    my_show_poly(poly1);
    my_sort_poly(poly1);
 
    printf("\n\n Number of terms in 2nd polynomial expression : ");
    scanf("%d", &num);
    my_create_poly(&poly2,num);
    printf(" Stored 2nd polynomial expression : ");
    my_show_poly(poly2);
    my_sort_poly(poly2);
    
    my_add_poly(&poly3, poly1, poly2);
    printf("\n\n Addition : ");
    my_show_poly(poly3);
            
    my_mul_poly(&poly3, poly1, poly2);
    printf("\n Multiplication : ");
    my_show_poly(poly3);
}
