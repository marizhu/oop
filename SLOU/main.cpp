#include <iostream>
#include <fstream>
#include <cmath>
#include <clocale>
using namespace std;
//файл1-- размерность матрицы и сама матрица, в файле 2 раззмерность и вектор св.членов. файл 3---результат и проверка

int main()
{
setlocale(LC_ALL,".1251");
 ifstream matrix;
 ifstream vektor;
 ofstream fout;
 matrix.open("matrR.txt");
 vektor.open("vektorR.txt");
 fout.open("resultR.txt");

 if((!matrix.is_open())||(!vektor.is_open())||(!fout.is_open()))cout<<"error\n";
    else
      {
        int n=0,m=0;
        matrix>>n;
        vektor>>m;
        if (m!=n) cout<<"error: n!=m";
          else
            {
             double matr[n][n];
             double matrPROV[n][n];
             double obrmatr[n][n];
             double svk[m],res[m];
             double obrv1=0,obrv0=0;
             int b=n*n;
             for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                   {
                    if((matrix>>matr[i][j])!='\0')
                        {
                         matrPROV[i][j]=matr[i][j];
                         if(i==j)
                              obrmatr[i][j]=1;
                            else
                                obrmatr[i][j]=0;
                        }
                         else
                            {
                             cout<<"error: не корректный ввод матрицы";
                             return 0;
                            }
                    }
             int k=0;
             while(!vektor.eof())
                {
                 vektor>>svk[k];
                 res[k]=svk[k];
                 k++;
                }
            if(k=m)
                cout<<"error: не корректный ввод вектора"<<endl;
             else
                 {
                  fout<<"матрица: \n";
                  for(int i=0;i<n;i++)
                     {
                       for(int j=0;j<n;j++)
                           fout<<"\t"<<matrPROV[i][j];
                      fout<<"\n";
                    }
                  fout<<"вектор св.членов:  ";
                  for(int i=0;i<m;i++)
                      fout<<res[i]<<"  ";
                  fout<<"\n";

/*
int ime=m;///ime-индекс наибольшего по модулю элемента
     for(int i=m+1;i<n;i++)
        if(abs(matr[ime][m])<abs(matr[i][m]))
           ime=i;
     for(int i=0;i<n;i++){
         swap(matr[ime][i],matr[m][i]);
         swap(matrprov[ime][i],matr[m][i]);}
     swap(svk[m],svk[ime]);
     swap(res[m],svk[ime]);*/
///прямой ход
             for(int k=0;k<n;k++)
                {
                 obrv1=matr[k][k];
                if(obrv1!=0){
                 for(int j=0;j<n;j++){
                     matr[k][j]=matr[k][j]/obrv1;
                     obrmatr[k][j]=obrmatr[k][j]/obrv1;
                     }
                 svk[k]=svk[k]/obrv1;
                 for(int i=k+1;i<n;i++)
                    {
                     obrv0=matr[i][k];
                     for(int j=0;j<n;j++){
                         matr[i][j]=matr[i][j]-obrv0*matr[k][j];
                         obrmatr[i][j]=obrmatr[i][j]-obrv0*obrmatr[k][j];
                         }
                     svk[i]=svk[i]-obrv0*svk[k];
                    }
                    }//else{for(int mm=0;mm<n;mm++){swap(matr[k][mm],matr[k+1][mm]);swap(svk[k],svk[k+1]);}}
                   }
///determinate
 int det=1;
 for(int i=0;i<n;i++)
        det*=matr[i][i];

cout<<det<<endl;
if(det!=0){

///обратный ход
//if(re!=true){
             for(int k=n-1;k>0;k--)
                {
                 for(int i=k-1;i+1>0;i--)
                    {
                     obrv0=matr[i][k];
                     for(int j=0;j<n;j++){
                         matr[i][j]=matr[i][j]-obrv0*matr[k][j];
                         obrmatr[i][j]-=obrv0*obrmatr[k][j];
                         }
                     svk[i]=svk[i]-obrv0*svk[k];
                    }
                }

  fout<<"матрица получ.: \n";
             for(int i=0;i<n;i++)
                {
                 for(int j=0;j<n;j++)
                     fout<<"\t"<<matr[i][j];
                 fout<<"\n";
                }

             fout<<"\n x: ";
             for(int i=0;i<n;i++)
                 fout<<svk[i]<<"  ";
             fout<<"\nОбратная матрица: \n";
             for(int i=0;i<n;i++)
                {
                 for(int j=0;j<n;j++)
                     fout<<"\t"<<obrmatr[i][j];
                 fout<<"\n";
                }

 ///проверка
             double result[m];
             fout<<"Проверка: \n";
             for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                     result[i]+=matrPROV[i][j]*svk[j];
             fout<<"полученно:  ";
             bool flag=false;
             for(int k=0;k<m;k++)
                {
                 fout<<result[k]<<"  ";
                 if(fabs(result[k]-res[k])<0.0000000000001)
                    flag=true;
                 else
                    flag=false;
                }
             if (flag==true)
                 fout<<"  =>  Решено верно \n";
             else
                 fout<<"  =>  Решено не верно\n";
            }else fout<<"\nСистема не имеет решений(det=0)\n";}
    //}
    }
      }
matrix.close();
vektor.close();
fout.close();

    return 0;
}
