#include "GraphMatrix.hpp"

GraphMatrix::GraphMatrix(int numV, GType type) : Graph(numV, 0, type) {
    
    adjMatrix = new bool*[v];
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = new bool[v];
        for (int j = 0; j < v; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

GraphMatrix::~GraphMatrix() {
    if (adjMatrix != nullptr) {
        for (int i = 0; i < v; i++) {
            delete [] adjMatrix[i];
        }
        delete [] adjMatrix;
        adjMatrix = nullptr;
    }
}

bool GraphMatrix::isEdge(int i, int j) const {
    if (i < 0 || i >=v || j < 0 || j >= v) {
        return false;
    }
    return adjMatrix[i][j];
}

ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < v; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < v; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < v; i++) {
        os << i << " | ";
        for (int j = 0; j < v; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

void GraphMatrix::toggleEdge(int i, int j) {
    if (i < 0 || i >= v || j < 0 || j >= v) {
        return;
    }

    bool oldVal = adjMatrix[i][j];
    bool newVal = !oldVal;

    adjMatrix[i][j] = newVal;

    if (graphType == UNDIRECTED) {
        adjMatrix[i][j] = newVal;

        if (!oldVal && newVal) {
            e++;
        } else if (oldVal && !newVal) {
            e--;
        }
    } else { // DIRECTED
        if (!oldVal && newVal) {
            e++;
        } else if (oldVal && !newVal) {
            e--;
        }
    }
}
