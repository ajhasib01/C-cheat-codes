#include <iostream>
using namespace std;
void findDominantValues(int data[], int size);

void findDominantFromAuto(int auto_survey[], int size);


void explanation(char ans)
{

    cout<<"This Dominant program simply output the maximum number count.\nFor example - {1,3,4,2,5,6,7,8,9,1} Here you can see 10 data and the data (1) appears two times and there is no other data more than once.\nSo,1 is the Dominant value here.";
    cout<<'\n'<<endl;
}
int main()
{
    char answer;

    int size;
    do
    {
        int input;
        cout<<"There are two ways to find the dominant option: \n1)Automated or 2)User Input. \nPlease select either option 1 or 2 by pressing the corresponding number: ";
        cin>>input;
        system("CLS");
        if(input==1)
        {
            cout<<"\nIn this automated program you have 10 data {1,3,4,2,5,6,7,8,9,1} and from these data we will find the Dominant value.\nNOTE-(You can change the data as you wish,Just input the data inside the auto_data box.)\n"<<endl;

            int auto_data[]= {1,3,4,2,5,6,7,8,9,1};

            int size= sizeof(auto_data)/sizeof(auto_data[0]);

            findDominantFromAuto(auto_data,size);

            char ans;
            cout<<"Want explanation?(y/n): ";
            cin>>ans;
            if (ans=='y'||ans=='Y')
            {

                explanation(ans);

            }
            cout<<endl;
        }

        else if(input==2)
        {

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

            findDominantValues(surveyData, size);


            delete[]surveyData;
        }

        else{
            cout<<"Invalid Value :)\n"<<endl;
        }


cout<<"Want to use this program again?(y/n): ";
        cin>>answer;

        cout<<endl;

    }
    while(answer=='y' || answer=='Y');

}

void findDominantValues(int data[], int size)
{
    const int MAX_VALUE = 1000;
    int counts[MAX_VALUE] = {0};


    for (int i = 0; i < size; ++i)
    {
        counts[data[i]]++;
    }


    int maxCount = 0;
    for (int i = 0; i < MAX_VALUE; ++i)
    {
        if (counts[i] > maxCount)
        {
            maxCount = counts[i];
        }
    }


    cout << "Dominant value(s): ";
    bool Dominant = false;
    for (int i = 0; i < MAX_VALUE; ++i)
    {
        if (counts[i] == maxCount && maxCount > 1)
        {
            cout << i << " ";
            Dominant = true;
        }
}



   if (!Dominant)
    {
        cout << "None"<<endl;;
    }

    cout <<endl;
}

int MAX_VALUE= 1000;
void findDominantFromAuto(int auto_survey[], int size)
{
    int count[MAX_VALUE] = {0};

    for (int i = 0; i < size; ++i)
    {
        count[auto_survey[i]]++;
    }

    int max_count = 0;

    for (int i = 0; i < MAX_VALUE; ++i)
    {
        if (count[i] > max_count)
        {
            max_count = count[i];
        }
    }

    cout << "Dominant value(s) of {1,3,4,2,5,6,7,8,9,1} : ";
    bool Dominant = false;
    for (int i = 0; i < MAX_VALUE; ++i)
    {
        if (count[i] == max_count && max_count>1)
        {

            cout << i << " "<<endl;
            Dominant = true;
        }
    }
    if(!Dominant)
    {
        cout<<"NONE"<<endl;

    }
    cout<<endl;
}

