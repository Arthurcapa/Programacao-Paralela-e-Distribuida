// Compilar: gcc -o reproduz_texto reproduz_texto.c

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
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

int main(int argc, char **argv){
  struct timeval t1, t2;
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
  for (i = 0; i < tam; i++)    
    for (j = 0; j < 255; j++){
    chute[i]=j;
       if(chute[i] == texto[i]){
         j=0;
         break;
       }    
    }
  gettimeofday(&t2, NULL);
  printf("Palavra secreta:    %s\n\n",texto);
  printf("Palavra descoberta: %s\n",chute);
  double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);
  printf("Tempo de Execucao: %f\n",t_total);
 
  return 0;
}


