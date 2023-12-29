// learning/cpp-plus-data-structures-5th-ed/graph/GraphSearch.cpp

#include "stack/StackType.h"
#include "queue/QueType.h"
#include "GraphType.h"
#include "priority-queue/PQ.h"
#include <iostream>

// back up as little as possible
template<class VertexType>
void depthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex)
// pre: operators == and << for VertexType are defined
{
    using namespace std;

    StackType<VertexType> stack;
    QueType<VertexType> vertexQ;

    bool found = false;
    VertexType vertex;
    VertexType item;

    graph.clearMarks();
    stack.push(startVertex);

    do
    {
        stack.pop(vertex);
        if (vertex == endVertex)
        {
            cout << vertex << endl;
            found true;
        }
        else
        {
            if (graph.isMarked(vertex))
            {
                graph.markVertex(vertex);
                cout << vertex << endl;
                graph.getToVertices(vertex, vertexQ);

                while (!vertexQ.isEmpty())
                {
                    vertexQ.dequeue(item);
                    if (!graph.isMarked(item));
                        stack.push(item);
                }
            }
        }
    } while (!stack.isEmpty() && !found)
    if (!found)
        cout << "Path not found." << endl;
}

// back up as much as possible
template<class VertexType>
void breadthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex)
// pre: operators == and << for VertexType are defined
{
    using namespace std;
    QueType<VertexType> queue;
    QueType<VertexType> vertexQ;

    bool found = false;
    VertexType vertex;
    VertexType item;

    graph.clearMarks();
    queue.enqueue(startVertex);

    do
    {
        queue.dequeue(vertex);

        if (vertex == endVertex)
        {
            cout << vertex << endl;
            found = true;
        }
        else
        {
            if (!graph.isMarked(vertex))
            {
                graph.markVertex(vertex);
                cout << vertex << endl;
                graph.getToVertices(vertex, vertexQ);

                while (!vertexQ.isEmpty())
                {
                    vertexQ.dequeue(item);
                    if (!graph.isMarked(item))
                        queue.enqueue(item);
                }
            }
        }
    } while (!queue.isEmpty() && !found)
    if (!found)
        cout << "Path not found." << endl;
}

// find the path with the smallest edge value sum, i.e. the shortest path
template<class VertexType>
struct ItemType
{
    bool operator<(ItemType otherItem);
    bool operator==(ItemType otherItem);
    bool operator<=(ItemType otherItem);
    VertexType fromVertex;
    VertexType toVertex;
    int distance;
};

template<class VertexType>
void shortestPath(GraphType<VertexType> graph, VertexType startVertex)
{
    using namespace std;
    ItemType item;
    int minDistance;
    PQType<VertexType> pq(10); // assume at most 10 vertices
    QueType<VertexType> vertexQ;
    VertexType vertex;

    graph.clearMarks();
    item.fromVertex = startVertex;
    item.toVertex = startVertex;
    item.distance = 0;
    pq.enqueue(item);
    cout << "Last Vertex Destination Distance" << endl;
    cout << "--------------------------------" << endl;

    do
    {
        pq.dequeue(item);

        if (!graph.isMarked(item.toVertex))
        {
            graph.markVertex(item.toVertex);
            cout << item.fromVertex << " " << item.toVertex << " " << item.distance << endl;
            item.fromVertex = item.toVertex;
            minDistance = item.distance;
            graph.getToVertices(item.fromVertex, vertexQ);

            while (!vertexQ.isEmpty())
            {
                vertexQ.dequeue(vertex);
                if (!graph.isMarked(vertex))
                {
                    item.toVertex = vertex;
                    item.distance = minDistance + graph.getWeight(item.fromVertex, vertex);
                    pr.enqueue(item);
                }
            }
        }
    } while (!pq.isEmpty());
}