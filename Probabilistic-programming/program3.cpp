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
  double lamda = 2; // λの値を宣言
  double myu = 16; // μの値を宣言
  double rand_val_lamda; // 下のrnd_exp_lamdaの乱数生成のために使用
  double rand_val_myu; // 下のrnd_exp_myuの乱数生成のために使用
  double rnd_exp_lamda; //  到着率 λ で客がランダムに到着するような乱数生成に使用
  double rnd_exp_myu; // 平均1/μの指数分布に従う食事時間の乱数生成に使用
  double Ta=0; // お客の到着時刻
  double Td=0; // サーバの利用終了時刻
  double cus_num=0; // 到着した客数
  double loss_num=0; // ロスした客数
  double END_TIME=10000; // 終了時刻

  while(END_TIME >= Ta){ // お客の到着時刻TaがEND_TIMEに到達するまでの間シミュレーションを回す
    cus_num += 1; // お客の到着時刻 Ta を更新
    rand_val_lamda=(rand() + 0.5) / (RAND_MAX + 1.0); // 下のrnd_exp_lamdaの乱数生成のために使用する一様乱数(0,1)の生成
    rand_val_myu=(rand() + 0.5) / (RAND_MAX + 1.0);  // 下のrnd_exp_myuの乱数生成のために使用する一様乱数(0,1)の生成
    rnd_exp_lamda=(-1/lamda)*log(rand_val_lamda); // 到着率 λ で客がランダムに到着するような到着間隔の生成
    rnd_exp_myu=(-1/myu)*log(rand_val_myu); // 平均1/μの指数分布に従う食事時間を生成
    Ta += rnd_exp_lamda; // 客の到着時刻 Ta の更新
    if(Td < Ta){ // 1台のレジが空いている場合
      Td = Ta + rnd_exp_myu; // 利用終了時刻 (= 到着時刻 + 食事時間) の更新
    }else{ // 1台のレジが空いていない場合
      loss_num +=1; // ロスした客数 loss_num を増やす
    }
  }
  cout << "λ = " << lamda << " , " << "μ ＝ "<< myu << endl; // 最初で設定したλとμの値を出力
  cout << "ロスした客数 = " << loss_num << endl; // お店の前まで来たがレジが空いておらず残念にもロスしたお客の数を出力
  cout << "到着した客数 = " << cus_num << endl; // 利用しないかどうかにはよらず、とりあえずお店の前までは到着したお客の数を出力

  printf("ロス率 = %.20lf", loss_num/cus_num); // お客のロス率の計算、そして出力
}
