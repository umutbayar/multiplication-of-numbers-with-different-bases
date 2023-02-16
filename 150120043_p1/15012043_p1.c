#include<stdio.h>
#include<stdlib.h>
#include<math.h>
	//umut bayar 150120043 
	//in this code block , we created LinkedList
int counter=0;
struct node {
    int value;
    struct node *nextNode;
    
};

typedef struct node node;

node *multiplicand = NULL;
node *multiplier = NULL;
int base = 0;
		//in this code block , we called functions
void addNodeToEnd(int ,node**);
void printList(node*);
int getProduct(int base,int multiplicatio,int multiplie);

int main(int argc,char* argv[]) {
		//in this code block , we opened file
    FILE* file;
    file = fopen("sample_input.txt", "r");
    
    //Check if file is empty
    if (file == NULL) {
        printf("file can't be opened \n");
    }
    
    //in this code block , we readed multiplicand from file
    char letter;
    int digit;
    int arrMultipl[100];
    do {
        letter = fgetc(file);
        digit = letter - '0';
        if (digit >= 0){
            arrMultipl[counter]=digit;
        	counter++;
			addNodeToEnd(digit,&multiplicand);
		}
    } while (!(letter == EOF || letter == '\n' || letter == ' '));
    //in this code block , we readed multiplier from file
	do {
        letter = fgetc(file);
        digit = letter - '0';
        if (digit >= 0){
			 arrMultipl[counter]=digit;
			 counter++;
            addNodeToEnd(digit,&multiplier);
        }
    } while (!(letter == EOF || letter == '\n' || letter == ' '));
    
    //in this code block , we readed base from file
    letter = fgetc(file);
    base = letter - '0';
    if (base == 1){
        base = 10;
    }
    
    //in this code block , we closed input file
    fclose(file);
    //in this code block , we assign the values we transferred from the linked list to the array as an integer.
    	int multiplicatio=0,multiplie=0;
	int i=0,j=(counter/2)-1,k=1,z=counter-1;
	for(i;i<counter/2;i++){
		multiplicatio+=arrMultipl[j]*k;
		multiplie+=arrMultipl[z]*k;
		z--;
		j--;
		k*=10;
}
    //in this code block ,we opens output
    FILE* output;
    output = fopen("sample_output.txt", "w");

    //in this code block we prints multiplicand,multiplier and result to output file
    node *temp = multiplicand;
    while (temp != NULL){
        fprintf(output, "%d", temp->value);
        temp = temp->nextNode;
    }
    fputc('\n',output);
    temp = multiplier;
    while (temp != NULL){
        fprintf(output, "%d", temp->value);
        temp = temp->nextNode;
    }
    fputc('\n',output);
    fprintf(output,"%d",getProduct(base,multiplicatio,multiplie));
    fputc('\n',output);
    fprintf(output,"%d",convertNumber(base,multiplicatio));
    fputc('\n',output);
    fprintf(output,"%d",convertNumber(base,multiplie));
    fputc('\n',output);
    fprintf(output,"%d",multiply(convertNumber(base,multiplicatio),convertNumber(base,multiplie)));


    //in this code block we Prints in main base result , also we print in base 10 multiplicand ,multiplier and result 
    printList(multiplicand);
    printf("\n");
    printList(multiplier);
    printf("\n");  
    printf("%d",getProduct(base,multiplicatio,multiplie));
	printf("\n");
	printf("%d",convertNumber(base,multiplicatio));//convert multiplicand
	printf("\n");
	printf("%d",convertNumber(base,multiplie));//convert multiplie
	printf("\n");
	printf("%d",multiply(convertNumber(base,multiplicatio),convertNumber(base,multiplie)));//conver result base 10
}
//in this code block, we multiply the numbers on any base 
 int getProduct (int b,int n1,int n2){
 	int rv=0;
	int p=1;
		while(n2>0){
	int d2=n2%10;
	n2=n2/10;
	int sprd=getProductWithASingleDigit(b,n1,d2);
	rv=getSum(b,rv,sprd*p);
	p=p*10;
	}
	return rv;
}
int getProductWithASingleDigit(int b,int n1,int d2){
	int rv=0;
	int c=0;
	int p=1;
	while(n1>0||c>0){
		int d1=n1%10;
		n1=n1/10;
		int d=d1*d2+c;
		c=d/b;
		d=d%b;
		rv=rv+d*p;
		p=p*10;}
		return rv;
	}	
	int getSum(int b,int n1,int n2){
		int rv=0;
		int c=0;
		int p=1;
		while(n1>0||n2>0||c>0){
			int d1=n1%10;
			int d2=n2%10;
			n1=n1/10;
			n2=n2/10;
			int d=d1+d2+c;
			c=d/b;
			d=d%b;
			rv+=d*p;
			p=p*10;
		}
		return rv;
		}

	
//printList function created for printing in of linked list
void printList(node *head){

    if (head != NULL){
        node *tempNode = head;
        while (tempNode->nextNode != NULL){
            printf("%d",tempNode->value);
            tempNode = tempNode->nextNode;
        }
        printf("%d",tempNode->value);

    } else {
        printf("List is empty\n");
        return;
    }
}
//addNodeToEnd function created for add to end of linked list a new value and creating new node
void addNodeToEnd(int val,node** head){
	
	//Creates new node
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->value = val;
    newNode->nextNode =  NULL;
    //Checks if list is empty
    if (*head == NULL){
        //if empty makes node head node
        *head =newNode;

    } else {
        //Searches for last node
        node *temp = *head;
        while (temp->nextNode != NULL){
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
    }
}
//in this code block, we wrote the function that converts the number from any base to base 10
int convertNumber(int b ,int n){
int ans=0,i=0;
while(n>0)
{
ans=ans+(n%10)*pow(b,i);
n=n/10;
i++;
}
return ans;
}
//in this code block , we multiply basicly two integers
int multiply(int a,int b){
	return a*b;
}
