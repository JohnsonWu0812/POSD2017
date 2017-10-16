#ifndef VARIABLE_H
#define VARIABLE_H

#include<string>
#include "term.h"
#include "atom.h"
#include "number.h"
using std::string;

class Variable:public Term{
  public:
    Variable(string s):_symbol(s),y(_symbol){
    _value=&y;
    }
    string _symbol;
    string symbol()const{
      return _symbol;
    }
    string value(){
      return *_value;
    }
    void setMemory(string &s)
    {
      _value = &s;
    }
    bool match(Term &term){
        Atom *ps = static_cast<Atom *>(&term);
        Variable *ps3 = static_cast<Variable *>(&term);
       
      if(65<=int(ps->symbol()[0]) && int(ps->symbol()[0])<=90){
        if((65>int(ps3->value()[0]) || int(ps->value()[0]) >90) && (65<=int((*_value)[0]) && int((*_value)[0])<=90))
        {_value = ps3->_value;  return true;}
        else if((65>int(ps3->value()[0]) || int(ps->value()[0]) >90) && (65>int((*_value)[0]) || int((*_value)[0])>90))
        return false;
        else if((65<=int(ps3->value()[0]) && int(ps->value()[0]) <=90) && (65<=int((*_value)[0]) && int((*_value)[0])<=90))
        {
        *ps3->_value = *_value ; 
        ps3->setMemory(*_value); 
        return true;
        }
        else 
        {
         ps3->setMemory(*_value);
          return true;
        }
      }
      else{
        if(ps && (65<=int(value()[0]) && int(value()[0])<=90) || *_value ==ps->symbol())
        {
          *_value = ps->value();
          return true;
        }
      }
      ps=NULL;
      ps3=NULL;

        return false;
    }
      string *_value;
  private:
  
    string y;

};

#endif
