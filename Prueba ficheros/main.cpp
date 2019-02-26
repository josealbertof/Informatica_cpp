#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

struct articulo{
    string nombre;
    double preciounidad;
};

void mostrararticulos(struct articulo v[],int n){
    for(int i=0;i<n;i++){
        cout << i+1 << ". " << v[i].nombre << " " << v[i].preciounidad << endl;
    }
}

int main()
{
    struct articulo v[10];

    cout << "Tienes los siguientes productos disponibles: " << endl;
    ifstream productos ("productos.txt");

    int n;
    productos >> n;
    for(int i=0;i<n;i++){
        productos >> v[i].nombre;
        productos >> v[i].preciounidad;
    }
    productos.close();
    mostrararticulos(v,n);

    double total=0,aux=0;
    int l=0,i=1;
    string a="Cliente ";
    ofstream ticket ("cliente.txt");



    while(l!=-2){
        ticket << a << i << endl;
        cout << "Numero de producto: " << endl;
        cin >> l;

        while(l!=-1 && l!=-2){
            ticket << v[l-1].nombre << ',' << ' ';
            cout << "Cantidad: " << endl;
            int unidades;
            cin >> unidades;
            ticket << unidades << ',' << ' ' ;
            ticket << v[l-1].preciounidad*unidades;
            ticket << endl;
            aux+=v[l-1].preciounidad*unidades;
            total+=aux;

            cout << "Numero de producto: " << endl;
            cin >> l;

        }

        if(l==-2 || l==-1){
            cout << "Gracias por su compra, que tenga un buen dia, le esperamos pronto. " << endl;
            ticket << aux;
            aux=0;
        }

        if(l==-1){
            cout << "Siguiente, por favor. " << endl;
            ticket << endl;
            i++;
        }
    }
    ticket << endl << total;
    ticket.close();
    return 0;
}
