#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da crianção de variável/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário 
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
		printf("Não foi possivel abrir o arquivo, não localizado!! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informamações do usuário: ");
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
    	printf("O usuário não se encontra no sistema!\n");
    	system("pause");
	}
    
}

int main()
{
	int opcao=0; //Definindo variáveis
	int x=1; //Definindo variável do FOR
	
	for(x=1;x=1;) // deixando a rep. infinita
	{
	
       system("cls"); //Limpando tela
	
	   setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	   printf("======== Cartório da EBAC ========\n\n"); //Início do menu
 	   printf("Escolha a opção desejada do menu :\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Escolha sua opção: "); //Final do menu
	
	   scanf("%d", &opcao); //Aremazenando a escolha do usuário
	
	   system("cls");//responsavel por limpar a tela 
	   
	   switch(opcao) // começando a rep com switch
	   {
	   	  case 1:
	   	  registro();//chamada de funções
		  break;
		  
		  case 2:
          consulta();//chamada de funções
		  break;
		  
		  case 3:
          deletar();//chamada de funções
	  	  break;
	  	  
	  	  default:
	  	  printf("Não bobo!! Essa opção não existe\n");
		  system("pause");
		  break;
	   }
    }
}
//printf("Se quiser usar meu código tem que pedir ;-;\n");
