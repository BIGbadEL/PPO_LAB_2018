#pragma once
#include <string>
#include <iostream>
struct TestClassA{
    TestClassA(std::string name) : _name(name) { std::cout << ".. Konstruuje TestClassA " << _name << std::endl;   }
    std::string name() const{ return _name; }
    ~TestClassA(){ std::cout << ".. Usuwam  TestClassA" << _name << std::endl; }
  private:
    std::string _name;
};