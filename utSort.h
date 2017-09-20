#ifndef UTSORT_H
#define UTSORT_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

TEST (Sort, sortByIncreasingPerimeter) {
	vertex vertex_1 = {0, 0};
	vertex vertex_2 = {3, 0};
	vertex vertex_3 = {3, 4};
	Triangle tri(vertex_1, vertex_2, vertex_3);
	Circle cir(0, 0, 12);
	Rectangle rect(0, 0, 8, 9);
	
	std::list<Shape *> shapeList;
	shapeList.push_back(&cir);//2*Pi*12
	shapeList.push_back(&tri);//12
	shapeList.push_back(&rect);//34
	
	Sort sort1;
	sort1.sortByIncreasingPerimeter(&shapeList);
	
	ASSERT_EQ(tri.perimeter(), shapeList.front()->perimeter());
	shapeList.pop_front();
	ASSERT_EQ(rect.perimeter(), shapeList.front()->perimeter());
	ASSERT_EQ(cir.perimeter(), shapeList.back()->perimeter());

}

TEST (Sort, sortByDecreasingPerimeter) {
	vertex vertex_1 = {0, 0};
	vertex vertex_2 = {3, 0};
	vertex vertex_3 = {3, 4};
	Triangle tri(vertex_1, vertex_2, vertex_3);
	Circle cir(0, 0, 12);
	Rectangle rect(0, 0, 8, 9);
	
	std::list<Shape *> shapeList;
	shapeList.push_back(&cir);//2*PI*12
	shapeList.push_back(&tri);//12
	shapeList.push_back(&rect);//34
	
	Sort sort1;
	sort1.sortByDecreasingPerimeter(&shapeList);
	
	ASSERT_EQ(cir.perimeter(), shapeList.front()->perimeter());
	shapeList.pop_front();
	ASSERT_EQ(rect.perimeter(), shapeList.front()->perimeter());
	ASSERT_EQ(tri.perimeter(), shapeList.back()->perimeter());	
}

TEST (Sort, sortByIncreasingArea) {
	vertex vertex_1 = {0, 0};
	vertex vertex_2 = {3, 0};
	vertex vertex_3 = {3, 4};
	Triangle tri(vertex_1, vertex_2, vertex_3);
	Circle cir(0, 0, 12);
	Rectangle rect(0, 0, 8, 9);
	
	std::list<Shape *> shapeList;
	shapeList.push_back(&cir);//12*12*PI
	shapeList.push_back(&tri);//6
	shapeList.push_back(&rect);//72
	
	Sort sort1;
	sort1.sortByIncreasingArea(&shapeList);
	
	ASSERT_EQ(tri.area(), shapeList.front()->area());
	shapeList.pop_front();
	ASSERT_EQ(rect.area(), shapeList.front()->area());
	ASSERT_EQ(cir.area(), shapeList.back()->area());
}

TEST (Sort, sortByDecreasingArea) {
	vertex vertex_1 = {0, 0};
	vertex vertex_2 = {3, 0};
	vertex vertex_3 = {3, 4};
	Triangle tri(vertex_1, vertex_2, vertex_3);
	Circle cir(0, 0, 12);
	Rectangle rect(0, 0, 8, 9);
	
	std::list<Shape *> shapeList;
	shapeList.push_back(&cir);//12*12*PI
	shapeList.push_back(&tri);//6
	shapeList.push_back(&rect);//72
	
	Sort sort1;
	sort1.sortByDecreasingArea(&shapeList);
	
	ASSERT_EQ(cir.area(), shapeList.front()->area());
	shapeList.pop_front();
	ASSERT_EQ(rect.area(), shapeList.front()->area());
	ASSERT_EQ(tri.area(), shapeList.back()->area());

}


TEST (Sort, sortByIncreasingCompactness) {
	vertex vertex_1 = {0, 0};
	vertex vertex_2 = {3, 0};
	vertex vertex_3 = {3, 4};
	Triangle tri(vertex_1, vertex_2, vertex_3);
	Circle cir(0, 0, 12);
	Rectangle rect(0, 0, 8, 9);
	
	std::list<Shape *> shapeList;
	shapeList.push_back(&cir);//6
	shapeList.push_back(&tri);//0.5
	shapeList.push_back(&rect);//2.11764705882
	
	Sort sort1;
	sort1.sortByIncreasingCompactness(&shapeList);
	
	ASSERT_EQ(tri.Compactness(), shapeList.front()->Compactness());
	shapeList.pop_front();
	ASSERT_EQ(rect.Compactness(), shapeList.front()->Compactness());
	ASSERT_EQ(cir.Compactness(), shapeList.back()->Compactness());
}

#endif
