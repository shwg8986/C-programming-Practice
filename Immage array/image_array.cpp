#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <random>
using namespace std;
int main()
{
  int a[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
  int b[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};

  cout << "1. 配列配列 a, b には数値が入力されている。" << endl
       << endl;
  cout << "① 配列a,bをモニタに表示" << endl
       << endl;
  int sum_a = 0, sum_b = 0;

  cout << "< 配列a >" << endl
       << endl;
  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      cout << a[y][x];
      if (a[y][x] == 1)
      {
        sum_a += 1;
      }
    }
    cout << endl;
  }
  cout << endl;
  // cout << "配列aの面積は" << sum_a << endl;

  cout << "< 配列b > " << endl
       << endl;
  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      cout << b[y][x];
      if (b[y][x] == 1)
      {
        sum_b += 1;
      }
    }
    cout << endl;
  }
  cout << endl;
  // cout << "配列bの面積は" << sum_b << endl;
  // printf("%.2f\n", ave2); //500 回目までに出たサイコロの目の期待値
  cout << "-------------------------" << endl
       << endl;
  cout << "② 配列a,bそれぞれの面積(1の画素数)を求める。" << endl
       << endl;
  cout << "配列aの面積 : " << sum_a << endl;
  cout << "配列bの面積 : " << sum_b << endl;
  cout << endl;

  cout << "-------------------------" << endl
       << endl;

  cout << "➂ 配列aにおいて1の画素に着目したときのy座標最大・最小、x座標最大・最小の要素を順に2,3,4,5に置き換えて表示。" << endl
       << endl;

  int min_x = 100, max_x = -100, min_y = 100, max_y = -100;
  int min_x_y = 0, max_x_y = 0, min_y_x = 0, max_y_x = 0;
  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {

      //y座標最小
      if (a[y][x] == 1 && min_y > y)
      {
        min_y = y;
        min_y_x = x;
      }

      // y座標最大
      if (a[y][x] == 1 && max_y < y)
      {
        max_y = y;
        max_y_x = x;
      }
      //x座標最小
      if (a[y][x] == 1 && min_x > x)
      {
        min_x = x;
        min_x_y = y;
      }

      //x座標最大
      if (a[y][x] == 1 && max_x < x)
      {
        max_x = x;
        max_x_y = y;
      }
    }
  }

  a[max_y][max_y_x] = 2;
  a[min_y][min_y_x] = 3;
  a[max_x_y][max_x] = 4;
  a[min_x_y][min_x] = 5;

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      cout << a[y][x];
    }
    cout << endl;
  }
  cout << endl;

  cout << "-------------------------" << endl
       << endl;

  cout << "④ 重心の座標を6に置き換えて表示" << endl
       << endl;

  int gx = (max_x + min_x) / 2;
  int gy = (max_y + min_y) / 2;

  a[gy][gx] = 6;

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      cout << a[y][x];
    }
    cout << endl;
  }

  cout << "-------------------------" << endl
       << endl;

  cout << "2.① 配列bの縦方向のエッジを求める" << endl
       << endl;

  int bout_ver[7][7]; //縦方向のエッジ

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      bout_ver[y][x] = 0;
    }
  }

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 6; x++)
    {
      int Edge = b[y][x] + (-1) * b[y][x + 1];
      if (Edge == -1)
      {
        bout_ver[y][x + 1] = 1;
      }
      else if (Edge == 1)
      {
        bout_ver[y][x] = 1;
      }
    }
  }

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      cout << bout_ver[y][x];
    }
    cout << endl;
  }
  cout << endl;

  cout << "-------------------------" << endl
       << endl;

  cout << "2.② 配列bの横方向のエッジを求める" << endl
       << endl;

  int bout_hor[7][7]; //横方向のエッジ

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      bout_hor[y][x] = 0;
    }
  }

  for (int y = 0; y < 6; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      int Edge = b[y][x] + (-1) * b[y + 1][x];
      if (Edge == -1)
      {
        bout_hor[y + 1][x] = 1;
      }
      else if (Edge == 1)
      {
        bout_hor[y][x] = 1;
      }
    }
  }

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      cout << bout_hor[y][x];
    }
    cout << endl;
  }
  cout << endl;

  cout << "①と合わせて表示すると..." << endl
       << endl;

  int bout[7][7]; //縦方向と横方向を合わせたエッジ

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      bout[y][x] = 0;
    }
  }

  for (int y = 0; y < 7; y++)
  {
    for (int x = 0; x < 7; x++)
    {
      if (bout_ver[y][x] == 1 or bout_hor[y][x] == 1)
      {
        bout[y][x] = 1;
      }
      cout << bout[y][x];
    }
    cout << endl;
  }
  cout << endl;
}
