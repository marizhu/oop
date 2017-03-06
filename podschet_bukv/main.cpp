#include<iostream>
#include<clocale>
#include<fstream>
#include <cstdio>
#define K 33
//#include <iomanip>
#include <Windows.h>
using namespace std;

int bukv[K];///letters
char buk[K];
long long lentxt=0;

struct kol
    {
     int klm=0;
     int klb=0;
     int kollet=0;
     double chast=0;
    }kol[K];

///заполнение структуры кодами букв
void zmass()
     {///kol[0].klb=192;
      ///kol[0].klm=224;
        kol[6].klb=-136;///168;///Ё
        kol[6].klm=-120;///184;///ё
        for(int i=0;i<6;i++)
            {
             kol[i].klb=-112+i;///A-E
             kol[i].klm=-80+i;///a-e
            }
        for(int i=7;i<K;i++)
            {
             kol[i].klb=-112+i-1;///Ж
             kol[i].klm=-80+i-1;///ж
            }
     }
///подсчет количества
void kolvobuk(int num)
    {
     if(((num>=-112)&&(num<=-49))||(num==-136)||(num==-120))
       {
        lentxt++;
        for(int j=0;j<K;j++)
            if((kol[j].klb==num)||(kol[j].klm==num))
                 kol[j].kollet++;
       }
    }

void chastota()
     {
      for(int i=0;i<K;i++)
          kol[i].chast=(double)kol[i].kollet/lentxt;
     }

void returnLetters()
    {
     for(int j=0;j<6;j++)
         bukv[j]=192+j;
     for(int j=7;j<K;j++)
         bukv[j]=192+j-1;
     bukv[6]=168;
     }

int main()
{
 zmass();
 setlocale(LC_ALL,".1251");
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 ifstream fin;
 ofstream fout;
 ifstream wiki;
 fin.open("Ф.Достоевский.Идиот.txt");///("война и мир");///("begin.txt");
 fout.open("theend.txt");
 wiki.open("wiki.txt");
 if(!fin.is_open()||!fout.is_open()||!wiki.is_open())cout<<"error"<<endl;
   else
   {
    int kodLet=0;
    char let;

    while(fin>>let)
        {
         kodLet=let-'0';
         kolvobuk(kodLet);
       //lentxt++;
        }
    chastota();
    returnLetters();
///вывод в файл
 string temp;
 fout<<"всего букв в тексте: "<<lentxt<<"\nбуква"<<"\t"<<"из википедии"<<"\t"<<"кол-во букв в тексте"<<"\t"<<"частота встр."<<"\t\n";
 for(int i=0;i<K;i++)
    {
     getline(wiki,temp);
     fout<<(char)bukv[i]<<"\t\t"<<temp<<"\t\t\t"<<kol[i].kollet<<"\t\t\t\t\t\t"<<kol[i].chast<<"\n";
    }
   }
  fin.close();
  fout.close();
  wiki.close();
    return 0;
}
