/*
Написать консольное многопоточное приложение, главный поток которого занимается получением входных данных (читает из консоли или файла).

Входные данные представляют собой строковое описание набора учетных данных служащих (Employee). Каждая учетная запись состоит из элементов: имени служащего, должности (директор, менеджер, рядовой работник), дата рождения. Элементы разделены запятыми, учетки - переводом строк. Рабочий поток 1 получает входные данные через очередь типа FIFO и помещает их в общую древовидную иерархическую структуру служащих (связи - начальник-подчиненный). Рабочий поток 2 выводит вновь полученные учетные данные в консоль или файл. (Навыки: структуры данных, использование алгоритмов и контейнеров станд. библиотеки, потоки и синхронизация, файловый ввод/вывод, обработка строк).
*/

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include "Employee.h"

ifstream in;
ofstream out;

void saveToFileInThread(Employee employee)
{
    out.open("test.txt", ios::app);
    if(out)
    {
        out << employee.getName() << ", " << employee.getDateOfBirth()<<", "<<employee.getPosition()<<endl;;
        out.close();
    }
}

void readFromFileInThread()
{
    string s;
    in.open("test.txt");
    if(in)
    {
        while(!in.eof())
        {
            this_thread::sleep_for(chrono::milliseconds(500));
            getline(in, s);
            cout<<s<<endl;
        }
    }
}

int main()
{
    Employee FirstEmployee;
    FirstEmployee.setName("Carl");
	FirstEmployee.setDateOfBirth("23.08.1970");
	FirstEmployee.setPosition("Director");
 
    thread secondThread(readFromFileInThread);
    	
	for(int i=0;i<10;++i){
	saveToFileInThread(FirstEmployee);
	}
    secondThread.join();
   
	return 0;
}
