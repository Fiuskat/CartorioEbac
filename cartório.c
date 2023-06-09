#include <stdio.h>         // Biblioteca de comunica��o com o usuario
#include <stdlib.h>        // Biblioteca de aloca��o de espa�o em memoria
#include <locale.h>        // Biblioteca de aloca��ode texto por regi�o
#include <string.h>        // Biblioteca responsavel pelas strings
 
 int registro() // fun��o resposn�vel por cadastrar os nomes no sistema

 {
// Cria��o de vari�veis/strings
 	
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  
// Final da Cria��o de vari�veis/strings
  
  printf("Digite o CPF a ser cadastrado: "); // Coletando informa��es do usuario
  scanf("%s", cpf); // %s refere se a strings

  strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings

  FILE *file; // Cria o arquivo
  file = fopen(arquivo, "w"); // Cria o arquivo

  if (file == NULL) {
    printf("Erro ao criar arquivo!\n");
    system("pause");
    return;
  }

  fprintf(file, "%s", cpf);
  fclose(file);

  file = fopen(arquivo, "a");

  printf("Digite o nome a ser cadastrado: ");
  scanf("%s", nome);

  fprintf(file, ",%s", nome);

  printf("Digite o sobrenome a ser cadastrado: ");
  scanf("%s", sobrenome);

  fprintf(file, ",%s", sobrenome);

  printf("Digite o cargo a ser cadastrado: ");
  scanf("%s", cargo);

  fprintf(file, ",%s", cargo);

  fclose(file);

  printf("Cadastro realizado com sucesso!\n");
  system("pause");
}

 consulta() {
  char cpf[40];
  char arquivo[40];
  char conteudo[200];

  printf("Digite o CPF a ser consultado: ");
  scanf("%s", cpf);

  strcpy(arquivo, cpf);

  FILE *file;
  file = fopen(arquivo, "r");

  if (file == NULL) {
    printf("Arquivo n�o encontrado!\n");
    system("pause");
    return;
  }

  printf("\nEssas s�o as informa��es do usu�rio:\n");

  while (fgets(conteudo, 200, file) != NULL) {
    printf("%s", conteudo);
  }

  printf("\n");
  fclose(file);

  system("pause");
}

 deletar() {
  char cpf[40];
  char arquivo[40];

  printf("Digite o CPF a ser deletado: ");
  scanf("%s", cpf);

  strcpy(arquivo, cpf);

  int status = remove(arquivo);
  


  if (status == 0) {
    printf("Arquivo deletado com sucesso!\n");
  } else {
    printf("Us�ario n�o se encontra no sistema!\n");
  }

  system("pause");
}

int main() {
  int opcao = 0;
  int laco = 1;

  while (laco == 1) {
    system("cls");
    setlocale(LC_ALL, "PORTUGUESE"); // Definindo linguagem
    printf("### Cart�rio da EBAC ###\n\n");
    printf("Escolha a op��o desejada do menu:\n\n");
    printf("\t1 - Registrar nomes\n");
    printf("\t2 - Consultar nomes\n");
    printf("\t3 - Deletar nomes\n");
    printf("\t4 - Sair do programa\n\n");
    printf("Op��o: ");

    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        registro();
        break;

      case 2:
        consulta();
        break;

      case 3:
        deletar();
        break;

      case 4:
        laco = 0;
        break;

      default:
        printf("Essa op��o n�o est� dispon�vel!\n");
        system("pause");
        break;
    }
  } 
   } 
