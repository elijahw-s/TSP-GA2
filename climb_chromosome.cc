#include "climb_chromosome.hh"

ClimbChromosome::ClimbChromosome(const Cities* cities_ptr)
  : cities_ptr_(cities_ptr),
    order_(random_permutation(cities_ptr->size())),
    generator_(rand())
{
  assert(is_valid());
}


void
ClimbChromosome::mutate() override {
    std::uniform_int_distribution<int> dist(0, order_.size() - 1);
    int swap_loc = dist(generator_)
    auto back_swap = this->clone();
    auto front_swap = this->clone();
    if (swap_loc == 0) {
        back_swap.swap_index(0, -1);
    } else {
        back_swap.swap_index(swap_loc, swap_loc - 1);
    }
    if (swap_loc = order_.size() - 1) {
        front_swap.swap_index(swap_loc, 0);
    } else {
        front_swap.swap_index(swap_loc, swap_loc + 1);
    }
    if (back_swap.get_fitness() > get_fitness() && back_swap.get_fitness() > front_swap.get_fitness()) {
        order_ = back_swap->order_;
    } else if (front_swap.get_fitness() > get_fitness() && front_swap.get_fitness() > back_swap.get_fitness()) {
        order_ = front_swap->ordeR_;
    }
}

void 
ClimbChromosome::swap_index(int index1, int index2) const {
    std::swap(ret_chrom.order_[index1], ret_chrom.order_[index2]);
    assert(is_valid());
}
