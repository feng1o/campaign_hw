#ifndef __MY_DEALDATA_H_
#define __MY_DEALDATA_H_

#include "iostream"
#include "memory"
#include "cstring"
#include "cassert"
#include "map"
#define def_myAssert(x)  do{if(nullptr == (x)) \
	std::cout << "error"  <<  __LINE__ << __DATE__ << __FUNCTION__ << __FILE__ <<std::endl; \
	std::abort(); }\
	while(0)
typedef unsigned short u_short;
typedef  enum enu_VertexInfo{ c_useLessTag = 0,  c_haveToGoTag = 1, c_startTag = 2,c_endTag = 3}vertexInfo;

typedef struct str_crossListNode   crossListNode;
typedef struct str_crossListNode*  pCrossListNode;

struct str_crossListNode
{
	int 		   row;
	int			   column;	
	u_short		   adjacentCost;
	int            edgeNumber;
	pCrossListNode down;
	pCrossListNode right;
	bool		   known;
};

typedef struct 
{
	pCrossListNode  head_row;
	pCrossListNode  head_colunm;
	u_short 		rowCount;
	u_short 		columnCount;
	int				edgeCount;
}tyCrossList;




void conditionCharToUshort(u_short  vertexCondition[600], const char *condition);
u_short graphCharToCrosList(tyCrossList* crosslist, char *graph[5000], int edgeNum);

#endif