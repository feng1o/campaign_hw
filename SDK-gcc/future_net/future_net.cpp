
#include "route.h"
#include "lib_io.h"
#include "lib_time.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "iostream"
int main(int argc, char *argv[])
{
    print_time("Begin");
    char *graph[5000];
    int edge_num;
    char *condition;
    int condition_num;

    char *graph_file = argv[1];
    edge_num = read_file(graph, 5000, graph_file);
    printf("\n .........edge_num = %d\n", edge_num);
	for(int i=0;i<1;i++) // edge_num
		{
            std::cout << "graph[" << i <<"]" << graph[0] << std::endl;
            for(int j =0 ; j<8; j++)
			std::cout<<"graph[" << i << "][" << j << "]" << graph[i][j] <<std::endl;
		}
    std::cout<<".............................\n\n";
    char *condition_file = argv[2];
    condition_num = read_file(&condition, 1, condition_file);

	unsigned int condition_len = strlen(condition);
    std::cout << "............"  << condition_len << std::endl;
	for(int i=0; i<=condition_len ;i++)
		{
			std::cout<<" condition[" << i << "]:" << condition[i] <<std::endl;
		}
    search_route(graph, edge_num, condition);

    char *result_file = argv[3];
    write_result(result_file);
    release_buff(graph, edge_num);
    release_buff(&condition, condition_num);

    print_time("End");

	return 0;
}

