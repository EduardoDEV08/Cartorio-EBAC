#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por registra os usuários no sistema
{
	//Inicio da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variáveis/string
	
	printf("Digite o CPF que deve ser cadastrado: "); //Coletando a informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsável por copiar o valor das string
    
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

int consulta() //Função para consultar nomes
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Liguagem que vai ser utilizada
	
	//Inicio das funções
	char cpf[40];
	char conteudo[40];
	
	printf ("Digite o CPF a ser consultado: "); //Parte de Consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo. \n"); //Aparece quando a seleção não se encontra no Menu/sistema!
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações dos usuários: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	//Fim das funções
	system("pause");
	
	
}

int deletar() //Função para deletar nomes
{
	//Inicio da função Deletar nomes do Banco de Dados
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Identificar CPF para ser deletado
	scanf("%s",cpf);
	
	remove("cpf"); //Informações a ser removida!
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário foi deletado com sucesso!.\n"); //Notificação de que o CPF foi deletado!
		system ("pause");
	}
	//Fim da função Deletar nomes do Banco de Dados

}


int main()
{
	
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
       system("cls"); //Responsavel por limpar a tela

	   setlocale(LC_ALL,"Portuguese"); //Definindo a Liguagem que vai ser utilizada
	
	   printf("#### Cartório da EBAC ####\n\n"); // Inicio do menu
	   printf("Escolha a opção desejada do menu: \n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do Sistema\n");
	   printf("\n");
	   printf("Opção: "); // Fim do menu
	
	   scanf("%d", &opcao); //Opções de Seleção do menu 
	
       system("cls");
       
       
       switch(opcao) //Abaixo temos as 3 opções para o menu, e uma caso aconteça algum erro na seleção
        {
            case 1:
            registro(); //Chamada de funções
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
    	    printf(" Opção invalida!\n\n ");
		    system("pause");
		    break;    
	    } //Fim das 3 seleções
       
	} //Fim da seleção
	
}
