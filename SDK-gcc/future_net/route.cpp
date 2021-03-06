
#include "route.h"
#include "lib_record.h"
#include <stdio.h>

#include "my_dealData.h"
#include "iomanip"


u_short startVertex =700;
u_short endVertex = 700;

std::map<int, int> mapVertexToMyNo;
std::map<int, int> mapMyNoToVertex;
//std::map<int, std::pair<u_short, int>> mapDeleteDuplicateArc;  //record arc, delete duplicate arc,
std::map<int, int> mapDeleteDuplicateArc;  //record arc, delete duplicate arc,

extern signed short  creatNodeNum = -1;  //vertex num


//你要完成的功能总入口
void search_route(char *graph[5000], int edge_num, char *condition)
{
	u_short vertexCondition[600];
	conditionCharToUshort(vertexCondition, condition);
    for (int i = 0; i < 600; ++i)
    {
    	std::cout << std::setw(2) << vertexCondition[i];
    	if((i+1) % 10 == 0)
    		std::cout << std::endl;
    }
    std::cout << "startVertex = " << startVertex << std::endl;
    std::cout << "endVertex   = " << endVertex << std::endl;

    std::cout << "\ntest grap to crosslist ................................" << std::endl;
    pCrossListHead  crosslist = creatCrossList(edge_num);
    u_short vertexNum = graphCharToCrosList(crosslist, graph, edge_num);
    std::cout << "vertexNum = " << vertexNum << std::endl;
   

    for (int i = 0; i < vertexNum; ++i)
    {
        std::cout << "mytovertex" << i << " is:" << mapMyNoToVertex[i] << std::endl;
    }
#if 0
    for (int i = 0; i < vertexNum; ++i) //less than 1
    {
        std::cout << "vertextomy" << i << " is " << mapVertexToMyNo[i]  << std::endl;
    }
#endif
	printCrossList(crosslist, creatNodeNum);
    unsigned short result[] = {2, 6, 3};//示例中的一个解
    for (int i = 0; i < 3; i++)
        record_result(result[i]);
}



























