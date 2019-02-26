#include <iostream>
#include <cstring>

using namespace std;
struct alumno{
    string nombre;
    double nota1;
    double nota2;
    double nota3;
};
void promediar(alumno v[],int tam,double notas[]);

int main()
{
    alumno v[20];
    string dato1;
    double dato2,dato3,dato4;
    int tam=0;
    bool introducir=true;
    while(introducir){
    cout << "Introduce los datos del alumno: " << endl;
    cin >> dato1 >> dato2 >> dato3 >> dato4;
    v[tam].nombre=dato1;
    v[tam].nota1=dato2;
    v[tam].nota2=dato3;
    v[tam].nota3=dato4;
    tam++;
    cout << "Si quiere parar introduzca 0: " << endl;
    int n;
    cin >> n;
    if(n==0)
        introducir=false;
    }
    double notas[10];
    promediar(v,tam,notas);
    for(int i=0;i<tam;i++){
        cout << v[i].nombre <<  "     ";
        if(v[i].nota1>=notas[0])
            cout << "Aprobado    ";
        else
            cout << "Suspenso    ";
        if(v[i].nota2>=notas[1])
            cout << "Aprobado    ";
        else
            cout << "Suspenso    ";
        if(v[i].nota3>=notas[2])
            cout << "Aprobado    ";
        else
            cout << "Suspenso    ";

        cout << endl;
    }

    return 0;
}

void promediar(alumno v[],int tam,double notas[]){
    double suma1,suma2,suma3;
    for(int i=0;i<tam;i++){
        suma1+=v[i].nota1;
        suma2+=v[i].nota2;
        suma3+=v[i].nota3;
    }
    notas[0]=suma1/tam;
    notas[1]=suma2/tam;
    notas[2]=suma3/tam;
}
