#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct node{
		int ogrNo;
		int ogrPuan;
		int index;
		struct node *left, *right;
	};
struct node *newNode(int ind,int no,int points){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->index=ind;
	temp->ogrNo=no;
	temp->ogrPuan=points;
	temp->left=temp->right=NULL;
	return temp;
}
struct node *insert(struct node *node, int ind,int no,int points){
	if(node==NULL) {
		return newNode(ind,no,points);
	}
	if(points==node->ogrPuan){
		if(no<node->ogrNo)
			node->left = insert(node->left,ind,no,points);
		else
			node->right = insert(node->right,ind,no,points);
	}
	else{
		if(points>node->ogrPuan)
			node->left=insert(node->left,ind,no,points);
		else
			node->right=insert(node->right,ind,no,points);
	}
}

struct node *del(struct node *root,int indx){
	if(root != NULL){
		del(root->left,indx);
		if(root->index==indx){
			free(root);
			return root;
		}
		del(root->right,indx);
	}
	
}
struct node *degistir(struct node *root, int no,int puan){
	if(root != NULL){
		degistir(root->left,no,puan);
		if(no==root->ogrNo){
			int ind=root->index;
			free(root);
			insert(root,ind,no,puan);
			return root;
		}
		degistir(root->right,no,puan);
	}
}

int height(struct node *node){
	if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void printGivenLevel(struct node* root, int level,int n);
void printLevelOrder(struct node* root,int notss)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i,notss);
}

void printGivenLevel(struct node* root, int level,int n)
{
    if (root == NULL)
        return;
    if (level == 1)
    	if(n<root->ogrPuan)
        	printf("%d ", root->ogrPuan);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1,n);
        printGivenLevel(root->right, level-1,n);
    }
}
int main(int argc, char *argv[]) {
	struct
	
	return 0;
}
