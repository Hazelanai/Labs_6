#include <iostream>
using namespace std;

int main() {
  int n;
  int num_scrto = 13;

  do{
    cout <<"Ingrese un numero entero" << endl;
    cin >> n;
    
    if(n == num_scrto){
      cout <<"El numero secreto es " << num_scrto << endl;

    }else if(n >= 10 && n <= 14){
      cout <<"Estas muy cerca" << endl;

    }else
      cout <<"Te pasaste por mucho" << endl;

  }while (n != num_scrto);
  return 0;
}