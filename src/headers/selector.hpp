#pragma once

#include "object.hpp"

// HERITE DE OBJET

class Selector : virtual public Object {
public:
    Selector();
    Selector(glm::vec3 position); // Nécessaire ? Ou ajouter : Object(glm::vec3 position)
    ~Selector();

    void drawSelector();
    
};