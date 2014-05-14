//
// Copyright (c) 2014 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWOM_UI_HPP
#define TWOM_UI_HPP


#include <Wt/WPushButton>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>


namespace twom
{
	class ui
	{
		Wt::WContainerWidget& m_root;

	public:
		Wt::WLineEdit m_le_mappath;
		Wt::WPushButton m_pb_browsemap;

		ui(Wt::WContainerWidget& root) :
			m_root{root}
		{this->init();}

		auto& operator()() noexcept
		{return m_root;}

		void add_widget(Wt::WWidget* widget)
		{m_root.addWidget(widget);}

	private:
		void init()
		{
			m_pb_browsemap.setText("Browse...");

			// add to container
			m_root.addWidget(&m_le_mappath);
			m_root.addWidget(&m_pb_browsemap);
		}
	};
}


#endif // TWOM_UI_HPP
