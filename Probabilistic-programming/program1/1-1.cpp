#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<random>
#include<ctime>
using namespace std;

double rand_val(){
    return ((double)rand() + 0.5) / ((double)RAND_MAX + 1.0);
}
double rnd_uni(double r_val,double a,double b){
    return a+((b-a)*r_val);
}
double rnd_exp(double r_val,double lamda){
    return (-1/lamda)*log(r_val);
}

int main(){
    srand(1111);
    double a,b,lamda;
    double r_val;
    double r_uni;
    double r_exp;
    cin >> a >> b >> lamda;
    r_val = rand_val();
    r_uni = rnd_uni(r_val,a,b);
    r_exp = rnd_exp(r_val,lamda);
    printf("一様乱数 , 一様分布 , 指数分布\n");
    printf("%.5f , %.5f , %.5f\n",r_val,r_uni,r_exp);
}
