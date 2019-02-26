#include <iostream>

using namespace std;
void laberinto(int &i,int &j,int M[][100],int &poli);
void crear_laberinto(int m[][100],int fil,int col);
void mostrar_vector(int v[],int cont);

int main()
{
    int M[100][100];
    cout << "Introduce el tamaño del laberinto" << endl;
    int fil,col;
    cin >> fil >> col;
    for(int i=0;i<=fil;i++)
        for(int j=0;j<=col;j++)
            M[i][j]=0;
    crear_laberinto(M,fil,col);
    cout << "Introduce la posicion inicial del raton y del queso" << endl;
    int i,j,pos_y,pos_x;
    cin >> i >> j >> pos_y >> pos_x;
    for(int i=0;i<=fil+1;i++){
        for(int j=0;j<=col+1;j++)
            cout << M[i][j];
        cout << endl;
    }
    int dato1=0,dato2=0;
    while(dato1>=0&&dato2>=0){
        M[dato1][dato2]=1;
        cout << "Introduce los obstaculos" << endl;
        cin >> dato1>>dato2;
    }
    M[pos_y][pos_x]=0;
    int poli=200000;
    int v[1000];
    int cont=0;
    v[0]=i,v[1]=j;
    while(i!=pos_y||j!=pos_x){
        laberinto(i,j,M,poli);
        cont++;
        v[2*cont]=i;
        v[2*cont+1]=j;
    }
    mostrar_vector(v,cont);

    return 0;
}
void laberinto(int &i,int &j,int M[][100],int &poli){
    int politicas=poli%4;
    switch (politicas)
    {
        case 0:
                if(M[i][j-1]!=1){
                    j--;
                    poli--;
                }else
                    if(M[i+1][j]!=1){
                        i++;
                    }else
                        if(M[i][j+1]!=1){
                            j++;
                            poli++;

                        }else{
                            i--;
                            poli+=2;
                        }
                break;
        case 1:
                if(M[i+1][j]!=1){
                    i++;
                    poli--;
                }else
                    if(M[i][j+1]!=1){
                        j++;
                    }else
                        if(M[i-1][j]!=1){
                            i--;
                            poli++;

                        }else{
                            j--;
                            poli+=2;
                        }
                break;
        case 2:
                if(M[i][j+1]!=1){
                    j++;
                    poli--;
                }else
                    if(M[i-1][j]!=1){
                        i--;
                    }else
                        if(M[i][j-1]!=1){
                            j--;
                            poli++;

                        }else{
                            i++;
                            poli+=2;
                        }
                break;
        case 3:
                if(M[i-1][j]!=1){
                    i--;
                    poli--;
                }else
                    if(M[i][j-1]!=1){
                        j--;
                    }else
                        if(M[i+1][j]!=1){
                            i++;
                            poli++;

                        }else{
                            j++;
                            poli+=2;
                        }
                break;
    }
    }
void crear_laberinto(int m[][100],int fil,int col){
        for(int i=0;i<col+2;i++)
            m[0][i]=1;
        for(int j=1;j<=fil;j++){
            m[j][0]=1;
            m[j][col+1]=1;
        }
         for(int i=0;i<col+2;i++)
            m[fil+1][i]=1;
    }
void mostrar_vector(int v[],int cont){
    for(int i=0;i<=cont;i++)
        cout << " " << v[2*i] << "  " << v[2*i+1] << endl;
}

