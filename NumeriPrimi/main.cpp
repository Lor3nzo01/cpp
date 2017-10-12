#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
using namespace std;

int main()
{
    clock_t t_start, t_end;
    double t_passed;
    cout<<"GENERATORE DI NUMERI PRIMI by Lorenzo De Luca"<<endl;
    unsigned long long max;
    cout<<"numero max(non deve essere obbligatoriamente primo): ";
    cin>>max;
    bool *primi = new bool[max+1];
    cout<<endl<<"Inizio del calcolo...";
    t_start = clock();
    memset(primi,true,max);
    for(unsigned long long i=3; i*i<max;i+=2)
    {
        for(unsigned long long l=i*2;l<=max;l+=i)primi[l]=false;
    }
    t_end = clock();t_passed = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    cout<<t_passed<<"seconds"<<endl<<"scrittura sul file...";
    ofstream file("primi.txt", ios::out);
    t_start = clock();
    file<<"2"<<endl;
    for(unsigned long long i=3; i<=max;i+=2)if(primi[i]==true)file<<i<<"\n";
    t_end = clock();t_passed = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    cout<<t_passed<<"seconds"<<endl<<"\\\\\\\\ END ////";
    file.close();
    return 0;
}
