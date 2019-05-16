#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

#define INFINITE_FLOAT numeric_limits<float>::max()
#define INFINITE_INT numeric_limits<int>::max()

using namespace std;


class GrafoNaoDirigido
{
private:
    vector< unordered_map<int, float> > adjs;
    vector<string> rotulos;
    int qtdArestas_;

public:
    GrafoNaoDirigido();
    ~GrafoNaoDirigido();

    // le o arquivop
    int ler(string fileName);

    //retorna o id do vertice inserido
    int inserirVertice(string rotulo);

    //inserir nova aresta
    void inserirAresta(int u, int v, float peso);

    // imprime o grafo
    void imprimir();

    // retorna a quantidade de vertices do grafo
    int qtdVertices();

    // retorna a quantidade de arestas do grafo
    int qtdArestas();

    // retorna o grau de um vertice v
    int grau(int v);

    // retorna o rotulo de um vertice v
    string rotulo(int v);

    // retorna a lista de vizinhos de um vertice v
    vector<int> vizinhos(int v);

    // retorna true caso exista uma aresta de u para v
    bool haAresta(int u, int v);

    // retorna o peso da aresta que liga u e v
    float peso(int u, int v);
};

#endif // UNDIRECTEDGRAPH_H
