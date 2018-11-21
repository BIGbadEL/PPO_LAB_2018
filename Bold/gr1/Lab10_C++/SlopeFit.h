#pragma once

#include "FitResult.h"

class SlopeFit : public Fit{
  public:
    SlopeFit();
    ~SlopeFit();
    void appendPoint(double x, double y) override;
    FitResult result() const override;
};

