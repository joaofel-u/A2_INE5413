#include "../include/UndirectedGraph.h"

GrafoNaoDirigido::GrafoNaoDirigido()
{
    adjs = *(new vector< unordered_map<int, float> >());
    rotulos = *(new vector<string>());
    qtdArestas_ = 0;
    inserirVertice("NULL");  // vertice nulo para normalizar id dos vertices com posicao no vetor
}

GrafoNaoDirigido::~GrafoNaoDirigido()
{
    // dtor
}

int GrafoNaoDirigido::ler(string fileName)
{
    ifstream myReadFile;
    myReadFile.open(fileName);
    if (myReadFile.fail()) {
        return 0;
    }
    // Leitura do arquivo e construcao do grafo
    string output;
    int vertices;

    if (myReadFile.is_open()) {
        myReadFile >> output; //descarta string *vertices
        myReadFile >> output; //pega a quantidade de vertices
        vertices = stoi(output);

        for (size_t i = 0; i < vertices; i++) {
            int vertice;
            string rotulo;
            myReadFile >> vertice;
            getline(myReadFile, rotulo);
            inserirVertice(rotulo);
        }

        myReadFile >> output; //descarta string *edges

        while (true) {
            int verticeOrigem, verticeDestino;
            float peso;
            myReadFile >> verticeOrigem >> verticeDestino >> peso;
            if (myReadFile.eof())
              break;
            inserirAresta(verticeOrigem, verticeDestino, peso);
        }
    }
    myReadFile.close();
    return 1;
}

int GrafoNaoDirigido::inserirVertice(string rotulo)
{
    adjs.push_back( unordered_map<int, float>() );
    rotulos.push_back( rotulo );

    return adjs.size()-1;
}

void GrafoNaoDirigido::inserirAresta(int u, int v, float peso)
{
    adjs[u].emplace(v, peso);
    adjs[v].emplace(u, peso);
    qtdArestas_ ++;
}

int GrafoNaoDirigido::qtdVertices()
{
    return adjs.size()-1;
}

int GrafoNaoDirigido::qtdArestas()
{
    return qtdArestas_;
}

int GrafoNaoDirigido::grau(int v)
{
    return adjs[v].size();
}

string GrafoNaoDirigido::rotulo(int v)
{
    return rotulos[v];
}

vector<int> GrafoNaoDirigido::vizinhos(int v)
{
    int tam = adjs[v].size();
    vector<int> vizinhos = *(new vector<int>());

    for (auto it : adjs[v])
        vizinhos.push_back(it.first);

    return vizinhos;
}

bool GrafoNaoDirigido::haAresta(int u, int v)
{
    return adjs[u].find(v) != adjs[u].end();
}

float GrafoNaoDirigido::peso(int u, int v)
{
    if (u == v)
        return 0;

    auto it = adjs[u].find(v);
    if (it == adjs[u].end())
        return INFINITE_FLOAT;
    else
        return adjs[u][v];

}

void GrafoNaoDirigido::imprimir()
{
    for (size_t i = 1; i < rotulos.size(); i++) {
        cout << i <<": " << rotulos[i] << "\n";
    }

    cout << endl;

    for(int v = 1; v < adjs.size(); v++) {
        cout << v << ": ";
        for (auto pr: adjs[v])
            cout << "(" << pr.first << ", " << pr.second << "), ";

        cout << "\n";
    }
}
