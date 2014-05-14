//
// Copyright (c) 2014 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWOM_APPLICATION_HPP
#define TWOM_APPLICATION_HPP



#include "ui.hpp"

#include <Wt/WApplication>
#include <Wt/WBootstrapTheme>
#include <Wt/WEnvironment>

#include "map_image_generator.hpp"

#include <twl/files/files.hpp>


namespace twom
{
	class application : public Wt::WApplication
	{
		ui m_ui;
		map_image_generator m_mapimagegen;

		// theme
		Wt::WBootstrapTheme m_theme;

	public:
		application(const Wt::WEnvironment& env) :
			Wt::WApplication{env},
			m_ui{*this->root()}
		{this->init();}

	private:
		void init()
		{
			this->setTheme(&m_theme);
		}
	};
}


#endif // TWOM_APPLICATION_HPP
