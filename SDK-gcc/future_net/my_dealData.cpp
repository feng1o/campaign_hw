/*
*funciotn: deal data
*
*/

#include "my_dealData.h"


void conditionCharToUshort(u_short  vertexCondition[600], const char *condition)
{
	//def_myAssert(vertexCondition);
	vertexInfo useLessVertex = c_useLessTag;
	for(int i =0 ; i < 600;  ++i){
		vertexCondition[i] = useLessVertex;
	}
	extern u_short startVertex;
	extern u_short endVertex;
	u_short  index=0;
	u_short count_index = 0;
	long long condition_length = std::strlen(condition);
	long long i =0;
	u_short intPlachHolder[10];
	int lastPosition = -1;
	//std::vector<u_short> have
	for(; count_index < 2;  ++i){
		if(condition[i]  <  '0'  || condition[i]  >  '9'){
			if( lastPosition != -1){
				int index = 0;
				for(int j=0;  j <= lastPosition;  ++j){
					index =  index*10 + intPlachHolder[j];
				}
				if(startVertex == 700){
					startVertex =index;
					vertexCondition[index] = c_startTag;
					}
				else if(endVertex == 700){
					endVertex = index;
					vertexCondition[index] = c_endTag;
					//break;
				}
				lastPosition = -1;
				++count_index;
			}
			continue;
		}
		intPlachHolder[++lastPosition] = condition[i] - '0';
		}
	
	for( ;  i < condition_length -1;  ++i){
		if(condition[i]  <  '0'  || condition[i]  >  '9'){
			if( lastPosition != -1){
				int index = 0;
				for(int j=0;  j <= lastPosition;  ++j){
					index =  index*10 + intPlachHolder[j];
				}
				vertexCondition[index] = c_haveToGoTag;
				lastPosition = -1;
			}
			continue;
		}
		intPlachHolder[++lastPosition] = condition[i] - '0';
	}
}

u_short graphCharToCrosList(tyCrossList* crosslist, char *graph[5000], int edgeNum){
	extern std::map<int, int> mapVertexToMyNo;
	extern std::map<int, int> mapMyNoToVertex;
	//mapMyNoToVertex.clear();
	//mapVertexToMyNo.clear();
	int vertexNum = 0;
	u_short intPlachHolder[10];
	int lastPosition = -1;
	int edgeIdentifer = -1;  //read edge num
	int 	startNode = -1;
	int     endNode = -1;
	u_short subCost = 700;
	int index = 0;
	for(int i = 0 ;  i < edgeNum ;  ++i){
		for(int n = 0; graph[i][n] != '\0'; ++n){
			if(graph[i][n]  <  '0'  || graph[i][n]  >  '9'){
				if( lastPosition != -1){
					for(int j=0;  j <= lastPosition;  ++j){
						index =  index*10 + intPlachHolder[j];
					}
					if (-1 == edgeIdentifer)
					{
						edgeIdentifer = index;
					}
					else if (-1 == startNode)
					{
						startNode = index;
						if(mapVertexToMyNo.count(index) == 0){
						mapVertexToMyNo[index] = ++vertexNum;  //start with 1
						mapMyNoToVertex[vertexNum] = index;
					}
				}
					else if (-1 == endNode)
					{
						endNode = index;
						if(mapVertexToMyNo.count(index) == 0)
						{
						mapVertexToMyNo[index] = ++vertexNum;  //start with 1
						mapMyNoToVertex[vertexNum] = index;
					}
				}
					else if (700 == subCost)
					{
						std::cout << "const is =" << index <<std::endl;

						edgeIdentifer = -1;  //read edge num
						startNode = -1;
						endNode = -1;
						subCost = 700;
					}
					lastPosition = -1;
					index = 0;
				}
				continue;
			}
			intPlachHolder[++lastPosition] = graph[i][n] - '0';
		}
	}
	return vertexNum;
}




























