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
/************************************************************************/

#include "renderuniform.h"

RenderUniform::RenderUniform()
{
	// Constructor.
}

RenderUniform::RenderUniform(GLint loc, const RenderUniformEntry & entry) : RenderUniformBase(entry.data), location(loc)
{
	// Constructor.
}

RenderUniform::RenderUniform(GLint loc, const std::vector <float> & newdata) : RenderUniformBase(newdata), location(loc)
{
	// Constructor.
}
