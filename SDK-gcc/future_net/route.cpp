
#include "route.h"
#include "lib_record.h"
#include <stdio.h>

#include "my_dealData.h"
#include "iomanip"
u_short startVertex =700;
u_short endVertex = 700;
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
   




    
    unsigned short result[] = {2, 6, 3};//示例中的一个解
    for (int i = 0; i < 3; i++)
        record_result(result[i]);
}



























