#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int tabloIndex[15][3];//1. indexleri tutar, 2.numaralar, 3.notlar
	int liste[15][2]={
		{18060311,40},
		{20060045,50},
		{19061091,75},
		{20060134,90},
		{20060678,40},
		{18061086,75},
		{20060032,50},
		{20060067,60},
		{19060456,60},
		{18060245,75},
		{20060110,40},
		{20060234,90},
		{20060141,60},
		{20060011,50},
		{20060012,60}
		};
		int i,j,ind,degisenNot,indx;
		for(i=0;i<15;i++){
			int a=liste[i][0];
			int b=liste[i][1];
			ekle(tabloIndex,a,b,i,0,2);
		}
		printf("Tum girdiler islendikten sonra olusan index tablosu \n");
		for(i=0;i<15;i++){
			printf("%d, ",tabloIndex[i][0]);
		}
		printf("\nSilmek istediginiz index numarasini girin : ");
		scanf("%d",&ind);
		sil(tabloIndex,ind);
		for(i=0;i<15;i++){
			for(j=0;j<3;j++){
				printf("%d ",tabloIndex[i][j]);
			}
			printf("\n");
		}
		
		printf("Ders notu degisecek olan ogrencinin index numarasini girin : ");
		scanf("%d",&indx);
		printf("Ogrencinin yeni notunu girin : ");
		scanf("%d",&degisenNot);
		degistir(tabloIndex,degisenNot,indx);
		for(i=0;i<15;i++){
			for(j=0;j<3;j++){
				printf("%d ",tabloIndex[i][j]);
			}
			printf("\n");
		}
		printf("Yazdir fonksiyonu icin Ders Notu girin : ");
		int t;
		scanf("%d",&t);
		printf("%d'den yuksek alan ogrenciler \n",t);
		yazdir(tabloIndex,t);
	return 0;
}
	int ekle(int tabloIndex[15][3],int ogrenciNo,int puan,int indx,int indo,int q){
		int n,d,j;
			if(tabloIndex[0][0]==0 && tabloIndex[0][1]==0){//Burasý ilk elemaný ekleme.
					tabloIndex[0][0]=indx;
					tabloIndex[0][1]=ogrenciNo;	
					tabloIndex[0][2]=puan;		
			}
			else{
				for(n=0;n<=14;n++){
					if(tabloIndex[n][2]<puan){
						for(d=indx;d>n;d--){
							tabloIndex[d][0]=tabloIndex[d-1][0];
							tabloIndex[d][1]=tabloIndex[d-1][1];
							tabloIndex[d][2]=tabloIndex[d-1][2];				
						}	
						if(q==1){
							tabloIndex[n][0]=indo;
						}
						else{
							tabloIndex[n][0]=indx;
						}
					tabloIndex[n][1]=ogrenciNo;	
					tabloIndex[n][2]=puan;	
					break;
				}
					else if(tabloIndex[n][2]==puan){
						if(tabloIndex[n][1]>ogrenciNo){
							for(d=indx;d>n;d--){
								tabloIndex[d][0]=tabloIndex[d-1][0];
								tabloIndex[d][1]=tabloIndex[d-1][1];
								tabloIndex[d][2]=tabloIndex[d-1][2];
							}
							if(q==1){
								tabloIndex[n][0]=indo;
							}
							else{
								tabloIndex[n][0]=indx;
							}
							tabloIndex[n][1]=ogrenciNo;	
							tabloIndex[n][2]=puan;
							break;
						}
						else{
						for(j=n+1;j>0;j++){
							if(puan!=tabloIndex[j][2]){
								for(d=indx;d>=j;d--){
									tabloIndex[d][0]=tabloIndex[d-1][0];
									tabloIndex[d][1]=tabloIndex[d-1][1];
									tabloIndex[d][2]=tabloIndex[d-1][2];
							}
									if(q==1){
										tabloIndex[j][0]=indo;
									}
									else{
										tabloIndex[j][0]=indx;
									}
									tabloIndex[j][1]=ogrenciNo;	
									tabloIndex[j][2]=puan;
							break;
							}
							else{
								if(tabloIndex[j][1]>ogrenciNo){
									for(d=indx;d>=j;d--){
									tabloIndex[d][0]=tabloIndex[d-1][0];
									tabloIndex[d][1]=tabloIndex[d-1][1];
									tabloIndex[d][2]=tabloIndex[d-1][2];
							}
									if(q==1){
										tabloIndex[j][0]=indo;
									}
									else{
										tabloIndex[j][0]=indx;
									}
									tabloIndex[j][1]=ogrenciNo;	
									tabloIndex[j][2]=puan;
									break;
								}
							}
						}
					}
						break;
					}	
						
					else if(tabloIndex[n][1]==0){	
					tabloIndex[n][0]=indx;
					tabloIndex[n][1]=ogrenciNo;	
					tabloIndex[n][2]=puan;	
					break;
					}		
				}
			}
		return tabloIndex[15][3];
	}
	int sil(int tabloIndex[15][3],int ind){
		int j,i;
		for(i=0;i<15;i++){
			if(tabloIndex[i][0]==ind){
				for(j=i;j<14;j++){
					tabloIndex[j][0]=tabloIndex[j+1][0];
					tabloIndex[j][1]=tabloIndex[j+1][1];
					tabloIndex[j][2]=tabloIndex[j+1][2];
					}
					tabloIndex[j][0]=0;
					tabloIndex[j][1]=0;
					tabloIndex[j][2]=0;
				break;
			}
		}
		return tabloIndex[15][3];
	}
	int degistir(int tabloIndex[15][3],int degisenNot,int indx){
		int i,ogrenciNo,puan,indo;
		for(i=0;i<15;i++){
			if(tabloIndex[i][0]==indx){
				ogrenciNo=tabloIndex[i][1];
				puan=degisenNot;
				indo=tabloIndex[i][0];
				break;
			}
		}
		sil(tabloIndex,indx);
		ekle(tabloIndex,ogrenciNo,puan,14,indo,1);
		return tabloIndex[15][3];
	}
	int yazdir(int tabloIndex[15][3],int notum){
		int i,a;
			for(i=0;i<15;i++){
				if(tabloIndex[i][2]<=notum){
					for(a=0;a<i-1;a++){
						printf("%d-%d-%d \n",tabloIndex[a][0],tabloIndex[a][1],tabloIndex[a][2]);
					}
					break;
				}
			}
	}
