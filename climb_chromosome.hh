#pragma once
#include "chromosome.hh"

class ClimbChromosome : public Chromosome {
  public:

    ClimbChromosome(const Cities*);

    virtual ~ClimbChromosome() = default;

    virtual void mutate() override;

    virtual Chromosome* clone() const override
    {
        return new ClimbChromosome(*this);
    }

    ClimbChromosome* swap_index(int index1, int index2) const;
};