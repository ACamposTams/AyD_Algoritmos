#include "stdafx.h"
#include <fstream>
#include <chrono>
#include <iostream>

void GraphML(PNGraph);
void GEXF(PNGraph);
void GDF(PNGraph);
void JSON(PNGraph);

int main(int argc, char* argv[]) 
{
	PNGraph graph = TSnap::LoadEdgeList<PNGraph>("CA-GrQc.txt", 0, 1);
	
	auto begin = std::chrono::high_resolution_clock::now();
	GraphML(graph);
	auto end = std::chrono::high_resolution_clock::now();
	auto tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "GraphML: " << tiempo.count() << std::endl;

	begin = std::chrono::high_resolution_clock::now();
	GEXF(graph);
	end = std::chrono::high_resolution_clock::now();
	tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "GEXF: " << tiempo.count() << std::endl;

	begin = std::chrono::high_resolution_clock::now();
	GDF(graph);
	end = std::chrono::high_resolution_clock::now();
	tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "GDF: " << tiempo.count() << std::endl;

	begin = std::chrono::high_resolution_clock::now();
	JSON(graph);
	end = std::chrono::high_resolution_clock::now();
	tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "JSON: " << tiempo.count() << std::endl;
}

void GraphML(PNGraph graph)
{
	std::ofstream file("CA-GrQc.graphml");
	if (file.is_open())
	{
		file << "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n";
		file << "<graphml xmlns= \"http://graphml.graphdrawing.org/xmlns\" xmlns:xsi= \"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation= \"http://graphml.graphdrawing.org/xmlns http ://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd\">\n";
		file << "<graph id=\"G\" edgedefault=\"undirected\">\n";

		for (PNGraph::TObj::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++)
		{
			file << "<node id=\"" << NI.GetId() << "\"/>\n";
		}

		for (PNGraph::TObj::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++)
		{
			file << "<edge source=\"" << EI.GetSrcNId() << "\" target=\"" << EI.GetDstNId() << "\"/>\n";
		}

		file << "</graph>\n";
		file << "</graphml>\n";

		file.close();
	}
}

void GEXF(PNGraph graph)
{
	std::ofstream file("CA-GrQc.gexf");
	if (file.is_open())
	{
		file << "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n";
		file << "<gexf xmlns = \"http://www.gexf.net/1.2draft\" version=\"1.2\">\n";
		file << "<graph mode=\"static\" defaultedgetype=\"undirected\">\n";

		file << "<nodes>\n";

		for (PNGraph::TObj::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++)
		{
			file << "<node id=\"" << NI.GetId() << "\" />\n";
		}

		file << "</nodes>\n";
		file << "<edges>\n";

		for (PNGraph::TObj::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++)
		{
			file << "<edge source=\"" << EI.GetSrcNId() << "\" target=\"" << EI.GetDstNId() << "\" />\n";
		}

		file << "</edges>\n";
		file << "</graph>\n";
		file << "</gexf>\n";
		file.close();
	}
}

void GDF(PNGraph graph)
{
	std::ofstream file("CA-GrQ.gdf");

	if (file.is_open())
	{
		file << "nodedef>id VARCHAR\n";

		for (PNGraph::TObj::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++)
		{
			file << NI.GetId() << "\n";
		}

		file << "edgedef>source VARCHAR,destination VARCHAR\n";

		for (PNGraph::TObj::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++)
		{
			file << EI.GetSrcNId() << ", " << EI.GetDstNId() << "\n";
		}

		file.close();
	}
}

void JSON(PNGraph graph)
{
	std::ofstream file("CA-GrQ.json");

	if (file.is_open())
	{
		file << "{ \n \"graph\": {\n";
		file << "vertices\": [\n";

		for (PNGraph::TObj::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++)
		{
			if (NI != graph->EndNI())
			{
				file << "{\n \"_id\": \"" << NI.GetId() << "\"\n },\n";
			}
			else
			{
				file << "{\n \"_id\": \"" << NI.GetId() << "\"\n }\n";
			}
		}

		file << "],\n";
		file << "edges\": [\n";

		for (PNGraph::TObj::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++)
		{
			if (EI != graph->EndEI())
			{
				file << "{\n \"_outV\": \"" << EI.GetSrcNId() << "\",\n";
				file << "\"_inV\": \"" << EI.GetDstNId() << "\"\n }, \n";
			}
			else
			{
				file << "{\n \"_outV\": \"" << EI.GetSrcNId() << "\",\n";
				file << "\"_inV\": \"" << EI.GetDstNId() << "\"\n } \n";
			}
		}

		file << "]\n";
		file << "}\n }\n";

		file.close();
	}
}
