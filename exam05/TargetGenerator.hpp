#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <vector>
# include "ATarget.hpp"

class	TargetGenerator {
	public:
		TargetGenerator(void);
		virtual	~TargetGenerator(void);

		void	learnTargetType(ATarget *t);
		void	forgetTargetType(const std::string &t);
		ATarget	*createTarget(const std::string &t);

	private:
		std::vector<ATarget *>	_targets;

		TargetGenerator(const TargetGenerator &t);
		TargetGenerator	&operator=(const TargetGenerator &t);
};

#endif
