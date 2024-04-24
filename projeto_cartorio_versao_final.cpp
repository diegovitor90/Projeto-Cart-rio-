#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca resposável por cuidar da string



int registro() //função para regitro de usuárrio
{
	//início de regsitro de usário
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de registro de usuário
	
	printf("Digite o seu CPF a ser cadastrado: "); //solicitando o input do usário
	scanf("%s", cpf); //%s refere-se aos valores da string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores da string
	FILE *file; //direcionando para o arquivo file 
	file = fopen(arquivo, "w"); //abrindo e escrevendo a string arquivo 
	fprintf(file,cpf); //colocando o CPF no banco de dados 
	fclose(file); //fechando o arquivo file 
	
	file = fopen(arquivo, "a"); //abrindo para armazenando na variavél a 
	fprintf(file, ",");//colcando a virgula na variável a  
	fclose(file); //fechando o arquivo
	
	printf("Digite o nome a ser cadastrado:\n"); //solicitando o input do usuário
	scanf("%s", nome); //%s refere-se aos valores da string
	
	file = fopen(arquivo, "a"); //abrindo para armazenamento na variável a 
	fprintf(file,nome);//colacando o nome no banco de dados
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo para armazenamento na variável a 
	fprintf(file, ","); //colocando a vírgula na variável a 
	fclose(file);//fechando o arquivo
	 	
	printf("Digite o sobrenome a ser cadastrado:\n"); //solicitando o input do usuário
	scanf("%s", sobrenome); //colcando o sobrenome no banco de dados
	
	file = fopen(arquivo, "a"); //abrindo para armazenamento na variável a
	fprintf(file,sobrenome); //colocando o sobrenome na variável a 
	fclose(file);//fechando o arquivo
		
	file = fopen(arquivo, "a"); //abrindo para armazenamento na variável a 
	fprintf(file, ","); //colcando a vírgula na variável a 
	fclose(file);//fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado:\n"); //solicitando input do usuário
	scanf("%s", cargo); //colocando o cargo no banco de dados
	
	file = fopen(arquivo, "a"); //abrindo para armazenamento na variável a 
	fprintf(file,cargo); //colocando cargo na variável na cargo
	fclose(file); //fechando o arquivo file
	
	system("pause");  //pausa na tela para o usuário fazer a leitura 
	
	system("cls"); //comando para apagar as informações da tela	
}

int consulta() //função para cosulta do ursuário
{
	setlocale(LC_ALL, "Portuguese");  //configurando o idioma

	//início de consulta do usuário 
	char cpf[40];
	char conteudo[200];
	//fim de consulta do usuário
	
	printf("Digite o CPF a ser consultado: "); //solicitando input de usuários
	scanf("%s", cpf); // %s refere-se aos valores da string  e o parâmentro aqui usado é CPF por ser um valor único de cada usuário 
	
	FILE *file;
	file = fopen ( cpf, "r"); //abrindo e fazendo a leitura da string
	
	if(file == NULL)//condição para caso o CPF do usuário seja nulo
	{
	  printf("Não foi possível abrir o arquivo, não localizado!");	//output para usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //condição para CPF seja válido e mostrar as informações do usuário
	{
		printf("Essas são as informações do usuário: "); //solicitando input de usuários
	    printf("%s", conteudo);//%s refere-se aos valores armazenado na string
	    printf("\n\n");//output de informações para usuário
	}

	fclose(file); //fechando o arquivo file
	system("pause"); //pausa na tela para o usuário fazer a leitura
	
	system("cls"); //comando para apagar as informações da tela

}

int deleta()
{
	setlocale(LC_ALL, "Portuguese");  //configurando o idioma
	
	char cpf[40];//o parâmetro utilizado também vai sr o cpf
	
	printf("Qual CPF você quer deletar? "); //coletando o dado para a função	
	scanf("%s", cpf);//salvando o valor da string
	
	FILE *file;//fazendo a validação se o usuário não estiver no sistema  
	file = fopen (cpf, "r"); // leitura do cpf digitado
	
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n"); //output para o usuário
	}
	
	while(fgets(cpf, 40, file) !=NULL ) //condição de remoção do CPF caso ele esteja no banco de dados
	{
	remove(cpf);//comando para deletar 
	printf("Usuário removido com sucesso!\n\n");//output para usuário
	fclose(file); //fechando o arquivo file
	}
	
	system("pause");  //pausa na tela para o usuário fazer a leitura
	
	system("cls"); //comando para apagar as informações da tela
	
}

int main()
{
	    int opcao=0; //amarzenando a variável
	    int laco=1; //declarando a variavél laço
	    char senhadigitada[]="a"; //iniciando a senha
	    int comparacao;
	    setlocale(LC_ALL, "Portuguese");  //configurando o idioma
	    
		printf("\t - Cartório da EBAC - \n\n"); //início do menu
	    printf("\t - Login de Administrador - \n\n Digite sua senha:\n\n"); //solicitar senha pra admin
	    scanf("%s", senhadigitada);
	    
	    comparacao = strcmp(senhadigitada,"admin"); //comparando a senha digitada com texto amarzenado
	    
	    if(senhadigitada[10] == 0)//true: acesso para o sistema
		{ 
	    system("cls"); //comando para apagar as informações da tela
		 for (laco=1;laco=1;) //Início da seleção com laço
		  {
			setlocale(LC_ALL, "Portuguese");  //configurando o idioma
			
			printf("\t - Cartório da EBAC - \n\n"); //início do menu
			printf(" Olá, Somos a EBAC - Escola Britânica de Artes Criativas, estamos aqui pra te atender! \n");
			printf("\t Selecione umas das opções abaixo para: \n\n");
			printf("\t 1. Cadastrar - é o seu primeiro contato? \n\n");
			printf("\t 2. Consultar - Já possui cadastro? \n\n");
			printf("\t 3. Deletar - Está saindo do curso? \n\n");
			printf("\t 4. Sair do sistema\n\n");
			printf("Opção:");
			 //fim do menu
			
			scanf("%d", &opcao); //armazenando a escolha do usuário 
			
			system("cls"); //comando para apagar as informações da tela
		
			//comando para chamar as funções 
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
		           printf("Você digitou opção inválida\n");
		           system("pause");
		           break; 
		           
		    } //Fim da Seleção
		  }
		}
      else
      printf("Senha incorreta!");
		
		
 }
