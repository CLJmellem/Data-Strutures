//Nome: Cássio Luis Junqueira Mellem Filho
//TIA: 32089694

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


//Functions

    /*Ex11*/
float MulViaAdd(int num1, float num2)
{
    float mult = 0;
    for(int i = 0; i < num1; i++)
    {
        mult = num2 + mult;
    }

    return mult;
}


    /*Ex12*/
int Min(int num1, int num2)
{
    if (num1 < num2)
    {
        return num1;
    }
    else {
        return num2;
    }
}



    /*Ex13*/
int Max(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }else{
        return num2;
    }
}



    /*Ex14*/
int VowelsCount(string phrase)
{
    phrase.erase(remove(phrase.begin(), phrase.end(), ' '),
        phrase.end());

    string Vowel = "AaEeIiOoUu";
    int sizeV = Vowel.length();
    int sizeP = phrase.length();
    int verify = 0;


    for(int i = 0; i < sizeP; i++)
    {
        for (int j = 0; j < sizeV; j++) 
        {
            if (phrase[i] == Vowel[j]) 
            { 
                verify++;  
            }
        }
    }

    return verify;
}



    /*Ex15*/
float AreCirclesColliding(float x1, float y1, float radius1, float x2, float y2, float radius2)
{
    int sumRadius = radius1 + radius2;
    int distance = sqrt(pow((x1 + x2), 2) + pow((y1 + y2), 2));

    if (sumRadius > distance || sumRadius == distance)
        return true;
    else
        return false;
}



int main()
{
    setlocale(LC_ALL, "pt_BR");

    void Ex1();
    {
      /*int var1, var2, aux;
        cout << "Digite valor 1: "; cin >> var1;
        cout << "Digite valor 2: "; cin >> var2;
        aux = var1;
        var1 = var2;
        cout << "\nValor 1: " << var1 <<endl;
        cout << "Valor 2: " << aux; */
    }

    void Ex2();
    {
      /*int km, speed;
        float time;
        cout << "Digite a distância: "; cin >> km;
        cout << "Digite o tempo em horas: "; cin >> time;
        speed = km / time;
        cout <<"\n" << speed << "Km/h\n";
        if (speed > 90) 
        {
            cout << "Velocidade acima de 90!";
        } */
    }

    void ex3();
    {
     /* int verify = 0;
        char userHW;
        string vowel = "AaEeIiOoUu";
        cout << "Digite a letra: "; cin >> userHW;
        for(int i = 0; i < 10; i++)
        {
            if (vowel[i] == userHW)
            {
                verify++;
            }
        }
        if(verify > 0)
        {
            cout << "Letra é uma vogal";
        }
        else {
            cout << "Letra é uma consoante";
        } */
    }

    void ex4();
    {
     /* int num, num2;
        cout << "Digite um numero: "; cin >> num;
        num2 = num % 2;
        if(num2 == 1)
        {
            cout << "Numero ímpar";
        }else {
            cout << "Numero par";
        } */
    }

    void Ex5();
    {
      /*int x, y, f;
        cout << "X = "; cin >> x;
        cout << "Y = "; cin >> y;
        f = 3 * x + y;
        if(f == 8)
        {
            cout << "Ponto (" << x << "," << y << ") esta na reta";
        }else{
            cout << "Ponto (" << x << "," << y << ") não pertence a reta";
        } */
    }

    void Ex6();
    {
      /*int num, fatorial = 1;
        cout << "Digite o numero: "; cin >> num;
        for(int i = 1; i < num + 1; i++)
        {
            fatorial *= i;
        }
        
        cout << "Fatorial" << fatorial;  */
    }

    void Ex7();
    {
     /* int numVet[10];
        for (int i = 0; i < 10; i++)
        {
            cout << "Digite o valor do " << i << "º: "; cin >> numVet[i];
        }

        for(int j = 0; j < 10; j++)
        {
            int maior = 0, menor = 0;
            for(int k = 0; k < 10; k++)
            {
                if(numVet[j] > numVet[k])
                {
                    maior++;
                    if (maior == 9) { cout << "Maior numero: " << numVet[j] << endl; }
                }
                if(numVet[j] < numVet[k])
                {
                    menor++;
                    if (menor == 9) { cout << "Menor numero: " << numVet[j] << endl; }
                }
            }
        } */
    }

    void Ex8();
    {
     /* int n, n1, n2, nextNum;
        n1 = 1;
        n2 = 1;
        nextNum = 0;
        cout << "Quantidade para fibonacci: ";
        cin >> n;
        cout << "Fibonacci: ";
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1) {
                cout << n1 << ", ";
                continue;
            }
            if (i == 2) {
                cout << n2 << ", ";
                continue;
            }
            nextNum = n1 + n2;
            n1 = n2;
            n2 = nextNum;

            cout << nextNum << ", ";
        }*/
    } 

    void Ex9(); 
    {
      /*int numArray[10];
        cout << "Digite valor por valor! \n";
        for(int i = 9; i >= 0; i--)
        {
            cout << "Digite o valor: ";  cin >> numArray[i];
        }

        for(int j = 0; j < 10; j++)
        {
            cout << numArray[j] << ", ";
        } */
    }

    void Ex10();
    {
     /*   int lst[6]{};
        int aux = 0;

        for (int i = 0; i < 6; ++i) { cin >> lst[i]; }

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (lst[i] < lst[j])
                {
                    aux = lst[i];
                    lst[i] = lst[j];
                    lst[j] = aux;
                }
            }
        }
        for (int i = 0; i < 6; i++)
        {
            cout << lst[i] << ", ";
        } */
    }

    void Ex11();
    {
      /*  float real, mult;
        int numInt;
        cout << "Digite o numero inteiro: "; cin >> numInt;
        cout << "Digite o numero real:"; cin >> real;
        mult = MulViaAdd(numInt, real);

        cout << "Resultado da multiplicação: " << mult; */
    }

    void Ex12(); 
    {
        /*int num1, num2, menor;
        cout << "Digite o primeiro valor: "; cin >> num1;
        cout << "Digite o segundo valor: "; cin >> num2;

        menor = Min(num1, num2);
        cout << "\n" << menor << " é o menor número"; */
    }

    void Ex13();
    {
        /*int num1, num2, maior;
        cout << "Digite o primeiro valor: "; cin >> num1;
        cout << "Digite o segundo valor: "; cin >> num2;

        maior = Max(num1, num2);
        cout << "\n" << maior << " é o maior número";*/
    }

    void Ex14();
    {
        /*string phrase;
        int quant;
        cout << "Digite uma frase: ";
        getline(cin, phrase);
       
        quant = VowelsCount(phrase);
        cout << "Quantidade de vogais na frase: " << quant;*/
    }

    void Ex15();
    {
        /*float x1, y1, x2, y2, radius1, radius2;
        
        cout << "Digite o valor de x1: "; cin >> x1;
        cout << "Digite o valor de y1: "; cin >> y1;
        cout << "Digite o valor de x2: "; cin >> x2;
        cout << "Digite o valor de y2: "; cin >> y2;
        cout << "Digite o valor do raio 1: "; cin >> radius1;
        cout << "Digite o valor do raio 2: "; cin >> radius2;

        bool colliding = AreCirclesColliding(x1, y1, x2, y2, radius1, radius2);
        if (colliding == 0)
            cout << "False";
        else
            cout << "True"; */
    }

}


