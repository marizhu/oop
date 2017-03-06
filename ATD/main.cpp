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
Зоопарк:
необходимые члены-данные:количество зверей,
массив, содержащий информацию о зверях(имя, номер клетки, название любимой еды),
часы работы зоопарка,
адрес зоопарка,
фамилия сторожа.
Определить методы, позволяющие "накормить зверей",
поменять сторожа.
*/
using namespace std;

 class ZOO{
 private:
     ///животные
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
  time timeWork[7];///время по дням недели
  string adressZoo;
  string guard;

 public:
 void spisokAn(int);///создание списка животных
 void spisokZo();/// создание информации о зоопарке
 ///string get_guardName();
 string get_animalFood(int);
 int get_animalBox(int);
 string get_animalName(int);
 string get_animalVid(int);
 int get_amountAnimal();
 void feedAnimal(string,int);/// ЭнакормитьЭ животное
 void replaceGuard(string);/// изменить сторожа
 void infoZoo();
 void week(int);
 };
/// создания списка животных
 void ZOO::spisokAn(int k)
 {for(int i=0;i<k;i++){
cout<<"\n\nВид животного: ";cin>>anim[i].vid;
cout<<"Имя животного: ";cin>>anim[i].name;
cout<<"Номер клетки: ";cin>>anim[i].numberBox;
cout<<"пища: ";cin>>anim[i].food;
 }}
 /// ввод инфотрмации о зоопарке
 void ZOO::spisokZo()
 {

     cout<<"Количество животных: ";cin>>amountAnimals;
     cout<<"Адресс зоопарка: ";cin>>adressZoo;
     cout<<"Дни недели,когда зоопарк открыт: \n";

     int cd=0;
     cout<<"Сколько дней: \n";cin>>cd;
     int temp[cd];
    cout<<"Дни : ";

         for(int i=0;i<cd;i++)
            {cout<<"\nДень: ";
             cin>>temp[i];
             cout<<"\nВремя открытия:";cin>>timeWork[temp[i]-1].t_open;
             cout<<"Время закрытия: ";cin>>timeWork[temp[i]-1].t_close;
            }


     cout<<"Фамилия сторожа: ";cin>>guard;


 }
 ///методы класса
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
        cout<<"Количество животных: "<<amountAnimals<<"\n";
        cout<<"Адрес зоопарка: "<< adressZoo<<"\n";
        cout<<"Время работы зоопарка: \n";
        for(int i=0;i<7;i++)
          week(i);
        cout<<"Фамилия сторожа: "<<guard<<"\n";
       }

 void ZOO::week(int d)
 {
  string  day[]={"пн","вт","ср","чт","пт","сб","вс"};
  if((timeWork[d].t_open!="none")||(timeWork[d].t_close!="none"))
  cout<<day[d]<<setw(8)<<timeWork[d].t_open <<" -- "<<timeWork[d].t_close<<"\n";
  else  cout<<day[d]<<"  no work  "<<"\n";
 }
 ///функции
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
  cout<<"Вид животного: ";cin>>vidA;
  cout<<"Имя животного: ";cin>>nameA;
  for(int i=0;i<z.get_amountAnimal();i++)
     {
      if(z.get_animalVid(i)==vidA)
        {
          if(z.get_animalName(i)==nameA)
            {
              cout<<"'кормить'  ";cin>>korm;
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
    cout<<"Вид: "<<z.get_animalVid(i)<<"\n";
    cout<<"Имя: "<<z.get_animalName(i)<<"\n";
    cout<<"Номер клетки: "<<z.get_animalBox(i)<<"\n";
    cout<<"Пища: "<<z.get_animalFood(i)<<"\n";
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
cout<<"Животные;"<<endl;
one.spisokAn(kolvo);
system("cls");
int obj;
 while(1)
    {
     cout<<"\n************************************************\nВыберите:"<<endl;
     cout<<
           "1-Список животных в зоопарке;\n"
           "2-Изменить имя сторожа зоопарка;\n"
           "3-'Накормить' животное;\n"
           "4-Информация о зоопарке;\n"
           "5-Выход\n";
     cin>>obj;

     switch(obj)
           {
            case 1:infoANIMAL(one);break;
            case 2:renameGuard(one);break;
            case 3:kormAnim(one);break;
            case 4:infoZOO(one);break;
            case 5:return 0;
           default: puts("Такого варианта не существует!");
           }
     puts ("\nНажать любую клавишу для возврата в меню.");
     getch (); // Ожидание нажатия любой клавиши

     system("cls");
    }

 return 0;
}
