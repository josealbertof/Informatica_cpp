#include <iostream>

using namespace std;

int main()
{
    int aro;
    cout << "Torres de Hanoi: " << endl;
    do{
        cout << "Inserte el numero de aros: " << endl;
        cin >> aro;
    }while(aro<=0);

    int A[aro];
    int B[aro];
    int C[aro];
    bool par;
    int tamA=aro,tamB=0,tamC=0;
    char uno='A';

    for(int i=0;i<aro;i++){
        A[i]=aro-i;
        B[i]=0;
        C[i]=0;
    }

    if(aro%2==0){
        par=true;
        cout << "Mueve el aro 1 desde A hasta B"<< endl;
        B[0]=1;
        tamB++;
        A[aro-1]=0;
        tamA--;
        uno='B';
    }
    else{
        par=false;
        cout << "Mueve el aro 1 desde A hasta C"<< endl;
        C[0]=1;
        tamC++;
        A[aro-1]=0;
        tamA--;
        uno='C';
    }

    int ok;
    while(tamC!=aro){
        switch(uno){
            case 'A':
                if(tamB==0){
                    cout << "Mueve el aro " << C[tamC-1] << " desde C hasta B"<< endl;
                    B[tamB]=C[tamC-1];
                    C[tamC-1]=0;
                    tamB++;
                    tamC--;
                }
                else if(tamC==0){
                    cout << "Mueve el aro " << B[tamB-1] << " desde B hasta C"<< endl;
                    C[tamC]=B[tamB-1];
                    B[tamB-1]=0;
                    tamC++;
                    tamB--;
                }
                else if(B[tamB-1]>C[tamC-1]){
                    cout << "Mueve el aro " << C[tamC-1] << " desde C hasta B"<< endl;
                    B[tamB]=C[tamC-1];
                    C[tamC-1]=0;
                    tamB++;
                    tamC--;
                }
                else{
                    cout << "Mueve el aro " << B[tamB-1] << " desde B hasta C"<< endl;
                    C[tamC]=B[tamB-1];
                    B[tamB-1]=0;
                    tamC++;
                    tamB--;
                }
                if(par){
                    cout << "Mueve el aro 1 desde A hasta B"<< endl;
                    B[tamB]=A[tamA-1];
                    A[tamA-1]=0;
                    tamB++;
                    tamA--;
                    uno='B';
                }
                else{
                    cout << "Mueve el aro 1 desde A hasta C"<< endl;
                    C[tamC]=A[tamA-1];
                    A[tamA-1]=0;
                    tamC++;
                    tamA--;
                    uno='C';
                }
                break;
            case 'B':
                if(tamA==0){
                    cout << "Mueve el aro " << C[tamC-1] << " desde C hasta A"<< endl;
                    A[tamA]=C[tamC-1];
                    C[tamC-1]=0;
                    tamA++;
                    tamC--;
                }
                else if(tamC==0){
                    cout << "Mueve el aro " << A[tamA-1] << " desde A hasta C"<< endl;
                    C[tamC]=A[tamA-1];
                    A[tamA-1]=0;
                    tamC++;
                    tamA--;
                }
                else if(A[tamA-1]>C[tamC-1]){
                    cout << "Mueve el aro " << C[tamC-1] << " desde C hasta A"<< endl;
                    A[tamA]=C[tamC-1];
                    C[tamC-1]=0;
                    tamA++;
                    tamC--;
                }
                else{
                    cout << "Mueve el aro " << A[tamA-1] << " desde A hasta C"<< endl;
                    C[tamC]=A[tamA-1];
                    A[tamA-1]=0;
                    tamC++;
                    tamA--;
                }
                if(par){
                    cout << "Mueve el aro 1 desde B hasta C"<< endl;
                    C[tamC]=B[tamB-1];
                    B[tamB-1]=0;
                    tamC++;
                    tamB--;
                    uno='C';
                }
                else{
                    cout << "Mueve el aro 1 desde B hasta A"<< endl;
                    A[tamA]=B[tamB-1];
                    B[tamB-1]=0;
                    tamA++;
                    tamB--;
                    uno='A';
                }
                break;
            case 'C':
                if(tamB==0){
                    cout << "Mueve el aro " << A[tamA-1] << " desde A hasta B"<< endl;
                    B[tamB]=A[tamA-1];
                    A[tamA-1]=0;
                    tamB++;
                    tamA--;
                }
                else if(tamA==0){
                    cout << "Mueve el aro " << B[tamB-1] << " desde B hasta A"<< endl;
                    A[tamA]=B[tamB-1];
                    B[tamB-1]=0;
                    tamA++;
                    tamB--;
                }
                else if(B[tamB-1]>A[tamA-1]){
                    cout << "Mueve el aro " << A[tamA-1] << " desde A hasta B"<< endl;
                    B[tamB]=A[tamA-1];
                    A[tamA-1]=0;
                    tamB++;
                    tamA--;
                }
                else{
                    cout << "Mueve el aro " << B[tamB-1] << " desde B hasta A"<< endl;
                    A[tamA]=B[tamB-1];
                    B[tamB-1]=0;
                    tamA++;
                    tamB--;
                }
                if(par){
                    cout << "Mueve el aro 1 desde C hasta A"<< endl;
                    A[tamA]=C[tamC-1];
                    C[tamC-1]=0;
                    tamA++;
                    tamC--;
                    uno='A';
                }
                else{
                    cout << "Mueve el aro 1 desde C hasta B"<< endl;
                    B[tamB]=C[tamC-1];
                    C[tamC-1]=0;
                    tamB++;
                    tamC--;
                    uno='B';
                }
                break;
        }
    }

    int res=1;
    for(int i=0;i<aro;i++){
        res*=2;
    }
    cout << "El numero de movimientos es: " << res-1 << endl;
    return 0;
}
