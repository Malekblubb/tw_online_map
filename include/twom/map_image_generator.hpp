//
// Copyright (c) 2014 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWOM_MAP_IMAGE_GENERATOR_HPP
#define TWOM_MAP_IMAGE_GENERATOR_HPP


#include <QBuffer>
#include <QByteArray>
#include <QImage>
#include <Wt/WImage>
#include <Wt/WMemoryResource>

#include <mlk/types/types.h>


namespace twom
{
	class map_image_generator
	{
		QByteArray m_bytearray;
		QBuffer m_helperbuffer{&m_bytearray};

		std::vector<mlk::sptr<Wt::WMemoryResource>> m_resources;


	public:
		Wt::WImage* generate(const mlk::data_packet& data, mlk::st width, mlk::st height)
		{
			QImage helper{data.data(), static_cast<int>(width), static_cast<int>(height), QImage::Format_ARGB32};
			helper = helper.rgbSwapped(); // swap rgb

			m_helperbuffer.close();
			m_bytearray.clear();
			m_helperbuffer.open(QIODevice::WriteOnly);
			helper.save(&m_helperbuffer, "PNG");

			m_resources.push_back(std::make_shared<Wt::WMemoryResource>());
			m_resources.back()->setData({m_helperbuffer.data().begin(), m_helperbuffer.data().end()});
			auto* result(new Wt::WImage{m_resources.back().get()});
			return result;
		}
	};
}


#endif // TWOM_MAP_IMAGE_GENERATOR_HPP
