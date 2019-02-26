#include <iostream>

using namespace std;
struct intervalo{
    double inferior;
    double superior;
};
void introducir(&intervalo i);
bool contenido(intervalo i,intervalo j);
void mostrar(intervalo i);
double distancia(intervalo i);
int main()
{
    bool introducir;
    do{

    }while();
    return 0;
}
void introducir(&intervalo i){
    double inf,sup;
    cout << "Introduce el extremo inferior: " << endl;
    cin >> inf;
    i.inferior=inf;
    cout << "Introduce el extremo superior: " << endl;
    i.superior=sup;
}
bool contenido(intervalo i,intervalo j){
    bool cont=true;
    if(i.inf<j.inf)
        cont=false;
    if(i.sup>j.sup)
        cont=false;
    return(cont);
}
void mostrar(intervalo i){
    cout << "[" << i.inf << "," << i.sup << "]";
}
double distancia(intervalo i){
    return(i.sup-i.inf);
}
