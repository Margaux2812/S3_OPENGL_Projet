#ifndef _Selector_hpp_
#define _Selector_hpp_

#include "object.hpp"

// HERITE DE OBJET

class Selector : virtual public Object {
public:
    Selector();
    Selector(glm::vec3 position);
    ~Selector();

    void drawSelector();
    
};

#endif