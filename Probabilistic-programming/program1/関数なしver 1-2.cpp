#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<random>
#include<ctime>
using namespace std;
int main(){
  srand(1111);
  ofstream ofs("1--2.csv");
  double a=20,b=80,lamda = 2.5;
  double rand_val;
  double rnd_uni[10000];
  double rnd_exp[10000];
  double sum1=0,sum2=0,sum3=0,sum4=0;
  double uni=0,exp=0;
  double ave1,ave2,dece1,dece2;
  printf("一様乱数 , 一様分布 , 指数分布\n");
  for(int i=0;i<10000;i++){
    rand_val = ((double)rand() + 0.5) / ((double)RAND_MAX + 1.0);
    rnd_uni[i] = (a+((b-a)*rand_val));
    sum1 += rnd_uni[i];
    rnd_exp[i] = (-1/lamda)*log(rand_val);
    sum2 += rnd_exp[i];
    printf("%.5f , %.5f , %.5f\n",rand_val,rnd_uni[i],rnd_exp[i]);
    ofs << rand_val << "," << rnd_uni[i] << "," << rnd_exp[i] <<endl;
  }
  ave1 = sum1 / 10000;
  ave2 = sum2 / 10000;

  for(int j=0;j<10000;j++){
    uni=(ave1-rnd_uni[j])*(ave1-rnd_uni[j]);
    exp=(ave2-rnd_exp[j])*(ave2-rnd_exp[j]);
    sum3 += uni;
    sum4 += exp;
  }
  dece1 = sum3 / 10000;
  dece2 = sum4 / 10000;
  cout << endl;
  printf("一様分布の期待値⇨%.5f\n一様分布の分散⇨%.5f\n指数分布の期待値⇨%.5f\n指数分布の分散⇨%.5f\n",ave1,dece1,ave2,dece2);

}
