#ifndef NUMBER_H
#define NUMBER_H

#include "atom.h"

class Number : public Term{
public:
  Number(double db):Term(db) {}
  string getClassName() const {return "Number";}
};

#endif
