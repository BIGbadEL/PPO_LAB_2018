#pragma once

#include <string.h>
#include <iostream>

struct Tab{
    float *m_Data;
    int m_Rows;
    int m_Columns;
};

struct TabRange{
    int m_Column_up;
    int m_Row_up;
    int m_Column_down;
    int m_Row_down;
};

void init(Tab* tab, int rows, int columns, float value);
void diag(Tab* tab, float value);
void print(Tab* tab);
void set(Tab* tab, int row, int column, float value);
void set_part(Tab* tab, const TabRange& range, float value);
void clean(Tab *tab);

Tab* extract(Tab *tab, const TabRange& range);
