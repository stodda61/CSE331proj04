/****************************************************************************
  Craig Stoddard
  A45086748
  CSE331 Project #2
  Binary Search Tree
****************************************************************************/
//#include "bst.h"
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<list>

using namespace std; 

class Graph {
	private:
		int v; //v is number of vertices in graph
		list<int> *adj; //pointer to array containing adjacency list
	public:
		Graph(int size = 2);
		void addEdge(int u, int v); //function to add edge to graph
		void BFS(int); // displays Breadth First Traversal based on starting node
};

Graph::Graph(int v) {
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v); //add v to u's list
}

void Graph::BFS(int s) {
	bool *visited = new bool[v];
	cout << "BFS" << endl;
	cout << "D = ";
	//mark all vertices as not visited
	for (int i = 0; i <= v; i++)
	{
		visited[i] = false;
	}

	//create the BFS queue
	list<int> queue;

	//mark the first node as visited and add to queue
	visited[s] = true;
	queue.push_back(s);

	//i will get all adjacent vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		//dequeue a vertext from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		
		//get all adjacent vertices of the dequeued vertex s
		//if an adjacent has not been visited mark it visited and 
		//add to the queue
		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			cout << "Parent: " << s << endl;
			cout << "child: " << *i << endl;
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	cout << endl;
}

//main function, takes and converts the input file
//to ints and then adds edges based on who the parent
//currently is, finally calling the BFS function 
//to display the graph
int main(int argc, char * argv[])
{
	fstream input(argv[1], ios::in);
	char ch;
	string buffer;
	string ch1 = argv[2];
	int nodeStart = atoi(ch1.c_str());
	cout << "starting node: " << nodeStart << endl;
	int parent;
	ch = input.get();
	buffer += ch;
	int numNodes = atoi(buffer.c_str());
	cout << "Number of Nodes: " << numNodes << endl;
	buffer.clear();
	Graph graph(numNodes+1);

	while(!input.eof())
	{
		ch = input.get();
		if (isdigit(ch))
		{
			buffer += ch;
			
		}
		else if (ch == ' ')
		{
			int number = atoi(buffer.c_str());
			buffer.clear();
			graph.addEdge(parent, number);
			cout << number << endl;
		}
		else if (ch == ':') 
		{
			parent = atoi(buffer.c_str());
			cout << "Reached Colon with parent: " << parent << endl;
			buffer.clear();
		}
		else if (ch == '\n' && !buffer.empty() )
		{
			int number = atoi(buffer.c_str());
			cout << number << endl;
			buffer.clear();
			graph.addEdge(parent, number);
		}

	}

	graph.BFS(nodeStart);
		
	return 0;
}


