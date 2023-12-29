// learning/cpp-plus-data-structures-5th-ed/graph/Graph.h

#include "queue/QueType.h"

#pragma once

template<class VertexType>
class GraphType
{
    public:
        GraphType();
        GraphType(int maxV);
        ~GraphType();
        void makeEmpty();
        bool isEmpty() const;
        bool isFull const;
        void addVertex(VertexType);
        void addEdge(VertexType, VertexType, int);
        int getWeight(VertexType, VertexType);
        void getToVertices(VertexType, QueType<VertexType>&);
        void clearMarks();
        void markVertex(VertexType);
        bool isMarked(VertexType);
    private:
        int numVertices;
        int maxVertices;
        VertexType* vertices;
        int edges[50][50];
        bool* marks; // marks[i] is the mark for vertices[i]
};