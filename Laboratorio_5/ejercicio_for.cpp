#include <iostream>
using namespace std;

int main(){
    int n;

    cout <<"Ingrese un numero" << endl;
    cin >> n;

    for(int i = 1; i <= 20; i++ ){
        cout << n << "x" << i << "=" << n*i << endl;
    }
    
    return 0;
}