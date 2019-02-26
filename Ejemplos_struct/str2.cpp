#include <iostream>

using namespace std;

struct complejo{
    double real;
    double im;
};

complejo suma(complejo x,complejo y);
complejo resta(complejo x,complejo y);
complejo producto(complejo x,complejo y);
complejo division(complejo x,complejo y);

int main()
{
    complejo x;
    complejo y;
    cout << "Introduce dos numeos complejos: " << endl;
    cin >> x.real >> x.im >> y.real >> y.im;
    complejo z;
    z=suma(x,y);
    cout << "Su suma es: " << z.real << " " << " + " << z.im << "i" << endl;
    z=resta(x,y);
    cout << "Su diferencia es: " << z.real << " " << " + " << z.im << "i" << endl;
    z=producto(x,y);
    cout << "Su producto es: " << z.real << " " << " + " << z.im << "i" << endl;
    z=division(x,y);
    cout << "Su cociente es: " << z.real << " " << " + " << z.im << "i" << endl;
    return 0;
}


complejo suma(complejo x,complejo y){
    complejo z;
    z.real=x.real+y.real;
    z.im=x.im+y.im;
    return(z);
}
complejo resta(complejo x,complejo y){
    complejo z;
    z.real=x.real-y.real;
    z.im=x.im-y.im;
    return(z);
}
complejo producto(complejo x,complejo y){
    complejo z;
    z.real=x.real*y.real-x.im*y.im;
    z.im=x.im*y.real+y.im*x.real;
    return(z);
}
complejo  division(complejo x,complejo y){
    double norma=y.real*y.real+y.im*y.im;
    complejo z;
    complejo conjugado;
    conjugado.real=y.real/norma;
    conjugado.im=-y.im/norma;
    z=producto(x,conjugado);
    return(z);
}
