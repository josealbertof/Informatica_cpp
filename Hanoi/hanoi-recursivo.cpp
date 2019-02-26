#include <iostream>

using namespace std;
void hanoi(int aro,char desde,char aux,char hasta)
{
    if(aro>0){
        hanoi(aro-1,desde,hasta,aux);
        cout << "Mueve el aro " << aro << " desde " << desde << " hasta " << hasta << endl;
        hanoi(aro-1,aux,desde,hasta);
    }
}

int main()
{
    int aro;
    cout << "Torres de Hanoi: " << endl;
    cout << "Inserte el numero de aros: " << endl;
    cin >> aro;
    hanoi(aro,'A','B','C');
    int res=1;
    for(int i=0;i<aro;i++){
        res*=2;
    }
    cout << "El numero de movimientos es: " << res-1 << endl;
    return 0;
}

