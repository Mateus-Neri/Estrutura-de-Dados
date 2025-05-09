#include <iostream>
#include "EntradaCinema.cpp";

using namespace std;

int main(){
  
  EntradaDeCinema cliente1("Titanic", "14:30", 15, 4, 37.50);
  EntradaDeCinema cliente2("Vingadores", "18:00", 15, 2, 37.50);

  cliente1.CalculaDesconto(27,8,2001);
  cliente2.CalculaDesconto(01,04,2012);

  cliente1.to_string();
  cliente2.to_string();



  return 0;
}