#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
typedef struct list{
	char *isim[20];
	int fatura;
	struct list* next;
}liste;
	liste *yeni, *ilk = NULL, *son=NULL, *gecici, *silGecici=NULL ,*itr;

void ekle(char*,int);
void ekle1(char*,int);
void ekle2(char*,int);
void sil(int);
void harfYazdir(char);
void yazdirTutar(int );
void listele();
int main() {
	int i;
	ekle("Ahmet",1000);ekle("Bilal",100);  ekle("Cemal",600); ekle("Adem",650); ekle("Yasin",350); ekle("Esin",270); ekle("Emel",410); ekle("Mustafa",750); ekle("Ayten",600); ekle("Ceylan",1000); ekle("Nesrin",900); ekle("Bekir",850); ekle("Emin",790); ekle("Hakan",610); ekle("Hatice",550);
	printf("***Listenin ilk hali***\n");
	listele();
	for(i=1;i<=15;i++){
		sil(ilk->fatura);
	}
	ekle1("Ahmet",100); ekle1("Bilal",1000);   ekle1("Cemal",600); ekle1("Adem",650); ekle1("Yasin",350); ekle1("Esin",270); ekle1("Emel",410); ekle1("Mustafa",750); ekle1("Ayten",600); ekle1("Ceylan",1000); ekle1("Nesrin",900); ekle1("Bekir",850); ekle1("Emin",790); ekle1("Hakan",610); ekle1("Hatice",550);
	printf("***Tum listenin faturaya gore siralanmasi***\n");
	listele();
	
	yazdirTutar(900);
	
	for(i=1;i<=15;i++){
		sil(ilk->fatura);
	}
	ekle2("Bilal",1000); ekle2("Ahmet",100); ekle2("Cemal",600); ekle2("Adem",650); ekle2("Yasin",350); ekle2("Esin",270); ekle2("Emel",410); ekle2("Mustafa",750); ekle2("Ayten",600); ekle2("Ceylan",1000); ekle2("Nesrin",900); ekle2("Bekir",850); ekle2("Emin",790); ekle2("Hakan",610); ekle2("Hatice",550);
	printf("\n***Tum listenin isme gore siralanmasi***\n");
	listele();
	
	harfYazdir('A');	
	return 0;
}
void ekle(char *isim,int fatura){
    yeni = (liste*) malloc(sizeof(liste));
    yeni->isim[0]= isim;
    yeni->fatura = fatura;
    yeni->next = NULL;
    if(ilk == NULL){     
        ilk = yeni;
        son = ilk;
    }
    else{              
        son->next = yeni;
        son = son->next;
    }
}
void ekle1(char *isim,int fatura){
	if(ilk==NULL){
		ilk = (liste*) malloc(sizeof(liste));
		ilk->isim[0]=isim;
		ilk->fatura=fatura;
		ilk->next=NULL;
	}
	else{
		if((ilk->fatura)<(fatura)){
			yeni= (liste*) malloc(sizeof(liste));
			yeni->fatura=fatura;
			yeni->isim[0]=isim;
			yeni->next=ilk;
			ilk=yeni;
		}
		else{
			gecici=ilk;
			yeni= (liste*) malloc(sizeof(liste));
			yeni->fatura=fatura;
			yeni->isim[0]=isim;
			while(gecici!=NULL){
				if(gecici->next==NULL && (gecici->fatura)>=(fatura)){
					yeni->next=NULL;
					gecici->next=yeni;
					break;
				}
				if((gecici->next->fatura)<(fatura)){
					yeni->next=gecici->next;
					gecici->next=yeni;
					break;
				}
				gecici=gecici->next;
			}
		}
	}
}
void ekle2(char *isim,int fatura){
	if(ilk==NULL){
		ilk = (liste*) malloc(sizeof(liste));
		ilk->isim[0]=isim;
		ilk->fatura=fatura;
		ilk->next=NULL;
	}
	else{
		int a=strcmp(ilk->isim[0],isim);
		if(a>0){
			yeni= (liste*) malloc(sizeof(liste));
			yeni->fatura=fatura;
			yeni->isim[0]=isim;
			yeni->next=ilk;
			ilk=yeni;
		}
		else{
			gecici=ilk;
			yeni= (liste*) malloc(sizeof(liste));
			yeni->fatura=fatura;
			yeni->isim[0]=isim;
			while(gecici!=NULL){	
				if(gecici->next==NULL && (strcmp(gecici->isim[0],isim)<=0) ){
					yeni->next=NULL;
					gecici->next=yeni;
					break;
				}
				if(strcmp(gecici->next->isim[0],isim)>0){
					yeni->next=gecici->next;
					gecici->next=yeni;
					break;
				}
				gecici=gecici->next;
			}
		}
	}
}
void sil(int fatura)
{
    int kontrol = 0;
    if(ilk == NULL)
        kontrol = -1;    
    else if(ilk->fatura == fatura){
        silGecici = ilk;    
        ilk = ilk->next;
        free(silGecici);
        kontrol = 1;
    }
    else{
        gecici = ilk;
        while(gecici->next != NULL){        
            if(gecici->next->fatura == fatura){
                kontrol = 1;    
                silGecici = gecici->next;            
                if(silGecici == son)       
                    son = gecici;
                gecici->next = silGecici->next;        
                free(silGecici);                   
                break;  
            }
             gecici = gecici->next; 
        }
    }
}
void harfYazdir(char harf){
	printf("verilen harfe gore listeleme '%c'\n",harf);
	itr=ilk;
	int i;
	for(i=1;i<=15;i++){
		char c;
		c=itr->isim[0][0];
		if(c==harf){
			printf("%s  %d \n",itr->isim[0],itr->fatura);
		}
		itr=itr->next;
	}
}
void yazdirTutar(int tutar){
	printf("Verilen faturaya gore listeleme (%d) \n",tutar);
	itr=ilk;
	int i;
	for(i=1;i<=15;i++){
		printf("%s  %d\n",itr->isim[0],itr->fatura);
		if(itr->next->fatura<tutar){
			break;
		}
		itr=itr->next;
	}	
}
void listele() {
    gecici = ilk;
    if (gecici == NULL) {
        printf("Listenizde eleman bulunmamaktadir...");
    } else {
        while (gecici != NULL) {
            printf("%s %d\n",gecici->isim[0], gecici->fatura);
            gecici = gecici->next;
        }
    }
    printf("\n");
}

	
	
