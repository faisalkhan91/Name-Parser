#include <iostream>
#include <string>

using namespace std;

int NameParse(string Sname[], string Fname[], string Lname[]);

#define Size 5

//Main Function
int main()
{
    string Sname[Size], Fname[Size], Lname[Size]; //Defined String Array
    NameParse(Sname,Fname,Lname);
    return 0;
}

// Function to Parse a String
int NameParse (string Sname[], string Fname[], string Lname[])
{
    int i;
    string name[] = {"First", "Second", "Third", "Fourth", "Fifth"};

    cout<<"Enter the names below:\n";

    size_t pos, spos;

    for (i=0; i<Size; i++)          //For loop to input name
    {
        cout<<"\nPlease enter the "<<name[i]<<" name: \n";
        getline(cin>>ws,Sname[i]);
        pos = Sname[i].find_first_of(',');
        spos = Sname[i].find_first_of(' ');

        if(pos != string::npos)     //Condition for comma (If name has comma it will be processed as below)
        {
            Lname[i] = Sname[i].substr(0, pos);
            Fname[i] = Sname[i].substr(pos+1);
        }
        else if(spos !=string::npos) //Condition for Space (If name has space it will be processed as below)
        {
            Fname[i] = Sname[i].substr(0, spos);
            Lname[i] = Sname[i].substr(spos+1);
        }
        else{
            cout<<"Please Enter the full name!"; //Error if both condition fails
        }
    }

    cout<<"\n\nEntered Names:\n";

    for (i=0; i<Size; i++)      //Loop to display names
    {
        cout<<"\n"<<name[i]<<" name: "<< Fname[i]<<", "<< Lname[i]<<"\n";
    }
}
