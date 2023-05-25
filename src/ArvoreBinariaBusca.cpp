#include "../include/ArvoreBinariaBusca.h"

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <stack>
#include <fstream>

using namespace std;


// Construtores
ArvoreBinariaBusca::ArvoreBinariaBusca() // Construtores
{
    raiz = nullptr;
}

ArvoreBinariaBusca::~ArvoreBinariaBusca()
{ 
    deletarArvore(raiz);
}

// ----------------------------------------------------

// Apaga todos os ponteiros da árvore para evitar acúmulo de lixo na memária
void ArvoreBinariaBusca::deletarArvore(No * noatual){
    if(noatual==nullptr){
        deletarArvore(noatual->filhoEsquerda);
        deletarArvore(noatual->filhoDireita);
        delete noatual;
    }
}


// Método que chama a função getPre_ordem e retorna uma string contendo a árvore em pré-ordem  
string ArvoreBinariaBusca::pre_ordem()
{
    string valor;
    getPre_ordem(raiz, valor);
    return valor;
}

// Método recursivo que percorre a árvore em pré-ordem construindo uma string (valor),
// no final da sua execução como a string é passada por referência seu valor é mantido na memória  
void ArvoreBinariaBusca::getPre_ordem(No *no, string &valor)
{

    if (no != nullptr)
    {
        valor = valor + " " + to_string(no->chave);

        getPre_ordem(no->filhoEsquerda, valor);

        getPre_ordem(no->filhoDireita, valor);
    }
}


