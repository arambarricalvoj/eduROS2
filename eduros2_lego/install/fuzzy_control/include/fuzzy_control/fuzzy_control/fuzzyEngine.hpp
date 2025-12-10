#pragma once
#include <utility>
#include <fl/Headers.h>   // importa las clases de fuzzylite

class FuzzyEngine {
public:
    FuzzyEngine();
    double infer_delta_v(double e_v);

private:
    fl::Engine* engine_;
    fl::InputVariable* ev_;
    fl::OutputVariable* Delta_v_;
};
