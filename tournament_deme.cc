#include "tournament_deme.hh"
#include <vector>
#include <cmath>
#include <algorithm>

ClimbChromosome*
TournamentDeme::select_parent(int exp) override {
    std::vector<ClimbChromosome*> parents;
    for (int i=0; i < std::pow(2, exp), i++) { 
        std::uniform_int_distribution<int> dist(0, order_.size() - 1);
        auto new_parent = pop_[dist(generator_)];
        if (std::find(parents.begin(), parents.end(), new_parent) != parents.end()) {
            parents.push_back(new_parent);
    }
    for (exp > 0; exp--) {
        for (int i=0, i < std::pow(2, exp)) { 
            auto parent1 = parents[i++];
            auto parent2 = parents[i++];
            if (parent1->get_fitness() > parent2->get_fitness()) {
                parents.erase(i-1);
            } else {
                parents.erase(i-2);
            }
        }
    }
    return parents[0];
}