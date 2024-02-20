#include <iostream>
#define C_BLUE "\033[34m"
#define C_BLACK "\033[30m"
using namespace std;

typedef struct
{
    string nome = " ";
    int ano = 0;
    int ava = 0;
    string diretor = " ";
    string genero = " ";
    int id = 0;

} movie;

void inf_filmes(movie *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nome do filme" << endl;

        cin >> (v + i)->nome;

        cout << "nome do diretor" << endl;

        cin >> (v + i)->diretor;

        cout << "ano do filme" << endl;

        cin >> (v + i)->ano;

        cout << "genero do filme" << endl;

        cin >> (v + i)->genero;

        cout << "Avaliação do filme" << endl;

        cin >> (v + i)->ava;
    }
}

void inf_extras(movie *v, int id)
{

    cout << "nome do diretor" << endl;
    cout << v[id].diretor << endl;

    cout << "ano do filme" << endl;
    cout << v[id].ano << endl;

    cout << "genero do filme" << endl;
    cout << v[id].genero << endl;
}

int max(movie *v, int n)
{
    int maior = 0;
    for (int i = 0; i < n; i++)
        if (v[i].ava < v[maior].ava)
            maior = i;
    return maior;
}
void troca(movie *a, movie *b)
{
    movie aux = *a;
    *a = *b;
    *b = aux;
}
void rec_selection(movie *v, int n)
{
    if (n > 1)
    {
        troca(&v[max(v, n)], &v[n - 1]);
        rec_selection(v, n - 1);
    }
}

int busca_bin_r(int x, movie *v, int inicio, int fim)
{
    if (inicio > fim)
        return -1;
    else
    {
        int meio = (inicio + fim) / 2;
        if (x == v[meio].id)
            return meio;
        else if (x < v[meio].id)
            busca_bin_r(x, v, inicio, meio - 1);
        else
            busca_bin_r(x, v, meio + 1, fim);
    }
    return x;
}
int main()
{
    int quant_filmes = 0, quantidade = 0, id = 0;
    char menu = 0;

    movie *filmes;

    cout << C_BLUE <<"Deseja cadastrar seus filmes assistido esse ano?" << endl;
    cout << "Por avaliação" << C_BLUE << endl;
    cout << "digite s" << C_BLUE << endl;
    cin >> menu;

    if (menu == 's')
    {
        cout << "digite quantos filmes deseja cadastrar?" << C_BLACK << endl;
        cin >> quant_filmes;
    }

    filmes = new (nothrow) movie[quant_filmes];

    inf_filmes(filmes, quant_filmes);

    rec_selection(filmes, quant_filmes);

    for (int i = 0; i < quant_filmes; i++)
    {
        cout << " id " << filmes->id << endl;

        cout << "nome do filme" << endl;

        cout << (filmes + i)->nome << endl;

        cout << "Avaliação do filme" << endl;

        cout << (filmes + i)->ava << endl;

        filmes->id++;
    }

    cout << "Deseja visualizar informações a mais do filme?" << C_BLACK << endl;
    cout << " digite s " << C_BLACK << endl;
    cin >> menu;
    if (menu == 's')
    {
        cout << "Digite id do filme" << endl;
        cin >> id;

        if (id < quant_filmes)
        {
            busca_bin_r(filmes->id, filmes, 0, quant_filmes);
            inf_extras(filmes, id);
        }
    }
    delete[] filmes;
}
