
#pragma once

#include <type_traits>
#include "CommunicationData.h"

namespace ConceptTests
{

    template <class T>
    concept CommunicationDataDefault = requires(T a)
    {
        a.createDefaultData();
    };

    template <CommunicationDataDefault T>
    bool doSomething(T var)
    {
        var.createDefaultData();
        return true;
    }

} // namespace ConceptTests