// Método que chama o método recursivo getBusca, e a partir do dado retornado por ele
// identifica se a chave existe ou não.
bool ArvoreBinariaBusca::buscar(int chave)
{

    No *current = getBuscar(chave);

    if (current != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Método recursivo que verifica se a chave existe na árvore
No *ArvoreBinariaBusca::getBuscar(int chave)
{
    No *current = raiz;
    while (current != nullptr)
    {
        if (chave == current->chave)
        {
            return current;
        }
        else if (chave < current->chave)
        {
            current = current->filhoEsquerda;
        }
        else
        {
            current = current->filhoDireita;
        }
    }
    return nullptr;
}

// Método que chama o método getAlturaNo e retorna a altura
int ArvoreBinariaBusca::alturaNo(int chave)
{
    // Chama a função auxiliar para encontrar a altura do nó
    return getAlturaNo(raiz, chave, 0);
}


// Método que retorna a altura de um no na árvore (esse método auxilia outro métodos)
int ArvoreBinariaBusca::getAlturaNo(No *no, int chave, int altura)
{
    if (no == nullptr)
    {
        // O nó não foi encontrado, retorna -1 para indicar isso
        return -1;
    }

    if (chave == no->chave)
    {
        // Encontrou o nó desejado, retorna a altura
        return altura;
    }

    if (chave < no->chave)
    {
        // Busca no nó filho esquerdo
        return getAlturaNo(no->filhoEsquerda, chave, altura + 1);
    }
    else
    {
        // Busca no nó filho direito
        return getAlturaNo(no->filhoDireita, chave, altura + 1);
    }
}

// Método que retorna o tamanho das subárvores de um nó (esse método auxilia outro métodos)
int ArvoreBinariaBusca::getTamanho(No *no)
{
    if (no == nullptr)
    {
        return 0;
    }
    return no->tamanho;
}

// Método que dependendo da entrada imprime a árvore
void ArvoreBinariaBusca::imprimeArvore(int s)
{

    string final = "(";
    string final2 = "";

    int found = 1;

    if (s == 1)
    {
        imprimeFormartoUm(raiz, final);
        final = final + ")";

        do
        {
            found = final.find("()");

            if (found != -1)
            {
                final.erase(found, 2);
            }

        } while (found != -1);

        //cout << final << endl;

        ofstream arquivoS;

        arquivoS.open("/home/luiz/Área de Trabalho/ProjetoEDB2ArvoreBinaria/arquivos/saída/saida.txt", ios::app);

        if (arquivoS.is_open())
        {
            arquivoS << final << endl;
        }

        arquivoS.close();

    }
    else if (s == 2)
    {

        imprimeFormartoDois(raiz, final2, 30);
    }
    else
    {
        cout << "Formato inválido" << endl;
    }
}

// Método que imprime a árvore no formato 1 (com linha que delimitam os níveis)
void ArvoreBinariaBusca::imprimeFormartoUm(No *no, string &arvore)
{

    if (no == nullptr)
    {
        return;
    }

    arvore = arvore + to_string(no->chave);

    if (no->filhoEsquerda != nullptr || no->filhoDireita != nullptr)
    {
        arvore = arvore + "(";
        imprimeFormartoUm(no->filhoEsquerda, arvore);
        arvore = arvore + ")";
    }

    if (no->filhoDireita != nullptr)
    {
        arvore = arvore + "(";
        imprimeFormartoUm(no->filhoDireita, arvore);
        arvore = arvore + ")";
    }
}

// Método que imprime a árvore no formato 2 (com parênteses que delimitam os níveis)
void ArvoreBinariaBusca::imprimeFormartoDois(No *no, string &arvore, int tracos)
{

    if (no == nullptr)
    {
        return;
    }

    for (int i = 0; i < 7 * alturaNo(no->chave); i++)
    {
        cout << " ";
    }

    cout << no->chave << " ";

    for (int i = 0; i < tracos - ((alturaNo(no->chave) - 1) * 7); i++)
    {
        cout << "-";
    }
    
    cout << endl;

    imprimeFormartoDois(no->filhoEsquerda, arvore, tracos);

    imprimeFormartoDois(no->filhoDireita, arvore, tracos);
}


// Método que chama o método recursivo getMediana e retorna o valor da médiana da árvore,
// se a árvore for par, retorna o ménor valor (filho esquerdo). 
int ArvoreBinariaBusca::mediana()
{
    int tamanhoArvore = getTamanho(raiz);

    return getMediana(raiz, tamanhoArvore);
}

// Método recursivo que acha a mediana 
int ArvoreBinariaBusca::getMediana(No *no, int tamanhoArvore)
{

    // Índice do elemento do meio
    int indexCentral = (tamanhoArvore + 1) / 2;

    // Quando a árvore é par
    if (tamanhoArvore % 2 == 0)
    {
        int elementoEsqueda = enesimoElemento(indexCentral);
        int elementoDireita = enesimoElemento(indexCentral + 1);

        return min(elementoEsqueda, elementoDireita);
    }
    else
    {
        // Árvore ímpar
        return enesimoElemento(indexCentral);
    }
}


// Método que chama o método recursivo getEnesimoElemento, que dado uma determinada posição,
// retorna a chave revente a essa posição.
int ArvoreBinariaBusca::enesimoElemento(int n)
{
    int cont = 0;
    int resultado = -1;
    if (n < 1 || n > getTamanho(raiz))
    {
        cout << "índice inválido" << endl;
        return -1;
    }
    getEnesimoElemento(raiz, n, cont, resultado);

    return resultado;
}

// Método que dado uma posição retorna a chave
// Mesma coisa que pré-ordem mais a raiz não é visitada no início
void ArvoreBinariaBusca::getEnesimoElemento(No *no, int n, int &cont, int &resultado)
{

    if (no == NULL)
    {
        return;
    }

    getEnesimoElemento(no->filhoEsquerda, n, cont, resultado);

    cont++;

    if (cont == n)
    {
        resultado = no->chave;
        return;
    }

    getEnesimoElemento(no->filhoDireita, n, cont, resultado);
}


// Método que chama o método recursivo getPosição, que dado uma chave retorna a posição do elemento
int ArvoreBinariaBusca::posicao(int x)
{
    int cont = 0;
    int resultadoFinal = -1;

    getPosicao(raiz, cont, x, resultadoFinal);

    return resultadoFinal;
}

// Método recursivo que retorna a posição dada uma chave
void ArvoreBinariaBusca::getPosicao(No *no, int &cont, int &x, int &resultadoFinal)
{

    if (no == NULL)
    {
        return;
    }

    getPosicao(no->filhoEsquerda, cont, x, resultadoFinal);

    cont++;

    if (no->chave == x)
    {
        resultadoFinal = cont;
        // cout << cont<< " " << no->chave << endl;
        return;
    }

    getPosicao(no->filhoDireita, cont, x, resultadoFinal);
}

// Método que chama o método recursivo getMedia, que retorna a média da soma de todos os valores filhos de uma no
double ArvoreBinariaBusca::media(int x)
{

    No *current = getBuscar(x);
    double soma = 0;
    double cont = 0;
    int resultadoFinal = 0;

    if (current != nullptr)
    {
        getMedia(current, current, soma, cont, resultadoFinal);

        cout << soma << cont << endl;

        if (current->chave == raiz->chave)
        {
            return (soma / (cont == 0 ? 1 : cont));
        }
        else
        {
            return (soma / ((cont - 1) == 0 ? 1 : cont - 1));
        }
    }
    else
    {
        return 0.0;
    }
}


// Método recursivo que retorna a média dos filhos de uma dado no 
void ArvoreBinariaBusca::getMedia(No *no, No *noInicial, double &soma, double &cont, int &resultadoFinal)
{
    if (no == nullptr)
    {
        return;
    }

    getMedia(no->filhoEsquerda, noInicial, soma, cont, resultadoFinal);

    cont++;

    if (no->chave != noInicial->chave)
    {
        soma = soma + no->chave;
    }

    getMedia(no->filhoDireita, noInicial, soma, cont, resultadoFinal);
}

// Método que chama o método recursivo getTamanhoArvore, que retorna a altura da árvore
int ArvoreBinariaBusca::tamanhoArvore()
{
    return getTamanhoArvore(raiz) - 1;
}

// Método recursivo que retorna a altura da árvore, caminho mais longo entre a raiz e a folha.
int ArvoreBinariaBusca::getTamanhoArvore(No *no)
{
    if (no == nullptr)
    {
        return 0;
    }

    int tamanhoEsquerda = getTamanhoArvore(no->filhoEsquerda);
    int tamanhoDireita = getTamanhoArvore(no->filhoDireita);

    return 1 + max(tamanhoEsquerda, tamanhoDireita);
}

bool ArvoreBinariaBusca::ehCheia()
{
    int tamanhoArvore = getTamanhoArvore(raiz);
    bool ehCheiaResultado = true;
    getEhCheia(raiz, tamanhoArvore, ehCheiaResultado);

    return ehCheiaResultado;
}

/*Uma árvore binária cheia é uma árvore em
que se um nó tem alguma sub-árvore vazia
então ele está no último nível.
*/
void ArvoreBinariaBusca::getEhCheia(No *no, int &tamanhoArvore, bool &ehCheiaResultado)
{

    if (no == nullptr)
    {
        return;
    }

    getEhCheia(no->filhoEsquerda, tamanhoArvore, ehCheiaResultado);

    // cout << no->chave << endl;
    if (tamanhoArvore == 1)
    {
        ehCheiaResultado = true;
        return;
    }
    else if (no->filhoDireita != nullptr && no->filhoEsquerda == nullptr || no->filhoDireita == nullptr && no->filhoEsquerda != nullptr)
    {

        if (alturaNo(no->chave) == tamanhoArvore - 2)
        {
            //cout << "1" << endl;
            ehCheiaResultado = false;
            return;
        }
    }
    else if (no->filhoDireita == nullptr && no->filhoEsquerda == nullptr && tamanhoArvore - 1 != 1)
    {
        if (alturaNo(no->chave) != tamanhoArvore - 1)
        {
            //cout << "2" << endl;
            ehCheiaResultado = false;
            return;
        }
    }

    if (no->filhoDireita != nullptr && no->filhoEsquerda == nullptr || no->filhoDireita == nullptr && no->filhoEsquerda != nullptr)
    {
        if (alturaNo(no->chave) == 0 && tamanhoArvore >= 3)
        {
             //cout << "3" << endl;
            ehCheiaResultado = false;
            return;
        }
    }

    getEhCheia(no->filhoDireita, tamanhoArvore, ehCheiaResultado);

}


/*Uma árvore completa é aquela em que se n
 é um nó com alguma sub-árvores vazias,
 então n se localiza no penúltimo ou no
 último nível. Portanto, toda árvore cheia
 é completa e estritamente binária.*/
bool ArvoreBinariaBusca::ehCompleta()
{
    int tamanhoArvore = getTamanhoArvore(raiz);
    bool ehCompletaResultado = true;

    getEhCompleta(raiz, tamanhoArvore, ehCompletaResultado);

    
    return ehCompletaResultado;
}

// Método recursivo que retona se a árvore é completa ou não
void ArvoreBinariaBusca::getEhCompleta(No *no, int &tamanhoArvore, bool &ehCompletaResultado)
{

    if (no == nullptr)
    {
        return;
    }

    getEhCompleta(no->filhoEsquerda, tamanhoArvore, ehCompletaResultado);

    if (tamanhoArvore == 1)
    {
        ehCompletaResultado = false;
        return;
    }else if (no->filhoDireita != nullptr && no->filhoEsquerda == nullptr || no->filhoDireita == nullptr && no->filhoEsquerda != nullptr || no->filhoDireita == nullptr && no->filhoEsquerda == nullptr){
        
        if(alturaNo(no->chave) != tamanhoArvore-1 && alturaNo(no->chave) != tamanhoArvore-2 ){
            ehCompletaResultado = false;
            return;
        }
    }

    getEhCompleta(no->filhoDireita, tamanhoArvore, ehCompletaResultado);
}

// Método que chama o método recursivo inserirNo
bool ArvoreBinariaBusca::inserir(int chave)
{
    if(buscar(chave) == true ){
        cout << "O elemento já existe na árvore"<< endl;
        return false;
    }
    raiz = inserirNo(raiz, chave);
    return true;
    //inserirNaoRecursivo(chave);
}

// Método recursivo que insere um novo elemento na árvore. 
No *ArvoreBinariaBusca::inserirNo(No *no, int chave)
{

    if (no == nullptr)
    {
        return new No(chave);
    }

    if (chave < no->chave)
    {
        no->filhoEsquerda = inserirNo(no->filhoEsquerda, chave);
    }
    else
    {
        no->filhoDireita = inserirNo(no->filhoDireita, chave);
    }

    no->tamanho++; // Atualiza o tamanho da subárvore enraizada neste nó

    return no;
}


// Inserir de forma não recursiva (achei muito grande, resolvi deixar de forma recursiva)!

void ArvoreBinariaBusca::inserirNaoRecursivo(int chave)
{

    No *NoNovo = new No(chave);
    NoNovo->filhoDireita = nullptr;
    NoNovo->filhoEsquerda = nullptr;

    if (raiz == nullptr)
    {
        raiz = NoNovo;
    }
    else
    {
        //Testar se da vazamento de mémoria (Se der tempo)
        No *temp = raiz;

        while (temp != nullptr)
        {
            if (chave < temp->chave)
            {

                if (temp->filhoEsquerda == nullptr)
                {
                    temp->filhoEsquerda = NoNovo;
                    break;
                }
                else
                {
                    temp = temp->filhoEsquerda;
                }
            }
            else
            {

                if (temp->filhoDireita == nullptr)
                {
                    temp->filhoDireita = NoNovo;
                    break;
                }
                else
                {
                    temp = temp->filhoEsquerda;
                }
            }
        }
      
    }

    // Atualizar o tamanho da subárvore enraizada em cada nó percorrido

    No *percorrer = raiz;
    while (percorrer != nullptr)
    {
        percorrer->tamanho++;
        if (chave < percorrer->chave)
        {
            percorrer = percorrer->filhoEsquerda;
        }
        else
        {
            percorrer = percorrer->filhoDireita;
        }
    }
}


// conjunto de métodos que deletam um valor da árvore.
bool ArvoreBinariaBusca::removeInicial(int chave){

    if(buscar(chave) == true ){
        cout << "O elemento não existe na árvore"<< endl;
        return false;
    }
    remove(chave);
    return true;
}   

void ArvoreBinariaBusca::remove(int chave){

    if(buscar(chave) == false ){
        cout << "O elemento não existe na árvore"<< endl;
        return;
    }

    removerBusca(chave, raiz);

    No *percorrer = raiz;
    while (percorrer != nullptr)
    {
        percorrer->tamanho--;
        if (chave < percorrer->chave)
        {
            percorrer = percorrer->filhoEsquerda;
        }
        else
        {
            percorrer = percorrer->filhoDireita;
        }
    }

    if(buscar(chave) == false ){
        cout << "O elemento foi removido da árvore"<< endl;
        return;
    }
}

void ArvoreBinariaBusca::removerBusca(int chave, No *& noatual){
    
    if(chave < noatual->chave){
        removerBusca(chave, noatual->filhoEsquerda);
    }else if(chave > noatual->chave){
        removerBusca(chave, noatual->filhoDireita); 
    }else{
        deletarNo(noatual);
    }

}

void ArvoreBinariaBusca::deletarNo(No *& noatual){
    No * temp = noatual;

    if(noatual->filhoEsquerda == nullptr){
        noatual  = noatual->filhoDireita;
        delete temp;
    }else if (noatual->filhoDireita == nullptr){
        noatual  = noatual->filhoEsquerda; 
        delete temp;
    }else{
        int chaveSecessor;
        obterSucessor(chaveSecessor, noatual);
        noatual->chave = chaveSecessor;

        removerBusca(chaveSecessor, noatual->filhoDireita);
    }

}

void ArvoreBinariaBusca::obterSucessor(int &chave, No* temp ){
        temp = temp->filhoDireita;

        while(temp->filhoEsquerda != nullptr){
            temp = temp->filhoEsquerda;
        }

        chave = temp->chave;
}

// ----------------------------------------------------------------

