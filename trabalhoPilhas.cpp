#include<stdin.h>
#include<stdlib.h>
typedef struct lista{
	int codigo, idade;
	char nome[];
	char telefone[8];
	struct lista *cadastro
}lista;
typedef lista *listaPtr;

typedef struct pilhaRefazer{
	lista valor;
	int tipoAcao; // 1 - Inclusão; 2 - Exclusao
	struct pilhaRefazer *proximaRefazer;
}pilhaRefazer;
typedef pilhaRefazer *pilhaPtr;

typedef struct pilhaDesfazer{
	lista valor;
	int tipoAcao; // 1 - Inclusão; 2 - Exclusao
	struct pilhaDesfazer *proximoDesfazer;
}pilhaDesfazer;
typedef pilhaDesfazer *pilhaPtrDesfazer;

void menu(lista listaPtr);
void cadastroPessoa(listaPtr *primeiraPessoa, char name[], int id, int i, char tele[]);
void imprimirPessoa(listaPtr pessoaAtual);
void remocaoPessoa(listaPtr *primeiraPessoa, int id);
void desfazerAcao(pilhaPtr *pilhaRefazer, pilhaPtrDesfazer *pilhaDesfazer, listaPtr *primeiraPessoa);
void refazerAcao(pilhaPtr *pilhaRefazer, pilhaPtrDesfazer *pilhaDesfazer, listaPtr *primeiraPessoa);

int main(){
	listaPtr aLista = NULL;
	menu();
	
	system("pause");
	return 0;
}

void menu(listaPtr primeiraPessoa){
	int op = 0;
	int codigo = 0, idade = 0;
	char nome[], telefone[8];
	listaPtr primeiraPessoa = NULL;
	pilhaPtr pilhaRefazer;
	pilhaPtrDesfazer pilhaDesfazer;
	
	printf("------------------Menu:");
	printf("1 - Cadastrar pessoa\n");
	printf("2 - Remover \n");
	
	switch(op){
		case 1:
			system("cls");
			
			printf("Codigo:\n");
			scanf("%d",&codigo);
			printf("Nome:\n");
			scanf("%s",&nome);
			printf("Idade:\n");
			sscanf("%d",&idade);
			printf("Telefone:\n");
			scanf("%s",&telefone);
			
			system("cls");
			
			cadastroPessoa(&primeiraPessoa, nome, codigo, idade, telefone);
			if(pilhaDesfazer == NULL){
				pilhaDesfazer->tipoAcao = 1;
				pilhaDesfazer->valor->codigo = codigo;
				pilhaDesfazer->valor->idade = idade;
				pilhaDesfazer->valor->nome = nome;
				pilhaDesfazer->valor->telefone = telefone;
			}else{
				pilhaPtrDesfazer novaPilhaDesfazer;
				novaPilhaDesfazer->tipoAcao = 1;
				novaPilhaDesfazer->valor->codigo = codigo;
				novaPilhaDesfazer->valor->idade = idade;
				novaPilhaDesfazer->valor->nome = nome;
				novaPilhaDesfazer->valor->telefone = telefone;
				novaPilhaDesfazer->proximoDesfazer = *pilhaPtrDesfazer;
				*pilhaPtrDesfazer = novaPilhaDesfazer;
			}
			
			break;
		case 2:
			system("cls");
			imprimirPessoa(primeiraPessoa);
			
			printf("So pode ser removido pelo codigo da pessoa\n");
			
			printf("Codigo da pessoa que deseja remover:\n");
			scanf("%d",&codigo);
			system("cls");
			removerPessoa(&primeiraPessoa, codigo);
			
			if(pilhaDesfazer == NULL){
				pilhaDesfazer->tipoAcao = 2;
				pilhaDesfazer->valor->codigo = codigo;
				pilhaDesfazer->valor->idade = idade;
				pilhaDesfazer->valor->nome = nome;
				pilhaDesfazer->valor->telefone = telefone;
			}else{
				pilhaPtrDesfazer novaPilhaDesfazer;
				novaPilhaDesfazer->tipoAcao = 2;
				novaPilhaDesfazer->valor->codigo = codigo;
				novaPilhaDesfazer->valor->idade = idade;
				novaPilhaDesfazer->valor->nome = nome;
				novaPilhaDesfazer->valor->telefone = telefone;
				novaPilhaDesfazer->proximoDesfazer = *pilhaPtrDesfazer;
				*pilhaPtrDesfazer = novaPilhaDesfazer;
			}
			
			break;
		default:
			printf("Digite alguma opcao valida!");
	}
};
void cadastroPessoa(listaPtr *primeiraPessoa, char name[], int id, int i, char tele[]){
	listaPtr novaPessoa, pessoaAtual, pessoaAnterior;
	novaPessoa = (listaPtr) malloc(sizeof(lista));
	
	strcpy(novaPessoa->telefone, tele);
	strcpy(novaPessoa->nome, name);
	novaPessoa->codigo = id;
	novaPessoa->idade = i;
	novaPessoa->cadastro = NULL;
	
	pessoaAtual = *primeiraPessoa;
	pessoaAnterior = NULL;
	
	if(novaPessoa != NULL){
		if(id != primeiraPessoa->codigo){
			while((pessoaAtual != NULL)&&(i > pessoaAtual->idade)){
				pessoaAnterior = pessoaAtual;
				pessoaAtual = pessoaAtual->proximaPessoa;
			}
			if(pessoaAnterior == NULL){
				novaPessoa->cadastro = *primeiraPessoa;
				*primeiraPessoa = novaPessoa;
			}else{
				pessoaAnterior->cadastro = novaPessoa;
				novaPessoa->cadastro = pessoaAtual;
			}
			imprimirPessoa();
		}else{
			printf("Codigo ja registrado!\n");
		}
	}
	}else{
		printf("Lista cheia!\n");
	}	
}

