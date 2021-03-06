#include "Export.h"

json SeriousGraphTools::Export::exportToIncidenceMatrix(const SeriousGraphTools::SimpleGraph &graph) {
    json json;
    for (int col = 0; col < graph.getEdges().size(); col++)
        for (int row = 0; row < graph.getNodes().size(); row++)
        {
            json[row][col] = 0;
            if (graph.getEdges()[col].getTo()->getId() == row)
                json[row][col] = graph.getEdges()[col].isBi() ? 1 : -1;
            if (graph.getEdges()[col].getFrom()->getId() == row)
                json[row][col] = 1;
        }

    return json;
}
