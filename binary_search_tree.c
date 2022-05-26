#include <stdio.h>
#include <stdlib.h>

struct node{ 
     int ogrNo;
	 int ogrPuan; 
	 int data;
     struct node* left; 
     struct node* right; 
}; 
struct node* newNode(int data) { 
     struct node* node = (struct node*) 
     malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
     return(node); 
} 
void printPostorder(struct node* node) { 
     if (node == NULL) 
        return; 
     printPostorder(node->left); 
     printPostorder(node->right); 
     printf("%d ", node->data); 
} 
void printInorder(struct node* node) { 
     if (node == NULL) 
          return; 
     printInorder(node->left); 
     printf("%d ", node->data);   
     printInorder(node->right); 
} 
void printPreorder(struct node* node) { 
     if (node == NULL) 
          return; 
     printf("%d ", node->data);   
     printPreorder(node->left);   
     printPreorder(node->right); 
}
void printGivenLevel(struct node* root, int level,int a,int b); 
int height(struct node* node); 
struct node* newNode(int data); 

void printLevelOrder(struct node* root,int a,int b) { 
    int h = height(root); 
    int i; 
    for (i = 1; i <= h; i++) 
        printGivenLevel(root, i,a,b); 
} 
void printGivenLevel(struct node* root, int level,int a,int b) { 
    if (root == NULL) 
        return; 
    if (level == 1){
		if(b==0)
			printf("%d ",root->data);
		if(b==1){
        	if(a<root->ogrPuan)
        	printf("%d  %d  %d \n",root->data,root->ogrNo,root->ogrPuan);
		}
	}
    else if (level > 1) { 
        printGivenLevel(root->left, level-1,a,b); 
        printGivenLevel(root->right, level-1,a,b); 
    } 
} 
int height(struct node* node) { 
    if (node == NULL) 
        return 0; 
    else{
        int lheight = height(node->left); 
        int rheight = height(node->right); 
        if (lheight > rheight) 
            return(lheight + 1); 
        else return(rheight + 1); 
    } 
} 
//*******************************************************************
struct node *newNode1(int ind,int no,int points){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=ind;
	temp->ogrNo=no;
	temp->ogrPuan=points;
	temp->left=temp->right=NULL;
	return temp;
}

struct node *insert1(struct node *node, int ind,int no,int points){
	if(node==NULL) {
		return newNode1(ind,no,points);
	}
	if(points==node->ogrPuan){
		if(no<node->ogrNo){
			if(node->left==NULL){
				node->left=newNode1(ind,no,points);
			}
			else
				node->left = insert1(node->left,ind,no,points);
		}
		else
			if(node->right==NULL){
				node->right=newNode1(ind,no,points);
			}
			else
				node->right = insert1(node->right,ind,no,points);
	}
	else{
		if(points>node->ogrPuan)
			node->left=insert1(node->left,ind,no,points);
		else
			node->right=insert1(node->right,ind,no,points);
	}
}

struct node *degistir(struct node *root, int no,int puan,int a){
	if(root != NULL){
		degistir(root->left,no,puan,a);
		if(no==root->ogrNo){
			int ind=root->data;
			free(root);
			if(a==1){
				insert1(root,ind,no,puan);
			}
			return root;
		}
		degistir(root->right,no,puan,a);
	}
}

void istenen(struct node* node,int x) { 
     
     printInorder(node->left); 
     if(x==node->data){
	 	printf("%d  %d  %d", node->data,node->ogrNo,node->ogrPuan);  
	 	return ;
	}
     printInorder(node->right); 
} 
int main(int argc, char *argv[]) {
	struct node *root  = newNode(1); 
     root->left             = newNode(2); 
     root->left->left      = newNode(3); 
     root->left->right    = newNode(4); 
     root->right   = newNode(5);
	 root->right->left =newNode(6);
	 root->right->right =newNode(7);
    printf("Preorder Yazdirma\n\n");
	printPreorder(root);
    printf("\n\nInorder Yazdirma\n\n");
    printInorder(root);
    printf("\n\nPostorder Yazdirma \n \n");
    printPostorder(root);
    printf("\n\nLevelorder Yazdirma \n \n");
    printLevelOrder(root,-1,0); 
    
    struct node* root1= insert1(root1,0,18060311,40);
    insert1(root1,1,20060045,50);
    insert1(root1,2,19061091,75);
    insert1(root1,3,20060134,90);
    insert1(root1,4,20060678,40);
    insert1(root1,5,18061086,75);
    insert1(root1,6,20060032,50);
    insert1(root1,7,20060067,60);
    insert1(root1,8,19060456,60);
    insert1(root1,9,18060245,75);
    insert1(root1,10,20060110,40);
    insert1(root1,11,20060234,90);
    insert1(root1,12,20060141,60);
    insert1(root1,13,20060011,50);
    insert1(root1,14,20060012,60);
    
    printf("\n\n\n**********Agacin Tam Hali**********\n");
    printLevelOrder(root1,0,1);
    printf("\n**********Ýstanen Ýndexin silinmesi(2 nolu indexi sectik)**********\n");
	degistir(root1,19061091,75,0);
	printLevelOrder(root1,0,1);
	printf("\n**********Not Guncellemesi(4 indexli ogrenci 40->80)**********\n");
    degistir(root1,20060678,80,1);
    printLevelOrder(root1,0,1);
    printf("\n**********Istenen Nottan daha yuksek alanlar(70)**********\n");
    printLevelOrder(root1,70,1);
	return 0;
}


