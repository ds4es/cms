/**
 * This script load a road graph from an OpenStreetMap PBF file,
 * save its properties and the contracted form for later reuse
 *
 * COMPILE AND EXECUTE
 *
 * Compile:
 * g++ -Ilib/RoutingKit/include -Llib/RoutingKit/lib -std=c++11 ./test/graph_properties_preview.cpp -o ./bin/graph_properties_preview -lroutingkit -lprotobuf-lite -losmpbf -lz -lboost_serialization
 * 
 * Declare shared libraries to consider:
 * export LD_LIBRARY_PATH=./lib/RoutingKit/lib:~/.local/boost-libs/lib:/usr/local/lib64:/usr/local/lib
 * 
 * Launch the generated executable
 * ./bin/graph_properties_preview ./data/pbf/andorra-latest.osm.pbf
 */
#include "../src/graph/graph.h"

void graph_properties_preview(cms::Graph &graph) {

	printf("\n*** GRAPH PROPERTIES PREVIEW:*** \n\n");

	(!graph.first_out.empty()) 			? printf("graph.first_out[0] : %u \n", graph.first_out[0]) 			: printf("graph.first_out empty!!\n");
	(!graph.head.empty()) 				? printf("graph.head[0] : %u \n", graph.head[0]) 					: printf("graph.head empty!!\n");
	(!graph.tail.empty()) 				? printf("graph.tail[0] : %u \n", graph.tail[0]) 					: printf("graph.tail empty!!\n");
	(!graph.way.empty()) 				? printf("graph.way[0] : %u \n", graph.way[0]) 						: printf("graph.way empty!!\n");
	(!graph.geo_distance.empty()) 		? printf("graph.geo_distance[0] : %u \n", graph.geo_distance[0]) 	: printf("graph.geo_distance empty!!\n");
	(!graph.latitude.empty()) 			? printf("graph.latitude[0] : %f \n", graph.latitude[0]) 			: printf("graph.latitude empty!!\n");
	(!graph.longitude.empty()) 			? printf("graph.longitude[0] : %f \n", graph.longitude[0]) 			: printf("graph.longitude empty!!\n");
	(!graph.travel_time.empty()) 		? printf("graph.travel_time[0] : %u \n", graph.travel_time[0])		: printf("graph.travel_time empty!!\n");
	(!graph.way_speed.empty()) 			? printf("graph.way_speed[0] : %u \n", graph.way_speed[0]) 			: printf("graph.way_speed empty!!\n");
	(!graph.way_name.empty()) 			? printf("graph.way_name[0] : %u \n", graph.way_name[0]) 			: printf("graph.way_name empty!!\n");
	(!graph.way_osmid.empty()) 			? printf("graph.way_osmid[0] : %lu \n", graph.way_osmid[0]) 		: printf("graph.way_osmid empty!!\n");
	(!graph.ways_osm.empty()) 			? printf("graph.ways_osm[0] : %lu \n", graph.ways_osm[0]) 			: printf("graph.ways_osm empty!!\n");
	(!graph.osmwayid_to_idx.empty()) 	? printf("graph.osmwayid_to_idx[graph.ways_osm[0]] : %u \n"
		, graph.osmwayid_to_idx[graph.ways_osm[0]]) : printf("graph.osmwayid_to_idx empty!!\n");
	(!graph.osmwayid_to_idx.empty()) 	? printf("graph.get_nodes_from_way(graph.osmwayid_to_idx[graph.way_osmid[graph.way[0]]]) : %s \n"
		, graph.get_nodes_from_way(graph.osmwayid_to_idx[graph.way_osmid[graph.way[0]]]).c_str()) 			: printf("graph.get_nodes_from_way empty!!\n");

	printf("\ngraph.node_count : %u \n", graph.node_count);

	printf("\n*** \n");

}	

int main(int argc, char*argv[])
{
	try{

		std::string	pbf_file, destination_folder;
		pbf_file = argv[1];

		if (argc > 2) {
	  		destination_folder = argv[2];
		} else {
			destination_folder = "./data/backup";
		}

		cms::Graph graph;
		graph.load_from_pbf(pbf_file);

		graph_properties_preview(graph);

	}catch(std::exception&err){
		std::cerr << "Stopped on exception : " << err.what() << std::endl;
		return 1;
	}

	return 0;
}

