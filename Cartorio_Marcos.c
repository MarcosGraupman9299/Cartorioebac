#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

    int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
   {
        //inicio da cria��o de vari�veis/string 	
        char arquivo[40];
		char cpf[40];
      	char nome[40];
      	char sobrenome[40];
      	char cargo[40];
      	//final da cria��o de vari�veis/string
      	
        printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
        scanf("%s", cpf); //%s refere-se a string   Essencialmente, %s serve como um espa�o reservado que ser� substitu�do pela string fornecida
        
        strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
      	
      	FILE *file; //Cria o arquivo
      	file = fopen(arquivo, "w"); // cria o arquivo e o w significa escrever                 //fopen � a fun��o que abre o arquivo
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
      	fprintf(file,","); //",": Esta � a string que voc� est� escrevendo no arquivo. No caso, voc� est� escrevendo apenas uma v�rgula.
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
    	
    	printf("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio
    	scanf("%s",cpf); // %s serve como um espa�o reservado que ser� substitu�do pela string fornecida
    	
    	FILE *file;
    	file = fopen(cpf,"r");
    	
    	if(file == NULL)
    	{
    		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
		}
		
		while(fgets(conteudo, 200, file) !=NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo); //%s serve como um espa�o reservado que ser� substitu�do pela string fornecida
			printf("\n\n");
		}
    	
    	system("pause"); // serve para pausar a execu��o do programa at� que o usu�rio pressione uma tecla
   }

    int deletar()
   {
    	char cpf[40];
    	
    	printf("Digite o CPF do usu�rio a ser deletado: ");
    	scanf("%s",cpf); //%s serve como um espa�o reservado que ser� substitu�do pela string fornecida
    	
    	remove(cpf);
    	
    	FILE *file;
    	file = fopen(cpf, "r");                 //"r" significa read (ler) o arquivo vai ser aberto para leitura 
    	
    	if(file == NULL)                      // se o arquivo n�o existir....a fun��o fopen retornar� como NULL
    {
    	printf("O usu�rio n�o se encontra no sistema!. \n");
    	system("pause");
	}
    	
   }

int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	     system("cls"); // responsavel por limpar a tela
	
	     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	     printf("###Cart�rio da EBAC### \n\n"); //In�cio do menu
	     printf("Escolha a op��o desejada no menu:\n\n");
	     printf("\t1 - Registrar nomes \n");  // \t cria um espa�amento
	     printf("\t2 - Consultar nomes \n");  // \n pula linha
	     printf("\t3 - Deletar nomes \n\n\n"); 
	     printf("\t4 - Sair do sistema\n\n");
	     printf("Op��o: "); //Fim do menu

         scanf("%d",&opcao); // Armazenando a escolha do usu�rio
    
         system("cls"); //Respons�vel por limpar a tela
           
         switch(opcao)// inicio da sele��o do menu
        {
           case 1:
           registro();// chamada de fun��es
	       break;
	       
	       case 2:
	       consulta();// chamada de fun��es
           break;
           
           case 3:
		   deletar();// chamada de fun��es
	       break;
	       
	       case 4:
	       	printf("Obrigado por utilizar o sistema\n");
	       	return 0;
	       	break;
	       
	       default:
	       	printf("Essa op��o n�o est� dispon�vel!\n");
           system("pause");
           break;
	       	
		}
    
    
    }
}
