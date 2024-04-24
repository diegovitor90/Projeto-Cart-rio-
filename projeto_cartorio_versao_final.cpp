#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar da string



int registro() //fun��o para regitro de usu�rrio
{
	//in�cio de regsitro de us�rio
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de registro de usu�rio
	
	printf("Digite o seu CPF a ser cadastrado: "); //solicitando o input do us�rio
	scanf("%s", cpf); //%s refere-se aos valores da string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	FILE *file; //direcionando para o arquivo file 
	file = fopen(arquivo, "w"); //abrindo e escrevendo a string arquivo 
	fprintf(file,cpf); //colocando o CPF no banco de dados 
	fclose(file); //fechando o arquivo file 
	
	file = fopen(arquivo, "a"); //abrindo para armazenando na variav�l a 
	fprintf(file, ",");//colcando a virgula na vari�vel a  
	fclose(file); //fechando o arquivo
	
	printf("Digite o nome a ser cadastrado:\n"); //solicitando o input do usu�rio
	scanf("%s", nome); //%s refere-se aos valores da string
	
	file = fopen(arquivo, "a"); //abrindo para armazenamento na vari�vel a 
	fprintf(file,nome);//colacando o nome no banco de dados
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo para armazenamento na vari�vel a 
	fprintf(file, ","); //colocando a v�rgula na vari�vel a 
	fclose(file);//fechando o arquivo
	 	
	printf("Digite o sobrenome a ser cadastrado:\n"); //solicitando o input do usu�rio
	scanf("%s", sobrenome); //colcando o sobrenome no banco de dados
	
	file = fopen(arquivo, "a"); //abrindo para armazenamento na vari�vel a
	fprintf(file,sobrenome); //colocando o sobrenome na vari�vel a 
	fclose(file);//fechando o arquivo
		
	file = fopen(arquivo, "a"); //abrindo para armazenamento na vari�vel a 
	fprintf(file, ","); //colcando a v�rgula na vari�vel a 
	fclose(file);//fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado:\n"); //solicitando input do usu�rio
	scanf("%s", cargo); //colocando o cargo no banco de dados
	
	file = fopen(arquivo, "a"); //abrindo para armazenamento na vari�vel a 
	fprintf(file,cargo); //colocando cargo na vari�vel na cargo
	fclose(file); //fechando o arquivo file
	
	system("pause");  //pausa na tela para o usu�rio fazer a leitura 
	
	system("cls"); //comando para apagar as informa��es da tela	
}

int consulta() //fun��o para cosulta do ursu�rio
{
	setlocale(LC_ALL, "Portuguese");  //configurando o idioma

	//in�cio de consulta do usu�rio 
	char cpf[40];
	char conteudo[200];
	//fim de consulta do usu�rio
	
	printf("Digite o CPF a ser consultado: "); //solicitando input de usu�rios
	scanf("%s", cpf); // %s refere-se aos valores da string  e o par�mentro aqui usado � CPF por ser um valor �nico de cada usu�rio 
	
	FILE *file;
	file = fopen ( cpf, "r"); //abrindo e fazendo a leitura da string
	
	if(file == NULL)//condi��o para caso o CPF do usu�rio seja nulo
	{
	  printf("N�o foi poss�vel abrir o arquivo, n�o localizado!");	//output para usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //condi��o para CPF seja v�lido e mostrar as informa��es do usu�rio
	{
		printf("Essas s�o as informa��es do usu�rio: "); //solicitando input de usu�rios
	    printf("%s", conteudo);//%s refere-se aos valores armazenado na string
	    printf("\n\n");//output de informa��es para usu�rio
	}

	fclose(file); //fechando o arquivo file
	system("pause"); //pausa na tela para o usu�rio fazer a leitura
	
	system("cls"); //comando para apagar as informa��es da tela

}

int deleta()
{
	setlocale(LC_ALL, "Portuguese");  //configurando o idioma
	
	char cpf[40];//o par�metro utilizado tamb�m vai sr o cpf
	
	printf("Qual CPF voc� quer deletar? "); //coletando o dado para a fun��o	
	scanf("%s", cpf);//salvando o valor da string
	
	FILE *file;//fazendo a valida��o se o usu�rio n�o estiver no sistema  
	file = fopen (cpf, "r"); // leitura do cpf digitado
	
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n"); //output para o usu�rio
	}
	
	while(fgets(cpf, 40, file) !=NULL ) //condi��o de remo��o do CPF caso ele esteja no banco de dados
	{
	remove(cpf);//comando para deletar 
	printf("Usu�rio removido com sucesso!\n\n");//output para usu�rio
	fclose(file); //fechando o arquivo file
	}
	
	system("pause");  //pausa na tela para o usu�rio fazer a leitura
	
	system("cls"); //comando para apagar as informa��es da tela
	
}

int main()
{
	    int opcao=0; //amarzenando a vari�vel
	    int laco=1; //declarando a variav�l la�o
	    char senhadigitada[]="a"; //iniciando a senha
	    int comparacao;
	    setlocale(LC_ALL, "Portuguese");  //configurando o idioma
	    
		printf("\t - Cart�rio da EBAC - \n\n"); //in�cio do menu
	    printf("\t - Login de Administrador - \n\n Digite sua senha:\n\n"); //solicitar senha pra admin
	    scanf("%s", senhadigitada);
	    
	    comparacao = strcmp(senhadigitada,"admin"); //comparando a senha digitada com texto amarzenado
	    
	    if(senhadigitada[10] == 0)//true: acesso para o sistema
		{ 
	    system("cls"); //comando para apagar as informa��es da tela
		 for (laco=1;laco=1;) //In�cio da sele��o com la�o
		  {
			setlocale(LC_ALL, "Portuguese");  //configurando o idioma
			
			printf("\t - Cart�rio da EBAC - \n\n"); //in�cio do menu
			printf(" Ol�, Somos a EBAC - Escola Brit�nica de Artes Criativas, estamos aqui pra te atender! \n");
			printf("\t Selecione umas das op��es abaixo para: \n\n");
			printf("\t 1. Cadastrar - � o seu primeiro contato? \n\n");
			printf("\t 2. Consultar - J� possui cadastro? \n\n");
			printf("\t 3. Deletar - Est� saindo do curso? \n\n");
			printf("\t 4. Sair do sistema\n\n");
			printf("Op��o:");
			 //fim do menu
			
			scanf("%d", &opcao); //armazenando a escolha do usu�rio 
			
			system("cls"); //comando para apagar as informa��es da tela
		
			//comando para chamar as fun��es 
			switch(opcao) 
		    { case 1:
		           registro();
		           break;
		           
		      case 2:
		           consulta();
		           break;
		           
		      case 3:
		           deleta();
		           break;
		           
		      case 4:
		      	  printf("Obrigado por utilizar o sistema! ");
		      	  return 0;
		      	  break;
				    
		      default:
		           printf("Voc� digitou op��o inv�lida\n");
		           system("pause");
		           break; 
		           
		    } //Fim da Sele��o
		  }
		}
      else
      printf("Senha incorreta!");
		
		
 }
