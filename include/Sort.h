#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <list>

#include "Shapes.h"

class Sort {
	

  public :static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList){
	  
	std::list<Shape *> ::iterator i; 
	std::list<Shape *> ::iterator j;

	for(i =  shapeList->begin();i != shapeList->end();i++){
		for(j = shapeList->begin(); j != shapeList->end(); j++){
			//Shape* temp = *i;
			//Shape* temp2 = *j;
			if( (*i)->perimeter() < (*j)->perimeter()){
				std::swap(*i,*j);
			}
		}
	}  
  }
	
  public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList){
  	std::list<Shape *> ::iterator i; 
	std::list<Shape *> ::iterator j;

	for(i =  shapeList->begin();i != shapeList->end();i++){
		for(j = shapeList->begin(); j != shapeList->end(); j++){
			//Shape* temp = *i;
			//Shape* temp2 = *j;
			if( (*i)->perimeter() > (*j)->perimeter()){
				std::swap(*i,*j);
			}
		}
	}   
  }
  
  public :static void sortByIncreasingArea(std::list<Shape *> * shapeList){ 
  	std::list<Shape *> ::iterator i; 
	std::list<Shape *> ::iterator j;

	for(i =  shapeList->begin();i != shapeList->end();i++){
		for(j = shapeList->begin(); j != shapeList->end(); j++){
			//Shape* temp = *i;
			//Shape* temp2 = *j;
			if( (*i)->area() < (*j)->area()){
				std::swap(*i,*j);
			}
		}
	}   
  }

  public :static void sortByDecreasingArea(std::list<Shape *> * shapeList){
	std::list<Shape *> ::iterator i; 
	std::list<Shape *> ::iterator j;

	for(i =  shapeList->begin();i != shapeList->end();i++){
		for(j = shapeList->begin(); j != shapeList->end(); j++){
			//Shape* temp = *i;
			//Shape* temp2 = *j;
			if( (*i)->area() > (*j)->area()){
				std::swap(*i,*j);
			}
		}
	}  
  }
  
  public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeList){
	std::list<Shape *> ::iterator i; 
	std::list<Shape *> ::iterator j;

	for(i =  shapeList->begin();i != shapeList->end();i++){
		for(j = shapeList->begin(); j != shapeList->end(); j++){
			//Shape* temp = *i;
			//Shape* temp2 = *j;
			if( (*i)->Compactness() < (*j)->Compactness()){
				std::swap(*i,*j);
			}
		}
	}  
  }

 
};
#endif
