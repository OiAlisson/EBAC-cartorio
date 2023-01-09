#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da crian��o de vari�vel/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio 
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w");//Cria o arquivo e o "w" = escrever
	fprintf(file,cpf);//Salvo o valor da variavel
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobre nome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
    char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informama��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema!\n");
    	system("pause");
	}
    
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int x=1; //Definindo vari�vel do FOR
	
	for(x=1;x=1;) // deixando a rep. infinita
	{
	
       system("cls"); //Limpando tela
	
	   setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	   printf("======== Cart�rio da EBAC ========\n\n"); //In�cio do menu
 	   printf("Escolha a op��o desejada do menu :\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Escolha sua op��o: "); //Final do menu
	
	   scanf("%d", &opcao); //Aremazenando a escolha do usu�rio
	
	   system("cls");//responsavel por limpar a tela 
	   
	   switch(opcao) // come�ando a rep com switch
	   {
	   	  case 1:
	   	  registro();//chamada de fun��es
		  break;
		  
		  case 2:
          consulta();//chamada de fun��es
		  break;
		  
		  case 3:
          deletar();//chamada de fun��es
	  	  break;
	  	  
	  	  case 4:
	  	  printf("Obrigado por utilizar o sistema!\n");
	  	  return 0;
	  	  break;
	  	  
	  	  default:
	  	  printf("N�o bobo!! Essa op��o n�o existe\n");
		  system("pause");
		  break;
	   }
    }
}
//printf("Se quiser usar meu c�digo tem que pedir ;-;\n");
