/**************************
Criar lista ligada com 3 nós
por Ariadne Falcão
2026-01-28
************************/
#include <iostream>
using namespace std;
//******** Novos tipos **********
struct ficha
{
int numero; // a lista passa a ser ordenada por aqui
int idade; // item generico
struct ficha* proximo; // membro para apontador
};
//******* Variaveis globais ********
ficha* CABECA = NULL; // o promeiro da lista
ficha* CAUDA = NULL; // o ultimo da lista
ficha* novo; // declaracao de apontador para a lista ligada
ficha* atual;
ficha* anterior;
ficha* remover;
ficha* numero;
ficha* seguinte;
//********Inicializar a listas com 3 nós *********
void inicializarCom3Nos()
{
   //******** nó 1 *******
   novo = (ficha*) malloc(sizeof(ficha)); // pedir espaco
   CABECA = novo;
   CAUDA = novo; // o mesmo acontece com a cauda: ter 1 nó
   (*novo).numero = 1;
   (*novo).idade = 1111;
   (*novo).proximo = NULL;
   //******** Nó 2 ********
   novo = (ficha*) malloc(sizeof(ficha)); // pedir espaco
   (*CAUDA).proximo = novo;
   CAUDA = novo;
   (*novo).numero =7;
   (*novo).idade = 7777;
   (*novo).proximo = NULL;
   //****** Nó 3 *********
   novo = (ficha*) malloc(sizeof(ficha)); // pedir espaco
   (*CAUDA).proximo = novo;
   CAUDA = novo;
   (*novo).numero = 9;
   (*novo).idade = 9999;
   (*novo).proximo = NULL;
}
// ***** LISTAGEM *******
void listar()
{
   if(CABECA == NULL)
   {
       cout << "\n***** Lista Vazia *********";
   }
   atual = CABECA;
   while (atual != NULL)
   {
       cout << (*atual).numero << "\t" << (*atual).idade << "\t" << (*atual).proximo<< endl;
       atual = (*atual).proximo;
   }
   cout << endl;
}
//****** Iserir novo valor para cabeca ********
void inserirCabeca()
{
   novo = (ficha*) malloc(sizeof(ficha));
   (*novo).numero = 0;
   (*novo).idade = 0000;
   if(CABECA == NULL)
   {
       CABECA = novo;
       CAUDA = novo;
       (*novo).proximo = NULL;
   }
   else if ((*novo).numero < (*CABECA).numero)
   {
       (*novo).proximo = CABECA;
       CABECA = novo;
   }
}
// ****** Inserir novo valor para a cauda ******
void inserirCauda()
{
   novo = (ficha*) malloc(sizeof(ficha));
   (*novo).numero = 14;
   (*novo).idade = 1414;
   if(CABECA == NULL)
   {
       CABECA = novo;
       CAUDA = novo;
       (*novo).proximo = NULL;
   }
   else if ((*novo).numero > (*CAUDA).numero)
   {
       (*novo).proximo = NULL;
       (*CAUDA).proximo = novo;
       CAUDA = novo;
   }
}
//****** Inserir novo valor para o nó do meio *******
void inserirAoMeio()
{
   novo = (ficha*) malloc(sizeof(ficha));
   (*novo).numero = 8;
   (*novo).idade = 8888;
   anterior = CABECA; // variavevel temp que comeca na cabeca
   atual = (*CABECA).proximo; // variavel temp, toma conta do proximo nó
   while (atual != NULL) // enquanto o proximo nó não for (enquanto não acabamos de procorrer a lista)
   {
       if ((*novo).numero > (*anterior).numero && (*novo).numero < (*atual).numero) // se o novo nó tem um valor maior que o atual e menor que o proximo nó, inserimos
       {
           (*novo).proximo = atual;
           (*anterior).proximo = novo;
           break;
       }
       else if ((*novo).numero > (*anterior).numero && (*novo).numero > (*atual).numero) // se o novo nó tem um valor maior que o atual e o proximo, continuamos procorrer a lista
       {
           anterior = atual;
           atual = (*atual).proximo;
       }
   }
}
//******** Insere entre a cabeca e a cauda ********
void inserirCompleto()
{
   novo = (ficha*) malloc(sizeof(ficha)); //solicita espaco para o novo valor
   (*novo).numero = 12; // o apontador guarda o novo valor
   (*novo).idade = 1212; // o mesmo serve para a idade
   (*novo).proximo = (*CABECA).proximo; // o entra a lista apos a cabeca
   (*CABECA).proximo = novo;
}
// ******* Remover Cabeca *******
void removerCabeca()
{
   if(CABECA != NULL && CABECA != CAUDA) // condicao para a remoçao da cabeca
   atual = CABECA; // o nó atual tem o valor de CABECA
   {
       CABECA = (*CABECA).proximo; // o proximo nó tomara o valor da CABECA
       (*atual).proximo = NULL;
       free(atual); // libera o espaco do no Atual que antes era a CABECA
   }
}
//******** Remover ao meio ********
void removerAoMeio()
{
   if(CABECA == NULL || (*CABECA).proximo == NULL || (*CABECA).proximo == CAUDA) // Lista pequena demais para ter meio
   {
       cout << "Nao ha meio para remover\n";
       return;
   }
   int total = 0;
   atual = CABECA;
   while(atual != NULL) // 1ª passagem: contar elementos
   {
       total++;
       atual = (*atual).proximo;
   }
   int meio = total / 2; // índice do meio: para par, pega o primeiro do meio
   atual = CABECA;
   anterior = NULL;
   int pos = 0;
   while(pos < meio) // 2ª passagem: ir até o nó do meio
   {
       anterior = atual;
       atual = (*atual).proximo;
       pos++;
   }
   (*anterior).proximo = (*atual).proximo; // Remove o nó do meio
   free(atual); // libera o espaço
}
//******* Remover cauda ********
void removerCauda()
{
   if(CAUDA != NULL && CABECA != NULL && CAUDA != CABECA)
   {
       atual = (*CABECA).proximo;
       anterior = CABECA;
       while(atual != CAUDA) // percorre os nós
       {
           anterior = atual;
           atual = (*atual).proximo; // o nó passa a ser a cauda
       }
       CAUDA = anterior;
       (*anterior).proximo = NULL;
       free(atual); // libera espaço
       }
}
// ****** Remover Completo *****
// Remove elemento depois da cabeca
void removerCompleto()
{
   if((*CABECA).proximo != NULL && CABECA != NULL) // condicao para a remoçao do elemento depois da cabeca
   {
       atual = (*CABECA).proximo; // o nó atual tem o valor do elemento depois da cabeça
       (*CABECA).proximo = (*atual).proximo;
       // se o nó removido era a cauda, atualiza a cauda
       if (atual == CAUDA)
       {
           CAUDA = CABECA;
       }
       free(atual); // libera o espaco do Atual (no removido)
   }
}
// ****** Limpa Lista ******
void limpaLista()
{
   while (CABECA != NULL)
   {
       atual = CABECA;          // atual aponta para o nó atual
       CABECA = (*CABECA).proximo; // cabeça avança
       free(atual);             // libera o nó antigo
   }
   CAUDA = NULL; // lista vazia
}
// ****** Verifica se a Lista esta Ordenada *****
void boolListaOrdenada()
{
    // lista vazia ou com apenas um elemento
   if (CABECA == NULL || (*CABECA).proximo == NULL)
   {
       cout << "\n****** Lista Ordenada ******\n";
       return;
   }
   anterior = CABECA;
   atual = (*CABECA).proximo;
   while (atual != NULL)
   {
       if ((*anterior).numero > (*atual).numero)
       {
           cout << "\n****** Lista Nao Ordenada ******\n";
           return;
       }
       anterior = atual;
       atual = (*atual).proximo;
   }
   cout << "\n****** Lista Ordenada ******\n";
}
// ****** Ordena Lista *******
void ordenaLista()
{
   int trocou;
   // lista vazia ou com um elemento
   if (CABECA == NULL || (*CABECA).proximo == NULL)
   {
       return;
   }
   do
   {
       trocou = 0;
       anterior = CABECA;
       atual = (*CABECA).proximo;
       while (atual != NULL)
       {
           if ((*anterior).numero > (*atual).numero)
           {
               // troca os valores
               int auxNumero = (*anterior).numero;
               int auxIdade  = (*anterior).idade;
               (*anterior).numero = (*atual).numero;
               (*anterior).idade  = (*atual).idade;
               (*atual).numero = auxNumero;
               (*atual).idade  = auxIdade;
               trocou = 1;
           }
           anterior = atual;
           atual = (*atual).proximo;
       }
   } while (trocou == 1);
}
// ****** Conta nós ******
int  contaNos()
{
    ficha* atualTemp = CABECA;
    int total = 0;
    
    while(atualTemp != NULL) 
    {
        total = total + 1;
        atualTemp = (*atualTemp).proximo;
    }
    return total;
}

