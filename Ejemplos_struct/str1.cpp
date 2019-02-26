#include <iostream>

using namespace std;

struct punto{
        int x;
        int y;
};

void maxi_mini(punto v[],int posi[],int tam);

int main()
{

    struct punto v[100];
    int posi[10];
    int dato1,dato2;
    int tam=0;
    cout << "Introduce el primer punto: " << endl;
    cin >> dato1 >> dato2;
    while(dato1!=-1&&dato2!=-1){
        v[tam].x=dato1;
        v[tam].y=dato2;
        tam++;
        cout << "Introduce el siguiente punto: " << endl;
        cin >> dato1 >> dato2;
    }
    maxi_mini(v,posi,tam);
    cout << "El mínimo de x esta en la posición: " << posi[0] << " es " << v[posi[0]].x << endl;
    cout << "El máximo de x esta en la posición: " << posi[1] << " es " << v[posi[1]].x << endl;
    cout << "El mínimo de y esta en la posición: " << posi[2] << " es " << v[posi[2]].y << endl;
    cout << "El máximo de y esta en la posición: " << posi[3] << " es " << v[posi[3]].y << endl;

    return 0;
}
void maxi_mini(punto v[],int posi[],int tam){
    posi[0]=0;
    posi[1]=0;
    posi[2]=0;
    posi[3]=0;
    for(int i=1;i<tam;i++){
        if(v[i].x<posi[0])
            posi[0]=i;
        if(v[i].x>posi[1])
            posi[1]=i;
        if(v[i].y<posi[0])
            posi[2]=i;
        if(v[i].y>posi[0])
            posi[3]=i;
    }
}
