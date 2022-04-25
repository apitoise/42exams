#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

class	Dummy;

class	Dummy : public ATarget {
	public:
		Dummy(void);
		virtual ~Dummy(void);
		virtual ATarget	*clone(void) const;
};

#endif
