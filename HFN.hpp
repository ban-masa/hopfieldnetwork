#pragma once

#include "lib.h"

class HFN {
  public:

    HFN()
    {
      if (sizex * sizey != size) {
        std::cerr << "invalid size" << std::endl;
        exit(0);
      }
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          w[i][j] = 0;
        }
      }
    }

    void read_data(const char* fname)
    {
      std::ifstream ifs(fname);
      std::array<int, size> temp;
      for (int i = 0; i < size; i++) {
        ifs >> temp[i];
      }
      data.push_back(temp);
    }

    void study(void)
    {
      int n = (int)data.size();
      for (int idx = 0; idx < n; idx++) {
        for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++) {
            if (i == j) {
              w[i][j] = 0;
            } else if (i < j) {
              w[i][j] += (double)(data[idx].at(i) * data[idx].at(j)) / (double)n;
              w[j][i] = w[i][j];
            }
          }
        }
      }
    }
    
    std::array<int, size> read_testdata(const char* fname)
    {
      std::ifstream ifs(fname);
      std::array<int, size> temp;
      for (int i = 0; i < size; i++) {
        ifs >> temp[i];
      }
      return temp;
    }

    std::array<int, size> test(const char* fname)
    {
      std::array<int, size> ans = read_testdata(fname);

      std::random_device rnd;
      for (int cnt = 0; cnt < 10000; cnt++) {
        int idx = rnd() % size;
        double val = 0;
        for (int i = 0; i < size; i++) {
          val += w[idx][i] * ans.at(i);
        }
        if (val > 0) ans.at(idx) = 1;
        else if (val < 0) ans.at(idx) = -1;
      }
      return ans;
    }

    double w[size][size];
    std::vector<std::array<int, size>> data;
};