// ****** Ler 2 Numeros e Troca Dados dos Nós ******
void ler2NumTrocaNos()
{
   int n1, n2;
   cout << "Digite os dois números (ID) para trocar seus dados: ";
   cin >> n1 >> n2;
   ficha *no1 = NULL, *no2 = NULL, *temp = CABECA;
   // Procura os dois nós na lista
   while (temp != NULL) {
       if (temp->numero == n1) no1 = temp;
       if (temp->numero == n2) no2 = temp;
       temp = temp->proximo;
   }
   // Se encontrou ambos, troca os valores de idade e número
   if (no1 && no2) {
       int auxNum = no1->numero;
       int auxIdade = no1->idade;
       no1->numero = no2->numero;
       no1->idade = no2->idade;
       no2->numero = auxNum;
       no2->idade = auxIdade;
       cout << "Dados trocados com sucesso!\n";
   } else {
       cout << "Um ou ambos os números não foram encontrados.\n";
   }
}

// ****** Inverter Lista ******
void inverterLista()
//Só inverte as posicoes da lista, não ordena de forma decrescente
{
  if (CABECA == NULL || (*CABECA).proximo == NULL)
   {
       return;
   }
   anterior = NULL;
   atual = CABECA;
   while (atual != NULL)
   {
       seguinte = (*atual).proximo;  // usa o membro da struct
       (*atual).proximo = anterior;
       anterior = atual;
       atual = seguinte;
   }
   // ajusta cabeça e cauda
   CAUDA = CABECA;
   CABECA = anterior;
}


