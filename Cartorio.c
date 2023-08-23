#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por regiões
#include <string.h> // Biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da criação de variáveis/strings
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem ao programa
	
	printf("\n\tDigite o CPF a ser cadastrado: "); // Solicita o cpf do usuário
	scanf("%s", cpf); // %s refere-se a strings (permite que o usuário escreva)
	
	strcpy(arquivo,cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // Cria o arquivo // "Acessa o FILE e traz o file"
	file = fopen(arquivo, "w"); // Abre o arquivo para escrita ("w" significa escrever)
    fprintf(file, cpf); // Salva o CPF no arquivo
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para atualização
    fprintf(file, ", "); // Adiciona uma vírgula após o cpf
    fclose(file); // Fecha o arquivo

    printf("\tDigite o nome a ser cadastrado: "); // Solicita o nome ao usuário
    scanf("%s", nome); // Lê o nome

    file = fopen(arquivo, "a"); // Abre o arquivo
    fprintf(file, nome); // Adiciona o nome
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo
    fprintf(file, ", "); // Adiciona uma vírgula após o nome
    fclose(file); // Fecha o arquivo

    printf("\tDigite o sobrenome a ser cadastrado: "); // Solicita o sobrenome ao usuário
    scanf("%s", sobrenome); // Lê o sobrenome

    file = fopen(arquivo, "a"); // Abre o arquivo
    fprintf(file, sobrenome); // Adiciona o sobrenome ao arquivo
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo
    fprintf(file, ", "); // Adiciona uma vírgula após o sobrenome
    fclose(file); // Fecha o arquivo

    printf("\tDigite o cargo a ser cadastrado: "); // Solicita o cargo ao usuário
    scanf("%s", cargo); // Lê o cargo

    file = fopen(arquivo, "a"); // Abre o arquivo novamente
    fprintf(file, cargo); // Adiciona o cargo ao arquivo
    fclose(file); // Fecha o arquivo

    system("pause"); // Pausa para aguardar a interação do usuário

	
}

int consulta() // Função responsável por consultar os usuários que estão no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa
	
	// Início da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	// Fim da criação de variáveis/strings
	
	printf("\n\tDigite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\tNão foi possível abrir o arquivo, não localizado!\n");	
	}
	
	while(fgets(conteudo, 200, file)!=NULL) 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // Pausa para aguardar a interação do usuário
	
}

int deletar() // Função responsável por remover os usuários do sistema
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa

	// Início da criação de variáveis/strings
    char cpf[40];
    char arquivo[40];
	// Fim da criação de variáveis/strings

    printf("\n\tDigite o CPF do usuário a ser deletado: "); // Solicita o cpf que sera deletado
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // copia o conteúdo da string cpf para a string arquivo, permitindo assim a exclusão

    int result = remove(arquivo); // Deletar o arquivo

    if (result == 0)
    {
        printf("\tUsuário deletado com sucesso!\n");
    }
    else
    {
        printf("\tErro ao deletar o usuário ou usuário não se encontra no sistema!\n");
    }

    system("pause"); // Pausa para aguardar a interação do usuário
}
 
int main()
{
	int opcao=0; // Definindo variáveis
	int repeticao=1; // Variável responsável por fazer o retorno para o menu
	
	for(repeticao=1;repeticao=1;) // Comando que faz o retorno para o menu
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa
		
		printf("\t### Cartório da EBAC ###\n\n"); // Início do menu
		printf("\tEscolha a opção desejada do menu:\n\n");
		printf("\t\t1 - Registrar Nomes\n");
		printf("\t\t2 - Consultar Nomes\n");
		printf("\t\t3 - Deletar Nomes\n"); 
		printf("\t\t4 - Sair do Sistema\n\n");
		printf("\tOpção: ");// Fim do menu
		
		scanf("%d", &opcao); // Armazena a escolha do usuário (permite que o usuário escreva)
		
		system("cls"); // Limpa a tela
		
		switch(opcao) // Início da seleção
		{
			case 1:
			registro();  // Chamada de funções
			break;
			
			case 2:
			consulta(); // Chamada de funções
			break;
			
			case 3:
			deletar(); // Chamada de funções
			break;
			
			case 4:
			printf("\tObrigado por ultilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system ("pause");
			break;			
		} // Fim da seleção
	}
}
