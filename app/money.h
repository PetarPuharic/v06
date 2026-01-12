#pragma once
#include <iostream>
#include <ostream>


namespace vsite::oop::v7 {
    
    class money {
    private:
        int total_cents;
    public:
        money(int euro = 0, int cents = 0);

        money& operator-=(const money& other);
        money& operator+=(const money& other);

        friend std::ostream& operator<<(std::ostream& os, const money& m);
        friend std::istream& operator>>(std::istream& is, money& m);

        int get_total_cents() const;
    };
}
