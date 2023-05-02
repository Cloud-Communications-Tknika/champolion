//https://aceptaelreto.com/problem/statement.php?id=660&cat=154

#include<iostream>

using namespace std;

bool contains(string diferentes_silabas[], int ext, string silaba);
bool is_vocal(char a);
void minusculizar_frase(string &frase);

int main()
{

    int iteraciones;
    string frase;
    string diferentes_silabas[1000];
    int silabas_distintas = 0;

    cin >> iteraciones;
    cin.ignore();

    string entradas[iteraciones];

    for(int ite = 0; ite < iteraciones; ite++)
    {
        getline(cin, frase);

        minusculizar_frase(frase);

        entradas[ite] = frase;
    }

    for(int ite = 0; ite < iteraciones; ite++)
    {
        for(int i = 0; i < silabas_distintas ; i++)
        {
            diferentes_silabas[i]= "";
        }
        
        int silabas_distintas = 0;
        string silaba = "";

        for(int i=0; i<entradas[ite].length(); i++)
        {
            if(is_vocal(entradas[ite][i]))
            {

                if((i==0)||(entradas[ite][i-1]==' '))
                {
                    silaba += entradas[ite][i];
                }
                else{
                    silaba += entradas[ite][i-1];
                    silaba += entradas[ite][i];
                }

                if(i<(entradas[ite].length() - 1) && (!is_vocal(entradas[ite][i+2]) || (!entradas[ite][i+2]==' ')) && entradas[ite][i+1]!=' ')
                {
                    silaba += entradas[ite][i+1];
                }

                if(!contains(diferentes_silabas, silabas_distintas, silaba))
                {
                    diferentes_silabas[silabas_distintas] = silaba;
                    silabas_distintas += 1;
                }

                silaba = "";

            }
        }

        cout  << silabas_distintas << "\n" ;


    }

    return 0;
}

bool contains(string diferentes_silabas[], int ext, string silaba)
{

    bool encontrado = false;
    int iteracion = 0;

    while((iteracion < ext) && (!encontrado))
    {
        if(diferentes_silabas[iteracion] == silaba)
        {
            encontrado = true;
        }

        iteracion++;
    }

    return encontrado;

}

bool is_vocal(char a)
{
    if((a=='a')||(a=='e')||(a=='i')||(a=='o')||(a=='u')||(a=='A')||(a=='E')||(a=='I')||(a=='O')||(a=='U'))
    {
        return true;
    }

    return false;
}

void minusculizar_frase(string &frase)
{
    for(int i=0; i<frase.length(); i++)
    {
        if((frase[i]>='A')&&(frase[i]<='Z')){
            frase[i] = frase[i] - 'A' + 'a';
        }
    }
}
