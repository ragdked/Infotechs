#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Employee
{
    private:
        string name;
        string position;
        string dateOfBirth;
        string fileName;
        
    public:

        void setName(string EmployesName)
        {
            name = EmployesName;
        }
        
        void setDateOfBirth(string EmployesDateOfBirth)
        {
            dateOfBirth = EmployesDateOfBirth;
        }
        
        void setPosition(string EmployesPosition)
        {
            position = EmployesPosition;
        }
        
        void setFileName(string fileNameToSave)
        {
            fileName = fileNameToSave;
        }
        
        string getName()
        {
            return name;
        }
        
        string getDateOfBirth()
        {
            return dateOfBirth;
        }
        
        string getPosition()
        {
            return position;
        }
        
        void getInfo()
        {
            cout<<"Name: "<<name<<" , ";
            cout<<"Date of birth: "<<dateOfBirth<<" , ";
            cout<<"Position: "<<position<<endl;
        }

};
