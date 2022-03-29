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
  ofstream ofs("1-3.csv");
  int t = 50 ;
  double rand_val;
  int time=1;
  double A[100]={};
  for(int i=0;i<100;i++){
    cout << endl;
    cout <<"シミュレーション"<< time << "回目の時のランダムウォーク" << endl;
    cout<< 0 << ",";
    double x = 0.0;
    for(int j=0;j<t;j++){
      rand_val = ((double)rand() + 0.5) / ((double)RAND_MAX + 1.0);
      if(rand_val <= 0.5){
        x -= 1.0;
      }
      else{
        x += 1.0;
      } cout  << x << ",";
      ofs << x << "," ;
      if(j==49){
        A[i] += x;
      }
    } cout << endl;
    ofs << endl;
    time +=1;
  }cout << endl;
  cout << "シミュレーション1~100回目までにおけるt=50の時のそれぞれの値"<< endl;
  for(int k=0;k<100;k++){
    cout << A[k] <<",";
    ofs << A[k] << "," ;
  }cout <<endl;
  ofs << endl;
}