// ****** Tamanho da Lista ******
void sizeOfStruct()
{
   int contador = 0;
   atual = CABECA; //var atual vai comecar aqui
   while(atual != NULL)
   {
       contador++; //incrementa a contagem
       atual = (*atual).proximo; //Move para o próximo nó
   }
   cout << "============================" << endl;
   cout << " STATUS DA LISTA" << endl;
   cout << " Total de fichas: [ " << contador << " ]" << endl;
   cout << "============================" << endl;
}

// ****** Apaga até o primeiro número par ******
void apagarAtePrimeiroPar()
{
   // Enquanto a cabeça não for par, removemos a cabeça
   while (CABECA != NULL && (CABECA->numero % 2 != 0)) {
       ficha* temp = CABECA;
       CABECA = CABECA->proximo;
       free(temp);
   }
   // Atualiza a cauda caso a lista tenha ficado vazia
   if (CABECA == NULL) CAUDA = NULL;
   cout << "Nós ímpares iniciais removidos.\n";
}

// ****** Elimina repetidos (considerando lista ordenada) ******
void eliminarRepetidos()
{
   if (CABECA == NULL) return;
   ficha* atual = CABECA;
   while (atual->proximo != NULL) {
       if (atual->numero == atual->proximo->numero) {
           ficha* duplicado = atual->proximo;
           atual->proximo = duplicado->proximo;
           if (duplicado == CAUDA) CAUDA = atual;
           free(duplicado);
       } else {
           atual = atual->proximo;
       }
   }
   cout << "Repetidos eliminados.\n";
}

// ******** MENU *********
void apresentarMenu()
{
   cout << "LISTA LIGADA-EXERCICIO DIDATICO (TRABALHO COOPERATIVO)-----------------\n";
   cout << "[1:Listar]\n";
   cout << "[2:insere cabeca]\n[3:insere no cauda]\n[4:insere ao meio]\n[5:INSERE(completo)]\n";
   cout << "[6:remove cabeca]\n[7:remove cauda]\n[8:remove ao meio]\n[9:REMOVE (completo)]\n";
   cout << "[a:limpa lista]\n[b:init lista com 3 nos]\n[c:lista ordenada? (sim/nao)]\n[d:ordena lista]\n[e:conta nos]\n";
   cout << "[f:ler 2 nums; trocar os nos]\n[g:inverter a lista]\n[H:ler isto, por favor]\n[k:sizeof da struct]\n";
   cout << "[0:SAIR]\n";
   cout << "[Y:apaga ate o primeiro par]\n[y:elimina repetido...se...]Op?" << endl;
}
//********* Funcao Main **********
int main()
{
   char op;
   do {
       apresentarMenu();
       cout << "Selecionar opcao: ";
       cin >> op;
       switch(op)
       {
           case '1':
           listar();
           cout << endl;
           break;
           case '2':
           inserirCabeca();
           cout << endl;
           break;
           case '3':
           inserirCauda();
           cout << endl;
           break;
           case '4':
           inserirAoMeio();
           cout << endl;
           break;
           case '5':
           inserirCompleto();
           cout << endl;
           break;
           case '6':
           removerCabeca();
           cout << endl;
           break;
           case '7':
           removerCauda();
           cout << endl;
           break;
           case '8':
           removerAoMeio();
           cout << endl;
           break;
           case '9':
           removerCompleto();
           cout << endl;
           break;
           case 'a':
           limpaLista();
           cout << endl;
           break;
           case 'b':
           inicializarCom3Nos();
           cout << endl;
           break;
           case 'c':
           boolListaOrdenada();
           cout << endl;
           break;
           case 'd':
           ordenaLista();
           cout << endl;
           break;
           case 'e':
           contaNos();
           cout << endl;
           break;
           case 'f':
           ler2NumTrocaNos();
           cout << endl;
           break;
           case 'g':
           inverterLista();
           cout << endl;
           break;
           case 'k':
           sizeOfStruct();
           cout << endl;
           break;
           case 'Y':
           apagarAtePrimeiroPar();
           cout << endl;
           break;
           case 'y':
           eliminarRepetidos();
           cout << endl;
           break;
           
           
       }
   } while (op != '0');

}
