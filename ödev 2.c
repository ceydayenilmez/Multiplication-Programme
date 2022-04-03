#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

struct  soru
{
	int sayi1 = 0;
	int sayi2 = 0;
	int sonuc = 0;
	bool cevap_dogru = false;
};


int main()
{

	char dogru_cevaplar  [4] [20] = {"Cok guzel", "Mukemmel", "Aferin","Boyle Devam Et"};
	char yanlis_cevaplar [4] [40] = {"Hayir. Lutfen tekrar deneyin","Yanlis. Lutfen bir daha deneyin","Pes etmeyin","Hayir. Denemeye devam edin"};
    soru ogrsoru [100];
	
	srand(time(NULL)); 
	
	int max_soru = 10;
	int min_soru = 0;
	int i;
	bool tekrar = false;
	
	do {
	
		for (i = min_soru; i < max_soru; i++) {
			ogrsoru[i].sayi1=rand()%9;
			ogrsoru[i].sayi2=rand()%9;
			
			printf("%d kere %d kactir?\n", ogrsoru[i].sayi1, ogrsoru[i].sayi2);
			
			scanf("%d", &ogrsoru[i].sonuc);
			
			int cevap = rand()%3;
	
			if (ogrsoru[i].sonuc == ogrsoru[i].sayi1 * ogrsoru[i].sayi2){
				printf("%s\n", dogru_cevaplar[cevap]);
				ogrsoru[i].cevap_dogru = true;
			}
			else {
				printf("%s\n", yanlis_cevaplar[cevap]);
				ogrsoru[i].cevap_dogru = false;	
			}
		}
		
		int dogru_cevap_sayi = 0;
		for (i = 0; i < max_soru; i++) {
			if (ogrsoru[i].cevap_dogru){
				dogru_cevap_sayi = dogru_cevap_sayi + 1; 
			}	
		}
			
		float puan = dogru_cevap_sayi * 100 / max_soru;	
		if (puan < 75){
			printf("Uzulme ve carpim tablosunu bir daha calis.");
		}
		else {
			if (puan < 85){
				tekrar = true;
				max_soru = max_soru + 10;
				min_soru = min_soru + 10;
			}
			else {
				printf("Aferin basardin!");
			}
		}
	
	} while ( tekrar );
	
	
	for (i = 0; i < max_soru; i++) {
		printf("%d kere %d kactir?		%d 		%d\n", ogrsoru[i].sayi1, ogrsoru[i].sayi2, ogrsoru[i].sonuc, ogrsoru[i].sayi1 * ogrsoru[i].sayi2);	
	}
    return 0;
}
