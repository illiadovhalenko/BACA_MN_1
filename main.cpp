//Illia Dovhalenko
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
using namespace std;

//Funkcja signum zwracająca znak liczby
int sgn(float val){
    return (0. < val) - (val < 0.);
}


int main() {
    int N;  //liczba zestawow
    cin >> N;
    float sum;      //suma trzech liczb
    float product;      //iloczyn liczb
    float a0, a1, a2;       //kolejne liczby ciagu geometrycznego
    float r1, r2;       //mozliwe wspolczyniki
    float division, division_1;     //dzielenie sumy przez a1, i 1 - to dzielenie
    float delta_root, delta;        //pierwistek z delty, i delta
    cout << scientific;
    cout.precision(10);
//    cin>>sum;
//    cout<<sum<<endl;
    for (int i = 0; i < N; i++) {
        cin >> product >> sum;
        // cout<<product<<" "<<sum<<endl;
        a1 = cbrtf(product);        //a0*a1*a2=(a1/q)*(a1)*(a1*q)=product
        division = sum / a1;
        division_1 = 1- division;
        delta = (division_1-2)*(division_1+2);      //(division_1-4)^2=(division_1-2)*(division_1+2)
        delta_root= sqrtf(delta);           //pierwiastek z delty
        r1 = (-division_1- sgn(division_1)*delta_root)/2;       //wyznacznie roznwiazania rownania kwadratowego
        r2 = 1/r1;  //ciag moze byc albo rosnacy, albo malejacy
        if (a1 / r1 >= a1 * r1 ) {
            a0 = a1 / r1;
            a2 = a1 * r1;
        } else if (a1 / r2 >= a1 * r2) {
            a0 = a1 / r2;
            a2 = a1 * r2;
        } else {
            a0 = 0;
            a1 = 0;
            a2 = 0;
        }
        cout << a0 << " " << a1 << " " << a2 << endl;
    }
    return 0;
}
