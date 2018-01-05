#include <gtest/gtest.h>
#include "scanner.h"
#include "parser.h"
#include "shell.h"
#include <iostream>

using namespace std;

// }
int main(int argc, char **argv){
  string x = "";
  string result = "";

  while(1){
    do{
      if(result.back() == ';'){
        cout << "|   " ;
      }else {
        cout << "?- " ;
			}
      getline(cin,x);
			if(x[0] == ' ') x = "";
			result += x;
    }while(x == "" || result.back() != '.');

		if(result == "halt.") {
			break;
		}

    Scanner s(result);
    Parser p(s);
		try {
      p.buildExpression();
      Shell sh(p);
      string result = sh.getResult();
			cout << result << endl;

		} catch (string &msg) {
			cout << msg << endl;
		}
		result = "";
  }
}
