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
  ofstream ofs("2-1.csv");
  double lamda = 2;
  double rand_val;
  double rnd_exp;
  double y,t;
  int time=0;
  double END_TIME=10000;
    while(END_TIME >= t){
      time+=1;
      rand_val=(rand() + 0.5) / (RAND_MAX + 1.0);
      rnd_exp=(-1/lamda)*log(rand_val);
      y = rnd_exp;
      t += y;

      cout << "t" << time << "=" << t <<endl;
      cout << "到着間隔y="<< y << endl;
      cout << endl;
      ofs << "t" << time << "," << t << "," << rand_val << "," << y << endl;
  }
}
