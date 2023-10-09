#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por registra os usu�rios no sistema
{
	//Inicio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o das vari�veis/string
	
	printf("Digite o CPF que deve ser cadastrado: "); //Coletando a informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar o valor das string
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // Salva o valor da Variavel
    fclose(file); //Finaliza o arquivo
    
    file = fopen(arquivo, "a"); 
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o seu nome: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite seu sobrenome: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Informe o seu cargo: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    
    system("pause");

}

int consulta() //Fun��o para consultar nomes
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Liguagem que vai ser utilizada
	
	//Inicio das fun��es
	char cpf[40];
	char conteudo[40];
	
	printf ("Digite o CPF a ser consultado: "); //Parte de Consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo. \n"); //Aparece quando a sele��o n�o se encontra no Menu/sistema!
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es dos usu�rios: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	//Fim das fun��es
	system("pause");
	
	
}

int deletar() //Fun��o para deletar nomes
{
	//Inicio da fun��o Deletar nomes do Banco de Dados
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Identificar CPF para ser deletado
	scanf("%s",cpf);
	
	remove("cpf"); //Informa��es a ser removida!
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usu�rio foi deletado com sucesso!.\n"); //Notifica��o de que o CPF foi deletado!
		system ("pause");
	}
	//Fim da fun��o Deletar nomes do Banco de Dados

}


int main()
{
	
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
       system("cls"); //Responsavel por limpar a tela

	   setlocale(LC_ALL,"Portuguese"); //Definindo a Liguagem que vai ser utilizada
	
	   printf("#### Cart�rio da EBAC ####\n\n"); // Inicio do menu
	   printf("Escolha a op��o desejada do menu: \n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do Sistema\n");
	   printf("\n");
	   printf("Op��o: "); // Fim do menu
	
	   scanf("%d", &opcao); //Op��es de Sele��o do menu 
	
       system("cls");
       
       
       switch(opcao) //Abaixo temos as 3 op��es para o menu, e uma caso aconte�a algum erro na sele��o
        {
            case 1:
            registro(); //Chamada de fun��es
            break;
       	 	
        	case 2:
        	consulta(); 
    	    break;
    	    
    	    case 3:
    	    deletar();
    	    break;
    	    
    	    case 4:
    	    printf("Obrigado por utilizar o Sistema\n");
    	    return 0;
    	    break;
    	    
    	    default:
    	    printf(" Op��o invalida!\n\n ");
		    system("pause");
		    break;    
	    } //Fim das 3 sele��es
       
	} //Fim da sele��o
	
}
