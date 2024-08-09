#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

    int registro() //Função responsavel por cadastrar os usuários no sistema
   {
        //inicio da criação de variáveis/string 	
        char arquivo[40];
		char cpf[40];
      	char nome[40];
      	char sobrenome[40];
      	char cargo[40];
      	//final da criação de variáveis/string
      	
        printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
        scanf("%s", cpf); //%s refere-se a string   Essencialmente, %s serve como um espaço reservado que será substituído pela string fornecida
        
        strcpy(arquivo, cpf); //Responsável por copiar os valores das string
      	
      	FILE *file; //Cria o arquivo
      	file = fopen(arquivo, "w"); // cria o arquivo e o w significa escrever                 //fopen é a função que abre o arquivo
      	fprintf(file,cpf); //salva o valor na variavel
      	fclose(file); //fecha o arquivo
      	
      	file = fopen(arquivo, "a");    // "a" significa append(acrescentar)
      	fprintf(file,",");
      	fclose(file);
      	
      	printf("Digite o nome a ser cadastrado: ");
      	scanf("%s",nome);
      	
      	file = fopen(arquivo, "a");  // "a" significa append(acrescentar)
      	fprintf(file,nome); // fprintf funciona de maneira semelhante a printf, mas em vez de escrever na tela, ela escreve em um arquivo.
      	fclose(file);
      	
      	file = fopen(arquivo, "a"); // "a" significa append(acrescentar)
      	fprintf(file,","); //",": Esta é a string que você está escrevendo no arquivo. No caso, você está escrevendo apenas uma vírgula.
      	fclose(file);
      	
      	printf("Digite o sobrenome a ser cadastrado: ");
      	scanf("%s",sobrenome);
      	
      	file = fopen(arquivo, "a"); // "a" significa append(acrescentar)
      	fprintf(file,sobrenome);
      	fclose(file);
      	
      	file = fopen(arquivo, "a"); // "a" significa append(acrescentar)
      	fprintf(file,",");
      	fclose(file);
      	
      	printf("Digite o cargo a ser cadastrado: ");
      	scanf("%s",cargo);
      	
      	file = fopen(arquivo, "a"); // "a" significa append(acrescentar)
      	fprintf(file,cargo);
      	fclose(file);
      	
      	system("pause");
      	
      	
      	
      	
   }

    int consulta()
   {
     	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   	
    	char cpf[40];
    	char conteudo[200];
    	
    	printf("Digite o CPF a ser consultado: "); //coletando informações do usuário
    	scanf("%s",cpf); // %s serve como um espaço reservado que será substituído pela string fornecida
    	
    	FILE *file;
    	file = fopen(cpf,"r");
    	
    	if(file == NULL)
    	{
    		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
		}
		
		while(fgets(conteudo, 200, file) !=NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo); //%s serve como um espaço reservado que será substituído pela string fornecida
			printf("\n\n");
		}
    	
    	system("pause"); // serve para pausar a execução do programa até que o usuário pressione uma tecla
   }

    int deletar()
   {
    	char cpf[40];
    	
    	printf("Digite o CPF do usuário a ser deletado: ");
    	scanf("%s",cpf); //%s serve como um espaço reservado que será substituído pela string fornecida
    	
    	remove(cpf);
    	
    	FILE *file;
    	file = fopen(cpf, "r");                 //"r" significa read (ler) o arquivo vai ser aberto para leitura 
    	
    	if(file == NULL)                      // se o arquivo não existir....a função fopen retornará como NULL
    {
    	printf("O usuário não se encontra no sistema!. \n");
    	system("pause");
	}
    	
   }

int main()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	     system("cls"); // responsavel por limpar a tela
	
	     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	     printf("###Cartório da EBAC### \n\n"); //Início do menu
	     printf("Escolha a opção desejada no menu:\n\n");
	     printf("\t1 - Registrar nomes \n");  // \t cria um espaçamento
	     printf("\t2 - Consultar nomes \n");  // \n pula linha
	     printf("\t3 - Deletar nomes \n\n\n"); 
	     printf("\t4 - Sair do sistema\n\n");
	     printf("Opção: "); //Fim do menu

         scanf("%d",&opcao); // Armazenando a escolha do usuário
    
         system("cls"); //Responsável por limpar a tela
           
         switch(opcao)// inicio da seleção do menu
        {
           case 1:
           registro();// chamada de funções
	       break;
	       
	       case 2:
	       consulta();// chamada de funções
           break;
           
           case 3:
		   deletar();// chamada de funções
	       break;
	       
	       case 4:
	       	printf("Obrigado por utilizar o sistema\n");
	       	return 0;
	       	break;
	       
	       default:
	       	printf("Essa opção não está disponível!\n");
           system("pause");
           break;
	       	
		}
    
    
    }
}
