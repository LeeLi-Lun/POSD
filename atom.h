#ifndef ATOM_H
#define ATOM_H

#include "term.h"

class Atom : public Term{
public:
  Atom(string s):Term(s) {}
  string getClassName() const {return "Atom";}
};

#endif
