#include <iostream>
using namespace std;


void main_loop(char ans);
void loop1(int input);
void loop2(int input);
void findDominantValues(int data[], int size);
void findDominantFromAuto(int auto_survey[], int size);
void explanation(char ans);


int main()
{
    char ans;
    main_loop(ans);
}


void main_loop(char ans)

{

    char answer;
    do
    {

        int input;
        cout<<"There are two ways to find the dominant option: \n1)Automated(DEMO) or 2)User Input. \nPlease select either option 1 or 2 by pressing the corresponding number: ";
        cin>>input;
        system("CLS");

        if(input==1)
        {
            loop1(input);

        }
        else if(input==2)
        {
            loop2(input);

        }

        else
        {
            cout<<"Invalid Value :)\n"<<endl;
        }


        cout<<"Want to use this program again?(y/n): ";
        cin>>answer;
        cin.ignore(100,'\n');

        cout<<endl;

    }
    while(answer=='y' || answer=='Y');


}

void loop1(int input)

{


    cout<<"\nIn this program, you have ten data points {1, 3, 4, 2, 5, 6, 7, 8, 9, 1}. We will determine the dominant value from these data points.\nNote: You can modify the data points as desired by inputting them in the auto_data box.\n"<<endl;

    int auto_data[]= {1,3,4,2,5,6,7,8,9,1};

    int size= sizeof(auto_data)/sizeof(auto_data[0]);

    findDominantFromAuto(auto_data,size);

    char ans;
    cout<<"Want explanation?(y/n): ";
    cin>>ans;
    cin.ignore(100,'\n');
    if (ans=='y'||ans=='Y')
    {

        explanation(ans);

    }
    cout<<endl;
}

void loop2(int input)

{
    int size;
    cout << "\nEnter the size of the survey data: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid data size!" << endl;

    }

    int *surveyData= new int[size];
    cout << "Enter data:" <<endl;

    for (int i = 0; i < size; ++i)
    {
        cout << i + 1 << ") ";
        cin >> surveyData[i];
    }
    cout<<"Dominant value(s) of "<<"{ ";
    for (int i = 0; i < size; ++i)
    {

        cout<<surveyData[i]<<"  ";
    }
    cout<<"}";
    findDominantValues(surveyData, size);


    delete[]surveyData;

}

void findDominantValues(int data[], int size)
{
    const int Range = 1000;
    int counts[Range] = {0};


    for (int i = 0; i < size; ++i)
    {
        counts[data[i]]++;
    }


    int maxCount = 0;
    for (int i = 0; i < Range; ++i)
    {
        if (counts[i] > maxCount)
        {
            maxCount = counts[i];
        }
    }


    cout << " => ";
    bool Dominant = false;
    for (int i = 0; i < Range; ++i)
    {
        if (counts[i] == maxCount && maxCount > 1)
        {
            cout << i <<'\t';
            Dominant = true;
        }
    }



    if (!Dominant)
    {
        cout << "None";
    }

    cout <<endl;
}

void findDominantFromAuto(int auto_survey[], int size)
{

    int Range= 1000;
    int count[Range] = {0};

    for (int i = 0; i < size; ++i)
    {
        count[auto_survey[i]]++;
    }

    int max_count = 0;

    for (int i = 0; i < Range; ++i)
    {
        if (count[i] > max_count)
        {
            max_count = count[i];
        }
    }

    cout << "Dominant value(s) of {1, 3, 4, 2, 5, 6, 7, 8, 9, 1} => ";
    bool Dominant = false;
    for (int i = 0; i < Range; ++i)
    {
        if (count[i] == max_count && max_count>1)
        {

            cout << i <<'\t';
            Dominant = true;
        }
    }

    if(!Dominant)
    {
        cout<<"NONE";

    }
    cout<<endl;
}

void explanation(char ans)
{

    cout<<"This program outputs the most frequently occurring value in a data set.\nFor example, given the data set {1,3,4,2,5,6,7,8,9,1},the value 1 appears twice and no other value appears more than once.\nso 1 is the dominant value.";
    cout<<'\n'<<endl;
}

