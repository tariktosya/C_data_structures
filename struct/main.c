#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct etler{
	int a;
	char adi[20];
	int tlmaliyet;
	char kategori;
	char tr[2];
	char pakettarih[11];
	char sontarih[11];
}et;
struct tarimurunleri{
	int a;
	char adi[20];
	int tlmaliyet;
	char kategori;
	char tr[2];
	char tarih[10];
}tarimurun;
struct suturunu{
	int a;
	char adi[20];
	int tlmaliyet;
	char kategori;
	char tarih[10];
}sut;
struct konserveurunleri{
	int a;
	char adi[20];
	int tlmaliyet;
	char kategori;
	char tarih[8];
	int reyonno;
	char reyontarafi[2];
}konserve;
struct gidadisi{
	int a;
	char adi[20];
	int tlmaliyet;
	char kategori;
	char tr[2];
	int reyonno;
	char reyontarafi[2];
}gidadis;
char kategori;
void urun_kaydet(){
	printf("Ürün Kategorisini Seciniz (E,T,S,K,G) -> ");
	kategori='\0';
	scanf("%s",&kategori);
	switch(kategori){
		case 'E' :{
			et.a=1;
			et.kategori='E';
			printf("Ürün adini giriniz -> ");
			scanf("%s",&et.adi);
			printf("Ürünün tl cinsinden birim maliyetini giriniz -> ");
			scanf("%d",&et.tlmaliyet);
			printf("Et trünü giriniz (R,B,P) -> ");
			scanf("%s",&et.tr);
			printf("Paketlenme tarihini giriniz (#-#-#) ->");
			scanf("%s",&et.pakettarih);
			printf("Son kullanma tarihini girini (#-#-#) ->");
			scanf("%s",&et.sontarih);
			break;
		}
		case 'T':{
			tarimurun.a=1;
			tarimurun.kategori='T';
			printf("Ürün adini giriniz -> ");
			scanf("%s",&tarimurun.adi);
			printf("Ürünün tl cinsinden birim maliyetini giriniz -> ");
			scanf("%d",&tarimurun.tlmaliyet);
			printf("Tarim türünü girin (M,S) ->");
			scanf("%S",&tarimurun.tr);
			printf("Alinma tarihini girin (#-#-#) ->");
			scanf("%s",&tarimurun.tarih);
			break;
		}
		case 'S':{
			sut.a=1;
			sut.kategori='S';
			printf("Ürün adini giriniz -> ");
			scanf("%s",&sut.adi);
			printf("Ürünün tl cinsinden birim maliyetini giriniz -> ");
			scanf("%d",&sut.tlmaliyet);
			printf("Son kullanma tarihini girin (#-#-#) ->");
			scanf("%s",&sut.tarih);
			break;
		}
		case 'K':{
			konserve.a=1;
			konserve.kategori='K';
			printf("Ürün adini giriniz -> ");
			scanf("%s",&konserve.adi);
			printf("Ürünün tl cinsinden birim maliyetini giriniz -> ");
			scanf("%d",&konserve.tlmaliyet);
			printf("Ürünün son kullanma tarihini yalnýzca ay ve yil olarak (#-#) -> ");
			scanf("%s",&konserve.tarih);
			printf("Ürünün reyon numarasini girin -> ");
			scanf("%d",&konserve.reyonno);
			printf("Ürünün bulundugu reyon tarafi (A,B) ->");
			scanf("%s",&konserve.reyontarafi);
			break;
		}
		case('G'):{
			gidadis.a=1;
			gidadis.kategori='G';
			printf("Ürün adini giriniz -> ");
			scanf("%s",&gidadis.adi);
			printf("Ürünün tl cinsinden birim maliyetini giriniz -> ");
			scanf("%d",&gidadis.tlmaliyet);
			printf("Ürünün trü (C,P,D) -> ");
			scanf("%s",&gidadis.tr);
			printf("Ürünün reyon numarasi -> ");
			scanf("%d",&gidadis.reyonno);
			printf("Ürünün bulundugu reyon tarafi (A,B) -> ");
			scanf("%s",&gidadis.reyontarafi);
			break;
		}
	}
}
void urun_goster(char kontrol){
	if(kontrol=='E'){
		printf("%s  %dTL  %c  %s  %s  %s\n", et.adi, et.tlmaliyet, et.kategori, et.tr, et.pakettarih, et.sontarih);
	}
	if(kontrol=='T'){
		printf("%s  %dTL  %c  %s  %s\n", tarimurun.adi, tarimurun.tlmaliyet, tarimurun.kategori, tarimurun.tr, tarimurun.tarih);
	}
	if(kontrol=='S'){
		printf("%s  %dTL  %c  %s\n", sut.adi, sut.tlmaliyet, sut.kategori, sut.tarih);
	}
	if(kontrol=='K'){
		printf("%s  %dTL  %c  %s  %d  %s\n", konserve.adi, konserve.tlmaliyet, konserve.kategori, konserve.tarih, konserve.reyonno, konserve.reyontarafi);
	}
	if(kontrol=='G'){
		printf("%s  %dTL  %c  %s  %d  %s\n", gidadis.adi, gidadis.tlmaliyet, gidadis.kategori, gidadis.tr, gidadis.reyonno, gidadis.reyontarafi);
	}
}
int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "turkish");
	char kontrol1,kontrol2;
	printf("-----TEST-----\n");
	sut.adi[0]='P'; sut.adi[1]='e'; sut.adi[2]='y'; sut.adi[3]='n'; sut.adi[4]='i'; sut.adi[5]='r';
	sut.tlmaliyet=45;
	sut.kategori='S';
	sut.tarih[0]='0'; sut.tarih[1]='9'; sut.tarih[2]='-'; sut.tarih[3]='1'; sut.tarih[4]='2'; sut.tarih[5]='-'; sut.tarih[6]='2'; sut.tarih[7]='0'; sut.tarih[8]='2'; sut.tarih[9]='0'; ; 
	kontrol1='S';
	
	konserve.adi[0]='F'; konserve.adi[1]='a'; konserve.adi[2]='s'; konserve.adi[3]='ü'; konserve.adi[4]='l'; konserve.adi[5]='y'; konserve.adi[6]='e';
	konserve.tlmaliyet=25;
	konserve.kategori='K';
	konserve.tarih[0]='1'; konserve.tarih[1]='2'; konserve.tarih[2]='-'; konserve.tarih[3]='2'; konserve.tarih[4]='0'; konserve.tarih[5]='2'; konserve.tarih[6]='0';
	konserve.reyonno=12;
	konserve.reyontarafi[0]=('A');
	kontrol2='K';
	urun_goster(kontrol1);
	urun_goster(kontrol2);
	
	printf("---1. urun bilgileri---\n");
	urun_kaydet();
	kontrol1=kategori;
	printf("---2. urun bilgileri---\n");
	urun_kaydet();
	kontrol2=kategori;
	printf("----------Kayýtlý Ürünler----------\n");
	urun_goster(kontrol1);
	urun_goster(kontrol2);
	return 0;
}
