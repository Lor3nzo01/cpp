#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout<<"GENERATORE DI NUMERI PRIMI by Lorenzo De Luca"<<endl;
    unsigned long long max;
    cout<<"numero max(non deve essere obbligatoriamente primo): ";
    cin>>max;
    bool primi[max];
    for (unsigned long long i=1;i<=max;i+=2) primi[i]=true;
    for(unsigned long long i=3; i*i<=max;i+=2)
    {
        for(unsigned long long l=i*2,m=3;l<=max;l=i*m,m++)primi[l]=false;
    }
    ofstream file("primi.txt", ios::out);
    file<<"2"<<endl; //il 2 è l'unico numero pari per cui per risparmiare tempo lo scriviamo direttamente
    for(unsigned long long i=3; i<=max;i+=2)if(primi[i]==true)file<<i<<endl;
    file.close();
    cout<<"THE END";
    return 0;
}
