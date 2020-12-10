#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

int main(){

	char nazwa_pliku[64];
	char text_path[] = "./wiadomosc2.txt";
	int plik_1;
	int plik_2;
	struct stat status_pliku;
	struct stat status_pliku2;
	void *addr = NULL;
	
	
		while(1){
			printf("Podaj nazwę pliku : ");
			scanf("%s",nazwa_pliku);
			plik_1 = open(nazwa_pliku, O_RDONLY);
			while(plik_1 < 0){
				printf("Nie otwarto pliku\n");
				printf("Podaj nową nazwę pliku:\t");
				scanf("%s",nazwa_pliku);
				plik_1 = open(nazwa_pliku, O_RDONLY);
			}
			printf("\n");
			stat(nazwa_pliku, &status_pliku);
			stat(text_path, &status_pliku2);
			printf("Rozmiar pliku przem mapowaniem %ld \n", status_pliku2.st_size);
			plik_2 = open(text_path, O_RDWR);
			truncate(text_path,status_pliku.st_size + status_pliku2.st_size );
			stat(text_path, &status_pliku2);
			printf("Rozmiar pliku po mapowaniu %ld \n", status_pliku2.st_size);
			addr = mmap(NULL, status_pliku.st_size,PROT_WRITE | PROT_READ, MAP_SHARED, plik_2, 0);
			read(plik_1, addr, status_pliku.st_size);
			msync(addr, status_pliku.st_size,MS_SYNC);
			close(plik_1);
			close(plik_2);
		}

	munmap(addr, status_pliku.st_size);
	return 0;
}
