/**
 * (C) Copyright 2020, by Jonathan Howard
 *
 * This is my original solution to the Pencil Durability Kata for Pillar Technology
 * which describes a pencil with a point and an eraser that degrades with use.
 *
 * https://github.com/PillarTechnology/kata-pencil-durability
 */

#ifndef PENCIL_DURABILITY_PENCIL_H
#define PENCIL_DURABILITY_PENCIL_H

#include <cstddef>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
#include "Point.h"
#include "Eraser.h"
#include "helpers.h"

namespace PencilDurability {
    class Pencil {
    public:
        // defaults approximate typical #2 pencil
        explicit Pencil(int point = 3000, std::size_t length = 40, int eraser = 1000);
        void attach(std::string& paperRef);
        void write(std::string_view text);
        void erase(std::string_view text);
        void overwrite(std::string_view text);
        void sharpen();

    private:
        void checkPaper();
        std::string buildWriteString(std::string_view text);
        std::string buildEraseString(std::string_view text);
        std::string buildOverwriteString(std::string_view text, std::size_t off);
        Point& point();
        std::vector<Point> points;
        Eraser eraser;
        std::string* paper;
    };
}

#endif //PENCIL_DURABILITY_PENCIL_H