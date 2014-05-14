//
// Copyright (c) 2014 Christoph Malek
// See LICENSE for more information.
//

#include <twom/application.hpp>


int main(int argc, char* argv[])
{
	return Wt::WRun(argc, argv, [](const auto& env){return new twom::application{env};});
}
