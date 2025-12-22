#pragma once

namespace vsite::oop::v7 
{

		friend std::ostream& operator<<(std::ostream& os, const money& m);
		friend std::istream& operator>>(std::istream& is, money& m);

}
