#include <iostream>
using namespace std;
string Promt();
void getMinMax(int p[], int number, int *Max,int *Min);

int main()
{

    cout<<Promt()<<endl;
    cout<<endl;
    int number;
    cout<<"Enter the amount of number you wanna check: ";
    cin>>number;
    cin.ignore(100,'\n');

    int *p= new int [number];
    int Max,Min;
    getMinMax(p,number,&Max,&Min);
    cout<<"Maximum Number is = "<<Max<<endl;
    cout<<"Minimum Number is = "<<Min<<endl;

delete[]p;
}
string Promt()
{
    cout<<"This program can tell u the Maximum and Minimum Number.\nFirst you need to input how many numbers you want to check for exmple u have 10 different number and you want to know the maximum and the minimum number.\nso,at first input the total number you want to check after that input those numbers.";
}

void getMinMax(int p[], int number, int *Max,int *Min)
{
    if(number<=0)
    {
        cout<<"Invalid input :)\n";

        cout<<"Enter the amount of number you wanna check: ";
        cin>>number;
    }
    for(int i =0; i<number; ++i)
    {
        cout<<"Number "<<i+1<<" : ";
        cin>>p[i];
        cout<<'\n';
    }
    *Max=p[0];
    *Min=p[0];

    for(int i=1; i<number; ++i)
    {

        if(p[i]<*Min)
        {
            *Min=p[i];
        }

        if(p[i]>*Max)
        {
            *Max= p[i];
        }


    }

}



