/************************************************************************/
/*                                                                      */
/* This file is part of FirstDrive.                                         */
/*                                                                      */
/* FirstDrive is free software: you can redistribute it and/or modify       */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or    */
/* (at your option) any later version.                                  */
/*                                                                      */
/* FirstDrive is distributed in the hope that it will be useful,            */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of       */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        */
/* GNU General Public License for more details.                         */
/*                                                                      */
/* You should have received a copy of the GNU General Public License    */
/* along with FirstDrive.  If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                      */
/* This is the main entry point for FirstDrive.                             */
/*                                                                      */
/************************************************************************/

#include "game.h"
#include "logging.h"
#include "pathmanager.h"

#include <list>
using std::list;

#include <string>
using std::string;

#include <iostream>
using std::endl;

#include <fstream>
#include <sstream>



unsigned int Bezier::NumIdx = 0;

int main (int argc, char * argv[])
{
	// Find the path of the log file.
	PathManager paths;
	std::ostringstream dummy;
	paths.Init(dummy, dummy);
	string logfilename = paths.GetLogFile();

	// Open the log file.
	std::ofstream logfile(logfilename.c_str());
	if (!logfile)
	{
		std::cerr << "Couldn't open log file: " << logfilename << std::endl;
		return EXIT_FAILURE;
	}

	// Set up the logging arrangement.
	logging::splitterstreambuf infosplitter(std::cout, logfile);
	std::ostream infosplitterstream(&infosplitter);
	logging::splitterstreambuf errorsplitter(std::cerr, logfile);
	std::ostream errorsplitterstream(&errorsplitter);
	logging::logstreambuf infolog("INFO: ", infosplitterstream);
	logging::logstreambuf errorlog("ERROR: ", errorsplitterstream);

	// Primary logging ostreams.
	std::ostream info_output(&infolog);
	std::ostream error_output(&errorlog);

	// Create the game object.
	Game game(info_output, error_output);

	// Start the real game.
	list <string> args(argv, argv + argc);
	game.Start(args);

	info_output << "Exiting" << std::endl;

	return EXIT_SUCCESS;
}
