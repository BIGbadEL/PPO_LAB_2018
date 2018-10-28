#include "tab.h"

void init(Tab* tab, int columns, int rows, float value){
    tab->m_Rows = rows;
    tab->m_Columns = columns;
    tab->m_Data = new float[rows * columns];
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            tab->m_Data[r * columns + c] = value;
        }
    }
}

void diag(Tab* tab, float value){
    for(int i = 0; i < tab->m_Columns; i++){
        set(tab, i, i, value);
    }
}

void print(Tab* tab){
    for(int r = 0; r < tab->m_Rows; r++){
        std::cout << "| ";
        for(int c = 0; c < tab->m_Columns; c++){
            std::cout << tab->m_Data[r * tab->m_Columns + c] << " ";
        }
        std::cout << "|\n";
    }
}

void set(Tab* tab, int row, int column, float value){
    tab->m_Data[row * tab->m_Columns + column] = value;
}

void set_part(Tab* tab, const TabRange& range, float value){
    for(int r = range.m_Row_up; r < range.m_Row_down; r++){
        for(int c = range.m_Column_up; c < range.m_Column_down; c++){
            set(tab, r, c, value);
        }
    }
}

Tab* extract(Tab *tab, const TabRange& range){
    Tab *result = new Tab;
    int col = range.m_Column_down - range.m_Column_up;
    int row = range.m_Row_down - range.m_Row_up;
    init(result, col, row, 0);
    for(int i = 0; i < row; i++){
        //memcpy(result->m_Data + i * col, tab->m_Data + (range.m_Row_up + i) * tab->m_Columns + range.m_Column_up, col);
        for(int j = 0; j < col; j++){
            result->m_Data[i * col + j] = tab->m_Data[(range.m_Row_up + i) * tab->m_Columns + range.m_Column_up + j];
        }
    }

    return result;
}

void clean(Tab *tab){
    tab->m_Columns = 0;
    tab->m_Rows = 0;
    delete[] tab->m_Data;
    tab->m_Data = nullptr;
}