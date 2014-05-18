//
// Copyright (c) 2014 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWOM_MAP_TILELAYER_WIDGET_HPP
#define TWOM_MAP_TILELAYER_WIDGET_HPP


#include <Wt/WPaintedWidget>
#include <Wt/WPainter>
#include <Wt/WTransform>

#include <mlk/types/types.h>

#include <twl/files/files.hpp>

#include <algorithm>


namespace twom
{
	class map_tilelayer_widget final : public Wt::WPaintedWidget
	{
		Wt::WPainter::Image m_image;
		twl::tiles m_tiles;
		mlk::st m_width, m_height;

	public:
		map_tilelayer_widget(const std::string& img_uri, const twl::tiles& tiles, mlk::st width, mlk::st height) :
			Wt::WPaintedWidget{nullptr},
			m_image{img_uri, img_uri},
			m_tiles{tiles},
			m_width{width},
			m_height{height}
		{
			this->resize(width, height);
			this->update();
		}

	protected:
		void paintEvent(Wt::WPaintDevice* paintDevice) override
		{
			Wt::WPainter painter{paintDevice};

			mlk::st current_x{0}, current_y{0};
			for(const auto& tile : m_tiles)
			{
				if(tile.index == 0)
					continue;

				painter.resetTransform();

				auto tilepos_x((tile.index % 16) * 64), tilepos_y((tile.index / 16) * 64);

				if(tile.flags & 1)
					;
				if(tile.flags & 2)
					painter.rotate(180);
				if(tile.flags & 4)
					;
				if(tile.flags & 8)
					;


				painter.drawImage(current_x * 64, current_y * 64, m_image, tilepos_x, tilepos_y, 64, 64);


				if(current_x == m_width / 64 - 1)
				{
					current_x = 0;
					++current_y;
					continue;
				}
				++current_x;
			}
		}
	};
}


#endif // TWOM_MAP_TILELAYER_WIDGET_HPP
