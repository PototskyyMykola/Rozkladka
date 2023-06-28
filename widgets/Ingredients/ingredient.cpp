#include "ingredient.h"

Ingredient::Ingredient()
{
    clear();
}

void Ingredient::clear()
{
    setID(0);
    setName("");
    setWaist(0);
    setProteins(0);
    setFats(0);
    setCarbons(0);
    setEnergy(0);
}
