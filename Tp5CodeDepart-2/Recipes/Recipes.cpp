// Recipes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "RecipeBook.h"

int main()
{
    try {
        std::cout << "Creating the LOG1410 Recipe Book\n";
        RecipeBook log1410Recipes("The LOG1410 Recipe Book");

        std::cout << "Looking for pizza in the LOG1410 Recipe Book\n";
        const Recipe* pizzaPtr = log1410Recipes.findRecipe("pizza");

        if (pizzaPtr != nullptr)
            std::cout << "Pizza recipe found!" << std::endl << "Here is the recipe: " << std::endl << *pizzaPtr << std::endl;
        else
            std::cout << "No Pizza recipe found, sorry!" << std::endl;

        std::cout << "Impression du livre au complet: " << std::endl << log1410Recipes << std::endl;
    }

    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
