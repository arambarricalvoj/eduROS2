#include "fuzzy_control/fuzzyEngine.hpp"
#include <fl/Headers.h>

using namespace fl;

FuzzyEngine::FuzzyEngine() {
    engine_ = new Engine;
    engine_->setName("MotorFuzzyVel");

    // Entrada e_v (error de velocidad en tacho counts/segundo)
    // EV3 Large Motor: ±1050 grados/segundo ≈ ±1050 tacho counts/segundo
    ev_ = new InputVariable;
    ev_->setName("e_v");
    ev_->setRange(-1100.0, 1100.0);

    // términos solapados para cubrir todo el rango
    ev_->addTerm(new Triangle("muy_bajo", -1100, -800, -400));
    ev_->addTerm(new Triangle("bajo",     -600, -300, 0));
    ev_->addTerm(new Triangle("medio",    -200, 0, 200));
    ev_->addTerm(new Triangle("alto",      0, 300, 600));
    ev_->addTerm(new Triangle("muy_alto",  400, 800, 1100));
    engine_->addInputVariable(ev_);

    // Salida Delta_v (corrección en porcentaje de potencia del motor)
    Delta_v_ = new OutputVariable;
    Delta_v_->setName("Delta_v");
    Delta_v_->setRange(-100.0, 100.0);   // rango en porcentaje
    Delta_v_->setDefaultValue(0.0);
    Delta_v_->setDefuzzifier(new Centroid(200));
    Delta_v_->setAggregation(new Maximum);

    // términos de salida solapados
    Delta_v_->addTerm(new Triangle("negativo_fuerte", -100, -100, -50));
    Delta_v_->addTerm(new Triangle("negativo_suave",  -60, -30, 0));
    Delta_v_->addTerm(new Triangle("nulo",            -5, 0, 5));
    Delta_v_->addTerm(new Triangle("positivo_suave",   0, 30, 60));
    Delta_v_->addTerm(new Triangle("positivo_fuerte",  50, 100, 100));
    engine_->addOutputVariable(Delta_v_);

    // Reglas difusas
    RuleBlock* rules = new RuleBlock;
    rules->setImplication(new Minimum);

    rules->addRule(Rule::parse("if e_v is muy_bajo then Delta_v is negativo_fuerte", engine_));
    rules->addRule(Rule::parse("if e_v is bajo then Delta_v is negativo_suave", engine_));
    rules->addRule(Rule::parse("if e_v is medio then Delta_v is nulo", engine_));
    rules->addRule(Rule::parse("if e_v is alto then Delta_v is positivo_suave", engine_));
    rules->addRule(Rule::parse("if e_v is muy_alto then Delta_v is positivo_fuerte", engine_));

    engine_->addRuleBlock(rules);
}

double FuzzyEngine::infer_delta_v(double e_v) {
    ev_->setValue(e_v);     // asignar entrada
    engine_->process();     // ejecutar inferencia
    return Delta_v_->getValue(); // salida crisp en porcentaje
}
