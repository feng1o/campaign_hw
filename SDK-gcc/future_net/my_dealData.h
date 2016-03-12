#ifndef __MY_DEALDATA_H_
#define __MY_DEALDATA_H_

#include "iostream"
#include "memory"
#include "cstring"
#include "cassert"

#define def_myAssert(x)  do{if(nullptr == (x)) \
	std::cout << "error"  <<  __LINE__ << __DATE__ << __FUNCTION__ << __FILE__ <<std::endl; \
	std::abort(); }\
	while(0)
typedef unsigned short u_short;
typedef  enum enu_VertexInfo{ c_useLessTag = 0,  c_haveToGoTag = 1, c_startTag = 2,c_endTag = 3}vertexInfo;
	
void conditionCharToUshort(u_short  vertexCondition[600], const char *condition);

class cMyVertex{
	public:
		cMyVertex() = default;
		cMyVertex(const cMyVertex &vertex);
		~cMyVertex(){};
	private:
		u_short                     m_nodeNum =700;
		bool 			 m_travelKey = false;
		bool  			 m_known = false;
		u_short			 m_inDgree = 0;
		u_short 			 m_outDgree = 0;
		unsigned long long m_cost = 0;
		cMyVertex*          m_pNext = nullptr;
			};
#endif