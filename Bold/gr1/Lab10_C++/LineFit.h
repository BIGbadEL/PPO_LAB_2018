#pragma once
#include "FitResult.h"

class LineFit : public Fit{
  public:
    LineFit();
    ~LineFit() override;
    void appendPoint(double x, double y) override;
    FitResult result() const override;
  private:
    int N;
};