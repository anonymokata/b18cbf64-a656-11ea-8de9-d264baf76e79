#include "catch.hpp"
#include <string>
#include "Pencil.h"

using namespace PencilDurability;

SCENARIO("pencils can write text to paper")
{
    GIVEN("a pencil and paper") {
        Pencil pencil;
        std::string paper;

        WHEN("the pencil writes text") {
            pencil.writeTextToPaper("She sells sea shells", paper);

            THEN("the paper reflects the text that was written") {
                CHECK(paper == "She sells sea shells");
            }
        }
    }
}
