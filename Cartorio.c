#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�es
#include <string.h> // Biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da cria��o de vari�veis/strings
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem ao programa
	
	printf("\n\tDigite o CPF a ser cadastrado: "); // Solicita o cpf do usu�rio
	scanf("%s", cpf); // %s refere-se a strings (permite que o usu�rio escreva)
	
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo // "Acessa o FILE e traz o file"
	file = fopen(arquivo, "w"); // Abre o arquivo para escrita ("w" significa escrever)
    fprintf(file, cpf); // Salva o CPF no arquivo
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o
    fprintf(file, ", "); // Adiciona uma v�rgula ap�s o cpf
    fclose(file); // Fecha o arquivo

    printf("\tDigite o nome a ser cadastrado: "); // Solicita o nome ao usu�rio
    scanf("%s", nome); // L� o nome

    file = fopen(arquivo, "a"); // Abre o arquivo
    fprintf(file, nome); // Adiciona o nome
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo
    fprintf(file, ", "); // Adiciona uma v�rgula ap�s o nome
    fclose(file); // Fecha o arquivo

    printf("\tDigite o sobrenome a ser cadastrado: "); // Solicita o sobrenome ao usu�rio
    scanf("%s", sobrenome); // L� o sobrenome

    file = fopen(arquivo, "a"); // Abre o arquivo
    fprintf(file, sobrenome); // Adiciona o sobrenome ao arquivo
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo
    fprintf(file, ", "); // Adiciona uma v�rgula ap�s o sobrenome
    fclose(file); // Fecha o arquivo

    printf("\tDigite o cargo a ser cadastrado: "); // Solicita o cargo ao usu�rio
    scanf("%s", cargo); // L� o cargo

    file = fopen(arquivo, "a"); // Abre o arquivo novamente
    fprintf(file, cargo); // Adiciona o cargo ao arquivo
    fclose(file); // Fecha o arquivo

    system("pause"); // Pausa para aguardar a intera��o do usu�rio

	
}

int consulta() // Fun��o respons�vel por consultar os usu�rios que est�o no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa
	
	// In�cio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	// Fim da cria��o de vari�veis/strings
	
	printf("\n\tDigite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\tN�o foi poss�vel abrir o arquivo, n�o localizado!\n");	
	}
	
	while(fgets(conteudo, 200, file)!=NULL) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file); // Fecha o arquivo
	
	system("pause"); // Pausa para aguardar a intera��o do usu�rio
	
}

int deletar() // Fun��o respons�vel por remover os usu�rios do sistema
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa

	// In�cio da cria��o de vari�veis/strings
    char cpf[40];
    char arquivo[40];
	// Fim da cria��o de vari�veis/strings

    printf("\n\tDigite o CPF do usu�rio a ser deletado: "); // Solicita o cpf que sera deletado
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // copia o conte�do da string cpf para a string arquivo, permitindo assim a exclus�o

    int result = remove(arquivo); // Deletar o arquivo

    if (result == 0)
    {
        printf("\tUsu�rio deletado com sucesso!\n");
    }
    else
    {
        printf("\tErro ao deletar o usu�rio ou usu�rio n�o se encontra no sistema!\n");
    }

    system("pause"); // Pausa para aguardar a intera��o do usu�rio
}
 
int main() 
{
    // In�cio da cria��o de vari�veis/strings
	int opcao = 0;
    int repeticao = 1;
    char senhadigitada[10] = "a";
    int comparacao;
	// fim da cria��o de vari�veis/strings

    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem ao programa

    while (repeticao == 1) 
	{
        system("cls"); // Limpa a tela
        
        printf("\t### Cart�rio da EBAC ###\n\n");
        printf("\tDigite a sua senha de administrador: ");
        
        scanf("%s", senhadigitada);
        comparacao = strcmp(senhadigitada, "admin"); // strcmp - compara duas strings e determina se elas s�o iguais ou n�o.

        if (comparacao == 0) 
		{
            for(repeticao=1;repeticao=1;) // Comando que faz o retorno para o menu, ap�s tomada de decis�o
			{
                system("cls"); // Limpa a tela
                
                printf("\t### Cart�rio da EBAC ###\n\n"); // In�cio do menu
                printf("\tEscolha a op��o desejada do menu:\n\n");
                printf("\t\t1 - Registrar Nomes\n");
                printf("\t\t2 - Consultar Nomes\n");
                printf("\t\t3 - Deletar Nomes\n");
                printf("\t\t4 - Sair do Sistema\n\n");
                printf("\tOp��o: ");
                scanf("%d", &opcao); // Fim do menu
                
                system("cls"); // Limpa a tela

                switch (opcao) // In�cio da sele��o
				{
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
                    printf("\n\tObrigado por ultilizar o sistema!\n");
					return 0;
                    break;

                    default:
                    printf("\n\tEssa op��o n�o est� dispon�vel!\n");
                    system("pause");
                    break;
                } // Fim da sele��o
            }
        } 
		else if (strcmp(senhadigitada, "0") == 0) // verifica��o da senha digitada pelo usu�rio e tomando a��es com base no resultado da compara��o
		{
            printf("\tObrigado por utilizar o sistema!\n");
            repeticao = 0;
        } 
		else 
		{
            system("cls"); // In�cio do menu
            printf("\t### Cart�rio da EBAC ###\n\n");
            printf("\tSenha incorreta!\n\n");
            printf("\tEscolha a op��o desejada do menu:\n\n");
            printf("\t\t1 - Tentar novamente\n");
            printf("\t\t2 - Sair do sistema\n\n");
            printf("\tOp��o: ");
            scanf("%d", &repeticao); // Fim do menu
            
            if(repeticao == 2)
            {
            system("cls"); // Limpa a tela
            printf("\n\tObrigado por ultilizar o sistema!\n");
			return 0;
        	}
        }
    }

    return 0;
}
