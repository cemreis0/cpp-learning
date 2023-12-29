// learning/cpp-plus-data-structures-5th-ed/graph/Graph.cpp

#include "GraphType.h"

template<class VertexType>
int indexIs(VertexType* vertices, VertexType vertex);

// -------------------------

template<class VertexType>
GraphType<VertexType>::GraphType()
// post:    arrays of size 50 are dynamically allocated for
//          marks and vertices. numVertices is set to 0;
//          maxVertices is set to 50.
{
    numVertices = 0;
    maxVertices = 50;
    vertices = new VertexType[50];
    marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
// post:    arrays of size maxV are dynamically allocated for
//          marks and vertices. numVertices is set to 0;
//          maxVertices is set to maxV.
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
// post:    arrays for vertices and marks have been deallocated
{
    delete [] vertices;
    delete [] marks;
}

const int NULL_EDGE = 0;

template<class VertexType>
void GraphType<VertexType>::addVertex(VertexType vertex)
/*
post:   vertex has been stored in vertices.
        corresponding row and column of edges have been set
        to NULL_EDGE.
        numVertices has been incremented.
*/
{
    vertices[numVertices] = vertex;

    for (int index = 0; index < numVertices; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;
}

template<class VertexType>
void GraphType<VertexType>::addEdge(VertexType fromVertex, VertexType toVertex, int weight)
// post:    edge (fromVertex, toVertex) is stored in edges
{
    int row;
    int col;

    row = indexIs(vertices, fromVertex);
    col = indexIs(vertices, toVertex);
    edges[row][col] = weight;
}

template<class VertexType>
int GraphType<VertexType>::getWeight(VertexType fromVertex, VertexType toVertex)
// post:    return the weight associated with edge(fromVertex, toVertex)
{
    int row;
    int col;
    
    row = indexIs(vertices, fromVertex);
    col = indexIs(vertices, toVertex);
    return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::getToVertices(VertexType vertex, QueType<VertexType>& adjVertices)
// post:    returns a queue of vertices adjacent from vertex
{
    int fromIndex;
    int toIndex;

    fromIndex = indexIs(vertices, vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
        if (edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.enqueue(vertices[toIndex])
}



// -------------------------



template<class VertexType>
int indexIs(VertexType* vertices, VertexType vertex)
// post:    return the index of vertex in vertices
{
    int index = 0;
    while (!(vertex == vertices[index]))
        index++;
    return index;
}