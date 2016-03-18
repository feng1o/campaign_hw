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



/* crosslist */
typedef struct str_crossListArc   crossListArc;
typedef struct str_crossListArc*  pcrossListArc;
typedef struct str_crossList      crossListHead;
typedef struct str_crossList*      pCrossListHead;
struct str_crossListArc
{
	str_crossListArc(startnode, endnode, cost, edgenumber, NULL, NULL) :\
		startNode(startnode), endNode(endnode), Cost(cost), edgeNumber(edgenumber),\
		down(NULL), right(NULL) {};
	~str_crossListArc()
		{};
	const u_short 		   startNode;
	const u_short		   endNode;
	u_short			       Cost;
	const int              edgeNumber;
	pcrossListArc	       down;
	pcrossListArc          right;
	//bool		           known;
};
struct str_crosslistHeadRow {
	bool          is_key;	//是否关键点
	bool	      known;		//是否走过
	u_short       layer;		//层数
	u_short       outDgree;	//出度
	pcrossListArc next;
};
struct str_crosslistHeadColumn {
	bool		   is_key;	//是否关键点
	bool		   known;		//是否走过
	u_short		   layer;		//层数
	u_short		   inDgree;	//ru度
	pcrossListArc  next;
};

struct str_crossList
{
	struct str_crosslistHeadRow*	head_row;
	struct str_crosslistHeadColumn* head_colunm;
	u_short 						nodeCount;
	int								edgeCount;
};

pCrossListHead creatCrossList(int edgenum);
u_short insertCrossList(pCrossListHead crossList, signed short nodeNum, const u_short startNode, \
	const u_short endNode, u_short cost, const int edgenum);
void printCrossList(pCrossListHead crosslist, int num);
/* crosslist */


void conditionCharToUshort(u_short  vertexCondition[600], const char *condition);
u_short graphCharToCrosList(tyCrossList* crosslist, char *graph[5000], int edgeNum);

#endif