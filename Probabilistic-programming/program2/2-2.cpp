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
  ofstream ofs("2-2.csv");
  double lamda;
  double rand_val;
  double rnd_exp;
  double y,t;
  int time=0;
  double END_TIME=10000;
  int count=0;
  int A=0;
  double T=1;

  cin >> lamda;
  // λの値入力する

  while(END_TIME >= t){
    time+=1;
    rand_val=(rand() + 0.5) / (RAND_MAX + 1.0);
    rnd_exp=(-1/lamda)*log(rand_val);
    y = rnd_exp;
    t += y;
    while(1){
      if(t<T){
        count +=1;
        break;
      }
      else{
        cout << "A[" << A << "]=" << count <<endl;
        ofs  << "A[" << A << "]" << "," << count <<endl;
        A += 1;
        T++;
        count = 0;

      }
    }
  }
}
