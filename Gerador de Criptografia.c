#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void pause(){ //função de parada do script em distribuições linux / windows, usando compilação condicional. 
#ifdef __linux__ 
system("read -p \"Pressione qualquer tecla para continuar…\" saindo");
#elif _WIN32
system("pause");
#endif
}
int main(){   
	char nome[50];
  char crypter[50];
  int dicionario[50] = {9,3,4,7,9,5,4,1,8,2,0,1,3,4,4,7,2,9,5,9,0,1,3,6,8,6,1,8,2,0,3,4,5,9,3,5,1,2,8,9,1,1,7,6,8,3,5,2,0,9}; //O dicionario pode ser mudado na preferência do usuário, visando criar criptografias mais sofisticadas;  
  char x;
  setlocale(LC_ALL, ""); //Uso das acentuações no terminal
  printf("Deseja Criptografar(c) ou Descriptografar(d)?: ");
  scanf("%c",&x);

  if(x == 'c'){
    printf("Digite o que deseja criptogafar: ");
    fgets(nome, 49, stdin);//Limpando (a)/(enter) do buffer do teclado 
    fgets(nome, 49, stdin); 
    for(int i = 0; i < strlen(nome) ; i++){
      crypter[i] = nome[i] + dicionario[i+2];//Strings podem ser incrementadas ou decrementadas mudando assim para outro valor na Tabela ASCII
    }
    puts(crypter);

  }
 else if (x == 'd'){
   printf("Digite o que deseja descryptografar: ");
   fgets(crypter, 49, stdin);
   fgets(crypter, 49, stdin);
   for(int i = 0; i < strlen(crypter) ; i++){
      nome[i] = crypter[i] - dicionario[i+2];
    }
    puts(nome);
 }
 else{
      printf("Caractere não aceito\n");
 }
  
  pause();
	return (0);
}

