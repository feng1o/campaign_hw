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
	extern pCrossListHead  crosslist ;	
	extern signed short  creatNodeNum ; // record the created crosslist head index

	//mapMyNoToVertex.clear();
	//mapVertexToMyNo.clear();
	int vertexNum = -1;
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
						mapVertexToMyNo[index] = ++vertexNum;  //start with 0
						mapMyNoToVertex[vertexNum] = index;
					}
				}
					else if (-1 == endNode)
					{
						endNode = index;
						if(mapVertexToMyNo.count(index) == 0)
						{
						mapVertexToMyNo[index] = ++vertexNum;  //start with 0
						mapMyNoToVertex[vertexNum] = index;
					}
				}
					else if (700 == subCost)
					{
						subCost = index;
						//std::cout << "const is =" << index <<std::endl;
						creatNodeNum = insertCrossList(crosslist, creatNodeNum,  startNode, \
							endNode, subCost, edgeIdentifer);
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
	return vertexNum + 1;  //start from 0
}


/*cross lsit */

pCrossListHead creatCrossList(int edgenum)
{
	//def_MyAssert(edgenum);
	pCrossListHead crossList = new crossListHead{NULL, NULL, 0, edgenum };
	crossList->head_row = new struct str_crosslistHeadRow[600];
	crossList->head_colunm = new struct str_crosslistHeadColumn[600];
	return crossList;
}
void initCrossListHeadNode(pCrossListHead crossList, signed short nodeNum)
{
	crossList->head_row[nodeNum].is_key = false;
	crossList->head_row[nodeNum].known = false;
	crossList->head_row[nodeNum].layer = 0;
	crossList->head_row[nodeNum].outDgree = 0;
	crossList->head_row[nodeNum].next = NULL;

	crossList->head_colunm[nodeNum].is_key = false;
	crossList->head_colunm[nodeNum].known = false;
	crossList->head_colunm[nodeNum].layer = 0;
	crossList->head_colunm[nodeNum].inDgree = 0;
	crossList->head_colunm[nodeNum].next = NULL;
}
u_short insertCrossList(pCrossListHead crossList, signed short nodeNum, const u_short startNode, \
	const u_short endNode, u_short cost, const int edgenum)
{
	if (startNode > nodeNum  && endNode > nodeNum)  //increase tow node
	{
		++nodeNum;
		initCrossListHeadNode(crossList, nodeNum);
		++nodeNum;
		initCrossListHeadNode(crossList, nodeNum);
	}
	else if (startNode > nodeNum  || endNode > nodeNum)  //find just increase one node
	{
		++nodeNum;
		initCrossListHeadNode(crossList, nodeNum);
	}
	pcrossListArc cListArc = new crossListArc{ startNode, endNode, cost, edgenum, NULL, NULL };
	//def_MyAssert(cListArc);
	pcrossListArc tmpArc = crossList->head_row[startNode].next;
	crossList->head_row[startNode].next = cListArc;
	cListArc->right = tmpArc;
	++crossList->head_row[startNode].outDgree;

	tmpArc = crossList->head_colunm[endNode].next;
	crossList->head_colunm[endNode].next = cListArc;
	cListArc->down = tmpArc;
	++crossList->head_colunm[endNode].inDgree;
	return nodeNum;
}
void printCrossList(pCrossListHead crosslist, int num)
{
	for (int i = 0; i < num; i++)
	{
		std::cout << "headrow " << i << " iskey=" << crosslist->head_row[i].is_key << " outdgree=" << crosslist->head_row[i].outDgree << std::endl;
	}
	for (int i = 0; i < num; ++i){
		pcrossListArc arc = crosslist->head_row[i].next;
		while (arc){
			std::cout << "start =" << arc->startNode << " end =" << arc->endNode << " cost =" << arc->Cost \
				<< " edge=" << arc->edgeNumber << std::endl;
			arc = arc->right;
		}
	}
	std::cout << "..............................\n";
	for (int i = 0; i < num; i++)
	{
		std::cout << "headrow " << i << " iskey=" << crosslist->head_colunm[i].is_key << " outdgree=" << crosslist->head_colunm[i].inDgree << std::endl;
	}
	for (int i = 0; i < num; ++i){
		pcrossListArc arc = crosslist->head_colunm[i].next;
		while (arc){
			std::cout << "start =" << arc->startNode << " end =" << arc->endNode << " cost =" << arc->Cost \
				<< " edge=" << arc->edgeNumber << std::endl;
			arc = arc->down;
		}
	}
}

/*
int main()
{
	pCrossListHead crossList = creatCrossList(600);
	signed short nodeNum = -1;
	//nodeNum = insertCrossList(crossList, nodeNum, 0, 1, 1, 1);
	//nodeNum = insertCrossList(crossList, nodeNum, 0, 3, 10, 2);
	//nodeNum = insertCrossList(crossList, nodeNum, 0, 2, 18, 3);
	//nodeNum = insertCrossList(crossList, nodeNum, 1, 3, 5, 60);
	//nodeNum = insertCrossList(crossList, nodeNum, 2, 3, 2, 4);
	
	nodeNum = insertCrossList(crossList, nodeNum, 0, 1, 1, 1);
	nodeNum = insertCrossList(crossList, nodeNum, 0, 2, 18, 3);
	nodeNum = insertCrossList(crossList, nodeNum, 0, 3, 10, 2);
	nodeNum = insertCrossList(crossList, nodeNum, 1, 3, 5, 60);
	nodeNum = insertCrossList(crossList, nodeNum, 2, 3, 2, 4);
	std::cout << nodeNum << std::endl;
	printCrossList(crossList, nodeNum+1);
	
	return 0;

}
*/
























