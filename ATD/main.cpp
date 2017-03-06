#include <clocale>
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#define N 100
/**
�������:
����������� �����-������:���������� ������,
������, ���������� ���������� � ������(���, ����� ������, �������� ������� ���),
���� ������ ��������,
����� ��������,
������� �������.
���������� ������, ����������� "��������� ������",
�������� �������.
*/
using namespace std;

 class ZOO{
 private:
     ///��������
  struct animal
        {
         string name;
         string vid;
         int numberBox;
         string food;
         };
  struct time
        {
         string t_open="none";
         string t_close="none";
          };
  int amountAnimals=0;
  animal anim[N];
  time timeWork[7];///����� �� ���� ������
  string adressZoo;
  string guard;

 public:
 void spisokAn(int);///�������� ������ ��������
 void spisokZo();/// �������� ���������� � ��������
 ///string get_guardName();
 string get_animalFood(int);
 int get_animalBox(int);
 string get_animalName(int);
 string get_animalVid(int);
 int get_amountAnimal();
 void feedAnimal(string,int);/// ����������� ��������
 void replaceGuard(string);/// �������� �������
 void infoZoo();
 void week(int);
 };
/// �������� ������ ��������
 void ZOO::spisokAn(int k)
 {for(int i=0;i<k;i++){
cout<<"\n\n��� ���������: ";cin>>anim[i].vid;
cout<<"��� ���������: ";cin>>anim[i].name;
cout<<"����� ������: ";cin>>anim[i].numberBox;
cout<<"����: ";cin>>anim[i].food;
 }}
 /// ���� ����������� � ��������
 void ZOO::spisokZo()
 {

     cout<<"���������� ��������: ";cin>>amountAnimals;
     cout<<"������ ��������: ";cin>>adressZoo;
     cout<<"��� ������,����� ������� ������: \n";

     int cd=0;
     cout<<"������� ����: \n";cin>>cd;
     int temp[cd];
    cout<<"��� : ";

         for(int i=0;i<cd;i++)
            {cout<<"\n����: ";
             cin>>temp[i];
             cout<<"\n����� ��������:";cin>>timeWork[temp[i]-1].t_open;
             cout<<"����� ��������: ";cin>>timeWork[temp[i]-1].t_close;
            }


     cout<<"������� �������: ";cin>>guard;


 }
 ///������ ������
 string ZOO::get_animalFood(int k){return anim[k].food;}
 string ZOO::get_animalName(int k){return anim[k].name;}
 string ZOO::get_animalVid(int k){return anim[k].vid;}
 int ZOO::get_animalBox(int k){return anim[k].numberBox;}
 ///string ZOO::get_guardName(){return guard;}///***********************
 void ZOO::feedAnimal(string newFood,int k){anim[k].food=newFood;}
 void ZOO::replaceGuard(string newGuard){this->guard=newGuard;}
 int ZOO::get_amountAnimal(){return amountAnimals;}

 void ZOO::infoZoo()
   {
        cout<<"���������� ��������: "<<amountAnimals<<"\n";
        cout<<"����� ��������: "<< adressZoo<<"\n";
        cout<<"����� ������ ��������: \n";
        for(int i=0;i<7;i++)
          week(i);
        cout<<"������� �������: "<<guard<<"\n";
       }

 void ZOO::week(int d)
 {
  string  day[]={"��","��","��","��","��","��","��"};
  if((timeWork[d].t_open!="none")||(timeWork[d].t_close!="none"))
  cout<<day[d]<<setw(8)<<timeWork[d].t_open <<" -- "<<timeWork[d].t_close<<"\n";
  else  cout<<day[d]<<"  no work  "<<"\n";
 }
 ///�������
 void renameGuard(ZOO &z)
 {
  string newname;
  cout<<"New name: ";
  cin>>newname;
  z.replaceGuard(newname);
 }
 void kormAnim(ZOO &z)
{
  string nameA,vidA,korm;
  cout<<"��� ���������: ";cin>>vidA;
  cout<<"��� ���������: ";cin>>nameA;
  for(int i=0;i<z.get_amountAnimal();i++)
     {
      if(z.get_animalVid(i)==vidA)
        {
          if(z.get_animalName(i)==nameA)
            {
              cout<<"'�������'  ";cin>>korm;
              z.feedAnimal(korm,i);
            }
        }
    }
}

void infoZOO(ZOO z)
{
    z.infoZoo();
}
void infoANIMAL(ZOO z)
{
for(int i=0;i<z.get_amountAnimal();i++)
   {
    cout<<i+1<<":  \n";
    cout<<"���: "<<z.get_animalVid(i)<<"\n";
    cout<<"���: "<<z.get_animalName(i)<<"\n";
    cout<<"����� ������: "<<z.get_animalBox(i)<<"\n";
    cout<<"����: "<<z.get_animalFood(i)<<"\n";
   }
}
int main()
{ setlocale(LC_ALL,"russian");
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
    ZOO one;

one.spisokZo();
system("cls");
int kolvo=one.get_amountAnimal();
cout<<"��������;"<<endl;
one.spisokAn(kolvo);
system("cls");
int obj;
 while(1)
    {
     cout<<"\n************************************************\n��������:"<<endl;
     cout<<
           "1-������ �������� � ��������;\n"
           "2-�������� ��� ������� ��������;\n"
           "3-'���������' ��������;\n"
           "4-���������� � ��������;\n"
           "5-�����\n";
     cin>>obj;

     switch(obj)
           {
            case 1:infoANIMAL(one);break;
            case 2:renameGuard(one);break;
            case 3:kormAnim(one);break;
            case 4:infoZOO(one);break;
            case 5:return 0;
           default: puts("������ �������� �� ����������!");
           }
     puts ("\n������ ����� ������� ��� �������� � ����.");
     getch (); // �������� ������� ����� �������

     system("cls");
    }

 return 0;
}
