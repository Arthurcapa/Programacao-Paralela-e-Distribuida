// Compilar: gcc -o reproduz_texto reproduz_texto.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

char *texto;
char *chute;

int cria_palavra_secreta(char *palavra, int tam){
  srand((unsigned)time(NULL));
  for (int i = 0; i < tam-1; i++)
    // sorteia algum caracter visivel, valores ASCII entre 32 e 126
    palavra[i] = 32 + rand() % 94;    
  palavra[tam-1] = '\0';  
}

void thread1(unsigned long tam) {
	unsigned long i;
  	short j;
	for (i = 0; i < tam/8; i++)   {
		for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
       }    
    }	
	}
}

void thread2(unsigned long tam)  {
	unsigned long i;
  	short j;
	for (i = tam/8; i < 2*tam/8; i++) {
		for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
      	 }    
    	}
	}
}

void thread3(unsigned long tam) {
	unsigned long i;
  	short j;
	for (i = 2*tam/8; i < 3*tam/8; i++) {
		for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
       		}    
    	}
	}   
}

void thread4(unsigned long tam)  {
	unsigned long i;
  	short j;
	for (i = 3*tam/8; i < 4*tam/8; i++)  {
		for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
       		}    
    	}	
	} 
}

void thread5(unsigned long tam) {
	unsigned long i;
  	short j;
	for (i = 4*tam/8; i < 5*tam/8; i++)   {
		for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
       }    
    }	
	}
}

void thread6(unsigned long tam)  {
	unsigned long i;
  	short j;
	for (i = 5*tam/8; i < 6*tam/8; i++) {
		for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
      	 }    
    	}
	}
}

void thread7(unsigned long tam) {
	unsigned long i;
  	short j;
	for (i = 6*tam/8; i < 7*tam/8; i++) {
		for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
       		}    
    	}
	}   
}

void thread8(unsigned long tam)  {
	unsigned long i;
  	short j;
	for (i = 7*tam/8; i < tam; i++)  {
		for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
       		}    
    	}	
	} 
}

int main(int argc, char **argv){
  struct timeval t1, t2;
  pthread_t threads[8];
  unsigned long i,tam;
  short j;

  if(argc != 2){
    printf("Favor informar o tamanho da palavra. Por exemplo:\n");
    printf("./reproduz texto 100\n");
    return 0;
  }

  sscanf(argv[1],"%lu",&tam);
  texto = malloc(sizeof(char)*tam); 
  chute = malloc(sizeof(char)*tam);
  cria_palavra_secreta(texto,tam);

 // Procedimento que descobre o texto
  gettimeofday(&t1, NULL);
  chute[tam-1] = '\0';
  pthread_create(&threads[0], NULL, thread1, tam);
  pthread_create(&threads[1], NULL, thread2, tam);
  pthread_create(&threads[2], NULL, thread3, tam);
  pthread_create(&threads[3], NULL, thread4, tam);
  pthread_create(&threads[4], NULL, thread5, tam);
  pthread_create(&threads[5], NULL, thread6, tam);
  pthread_create(&threads[6], NULL, thread7, tam);
  pthread_create(&threads[7], NULL, thread8, tam);
  
  for (int i = 0; i < 8; ++i)
        pthread_join(threads[i], NULL);
  gettimeofday(&t2, NULL);
  printf("Palavra secreta:    %s\n\n",texto);
  printf("Palavra descoberta: %s\n",chute);
  double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);
  printf("Tempo de Execucao: %f\n",t_total);
 
  return 0;
}
