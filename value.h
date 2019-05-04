#include <stdexcept>
#include <string>
using std::string;
#include <iostream>
using std::ostream;

#ifndef _VALUE_H_
#define _VALUE_H_

class Value {
public:
    enum ValType { ERRVAL, INTVAL, STRVAL };
    
private:
    ValType        theType;
    int                 theInt;
    string            theStr;
    
public:
    Value() : theType(ERRVAL), theInt(0) {}
    Value(int i) : theType(INTVAL), theInt(i) {}
    Value(string s) : theType(STRVAL), theInt(0) , theStr(s) {}
    
    bool isInt() const { return theType == INTVAL; }
    bool isStr() const { return theType == STRVAL; }
    bool isErr() const { return theType == ERRVAL; }
    
    int GetInt() const {
        if( isInt() ) return theInt;
        throw std::logic_error("This Value is not an int");
    }
    
    string GetStr() const {
        if( isStr() ) return theStr;
        throw std::logic_error("This Value is not a string");
    }
    
    Value operator+(const Value& o) const{
        
        if(o.isInt() && isInt()){
      int sum = GetInt() + o.GetInt();
          
          return Value(sum);
        }
        
         else if(o.isStr() && isStr()) {
      string sum = GetStr() + o.GetStr();
          
          return Value(sum);
        }
        
        else{
         throw std::logic_error("Type mismatch for arguments of +");
            
        }
        
    }
    
    Value operator-(const Value& o) const{
         if(o.isInt() && isInt()){
        int diff = GetInt() - o.GetInt();
          return Value(diff);
         }
        
        else{
         throw std::logic_error("Type mismatch for arguments of -");
            
        }
    
    }
    
    Value operator*(const Value& o) const{
        if(o.isInt() && isInt()){
     int mul = GetInt() * o.GetInt();
          return Value(mul);
        }
        
        else if(isStr() && o.isInt()){
            string mul;
           int sp = o.GetInt();
            if(sp <0){
            throw std::logic_error("Repetition count less than 0");
            }
            while(sp >0){
                mul += GetStr() ;
                
                sp--;
            }
            
            return Value(mul);
        
        }
        
        else if(o.isStr() && isInt()){
             string mul;
           int sp = GetInt();
            while(sp >0){
                mul += o.GetStr() ;
                
                sp--;
            }
            
            return Value(mul);
        
        }
        
        else{
         throw std::logic_error("Type mismatch for arguments of *");
            
        }
        
         return Value(0);
    
    }
    
    Value operator/(const Value& o) const{
        if(o.GetInt()==0){
              throw std::logic_error("Divide by zero error");
        }
     int div = GetInt() / o.GetInt();
          return Value(div);
    }
    
    friend ostream& operator<<(ostream& out, const Value& v) {
        switch( v.theType ) {
            case ERRVAL:
                out << "RUNTIME ERROR: " << v.theStr;
                break;
            case INTVAL:
                out << v.theInt;
                break;
            case STRVAL:
                out << v.theStr;
                break;
        }
        
        return out;
    }
};

#endif
