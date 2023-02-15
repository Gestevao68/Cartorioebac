#include <stdio.h> // comunicacao com o usuario
#include <stdlib.h> // alocacao de espaco 
#include <locale.h> // alocacao de texto por regiao
#include <string.h> //responsavel por cuidar das strings

int registro() // cadastra usuarios no sistema
{	
	setlocale(LC_ALL,"Portuguese"); // colocou a linguagem em portugues
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF: "); // coleta informação
	scanf("%s",cpf); //salva na variavel, %s é referente a string
	
	strcpy(arquivo,cpf); // copia valor da string
	
	FILE *file; //funcao FILE recebe um comando file 
	file = fopen(arquivo,"w"); // comando quer dizer para abrir o arquivo com o oq estivar na variavel (arquivo) e escreve
	fprintf(file,cpf); // salva o valor de cpf
	fclose(file);	
	
	file = fopen(arquivo,"a"); // abre o arquivo para atualizar("a")
	fprintf(file,","); // escreve uma virgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); // recebe o valor de nome e salva
	
	file = fopen(arquivo,"a");
	fprintf(file,nome); // salva o valor de nome
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,","); // escreve uma virgula no arquivo
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); // recebe o valor de sobrenome
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome); // salva o valor de sobrenome
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,","); // escreve uma virgula no arquivo
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); // recebe o valor de cargo
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo); // salva o valor de cargo
	fclose(file);

	system("pause");
}

int consulta() // consulta os usuarios cadastrados
{
	setlocale(LC_ALL,"Portuguese"); // colocou a linguagem em portugues
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que quer consultar: ");
	scanf("%s",cpf);// salva o cpf digitado
	
	FILE *file;
	file = fopen(cpf,"r"); // abre o arquivo como 'r' para ler
	
	if(file == NULL) // se arquivo for igual a nulo
	{
		printf("O arquivo não foi localizado.\n");
	}
	while(fgets(conteudo,200,file) != NULL) // printa as informações que estão dentro do file 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
	fclose(file);
}

int deletar()
{
	setlocale(LC_ALL,"Portuguese"); // colocou a linguagem em portugues
	char cpf[40];
	
	
	printf("Digite o CPF do usuario que deseja ser Deletado: ");
	scanf("%s",cpf); // ve oq o usuario digita e salva em cpf
	
	remove(cpf); // deleta o arquivo
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("O arquivo não existe.\n");
		system("pause");
	}
	
	fclose(file);
	

	
	
}

int main() // funcao principal
{
	int opcao = 0;
	int laco = 1;
	
	for(laco=1;laco=1;)
	{
	system("cls"); // limpa a tela do que estiver escrito
	
	setlocale(LC_ALL,"Portuguese"); // colocou a linguagem em portugues
	
	printf("## Programa EBAC ##\n\n"); // /n serve para pular linhas e # foi para deixar mais bonito
	printf("Escolha a opção:\n\n");
	printf("\t1 - Registrar Nomes\n"); // /t serve para fazer separação e espaço
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n");
	printf("Opção: "); // fim do menu
	
	scanf("%d",&opcao); // armazena na variavel opcao, variavel inteira (numero)
	
	system("cls"); // limpa o prompt
	
	switch (opcao) //opção feita com o switch case
	{
		case 1: // aqui ele confere se a variavel opcao é igual a 1 e faz o código seguido, e depois fecha o programa com o Break
			registro();
		break;
		case 2: //mesma coisa do 1
			consulta();
		break;
		case 3: //mesma coisa do 1
			deletar();
		break;
		
		default: // opcao feita para se ele escrever um numero diferente de 1 a 3
			printf("Por Favor, escolha um numero de 1 a 3\n");
			system("pause");
		break;
	}
	//printf("\n\n Esse Software é do Trevo\n"); creditos do programa

	}
}
