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
  int dic[50];  
  char x;
  setlocale(LC_ALL, ""); //Uso das acentuações no terminal
  printf("Deseja Criptografar(c) ou Descriptografar(d)?: ");
  while(x != 'c' && x != 'd'){
       scanf("%c",&x);
       if( x!= 'c' && x!= 'd')
       printf("Caractere não aceito\n");
  }
 

  if(x == 'c'){
    printf("Ja tem um dicionario?\n Sim(s), Nao(n)?\n");
    scanf("%c",&x);
    while(x != 's' && x != 'n'){
        scanf("%c",&x);
        if( x!= 's' && x!= 'n')
          printf("Caractere não aceito\n");
    }
    if(x == 's'){
      FILE *dictionary;
      dictionary = fopen("dictionary.txt", "a");
      for(int i = 0 ; i < 50; i++){
        fscanf(dictionary, "%d", &dic[i]);
      }
    }
    if(x == 'n'){
      FILE *dictionary;
      dictionary = fopen("dictionary.txt", "a");
      for(int i = 0; i < 50; i++){
        dic[i] = rand() % 9;
        fprintf(dictionary, "%d\n",dic[i]);
      }
      fclose(dictionary);
    }
    printf("\nDigite o que deseja criptogafar: \n");
    fgets(nome, 49, stdin);//Limpando (a)/(enter) do buffer do teclado 
    fgets(nome, 49, stdin); 
    for(int i = 0; i < strlen(nome) ; i++){
      crypter[i] = nome[i] + dic[i];//Strings podem ser incrementadas ou decrementadas mudando assim para outro valor na Tabela ASCII
    }
    puts(crypter);

  }
 else if (x == 'd'){
   FILE *dictionary;
   dictionary = fopen("dictionary.txt", "r");
   if(dictionary == NULL){
   printf("Você não tem um dicionário, impossivél descriptografar");}
   else{
   for(int i = 0 ; i < 50; i++){
        fscanf(dictionary, "%d", &dic[i]);
      }
    }
   printf("Digite o que deseja descryptografar: ");
   fgets(crypter, 49, stdin);
   fgets(crypter, 49, stdin);
   for(int i = 0; i < strlen(crypter) ; i++){
      nome[i] = crypter[i] - dic[i];
    }
    puts(nome);
 }
 
  
  pause();
	return (0);
}
