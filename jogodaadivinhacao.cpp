#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    cout << "***************************************" << endl;
    cout << "* Boas vindas ao Jogo da Adivinhação! *" << endl;
    cout << "***************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade:" << endl;
    cout << "Facil(F), Medio(M) ou Dificil(D)" << endl;

    char dificuldade;
    cin >> dificuldade;


    int numero_de_tentativas;


    if(dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if(dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
     if(dificuldade == 'D'){
        numero_de_tentativas = 5;
    }

    srand(time(0));
    const int NUMERO_SECRETO = rand()%100;
    bool nao_acertou = true;

    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++)
    {

        cout << "tentativas: "<< tentativas << endl;

        int chute ;

        cout << "qual o seu chute ?" << endl;

        cin >> chute;
        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;


        cout << "seu chute foi :"<< chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou){
            cout << "parabens ! voce acertou o numero secreto" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior){
            cout << "seu chute foi maior que o numero secreto" << endl;
        }
        else  {
            cout << "seu chute foi menor que o numero secreto" << endl;
        
        }

    } 
    cout << "fim de jogo" << endl;
    if (nao_acertou)
    {
        cout << "voce perdeu ! tente novamente" << endl;
    }else{
    
    cout << "Voce acertou em " << tentativas << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "sua pontuacao foi de " << pontos << " pontos" << endl;
    }
}