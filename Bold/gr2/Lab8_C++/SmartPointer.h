#pragma once


class SmartPointer{


  public:
    void operator=(SmartPointer& right){ 
        this->~SmartPointer(); 
        _ref_counter = right._ref_counter; 
        (*_ref_counter)++; _pointer = right._pointer; 
    }

    SmartPointer(SmartPointerValueType* pointer): 
        _pointer(pointer),
        _ref_counter(new int)
        {  
            (*_ref_counter) = 1;   
        }

    SmartPointer( const SmartPointer& pointer): 
        _pointer(pointer._pointer), 
        _ref_counter(pointer._ref_counter) 
        { 
            (*_ref_counter)++;
        }

    SmartPointerValueType* data() const{ return _pointer; }

    ~SmartPointer(){ 
        (*_ref_counter)--;
        if((*_ref_counter) == 0){
            delete _pointer;
            delete _ref_counter;
        }
    }

  private:
    SmartPointerValueType* _pointer;
    int* _ref_counter;
};