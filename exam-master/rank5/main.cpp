/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:58:51 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 15:14:44 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"

int		main(void)
{
	Warlock john("John", "king of the north");

	john.introduce();
	john.setTitle("father of the dragons");
	john.introduce();

	Fwoosh		fw;	
	Fireball	fb;
	Polymorph	pm;

	Dummy		du;
	BrickWall	bw;

	john.learnSpell(&fw);
	john.learnSpell(&fb);
	john.launchSpell("Fwoosh", du);
	john.launchSpell("Fireball", du);
	john.launchSpell("Polymorph", du);
	john.learnSpell(&pm);
	john.launchSpell("Fwoosh", du);
	john.launchSpell("Fireball", du);
	john.launchSpell("Polymorph", du);
	john.forgetSpell("Fwoosh");

	TargetGenerator		tg;

	tg.learnTargetType(&du);
	tg.learnTargetType(&bw);
	john.launchSpell("Fwoosh", *tg.createTarget("Dummy Practice"));
	john.launchSpell("Fireball", *tg.createTarget("BrickWall Practice"));
	john.launchSpell("Polymorph", *tg.createTarget("BrickWall Practice"));
	if (!tg.createTarget("pute"))
		std::cout << "OK\n";
	return (0);
}