void imprimirPessoa(listaPtr novaPessoa){
	if (lista != NULL){
		printf("Lista:\n");
		while(lista != NULL){
			printf("Codigo:%d\nNome:%s\nIdade:%d\nTelefone:%s\n", lista->codigo, lista->nome, lista->idade, lista->telefone);
		}
	}else{
		printf("Nenhum cadastro\n");
	}
}

void remocaoPessoa(listaPtr *primeiraPessoa, int id){
	listaPtr pessoaExcluir, pessoaAnterior, pessoaAtual;
	
	pessoaAtual = *primeiraPessoa;
	
	if(novoValor != NULL){
		novoValor->valor = ;
		
	}
}
void desfazerAcao(pilhaPtr *pilhaRefazer, pilhaPtrDesfazer *pilhaDesfazer, listaPtr *primeiraPessoa){
	if(pilhaDesfazer != NULL){
		if(pilhaDesfazer->tipoAcao == 1){
			remocaoPessoa(&primeiraPessoa, pilhaDesfazer->valor->codigo);
			if(pilhaRefazer == NULL){
				pilhaRefazer->tipoAcao = 2;
				pilhaRefazer->valor->codigo = codigo;
				pilhaRefazer->valor->idade = idade;
				pilhaRefazer->valor->nome = nome;
				pilhaRefazer->valor->telefone = telefone;
			}else{
				pilhaPtr novaPilhaRefazer;
				novaPilhaRefazer->tipoAcao = 2;
				novaPilhaRefazer->valor->codigo = codigo;
				novaPilhaRefazer->valor->idade = idade;
				novaPilhaRefazer->valor->nome = nome;
				novaPilhaRefazer->valor->telefone = telefone;
				novaPilhaRefazer->proximoRefazer = *pilhaRefazer;
				*pilhaRefazer = novaPilhaRefazer;
			}
		}else{
			cadastroPessoa(&primeiraPessoa, pilhaDesfazer->valor->nome, pilhaDesfazer->valor->codigo, pilhaDesfazer->valor->idade, pilhaDesfazer->valor->telefone);
			if(pilhaRefazer == NULL){
				pilhaRefazer->tipoAcao = 1;
				pilhaRefazer->valor->codigo = codigo;
				pilhaRefazer->valor->idade = idade;
				pilhaRefazer->valor->nome = nome;
				pilhaRefazer->valor->telefone = telefone;
			}else{
				pilhaPtr novaPilhaRefazer;
				novaPilhaRefazer->tipoAcao = 1;
				novaPilhaRefazer->valor->codigo = codigo;
				novaPilhaRefazer->valor->idade = idade;
				novaPilhaRefazer->valor->nome = nome;
				novaPilhaRefazer->valor->telefone = telefone;
				novaPilhaRefazer->proximoRefazer = *pilhaRefazer;
				*pilhaRefazer = novaPilhaRefazer;
			}
		}
		if(pilhaDesfazer->proximoDesfazer != NULL){
			pilhaDesfazer = NULL;
		}else{
			pilhaPtrDesfazer tempDesfazer;
			lista tempLista;
			int tipoAcao;
			tempDesfazer = *pilhaDesfazer;
			*pilhaDesfazer = (*tempDesfazer)->proximoDesfazer;
			free(tempDesfazer);
		}
	}else{
		printf("Nenhuma acao a ser desfeita! \n");
	}
}


