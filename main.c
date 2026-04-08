#include <stdio.h>
#include <stdlib.h> 
#define bool int

int palindromo(char* texto, int n){
  int i;
  int j = n/2; //número de checagens (cmd for) de pares iguais de um palíndromo
  int x = 0;

  for(i=0; i<j; i++){
    if(texto[i] == texto[n-1-i]) x++;
  }
  if(x==j) return 1;
  return 0;
}

int contagem(char* texto){
  int i = 0;
  int n = 0;
  while(texto[i]!='\0'){
    n++;
    i++;
  }
  return n;
}

char* criaTexto(){
  int i = 0;
  int capacidade = 5;
  int tamanho = 0; //iremos alterar essa variável para encontrar o tamanho da string,iniciando no zero
  char* buffer = malloc(sizeof(char) * capacidade); //aloca inicialmente memória p/5 chars, alocando mais conforme o tamanho
  char c; //caracter à ser lido (input)

  while((c = getchar()) != '\n' && c != EOF){ //EOF indica fim do programa
    buffer[tamanho] = c; 
    tamanho++;

    if(tamanho >= capacidade - 1){ //verifica se haverá espaço para mais uma atribuição no array
      capacidade *= 2;             //caso não houver, aumenta a capacidade do buffer pelo realloc
      char* novo = realloc(buffer, sizeof(char) * capacidade);
      buffer = novo;
    }
  }

  buffer[tamanho] = '\0'; //atribui o ultimo elemento do buffer como final de string
  
    char* final = realloc(buffer, (tamanho + 1) * sizeof(char)); // realoca para o tamanho exato (opcional)
    return final;
}


int main(){
  char* texto;
  int n; //quantidade de caracteres
  bool pal; // pal = 0 -> não é palíndromo ; pal = 1 -> é palíndromo

  printf("Esse programa identifica palíndromos.\n");

  while (1==1){
    printf("Insira uma palavra à ser identificada ou 0 (zero) para sair do programa:\n");
    texto = criaTexto();
    if(texto[0] == '0' && texto[1] == '\0'){ 
      printf("Encerrando o programa.");
      break;
      }
    n = contagem(texto);

    pal = palindromo(texto, n);
    if(pal == 1) printf("Palíndromo!\n");
    else printf("Não é um palíndromo :(\n");
  }

  return 0;
}
