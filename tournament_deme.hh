#pragma once
#include "deme.hh"

class TournamentDeme : public Deme {
    public:

    virtual ~TournamentDeme() = default;

    protected:
    virtual ClimbChromosome* select_parent(int exp) override;
};