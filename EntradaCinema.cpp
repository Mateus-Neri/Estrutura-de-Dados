#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class EntradaDeCinema{

  public:
    int diaFilme, sala;
    string nomeFilme, horario;
    float valor;

    EntradaDeCinema(string nomeFilme, string hora, int dia, int sala, float preco){

      this -> nomeFilme = nomeFilme;
      diaFilme = dia;
      this -> sala = sala;
      horario = hora;
      valor = preco;
    }

    int Idade(int d, int m, int a){
      
      time_t agora = time(0);//Armazena a data atual
      tm* dataAtual = localtime(&agora); /*Ponteiro para estrutura 
      tm com as informações de data*/

      int anoAtual = 1900 + dataAtual -> tm_year;
      int mesAtual = 1 + dataAtual -> tm_mon;
      int diaAtual = dataAtual -> tm_mday;

      int idade = anoAtual - a; //Idade

      if(m > mesAtual || (m == mesAtual && d < diaAtual)){//Verifica se não fez aniversario
        idade--; //Se não fez aniversário, idade diminui um ano.
      }

      return idade;
    }



    float CalculaDesconto(int d, int m, int a){
      int idade = Idade(d,m,a); //Calcula a idade
      float desconto;

      //Aplica os descontos baseados nas idades
      if(idade < 12){
        desconto = valor * 0.50;

      }else if(idade >= 12 && idade <= 15){
        desconto = valor * 0.40;

      }else if(idade > 15 && idade <= 20){
        desconto = valor * 0.30;

      }else{
        desconto = valor * 0.20;
      }

      // Valor do atributo agora tem os descontos
      valor = valor - desconto;

      //Calcula o desconto referente a hora da sessão
      valor = CalculaDescontoHorario();

      //Valor atualizado com todos descontos
      return valor;
    }

    float CalculaDescontoHorario(){

      /*Transforma o atributo hora que vem como String
      em inteiro para fazer a comparação*/
      int hora = stoi(horario.substr(0, 2));
      float desconto;

      if(hora > 1 && hora <= 16){
        desconto = valor * 0.10;
        valor = valor - desconto;
      }

      //Retorna o valor com desconto
      return valor;

    }

    void to_string(){


      //Traz as informações do ingresso
      cout<< "Filme: " << nomeFilme << ", Horario: " << horario <<
       ", Sala: " << sala << ", Preco: R$" << valor << endl;
    }
};

